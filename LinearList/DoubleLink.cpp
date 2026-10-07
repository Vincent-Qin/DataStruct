#include "LinearList.h"

// 查找第i个元素，返回其地址
DouLNode* LocateDoubleLinkElem(DouLNode* DouLink, int i) {
	if (DouLink == nullptr) {
		std::cout << "双向链表未初始化或已销毁" << std::endl;
		return nullptr;
	}

	if (i < 1) {
		std::cout << "i的值不合法" << std::endl;
		return nullptr;
	}

	DouLNode* p = DouLink->next;

	for (int j = 1; j < i && p != nullptr; ++j) {
		p = p->next;
	}

	if (p == nullptr) {
		std::cout << "i的大小超出双向链表的范围" << std::endl;
		return nullptr;
	}

	return p;
}

// 插入：在第i个位置插入数据e
void DoubleLinkInsertElem(DouLNode* DouLink, int i, int e) {
	DouLNode* p = LocateDoubleLinkElem(DouLink, i);

	if (p == nullptr) {
		std::cout << "插入失败！" << std::endl;
		return;
	}
	
	DouLNode* s = new DouLNode;
	s->data = e;

	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;

	std::cout << "插入成功！" << std::endl;
	return;
}

// 删除: 删除第i个元素
void DeleteDoubleLinkElem(DouLNode* DouLink, int i) {
	DouLNode* p = LocateDoubleLinkElem(DouLink, i);

	if (p == nullptr) {
		std::cout << "删除失败！" << std::endl;
		return;
	}

	p->prior->next = p->next;

	if (p->next != nullptr) {
		p->next->prior = p->prior;
	}
	
	delete p;
	return;
}