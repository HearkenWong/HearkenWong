//删除单链表中最后一个与给定值相等的结点
void ListLocateAndDel_L(LinkList L, ElemType x)
{
	LNode *tgt_p = NULL;
	LNode *prep = L;
	LNode *p = L->next;
	while (p != NULL)
	{
		if (p->data == x)
		{
			tgt_p = prep;
		}
		prep = p;
		p = p->next;
	}
	//没有和x相等的元素
	if (tgt_p == NULL) return ;
	else 
	{
		p = tgt_p->next;
		tgt_p->next = p->next;
		free(p);
	}
}
