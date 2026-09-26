#pragma once

#include <iostream>
#include <cstdlib>

/*********** 顺序表 **********/

// 存储结构
struct SqList {
	int* elem;
	int length;

	SqList() :elem(nullptr), length(0) {}
};

// 初始化顺序表
void InitSqList(SqList& L);

// 销毁顺序表
void DestroySqList(SqList& L);

// 清空顺序表
void ClearSqList(SqList& L);

// 判断顺序表是否为空
bool SqListIsEmpty(const SqList& L);

// 返回顺序表中元素的个数
int SqListLength(const SqList& L);

// 若cur_e是顺序表的元素，且不是第一个元素，则返回其前驱pre_e
int SqListPriorElem(const SqList& L, int cur_e);

// 若cur_e是顺序表的元素，且不是最后一个元素，则返回其后继next_e
int SqListNextElem(const SqList& L, int cur_e);

// 取值：取第i个元素e
int GetSqListElem(const SqList& L, int i);

// 查找：在顺序表中查找元素e
int LocateSqListElem(const SqList& L, int e);

// 插入：在顺序表的第i个位置插入数据e
void SqListInsertElem(SqList& L, int i, int e);

// 删除：删除第i个元素
void DeleteSqListElem(SqList& L, int i);

// 遍历访问
void TraverseSqList(const SqList& L);



/*********** 单链表 **********/

// 存储结构
struct LNode {
	int data;
	LNode* next;

	LNode() :data(0), next(nullptr) {}
};

// 初始化单链表
void InitSingleLinkList(LNode*& LinkList);

// 销毁单链表
void DestroySingleLinkList(LNode*& LinkList);

// 清空单链表
void ClearSingleLinkList(LNode*& LinkList);

// 判断单链表是否为空
bool SingleLinkListIsEmpty(const LNode* LinkList);

// 返回单链表中元素的个数
int SingleLinkListLength(const LNode* LinkList);

// 若cur_e是单链表的元素，且不是第一个元素，则返回其前驱pre_e
int SingleLinkListPriorElem(const LNode* LinkList, int cur_e);

// 若cur_e是单链表的元素，且不是最后一个元素，则返回其后继next_e
int SingleLinkListNextElem(const LNode* LinkList, int cur_e);

// 取值：取第i个元素e
int GetSingleLinkListElem(const LNode* LinkList, int i);

// 查找：查找元素e
LNode* LocateSingleLinkListElem(LNode* LinkList, int e);

// 插入：在第i个位置插入数据e
void SingleLinkListInsertElem(LNode* LinkList, int i, int e);

// 删除：删除第i个元素
void DeleteSingleLInkListElem(LNode* LinkList, int i);

// 遍历访问
void TraverseSingleLInkList(const LNode* LinkList);
