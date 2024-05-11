//设将 n（n > 1）个整数存放到一维数组 R 中。试设计一个在时间和空间两方面都尽可能高效的算法。
//将 R 中保存的序列循环左移 p（0 < p < n）个位置，即将 R 中的数据由（X0, X1…Xn - 1）变换为（Xp, Xp + 1 …Xn - 1, X0, X1…Xp - 1）。
#include"method.h"

int method2010()
{
	
	int testArr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	const int arrlength = sizeof(testArr) / sizeof(int);
	int tmpArr[arrlength];

	int p = 0;
	printf("输入p:\n");
	scanf("%d", &p);
	p = p % arrlength;
	
	int i = 0;
	for (i = 0; i < arrlength; i++)
	{
		tmpArr[(i - p + arrlength)%arrlength] = testArr[i];
	}
	

	for (i = 0; i < arrlength; i++)
	{
		printf("%d ", tmpArr[i]);
	}
	return 0;
}