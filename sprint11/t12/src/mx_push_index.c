#include "list.h"

void mx_push_index(t_list **list, void *data, int index) {
    t_list *current = *list;
    t_list *node;
    int cur_idx = 0;

    if (index <= 0
        || current == NULL) {
        mx_push_front(list, data);
        return;
    }

    while (cur_idx < index - 1
           && current != NULL)
    {
        current = current->next;
        cur_idx++;
    }

    if (current == NULL) {
        mx_push_back(list, data);
        return;
    }

    node = mx_create_node(data);
    node->next = current->next;
    current->next = node;
}
