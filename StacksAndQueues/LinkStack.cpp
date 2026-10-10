#include "StacksAndQueues.h"

// 链栈的初始化
void InitlinkStack(LinkStack*& StackNode) {
	StackNode = nullptr;
}

// 入栈：在栈顶插入元素e
void PushLinkStack(LinkStack*& StackNode, int e) {
	LinkStack* p = new LinkStack;	//生成新结点
	p->data = e;					//将新结点的指针域置为e

	p->next = StackNode;			//将新结点插入栈顶
	StackNode = p;					//将新插入的结点置为栈顶指针

	std::cout << "元素" << e << "已入栈！" << std::endl;
}

// 出栈：删除栈顶元素，用e接收
void PopLinkStack(LinkStack*& StackNode, int& e) {
	if (StackNode == nullptr) {
		std::cout << "栈为空，出栈失败！" << std::endl;
		return;
	}

	e = StackNode->data;			//将栈顶元素赋给e

	LinkStack* temp = StackNode;	//临时指针保存栈顶地址以备释放

	StackNode = StackNode->next;	//栈顶指针向下移

	delete temp;					//释放原栈顶指针的空间
	temp = nullptr;

	std::cout << "元素" << e << "已出栈！" << std::endl;
}

// 取栈顶元素：返回栈顶元素，不修改栈顶指针
int GetLinkStackTop(LinkStack* StackNode) {
	if (StackNode == nullptr) {
		std::cout << "栈为空，取栈顶元素失败！" << std::endl;
		return ERROR;
	}

	return StackNode->data;
}
