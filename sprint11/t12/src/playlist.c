#include "header.h"

static bool check_command(const char *name, int argc, char *argv[]) {
    if (mx_strcmp(argv[2], name) != 0) {
        return false;
    }
    if (mx_strcmp(argv[2], "add") == 0) {
        return argc == 5;
    }
    if (mx_strcmp(argv[2], "remove") == 0) {
        return argc == 4;
    }
    if (mx_strcmp(argv[2], "sort") == 0) {
        return argc == 4
               && (mx_strcmp(argv[3], "artist") == 0
               || mx_strcmp(argv[3], "name") == 0);
    }
    if (mx_strcmp(argv[2], "print") == 0) {
        return argc == 3;
    }
    return false;
}

static bool read_playlist(const char *filename, t_list **out) {
    char *str = mx_file_to_str(filename);
    t_list *list = NULL;
    char *ptr = str;

    if (str == NULL) {
        return false;
    }

    while (*ptr != '\0') {
        t_song *song = malloc(sizeof(t_song));
        char* end = mx_strchr(ptr, ',');
        int len = end - ptr;
        
        song->artist = mx_strndup(ptr, len);
        ptr = end + 1;
        end = mx_strchr(ptr, '\n');
        len = end - ptr;
        song->name = mx_strndup(ptr, len);
        ptr = end + 1;

        mx_push_back(&list, song);
    }

    *out = list;
    return true;
}

static ssize_t min(ssize_t a, ssize_t b) {
    if (a < b) {
        return a;
    }
    return b;
}

static bool write_playlist(t_list *list, const char *filename) {
    int out = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    ssize_t result = 0;

    if (out == -1) {
        return false;
    }

    while (list != NULL
           && result != -1) {
        t_song *song = (t_song*)list->data;

        result = min(result, write(out, song->artist, mx_strlen(song->artist)));
        result = min(result, write(out, ",", 1));
        result = min(result, write(out, song->name, mx_strlen(song->name)));
        result = min(result, write(out, "\n", 1));

        list = list->next;
    }

    close(out);
    return result != -1;
}

static bool add(const char *filename, const char *name, const char *artist) {
    t_list *list;
    t_song *song = malloc(sizeof(t_song));

    if (!read_playlist(filename, &list)) {
        return false;
    }

    song->name = mx_strdup(name);
    song->artist = mx_strdup(artist);

    mx_push_back(&list, song);

    return write_playlist(list, filename);
}

static bool remove(const char *filename, const char *index_str) {
    t_list *list;
    int index;

    if (!read_playlist(filename, &list)) {
        return false;
    }

    if (list == NULL) {
        return false;
    }

    if (mx_atoi(index_str, &index) == -1) {
        return false;
    }
    
    mx_pop_index(&list, index);

    return write_playlist(list, filename);
}

static char *to_upper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] -= 32;
        }
    }
    return str;
}

static bool cmp_name(void *a, void *b) {
    t_song *song_a = (t_song*)a;
    t_song *song_b = (t_song*)b;
    
    char *name_a = to_upper(mx_strdup(song_a->name));
    char *name_b = to_upper(mx_strdup(song_b->name));

    return mx_strcmp(name_a, name_b) > 0;
}

static bool cmp_artist(void *a, void *b) {
    t_song *song_a = (t_song*)a;
    t_song *song_b = (t_song*)b;

    char *artist_a = to_upper(mx_strdup(song_a->artist));
    char *artist_b = to_upper(mx_strdup(song_b->artist));

    return mx_strcmp(artist_a, artist_b) > 0;
}

static bool sort(const char *filename, const char *field) {
    t_list *list;

    if (!read_playlist(filename, &list)) {
        return false;
    }

    if (list == NULL) {
        return false;
    }

    if (mx_strcmp(field, "name") == 0) {
        list = mx_sort_list(list, cmp_name);
    }
    else if (mx_strcmp(field, "artist") == 0) {
        list = mx_sort_list(list, cmp_artist);
    }

    return write_playlist(list, filename);
}

static bool print(const char *filename) {
    t_list *list;

    if (!read_playlist(filename, &list)) {
        return false;
    }

    if (list == NULL) {
        return false;
    }

    int i = 0;
    
    while (list != NULL) {
        t_song *song = (t_song*)list->data;
        
        mx_printint(i);
        mx_printstr(". ");
        mx_printstr(song->artist);
        mx_printstr(" - ");
        mx_printstr(song->name);
        mx_printstr("\n");

        i++;
        list = list->next;
    }

    return true;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        mx_printerr("usage: ./playlist [file] [command] [args]\n");
        return -1;
    }

    bool status = false;

    if (check_command("add", argc, argv)) {
        status = add(argv[1], argv[3], argv[4]);
    }
    else if (check_command("remove", argc, argv)) {
        status = remove(argv[1], argv[3]);
    }
    else if (check_command("sort", argc, argv)) {
        status = sort(argv[1], argv[3]);
    }
    else if (check_command("print", argc, argv)) {
        status = print(argv[1]);
    }

    if (!status) {
        mx_printerr("ERROR\n");
        return -1;
    }
}
