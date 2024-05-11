#include"method.h"

int method2012() {
	//创建测试用链表
	char loading[] = { 'l','o','a','d','i','n','g' };
	char being[] = { 'b','e','i','n','g' };
	int loadingLength = sizeof(loading) / sizeof(char);
	int beingLength = sizeof(being) / sizeof(char);
	ListNode2012 str1 = (ListNode2012)malloc(sizeof(LNode2012));
	str1->data = '0';
	str1->link = NULL;

	//生成being链表前半段
	ListNode2012 str2 = (ListNode2012)malloc(sizeof(LNode2012));
	LNode2012* e = (LNode2012*)malloc(sizeof(LNode2012));
	e->link = nullptr;
	e->data = 'e';

	LNode2012* b = (LNode2012*)malloc(sizeof(LNode2012));
	b->link = e;
	b->data = 'b';

	str2->link = b;

	//生成loading链表
	for (int i = 0; i < loadingLength; i++)
	{
		LNode2012* newnode = (LNode2012*)malloc(sizeof(LNode2012));
		newnode->link = nullptr;
		newnode->data = loading[loadingLength - 1 - i];
		newnode->link = str1->link;
		str1->link = newnode;

		if (loading[loadingLength - 1 - i] == 'i') {
			e->link = newnode;
		}
	}

	//test
	/*ListNode2012 str11 = str1->link;
	while (str11) {
		printf("%c", str11->data);
		str11 = str11->link;
	}

	printf("\n");

	ListNode2012 str12 = str2->link;
	while (str12)
	{
		printf("%c", str12->data);
		str12 = str12->link;
	}*/

	LNode2012* arr1[10];
	int i = 0;
	while (str1->link)
	{
		arr1[i] = str1->link;
		str1 = str1->link;
		i++;
	}

	while (str2 = str2->link)
	{
		for (int j = 0; j < 11; j++)
		{
			if (str2->link == arr1[j]) {
				printf("%c ", str2->link->data);
				break;
			}
		}
	}

	return 0;
}

