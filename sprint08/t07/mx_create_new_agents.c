#include "create_new_agents.h"

t_agent **mx_create_new_agents(char **name, int *power, int *strength, int count) {
    t_agent **agents;

    if (name == NULL
        || power == NULL
        || strength == NULL
        || count == 0) {
        return NULL;
    }

    agents = malloc(sizeof(t_agent*) * (count + 1));
    agents[count] = NULL;

    for (int i = 0; i < count; i++) {
        agents[i] = mx_create_agent(name[i], power[i], strength[i]);
    }

    return agents;
}
