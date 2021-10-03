//单链表元素定位
int ListLocate_L(LinkList L, ElemType x)
{
	LNode *p = L->next;
	int i = 1;
	while (p != NULL)
	{
		if (p->data == x)
			break;
		i++;
		p = p->next;
	}
	if (p == NULL) return 0;
	else return i;
}
