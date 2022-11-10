#pragma once

#include "header.h"

typedef struct s_agent {
    char *name;
    int power;
    int strength;
}              t_agent;

t_agent *mx_create_agent(char *name, int power, int strength);
void mx_exterminate_agents(t_agent ***agents);
void mx_sort(t_agent **arr, int size, bool (*f)(t_agent*, t_agent*));
