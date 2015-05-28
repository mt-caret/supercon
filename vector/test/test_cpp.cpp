#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
	if (argc != 3) exit(-1);
	long load = atol(argv[1]), rep = atol(argv[2]);

	while(rep--) {
		vector<int> v;
		v.reserve(load);
		for (long i = 0; i < load; i++) {
			v.push_back(i);
		}
		for (long i = 0; i < load; i++) {
			v.erase(v.begin(), v.begin()+1);
		}
	}
	
	printf("%s - Done.\n", argv[0]);
	return 0;
}

