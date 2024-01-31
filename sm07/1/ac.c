
enum {
    ISZERO = 0x0,
    WITHOUTSIGN = 0x7FFFFFFF,
    FULLEXP = 0x7F800000,
    EMPTYEXP = 0x7FFFFFFF,
    ONLYMANTIS = 0x7FFFFFFF,
    MANTIS_SIZE = 23,
    ALL_WITHOUTSIGN = 31,
};

union U {
    float value;
    int representation;
};

FPClass fpclassf(float value, int *psign) {
    union U u;
    u.value = value;
    if ((u.representation & WITHOUTSIGN) == ISZERO) {
        *psign = (u.representation >> ALL_WITHOUTSIGN);
        return FFP_ZERO;
    }
    if ((u.representation & WITHOUTSIGN) == FULLEXP) {
        *psign = (u.representation >> ALL_WITHOUTSIGN);
        return FFP_INF;
    }
    if ((((u.representation & WITHOUTSIGN) >> MANTIS_SIZE) ==
         (FULLEXP >> MANTIS_SIZE)) &&
        ((u.representation & WITHOUTSIGN) & ONLYMANTIS) != ISZERO) {
        return FFP_NAN;
    }
    if (((u.representation & WITHOUTSIGN) & FULLEXP) >> MANTIS_SIZE == ISZERO) {
        *psign = (u.representation >> ALL_WITHOUTSIGN);
        return FFP_DENORMALIZED;
    }
    *psign = (u.representation >> ALL_WITHOUTSIGN);
    return FFP_NORMALIZED;
}
