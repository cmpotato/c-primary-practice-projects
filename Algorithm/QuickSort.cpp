#include"method.h"

void quickSort(int arr[], int front, int rear) {
	if (front < rear)
	{
		int pivot = partition(arr, front, rear);
		quickSort(arr, front, pivot - 1);
		quickSort(arr, pivot + 1, rear);
	}
	
}

int partition(int arr[], int front, int rear)
{
	//������Ԫ���趨Ϊ�м���
	int pivot = arr[front];
	//��������front->rear���䣬�ƶ�Ԫ��
	while (front < rear)//ѭ����������
	{
		//�Ӻ���ǰ����
		while (front < rear && arr[rear] > pivot)
		{
			//���rear��ָԪ�ش���pivot������ǰ�ƶ�rearָ��
			rear--;
		}
		//��ʱrearָ��һ��С��pivot��Ԫ�أ����临�Ƶ�front��ָ��λ�ã�pivotԭ����λ�ã�
		arr[front] = arr[rear];

		//��ǰ������
		while (front < rear && arr[front] < pivot)
		{
			//���front��ָԪ��С��pivot��������ƶ�frontָ��
			front++;
		}
		arr[rear] = arr[front];
	}
	//���м����ŵ�ָ���غϵ�λ�ã���λ�õ�Ԫ���Ѿ���������һ�Σ�����ʱָ��ǰ��Ԫ��ȫ��С��pivot��ָ������Ԫ��ȫ������pivot
	arr[rear] = pivot;
	return rear;
}