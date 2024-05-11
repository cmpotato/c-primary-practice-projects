//一个长度为 L（L≥1）的升序序列 S，处在第 [L/2](向上取整) 个位置的数称为 S 的中位数。
//例如，若序列 S1 = （11, 13, 15, 17, 19），则 S1 的中位数是 15，两个序列的中位数是含它们所有元素的升序序列的中位数。
//例如，若 S2 = （2, 4, 6, 8, 20），则 S1 和 S2 的中位数是 11。
//现在有两个 等长 升序序列 A 和 B，试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列 A 和 B 的中位数。
#include"method.h"

int method2011() {
	int arr1[] = { 1,3,5,7,9 };
	int arr2[] = { 2,4,6,8,10 };

	const int arrlength = sizeof(arr1)/sizeof(int);
	int arr[2 * arrlength];
	int i = 0;
	int p1 = 0;
	int p2 = 0;
	for (i = 0; i < 2 * arrlength; i++) 
	{
		if (arr1[p1] <= arr2[p2]) 
		{
			arr[i] = arr1[p1];
			p1++;
		}
		else
		{
			arr[i] = arr2[p2];
			p2++;
		}
	}
	printf("%d", arr[arrlength - 1]);
	return 0;
}