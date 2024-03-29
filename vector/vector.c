#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mem_abort(void) {
	fprintf(stderr, "error (re)allocating memory.¥n");
	exit(-1);
}

#define V_INIT_CAP 4
#define V_SCALE_FACTOR 2 
typedef struct vector {
	void *items;
	size_t capacity;
	size_t size;
	size_t sizeof_type;
} vector;

vector *v_create_with_capacity(size_t sizeof_type, size_t capacity) {
	vector *v = malloc(sizeof(vector));
	if (v == NULL) mem_abort();
	v->capacity = capacity;
	v->size = 0;
	v->sizeof_type = sizeof_type;
	v->items = malloc(sizeof_type * capacity);
	if (v->items == NULL) mem_abort();
	return v;
}
vector *v_create(size_t sizeof_type) {
	return v_create_with_capacity(sizeof_type, V_INIT_CAP);
}
void *v_index(vector *v, size_t index) {
	return (void *)((char *) v->items + v->sizeof_type * index);
}
void v_resize(vector *v, size_t new_capacity) {
	void *new_v_items = realloc(v->items, v->sizeof_type * new_capacity);
	if (new_v_items == NULL) mem_abort();
	v->items = new_v_items;
	v->capacity = new_capacity;
}
void v_set(vector *v, int index, void *item) {
	memcpy(v_index(v, index), item, v->sizeof_type);
}
void *v_at(vector *v, int index) {
	return v_index(v, index);
}
void v_push_back(vector *v, void *item) {
	if (v->capacity == v->size) v_resize(v, v->capacity * V_SCALE_FACTOR);
	v_set(v, v->size, item);
	v->size++;
}
void v_delete(vector *v, int index, int auto_resize) {
	if (index != v-> size - 1) {
		memmove(v_index(v, index), v_index(v, index + 1), v->sizeof_type * (v->size - index - 1));
	}
	v->size--;
	if (auto_resize && v->size > 0 && v->size <= (size_t)(v->capacity / V_SCALE_FACTOR / V_SCALE_FACTOR))
		v_resize(v, v->capacity / V_SCALE_FACTOR);
}
void v_free(vector *v) {
	free(v->items);
	free(v);
}

#define iv_create() (v_create(sizeof(int)))
#define iv_at(v, index) (*((int *)v_at((v), (index))))
#define iv_push_back(v, item) {int __vdum = item; v_push_back(v, &__vdum);}

