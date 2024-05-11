#include"method.h"

int method2020(int arr1[], int a1, int arr2[], int a2, int arr3[], int a3) {

	int d = 0;
	int D = abs(arr1[1] - arr2[1]) + abs(arr2[1] - arr3[1]) + abs(arr1[1] - arr3[1]);
	int i1 ,i2 ,i3 = 0;

	for (i1 = 0; i1 < a1; i1++) {
		for (i2 = 0; i2 < a2; i2++) {
			for (i3 = 0; i3 < a3; i3++) {
				d = abs(arr1[i1] - arr2[i2]) + abs(arr2[i2] - arr3[i3]) + abs(arr1[i1] - arr3[i3]);
				if (d < D) {
					D = d;
				}
			}
		}
	}
	return D;
}
