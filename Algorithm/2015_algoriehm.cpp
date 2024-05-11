#include"method.h"

int method2015(ListNode2015 head, int n) {
	//创建标记数组
	n++;
	int* arr = (int*)malloc(sizeof(int) * n);
	memset(arr, 0, sizeof(int) * n);

	ListNode2015 HEAD = head;
	while (HEAD->link) {
		int data = abs(HEAD->link->data);
		//绝对值第一次出现
		if (arr[data] == 0) {
			arr[data] = 1;
		}
		//绝对值已经出现过
		else if(arr[data] == 1)
		{
			//删除head所指的节点
			HEAD->link = HEAD->link->link;
			continue;
		}

		HEAD = HEAD->link;
	}

	//打印处理后的数组
	while (head) 
	{
		printf("%d ", head->link->data);
		head = head->link;
	}
	return 0;
}

ListNode2015 setlist2015() {
	printf("初始化数组:");
	int arr[] = { 21,-15,15,-7,15 };
	int arrlength = sizeof(arr) / sizeof(int);
	ListNode2015 head = (LNode2015*)malloc(sizeof(LNode2015));
	head->link = NULL;
	head->data = 0;


	for (int i = 0; i < arrlength; i++)
	{
		LNode2015* newnode = (LNode2015*)malloc(sizeof(LNode2015));
		newnode->data = 0;
		newnode->link = NULL;

		newnode->data = arr[arrlength - 1 - i];
		newnode->link = head->link;
		head->link = newnode;
	}

	LNode2015* printp = head;
	while (printp = printp->link)
	{
		printf("%d ", printp->data);
	}
	printf("\n");
	return head;
}