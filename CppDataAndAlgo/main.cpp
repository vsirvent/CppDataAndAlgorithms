#include "UF.h"

void print_connected(UF1& uf, int p, int q) {
	printf("%d-%d => %s\n", p, q, uf.connected(p, q)?"CONNECTED":"NOT CONNECTED");
}

int main(void) {
	UF1 uf(10);
	uf.connect(0,1);
	uf.connect(0,2);
	uf.connect(2,3);
	uf.connect(8,9);
	print_connected(uf, 0, 3);
	print_connected(uf, 0, 9);

	for (int i = 0; i < 9; ++i) {
		print_connected(uf, i, i+1);
	}
	printf("components %d\n", uf.count());
	return 0;
}
