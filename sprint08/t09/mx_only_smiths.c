#include "only_smiths.h"

static bool is_smith(t_agent *agent, int strength) {
    return agent->strength < strength
           && mx_strcmp(agent->name, "Smith") == 0;
}

static int count_smiths(t_agent **agents, int strength) {
    int count = 0;

    for (int i = 0; agents[i] != NULL; i++) {
        if (is_smith(agents[i], strength)) {
            count++;
        }
    }

    return count;
}

t_agent **mx_only_smiths(t_agent **agents, int strength) {
    t_agent **smiths;
    int count;
    int idx = 0;

    if (agents == NULL) {
        return NULL;
    }

    count = count_smiths(agents, strength);
    smiths = malloc(sizeof(t_agent*) * (count + 1));
    smiths[count] = NULL;
    for (int i = 0; agents[i] != NULL; i++) {
        if (is_smith(agents[i], strength)) {
            smiths[idx] = mx_create_agent(agents[i]->name, agents[i]->power,
                                          agents[i]->strength);
            idx++;
        }
    }
    mx_exterminate_agents(&agents);
    return smiths;
}
