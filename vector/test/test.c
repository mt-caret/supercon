#include "../vector.c"
/*This include is used only for testing purposes!!!*/

int main(void) {
	vector *v = v_create(sizeof(long));
	int i;
	for (i = 0; i < 50; i++)
		v_push_back(v, &i);
	for (i = 0; i < 50; i++)
		printf("%d ", *((int *) v_get(v, i)));
	v_free(v);

	vector *v2 = v_create(sizeof(char));
	char *str = "Hello, World!";
	for (i = 0; i < strlen(str); i++)
		v_push_back(v2, str + i);
	for (i = 0; i < v2->size; i++)
		printf("%c ", *((char *) v_get(v2, i)));
  v_free(v2);

	vector *v3 = iv_create();
	iv_push_back(v3, 0);
	iv_push_back(v3, 1);
	iv_push_back(v3, 2);
	for (i = 3; i < 10; i++)
		iv_push_back(v3, i);
	for (i = 0; i < 10; i++)
		printf("%d ", iv_get(v, i));
	v_free(v3);

	printf("\nCompleted!\n");
	return 0;
}

