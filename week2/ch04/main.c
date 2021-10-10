#include <stdio.h>
#define MAX_STACK 1000 

int main(void) {
	int neededNum;
	int stack[MAX_STACK + 1]; // 索引 0 处用来存储辅助指标 
	
	stack[0] = 0; // 索引 0 处存储的是辅助指标，初始值为 0，表示没有元素 
	printf("想要多少个元素：");
	scanf("%d", &neededNum);
	input(stack, num);
	output(stack);
		
	return 0;
}
