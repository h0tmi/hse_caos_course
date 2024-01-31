#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct elt {
    uint32_t a;
    uint32_t b;
    struct elt *next;
};

struct elt *head;
void list_reverse();

int main() {
    uint32_t x;
    while (scanf("%u", 	&x) == 1) {
        struct elt* elt = calloc(sizeof(struct elt), 1);
        elt->a = x;
        elt->b = x/2;
        elt->next = head;
        head = elt;
    }
    list_reverse();
    while (head) {
        printf("%u %u\n", head->a, head->b);
        head = head->next;
    }
}
