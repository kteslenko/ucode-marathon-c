#include "only_smiths.h"

void mx_exterminate_agents(t_agent ***agents) {
    if (agents == NULL) {
        return;
    }
    if (*agents == NULL) {
        return;
    }
    for (int i = 0; (*agents)[i] != NULL; i++) {
        free((*agents)[i]);
    }
    free(*agents);
    *agents = NULL;
}
