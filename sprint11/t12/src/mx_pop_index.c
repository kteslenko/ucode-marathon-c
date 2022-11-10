#include "list.h"

void mx_pop_index(t_list **list, int index) {
    t_list *current = *list;
    t_list *temp;
    int cur_idx = 0;
    
    if (index <= 0) {
        mx_pop_front(list);
        return;
    }

    while (cur_idx < index - 1
           && current != NULL)
    {
        current = current->next;
        cur_idx++;
    }

    if (current == NULL) {
        mx_pop_back(list);
        return;
    }

    temp = current->next;
    current->next = temp->next;
    free(temp);
}
