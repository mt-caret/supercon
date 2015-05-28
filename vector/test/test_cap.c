#include "../vector.c"
/*This include is used only for testing purposes!!!*/

int main(int argc, char **argv) {
	if (argc != 3) exit(-1);
	long load = atol(argv[1]), rep = atol(argv[2]);

	vector *v = v_create_with_capacity(sizeof(int), load);
	while(rep--) {
		long i;
		for (i = 0; i < load; i++)
			iv_push_back(v, i);
		for (i = load - 1; i >= 0; i--)
			v_delete(v, i);
	}
	v_free(v);

	printf("%s - Done.\n", argv[0]);
	return 0;
}
