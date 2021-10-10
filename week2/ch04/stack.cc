//: stack.c--栈
#include <stack.h>

// 操作：向栈数组输入指定数量的数据 
void input(int stack[], int neededNum, const int maxStack) { 
	int i, element;

	puts("输入：");
	for (i = 0; i < neededNum; i++) {
		printf("请输入第 %d 个元素：", i + 1);
		scanf("%d", &element);
		push(stack, element, maxStack);
	}
}

// 操作：压入元素 
void push(int stack[], int element, const int maxStack) {
	if (stackFull(stack)) {
		printf("栈已满");
		exit(false);
	}
	else 
		stack[++stack[0]] = element; // 压入元素时，提前将辅助指标加 1 以指向下一个空白位置 
}

// 操作；测试栈是否为满
bool stackFull(int stack[], const int maxStack) {
	if (maxStack == stack[0])
		return true;
	else
		return false;
} 

// 操作：将栈数组的全部元素输出
void output(int stack[]) {
	int i = 0;
	
	puts("\n输出：");
	while (1) // 不需要终点指标，因为 pop() 在没有元素时程序会直接退出 
		printf("第 %d 个元素：%d\n", ++i, pop(stack));
}

// 操作：弹出元素 
int pop(int stack[]) {
	if (stackEmpty(stack)) {
		printf("栈已经没有元素");
		exit(false);
	}
	else 
		return stack[stack[0]--]; // 弹出元素后，将辅助指标减 1 
}

// 操作：测试栈是否为空 
bool stackEmpty(int stack[]) {
	if (0 == stack[0]) 
		return true;
	else
		return false;
}
