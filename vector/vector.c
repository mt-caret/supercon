#include <stdio.h>
#include <stdlib.h>

void mem_abort(void) {
	fprintf(stderr, "error (re)allocating memory.¥n");
	abort();
}

#define V_INIT_CAP 4
#define V_SCALE_FACTOR 1.5f
//TODO: tweak values
typedef struct vector {
	void **items;
	size_t capacity;
	size_t size;
} vector;

void v_init_with_capacity(vector *v, size_t capacity) {
	v->capacity = capacity;
	v->size = 0;
	v->items = calloc(v->capacity, sizeof(void *));
	//This call to calloc() guarantees zero-initialization of vector contents.
	//Use malloc() if it is unnecessary or performance is an issue.
	if (v->items == NULL) mem_abort();
}
void v_init(vector *v) {
	v_init_with_capacity(v, V_INIT_CAP);
}
unsigned int v_size(vector *v) {
	return v->size;
}
static void v_resize(vector *v, size_t new_capacity) {
	void **new_v_items = realloc(v->items, sizeof(void *) * new_capacity);
	//TODO: check realloc side-effects (eg. zero initialization)
	if (new_v_items == NULL) mem_abort();
	v->items = new_v_items;
	v->capacity = new_capacity;
}
void v_push_back(vector *v, void *item) {
	if (v->capacity == v->size) v_resize(v, (size_t) (v->capacity * V_SCALE_FACTOR));
	v->items[v->size] = item;
	v->size++;
}
void v_set(vector *v, int index, void *item) {
	v->items[index] = item;
}
void *v_get(vector *v, int index) {
	return v->items[index];
}
void v_delete(vector *v, int index) {
	for(int i = index; i < v->size - 1; i++) {
		v->items[i] = v->items[i + 1];
	}
	v->items[v->size - 1] = NULL;
	v->size--;
	if (v->size > 0 && v->size == (size_t)((float)v->capacity / V_SCALE_FACTOR / V_SCALE_FACTOR)
		vector_resize(v, v->capacity / V_SCALE_FACTOR);
	//TODO: check if shrink routine works
}
void v_free(vector *v) {
	free(v->items);
}