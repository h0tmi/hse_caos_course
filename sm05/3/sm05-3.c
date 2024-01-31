#include <stddef.h>

struct BSearchResult {
    size_t low;
    size_t high;
    int result;
};

struct BSearchResult
bsearch2(const void *key, const void *base, size_t nmemb, size_t size,
         int (*compar)(const void *p1, const void *p2, void *user),
         void *user) {
    if (nmemb == 0 || compar(key, base, user) < 0) {
        struct BSearchResult result = {0, 0, 0};
        return result;
    }
    size_t l = 0;
    size_t r = nmemb;
    size_t mid;

    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (compar(key, base + size * mid, user) < 0) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (compar(key, base + size * (r - 1), user) != 0) {
        struct BSearchResult result = {r, r, 0};
        return result;
    }
    struct BSearchResult result = {r, r, 1};
    l = 0;
    while (l < r) {
        mid = (l + r) / 2;
        if (compar(key, base + size * mid, user) <= 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    result.low = l;
    return result;
}
