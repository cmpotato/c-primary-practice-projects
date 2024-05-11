#include"method.h"



int method2009(ListNode2009 list, int k) {
	LNode2009* p = list->link;
	LNode2009* q = list->link;

	int i = 0;
	for (i = 0; i < k-1; i++) {
		if (p->link == NULL) {
			return 0;
		}
		p = p->link;
	}

	for (i = k - 1; ; i++) {
		if (p->link == NULL) {
			printf("data的值为%d\n", q->data);
			return 1;
		}
		p = p->link;
		q = q->link;
	}

	return 1;
}



//建立测试链表
ListNode2009 setlist2009(int length) {

	LNode2009* head = (LNode2009*)malloc(sizeof(LNode2009));
	head->data = -1;
	head->link = nullptr;
	int i = 0;
	for (i = 0; i < length; i++)
	{
		LNode2009* newnode = (LNode2009*)malloc(sizeof(LNode2009));
		if (!newnode) {
			perror("malloc");
			return NULL;
		}
		else{
			newnode->data = i;
			newnode->link = head->link;
			head->link = newnode;
		}
		
	}
	
	return head;
}