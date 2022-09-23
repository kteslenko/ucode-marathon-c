#include "../inc/header.h"

static bool check_bounds(t_map *map, t_point *point) {
    return point->x > 0
        && point->y > 0
        && point->x < map->width
        && point->y < map->height;
}

int main(int argc, char *argv[]) {

    if (argc != 6 ) {
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        return -1;
    }

    char *map_str = mx_file_to_str(argv[1]);
    bool status = true;
    t_map *map;
    t_point *entry;
    t_point *exit;

    if (map_str == NULL
        || mx_strlen(map_str) == 0) {
        mx_printerr("map does not exist\n");
        status = false;
    }

    if (status) {
        map = parse_map(map_str);
        if (map == NULL) {
            mx_printerr("map error\n");
            status = false;
        }
    }

    if (status) {
        entry = new_point(mx_atoi(argv[2]), mx_atoi(argv[3]));
        exit = new_point(mx_atoi(argv[4]), mx_atoi(argv[5]));

        if (!check_bounds(map, entry)
            || !check_bounds(map, exit)) {
            mx_printerr("points are out of map range\n");
            status = false;
        }
    }

    if (status
        && map->points[entry->x][entry->y] == 1) {
        mx_printerr("entry point cannot be an obstacle\n");
        status = false;
    }

    if (status
        && map->points[exit->x][exit->y] == 1) {
        mx_printerr("exit point cannot be an obstacle\n");
        status = false;
    }

    if (status) {
        int **temp = map->points;
        map->points = lee(map, entry);
        t_list *path = find_path(map, exit);
        t_list *max = get_max_distance(map);
        map->points = temp;

        if (path == NULL) {
            mx_printerr("route not found\n");
            status = false;
        }
    }

    

    /* 

    printf("width: %d\t height: %d\n", map->height, map->height);
    
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            printf("%d", map->points[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");

    t_point entry = {1, 1};

    map->points = lee(map, &entry);

    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            printf("%d \t", map->points[j][i]);
        }
        printf("\n");
    }
    
    printf("\n");
    printf("\n");

    t_point exit = {3, 3};

    t_list *list = find_path(map, &exit);
    mx_foreach_list(list, *print_point);
    */
}


