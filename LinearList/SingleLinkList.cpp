#include "ReturnValue.h"
#include "LinearList.h"

// 初始化单链表
void InitSingleLinkList(LNode*& LinkList) {
	while (LinkList->next != nullptr) {	//若原单链表不为空，则销毁原单链表
		LNode* p = LinkList;
		LinkList = LinkList->next;
		delete p;
	}

	LinkList = new LNode;				//初始化单链表

	std::cout << "初始化单链表成功！" << std::endl;
}

// 销毁单链表
void DestroySingleLinkList(LNode*& LinkList) {
	while (LinkList->next != nullptr) {
		LNode* p = LinkList;
		LinkList = LinkList->next;
		delete p;
	}

	std::cout << "销毁单链表成功！" << std::endl;
}

// 清空单链表
void ClearSingleLinkList(LNode*& LinkList) {
	if (LinkList == nullptr) {
		std::cout << "单链表为空" << std::endl;
		return;
	}

	LNode* p = LinkList->next;
	while (p != nullptr) {
		LNode* temp = p;
		p = p->next;
		delete temp;
	}

	LinkList->next = nullptr;

	std::cout << "清空单链表成功！" << std::endl;
}

// 判断单链表是否为空
bool SingleLinkListIsEmpty(const LNode* LinkList) {
	return LinkList->next == nullptr;
}

// 返回单链表中元素的个数
 int SingleLinkListLength(const LNode* LinkList) {
	if (LinkList == nullptr) {
		return 0;
	}

	int length = 0;
	const LNode* p = LinkList->next;

	while (p != nullptr) {
		++length;
		p = p->next;
	}

	return length;
}

// 若cur_e是单链表的元素，且不是第一个元素，则返回其前驱pre_e
 int SingleLinkListPriorElem(const LNode* LinkList, int cur_e) {
	 if (LinkList == nullptr) {
		 std::cout << "单链表未初始化或已销毁" << std::endl;
		 return ERROR;
	 }

	 const LNode* p = LinkList->next;
	 while (p != nullptr && p->next != nullptr) {
		 if (p->next->data == cur_e) {
			 return p->data;
		 }

		 p = p->next;
	 }

	 std::cout << "单链表中无此元素的前驱" << std::endl;
	 return ERROR;
 }


// 若cur_e是单链表的元素，且不是最后一个元素，则返回其后继next_e
 int SingleLinkListNextElem(const LNode* LinkList, int cur_e) {
	 if (LinkList == nullptr) {
		 std::cout << "单链表未初始化或已销毁" << std::endl;
		 return ERROR;
	 }

	 const LNode* p = LinkList->next;
	 while (p != nullptr && p->next != nullptr) {
		 if (p->data == cur_e) {
			 return p->next->data;
		 }
		 
		 p = p->next;
	 }

	 std::cout << "单链表中无此元素的后继" << std::endl;
	 return ERROR;
 }

// 取值：取第i个元素e
int GetSingleLinkListElem(const LNode* LinkList, int i) {
	if (LinkList == nullptr) {
		std::cout << "单链表未初始化或已销毁" << std::endl;
		return ERROR;
	}

	if (i < 1) {
		std::cout << "取值失败，i的值不合法" << std::endl;
		return ERROR;
	}

	const LNode* p = LinkList->next;

	for (int j = 1; j < i && p != nullptr; ++j) {	//i<j且指针p不为空则循环
		p = p->next;
	}

	if (p == nullptr) {
		std::cout << "取值失败，i的值超出单链表范围" << std::endl;
		return ERROR;
	}

	return p->data;
}
// 查找：查找元素e，找到返回元素地址
LNode* LocateSingleLinkListElem(LNode* LinkList, int e) {
	if (LinkList == nullptr) {
		return nullptr;
	}

	LNode* p = LinkList->next;

	while (p != nullptr && p->data != e) {
		p = p->next;
	}
	return p;
}

// 插入：在第i个位置插入数据e
void SingleLinkListInsertElem(LNode* LinkList, int i, int e) {
	if (LinkList == nullptr) {
		std::cout << "插入失败，单链表未初始化或已销毁" << std::endl;
		return;
	}

	if (i < 1 || i > SingleLinkListLength(LinkList) + 1) {	//i值不合法
		std::cout << "插入失败，i值不合法" << std::endl;
		return;
	}

	LNode* p = LinkList;

	for (int j = 1; j < i; ++j) {	//查找第i-1个结点，p指向该节点
		p = p->next;

		if (p == nullptr) {
			std::cout << "插入失败，i值不合法" << std::endl;
			return;
		}
	}

	LNode* s = new LNode;		//创建一个新结点
	s->data = e;				//将s的数据域设为e
	s->next = p->next;			//将结点s的指针域指向第i个结点
	p->next = s;				//将结点p的指针域指向指向s

	std::cout << "插入成功！" << std::endl;
}

// 删除：删除第i个元素
void DeleteSingleLInkListElem(LNode* LinkList, int i) {
	if (LinkList == nullptr) {
		std::cout << "删除失败，单链表未初始化或已销毁" << std::endl;
		return;
	}

	if (i < 1 || i > SingleLinkListLength(LinkList)) {	//i值不合法
		std::cout << "删除失败，i值不合法" << std::endl;
		return;
	}

	LNode* p = LinkList;

	for (int j = 1; j < i; ++j) {	//查找第i-1个结点，p指向该节点
		p = p->next;

		if (p == nullptr) {
			std::cout << "删除失败，没有这个元素" << std::endl;
			return;
		}
	}

	LNode* q = p->next;		//创建新结点q临时保存被删结点以备释放
	p->next = q->next;		//改变删除结点前驱结点的指针域
	delete q;				//释放删除结点的空间

	std::cout << "删除成功！" << std::endl;
}

// 遍历访问输出
void TraverseSingleLInkList(const LNode* LinkList) {
	if (LinkList == nullptr) {
		std::cout << "遍历失败，单链表未初始化或已销毁" << std::endl;
		return;
	}

	const LNode* p = LinkList;
	int length = SingleLinkListLength(LinkList);

	for (int j = 1; j <= length; ++j) {
		p = p->next;
		std::cout << p->data << " ";
	}
	std::cout << "遍历完毕！" << std::endl;
}
