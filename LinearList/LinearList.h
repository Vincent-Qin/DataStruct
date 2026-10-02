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
void InitSingleLink(LNode*& Link);

// 销毁单链表
void DestroySingleLink(LNode*& Link);

// 清空单链表
void ClearSingleLink(LNode*& Link);

// 判断单链表是否为空
bool SingleLinkIsEmpty(const LNode* Link);

// 返回单链表中元素的个数
int SingleLinkLength(const LNode* Link);

// 若cur_e是单链表的元素，且不是第一个元素，则返回其前驱pre_e
int SingleLinkPriorElem(const LNode* Link, int cur_e);

// 若cur_e是单链表的元素，且不是最后一个元素，则返回其后继next_e
int SingleLinkNextElem(const LNode* Link, int cur_e);

// 取值：取第i个元素e
int GetSingleLinkElem(const LNode* Link, int i);

// 查找：查找元素e
LNode* LocateSingleLinkElem(LNode* Link, int e);

// 插入：在第i个位置插入数据e
void SingleLinkInsertElem(LNode*& Link, int i, int e);

// 删除：删除第i个元素
void DeleteSingleLinkElem(LNode*& Link, int i);

// 遍历访问
void TraverseSingleLink(const LNode* Link);

// 前插法创建单链表
void CreatSingleLink_H(LNode*& Link, int len);

// 尾插法创建单链表
void CreatSingleLink_R(LNode*& Link, int len);



/*********** 循环链表 **********/
/* = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
 * 循环链表的基本操作和单链表基本上相同，
 * 唯一不同的是，由于循环链表的最后一个结点的next不再是空指针，而是指向头结点，
 * 因此，循环中的结束条件要发生变化
 * 单链表--------------循环链表
 * while (p)--------->while (p != L)
 * while (p->next)--->while (p->next != L)
 *= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = */

// 存储结构
struct CLNode {
	int data;
	LNode* next;

	CLNode() :data(0), next(nullptr) {}
};



/*********** 双向链表 **********/
/* = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
 * 在双向链表中，有些操作（如ListLength、GetElem、LocateElem等）
 * 仅需涉及一个方向上的指针，它们的算法描述与单链表的操作相同；
 * 但在插入、删除时有很大的不同，这里只实现插入和删除操作
 * 在双向链表中需要修改两个方向上的指针
 * = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = */

// 存储结构(Double Link)
struct DouLNode {
	int data;			//数据域
	DouLNode* prior;	//指向直接前驱
	DouLNode* next;		//指向直接后继

	DouLNode() :data(0), prior(nullptr), next(nullptr) {};
};

// 查找第i个元素，返回其地址
DouLNode* LocateDoubleLinkElem(DouLNode* DouLink, int i);

// 双向链表的插入
void DoubleLinkInsertElem(DouLNode* DouLink, int i, int e);

// 双向链表的删除
void DeleteDoubleLinkElem(DouLNode* DouLink, int i);