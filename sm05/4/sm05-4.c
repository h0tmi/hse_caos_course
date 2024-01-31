#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void append(struct Node **head, int value) {
    struct Node *new_node = calloc(1, sizeof(*new_node));

    new_node->value = value;
    new_node->next = NULL;

    if ((*head)) {
        struct Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    } else {
        *head = new_node;
    }
}

void print(struct Node *head) {
    if (!head) {
        return;
    }
    print(head->next);
    printf("%d \n", head->value);
}

int main() {
    struct Node *head = NULL;
    int value;

    while (scanf("%d", &value) == 1) {
        append(&head, value);
    }

    print(head);

    while (head) {
        struct Node *cur = head->next;
        free(head);
        head = cur;
    }
}
