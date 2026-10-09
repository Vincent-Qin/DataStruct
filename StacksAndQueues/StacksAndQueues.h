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

// 顺序栈的入栈
void PushSqStack(SqStack& SqS, int e);

// 顺序栈的出栈
void PopSqStack(SqStack& SqS, int& e);

// 取栈顶元素
int GetSqStackTop(SqStack SqS);