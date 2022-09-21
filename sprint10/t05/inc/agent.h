#pragma once

#include "header.h"

typedef struct s_agent {
    char *name;
    int power;
    int strength;
}              t_agent;

t_agent *mx_create_agent(char *name, int power, int strength);
void mx_exterminate_agents(t_agent ***agents);
