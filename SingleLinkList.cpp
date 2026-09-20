#include "LinearList/ReturnValue.h"

#include <iostream>
#include <cstdlib>

struct LNode {
	int data;
	LNode* next;
};

// 初始化单链表
static int InitSingleLinkList(LNode*& LinkList) {
	LinkList = new LNode;

	LinkList->data = 0;
	LinkList->next = nullptr;

	return SUCCESS;
}

// 销毁单链表


// 清空单链表


// 返回单链表中元素的个数


// 若cur_e是单链表的元素，且不是第一个元素，则返回其前驱pre_e


// 若cur_e是单链表的元素，且不是最后一个元素，则返回其后继next_e


// 取值：取第i个元素e


// 查找：查找元素e


// 插入：在第i个位置插入数据e


// 删除：删除第i个元素


// 遍历访问
