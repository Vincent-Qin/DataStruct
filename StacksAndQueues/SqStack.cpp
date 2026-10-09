#include "StacksAndQueues.h"

// 顺序栈的初始化
void InitSqStack(SqStack& SqS) {
	SqS.base = new int[MAXSIZE];	//栈底指针指向数组的基地址
	if (!SqS.base) {
		exit(OVERFLOW);			//分配内存失败，退出
	}

	SqS.top = SqS.base;				//栈顶指针top初始化为base，表示栈为空

	SqS.stacksize = MAXSIZE;

	std::cout << "顺序栈初始化成功！" << std::endl;
}

// 入栈：插入元素e为新的栈顶元素
void PushSqStack(SqStack& SqS, int e) {
	if (SqS.top - SqS.base == SqS.stacksize) {	//栈满，结束函数
		std::cout << "栈已满，入栈失败！" << std::endl;
		return;
	}

	*SqS.top = e;		//先赋值
	++SqS.top;			//后指针上移

	std::cout << "元素" << e << "已入栈" << std::endl;
}

// 出栈：删除栈顶元素，用e接收
void PopSqStack(SqStack& SqS, int& e) {
	if (SqS.top == SqS.base) {					//栈空，结束函数
		std::cout << "栈空，出栈失败！" << std::endl;
		return;
	}

	--SqS.top;			//先指针下移
	e = *SqS.top;		//再赋值

	std::cout << "元素" << e << "已出栈" << std::endl;
}

// 取栈顶元素：返回栈顶元素，不修改栈顶指针
int GetSqStackTop(SqStack SqS) {
	if (SqS.top != SqS.base) {		//栈不为空
		return *(SqS.top - 1);
	}

	std::cout << "栈为空，无法取到栈顶元素" << std::endl;
	return ERROR;
}