// ValuStorage — free plan
#define VALU_FREE_MAX (3 * 1024 * 1024) // 3 MB

typedef struct {
    unsigned int used;
    unsigned int max;
    int plus; // 0 = Free, 1 = Storage+
} ValuStorage;

ValuStorage valu_storage_init(int plus) {
    ValuStorage s;
    s.used = 0;
    s.plus = plus;
    s.max = plus ? (64 * 1024 * 1024) : VALU_FREE_MAX;
    return s;
}

int valu_storage_alloc(ValuStorage* s, unsigned int size) {
    if (s->used + size > s->max) return 0;
    s->used += size;
    return 1;
}
