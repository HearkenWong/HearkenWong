#include"head.h"
int main(void) {
	HashTable table;
	int i;
	List L;
	Position pos;
	table =  InitializeTable(17);
	
    Insert( "10", table );
    Insert( "20", table );
    Insert( "30", table );
    Insert( "40", table );
    Insert( "50", table );
    Insert( "60", table );
    Insert( "70", table );
    Insert( "80", table );
    Insert( "90", table );
    Insert( "91", table );
    Insert( "92", table );
    Insert( "93", table );
    Insert( "97", table );
    Insert( "95", table );
    Insert( "96", table );
    Insert( "99", table );
    //  打印数据，也可以独立写成函数
    for(i=0;i<table->TableSize;i++)
    {
    	printf("----hash %d ----\n",i);
    	L = table->TheLists[i];
    	pos = L->next;
    	while(pos != NULL)
    	{
    		printf("--%s--\n",pos->data);
    		pos = pos->next;
    	}
    }
    puts("\n\n\n\n");
    Delete("60",table);
    Delete("70",table);
 
    for(i=0;i<table->TableSize;i++)
    {
    	printf("----hash %d ----\n",i);
    	L = table->TheLists[i];
    	if(L==NULL)
    		break;
    	pos = L->next;
    	while(pos != NULL)
    	{
    		printf("--%s--\n",pos->data);
    		pos = pos->next;
    	}
    }
    DestroyTable(table);
	return EXIT_SUCCESS;
}
