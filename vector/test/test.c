#include "../vector.c"
/*This include is used only for testing purposes!!!*/

int main(void) {
	vector v;
	v_init(&v, sizeof(long));
	int i;
	for (i = 0; i < 50; i++)
		v_push_back(&v, &i);
	for (i = 0; i < 50; i++)
		printf("%d\n", *((int *) v_get(&v, i)));
	v_free(&v);

	vector *v2;
	v_init(v2, sizeof(char));
	char *str = "Hello, World!";
	for (i = 0; i < strlen(str); i++)
		v_push_back(v2, str + i);
	for (i = 0; i < v2->size; i++)
		printf("%c", *((char *) v_get(v2, i)));
  	v_free(v2);
	printf("\nCompleted!\n");
	return 0;
}
