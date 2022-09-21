#include "agent.h"

static int count_agents(const char *str) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '{') {
            count++;
        }
    }

    return count;
}

static void discard_whitespace(char **str) {
    while (mx_isspace(**str)) {
        (*str)++;
    }
}

static char* parse_field(char *str, const char *name, t_agent *agent) {
    str = mx_strstr(str, name);
    if (str == NULL) {
        return false;
    }

    str += mx_strlen(name);
    if (*str != ':') {
        return false;
    }
    str++;

    discard_whitespace(&str);
    char *end = str;

    while (!mx_isspace(*end)) {
        end++;
    }
    
    int len = end - str;
    if (mx_strncmp(name, "name", 4) == 0) {
        agent->name = mx_strndup(str, len);
    }
    else if (mx_strncmp(name, "power", 5) == 0) {
        agent->power = mx_atoi(str);
    }
    else {
        agent->strength = mx_atoi(str);
    }

    return end;
}

static t_agent *parse_agent(char **str) {
    t_agent *agent = malloc(sizeof(t_agent));
    char *close = mx_strchr(*str, '}');

    discard_whitespace(str);
    if (mx_strncmp(*str, "agent", 5) != 0) {
        return NULL;
    }

    *str += 5;

    discard_whitespace(str);
    if (**str != '{') {
        return NULL;
    }
    
    *str = parse_field(*str, "name", agent);
    if (*str > close) {
        return NULL;
    }
    *str = parse_field(*str, "power", agent);
        if (*str > close) {
        return NULL;
    }
    *str = parse_field(*str, "strength", agent);
        if (*str > close) {
        return NULL;
    }

    *str = close + 1;

    return agent;
}

static t_agent **parse_agents(char *str) {
    int count = count_agents(str);
    t_agent **agents = malloc(sizeof(t_agent*) * (count + 1));
    
    agents[count] = NULL;
    for (int i = 0; i < count; i++) {
        agents[i] = parse_agent(&str);
        if (agents[i] == NULL) {
            mx_exterminate_agents(&agents);
            break;
        }
    }

    return agents;
}

static void print_agents(t_agent **agents) {
    for (int i = 0; agents[i] != NULL; i++) {
        mx_printstr("agent: ");
        mx_printstr(agents[i]->name);
        mx_printstr(", strength: ");
        mx_printint(agents[i]->strength);
        mx_printstr(", power: ");
        mx_printint(agents[i]->power);
        mx_printstr("\n");
    }
}

bool sort_name(t_agent *a, t_agent *b) {
    return mx_strcmp(a, b) > 0;
}

bool sort_power(t_agent *a, t_agent *b) {
    return a->power > b->power;
}

bool sort_strength(t_agent *a, t_agent *b) {
    return a->strength > b->strength;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
        return -1;
    }

    char *str = mx_file_to_str(argv[2]);

    if (str == NULL) {
        mx_printerr("error\n");
        return -1;
    }

    t_agent **agents = parse_agents(str);

    if (agents == NULL) {
        mx_printerr("error\n");
        return -1;
    }

    print_agents(agents);
    mx_exterminate_agents(&agents);
    free(str);
}
