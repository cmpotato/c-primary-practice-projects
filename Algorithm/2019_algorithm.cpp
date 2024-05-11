#include"method.h"

int method2019(ListNode2019 head) {

	LNode2019* p, * q, * r, * s;
	p = q = head;
	while (q->next)
	{
		p = p->next;
		q = q->next;
		if (q->next) {
			q = q->next;
		}
	}
	q = p->next;
	p->next = NULL;

	while (q)
	{
		r = q->next;
		q->next = p->next;
		p->next = q;
		q = r;
	}

	s = head->next;
	q = p->next;
	p->next = nullptr;
	while (q)
	{
		r = q->next;
		q->next = s->next;
		s->next = q;
		s = q->next;
		q = r;
	}

	
	return 0;
}


