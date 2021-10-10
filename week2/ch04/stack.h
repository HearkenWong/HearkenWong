//:stack.h
// 此处底层使用的是固定大小的数组，并且索引 0 处存储辅助指标，用于辅助压入、弹出操作 
#ifndef STACK_H
#define STACK_H 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 

// 操作：向栈数组输入指定数量的数据 
void input();

// 操作：压入
void push();

// 操作：测试栈是否为满
bool stackFull(); 

// 操作：将栈数组的全部元素输出
void output(); 

// 操作：弹出
int pop(); 

// 操作：测试栈是否为空 
bool stackEmpty();

#endif
