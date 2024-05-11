#include"method.h"

int method2013() {
	int a1[] = { 0,5,5,3,5,7,5,5, };
	int a2[] = { 0,5,5,3,5,1,5,7 };

	int arrlength = sizeof(a1) / sizeof(int);
	int x = 0;
	int m = 0;

	for (x = 0; x < arrlength; x++) {
		int j = 0;
		m = 0;
		for (j = 0; j < arrlength; j++) {
			if (a2[j] == x) {
				m++;
			}
		}
		if (m > (arrlength / 2)) {
			printf("%d", m);
			return m;
		}
	}
	printf("-1");
	return -1;
}