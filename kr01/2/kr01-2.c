#include "dlist.h"
#include <stdio.h>
#include <stdlib.h>

Node *push(Node *place, int value) {
    Node *new_node = calloc(1, sizeof(*new_node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->value = value;
    if (place != NULL) {
        new_node->next = place;
        place->prev = new_node;
    }
    return new_node;
}

int pop(Node *node) {
    int value = node->value;
    if (node->prev) {
        node->prev->next = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    }
    free(node);
    return value;
}

int main() {
    Node *head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    printf("%d\n", pop(head->next));
    printf("%d\n", pop(head->next));
    printf("%d\n", pop(head));
    return 0;
}
