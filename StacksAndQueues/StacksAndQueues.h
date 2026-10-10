#pragma once

#include "../ReturnValue.h"
#include <iostream>
#include <cstdlib>

/*********** 顺序栈 **********/

// 存储结构
struct SqStack {
	int* base;
	int* top;
	int stacksize;

	SqStack() :base(nullptr), top(nullptr), stacksize(0) {};
};

// 顺序栈的初始化
void InitSqStack(SqStack& SqS);

// 入栈：插入元素e为新的栈顶元素
void PushSqStack(SqStack& SqS, int e);

// 出栈：删除栈顶元素，用e接收
void PopSqStack(SqStack& SqS, int& e);

// 取栈顶元素：返回栈顶元素，不修改栈顶指针
int GetSqStackTop(SqStack SqS);



/*********** 链栈 **********/

// 存储结构
struct LinkStack {
	int data;
	LinkStack* next;

	LinkStack() : data(0), next(nullptr) {};
};

// 链栈的初始化
void InitlinkStack(LinkStack*& StackNode);

// 入栈
void PushLinkStack(LinkStack*& StackNode, int e);

// 出栈
void PopLinkStack(LinkStack*& StackNode, int& e);

// 取栈顶元素
int GetLinkStackTop(LinkStack* StackNode);
