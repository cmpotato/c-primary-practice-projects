//�轫 n��n > 1����������ŵ�һά���� R �С������һ����ʱ��Ϳռ������涼�����ܸ�Ч���㷨��
//�� R �б��������ѭ������ p��0 < p < n����λ�ã����� R �е������ɣ�X0, X1��Xn - 1���任Ϊ��Xp, Xp + 1 ��Xn - 1, X0, X1��Xp - 1����
#include"method.h"

int method2010()
{
	
	int testArr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	const int arrlength = sizeof(testArr) / sizeof(int);
	int tmpArr[arrlength];

	int p = 0;
	printf("����p:\n");
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