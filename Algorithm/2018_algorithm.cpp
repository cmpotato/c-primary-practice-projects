#include"method.h"

int method2018(int arr [], int n) {
	
	int i = 0;
	int* b = (int*)malloc(sizeof(int) * n);
	if (b) {
		memset(b, 0, sizeof(int) * n);
	}
	

	for (i = 0; i < n; i++) {
		if (arr[i] > 0 && arr[i] <= n) {
			b[arr[i] - 1] = 1;
			continue;
		}
	}

	for (i = 0; i < n; i++) {
		if (b[i] == 0) {
			break;
		}
	}
	return i + 1;
}