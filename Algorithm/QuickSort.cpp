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
	//将最左元素设定为中间数
	int pivot = arr[front];
	//遍历数组front->rear区间，移动元素
	while (front < rear)//循环跳出条件
	{
		//从后向前遍历
		while (front < rear && arr[rear] > pivot)
		{
			//如果rear所指元素大于pivot，则向前移动rear指针
			rear--;
		}
		//此时rear指向一个小于pivot的元素，则将其复制到front所指的位置（pivot原来的位置）
		arr[front] = arr[rear];

		//从前向后遍历
		while (front < rear && arr[front] < pivot)
		{
			//如果front所指元素小于pivot，则向后移动front指针
			front++;
		}
		arr[rear] = arr[front];
	}
	//将中间数放到指针重合的位置（此位置的元素已经被复制了一次），此时指针前的元素全部小于pivot，指针后面的元素全部大于pivot
	arr[rear] = pivot;
	return rear;
}