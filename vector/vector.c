#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mem_abort(void) {
	fprintf(stderr, "error (re)allocating memory.¥n");
	abort();
}

#define V_INIT_CAP 4
#define V_SCALE_FACTOR 1.5f
//TODO: tweak values
typedef struct vector {
	void *items;
	size_t capacity;
	size_t size;
	size_t sizeof_type;
} vector;

void v_init_with_capacity(vector *v, size_t sizeof_type, size_t capacity) {
	v->capacity = capacity;
	v->size = 0;
	v->sizeof_type = sizeof_type;
	v->items = malloc(sizeof_type * capacity);
	if (v->items == NULL) mem_abort();
}
void v_init(vector *v, size_t sizeof_type) {
	v_init_with_capacity(v, sizeof_type, V_INIT_CAP);
}
void *v_index(vector *v, size_t index) {
	return (void *)((char *) v->items + v->sizeof_type * index);
}
static void v_resize(vector *v, size_t new_capacity) {
	void *new_v_items = realloc(v->items, v->sizeof_type * new_capacity);
	if (new_v_items == NULL) mem_abort();
	v->items = new_v_items;
	v->capacity = new_capacity;
}
void v_set(vector *v, int index, void *item) {
	memcpy(v_index(v, index), item, v->sizeof_type);
}
void *v_get(vector *v, int index) {
	return v_index(v, index);
}
void v_push_back(vector *v, void *item) {
	if (v->capacity == v->size) v_resize(v, (size_t) (v->capacity * V_SCALE_FACTOR));
	v_set(v, v->size, item);
	v->size++;
}
void v_delete(vector *v, int index) {
	for(int i = index; i < v->size - 1; i++) {
		for(int j = 0; j < v->sizeof_type; i++) {
			*((char *)(v_index(v, i)) + j) = *((char *)(v_index(v, i + 1)) + j);
		}
	}
	v->size--;
	if (v->size > 0 && v->size == (size_t)((float)v->capacity / V_SCALE_FACTOR / V_SCALE_FACTOR))
		v_resize(v, v->capacity / V_SCALE_FACTOR);
	//TODO: check if shrink routine works
}
void v_free(vector *v) {
	free(v->items);
}