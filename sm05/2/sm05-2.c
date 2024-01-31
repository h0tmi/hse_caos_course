#include <stdio.h>
#include <stdlib.h>

enum {
    MULT = 1103515245,
    BASE = 12345,
    MODUL = 2147483648,
};

typedef struct RandomGenerator RandomGenerator;

typedef struct {
    void (*destroy)(RandomGenerator *rr);
    int (*next)(RandomGenerator *rr);
} RandomOperations;

typedef struct RandomGenerator {
    int state;
    RandomOperations *ops;
} RandomGenerator;

static void destroy(RandomGenerator *rr) {
    free(rr->ops);
    free(rr);
}

static int next(RandomGenerator *rr) {
    rr->state =
        ((((MULT & (MODUL - 1)) * (rr->state & (MODUL - 1))) & (MODUL - 1)) +
         BASE) &
        (MODUL - 1);
    return rr->state;
}

RandomGenerator *random_create(int seed) {
    RandomGenerator *rr = calloc(1, sizeof(*rr));
    rr->state = seed;
    rr->ops = calloc(1, sizeof(*rr->ops));
    rr->ops->next = next;
    rr->ops->destroy = destroy;
    return rr;
}
