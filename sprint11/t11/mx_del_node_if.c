#include "list.h"

void mx_del_node_if(t_list **list, void *del_data, bool (*cmp)(void *a, void *b)) {
    t_list *current = *list;
    t_list *prev = NULL;
    t_list *temp = NULL;

    while (current != NULL)
    {
        temp = current;
        current = current->next;
        if (cmp(temp->data, del_data)) {
            if (prev != NULL) {
                prev->next = current;
            }
            if (*list == temp) {
                *list = current;
            }
            free(temp);
        }
        else {
            prev = temp;
        }
    }
}
