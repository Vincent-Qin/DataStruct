#include "ReturnValue.h"
#include "LinearList.h"

// 初始化单链表
void InitSingleLink(LNode*& Link) {
	while (Link->next != nullptr) {	//若原单链表不为空，则销毁原单链表
		LNode* p = Link;
		Link = Link->next;
		delete p;
	}

	Link = new LNode;				//初始化单链表

	std::cout << "初始化单链表成功！" << std::endl;
}

// 销毁单链表
void DestroySingleLink(LNode*& Link) {
	while (Link->next != nullptr) {
		LNode* p = Link;
		Link = Link->next;
		delete p;
	}

	std::cout << "销毁单链表成功！" << std::endl;
}

// 清空单链表
void ClearSingleLink(LNode*& Link) {
	if (Link == nullptr) {
		std::cout << "单链表为空" << std::endl;
		return;
	}

	LNode* p = Link->next;
	while (p != nullptr) {
		LNode* temp = p;
		p = p->next;
		delete temp;
	}

	Link->next = nullptr;

	std::cout << "清空单链表成功！" << std::endl;
}

// 判断单链表是否为空
bool SingleLinkIsEmpty(const LNode* Link) {
	return Link->next == nullptr;
}

// 返回单链表中元素的个数
 int SingleLinkLength(const LNode* Link) {
	if (Link == nullptr) {
		return 0;
	}

	int length = 0;
	const LNode* p = Link->next;

	while (p != nullptr) {
		++length;
		p = p->next;
	}

	return length;
}

// 若cur_e是单链表的元素，且不是第一个元素，则返回其前驱pre_e
 int SingleLinkPriorElem(const LNode* Link, int cur_e) {
	 if (Link == nullptr) {
		 std::cout << "单链表未初始化或已销毁" << std::endl;
		 return ERROR;
	 }

	 const LNode* p = Link->next;
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
 int SingleLinkNextElem(const LNode* Link, int cur_e) {
	 if (Link == nullptr) {
		 std::cout << "单链表未初始化或已销毁" << std::endl;
		 return ERROR;
	 }

	 const LNode* p = Link->next;
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
int GetSingleLinkElem(const LNode* Link, int i) {
	if (Link == nullptr) {
		std::cout << "单链表未初始化或已销毁" << std::endl;
		return ERROR;
	}

	if (i < 1) {
		std::cout << "取值失败，i的值不合法" << std::endl;
		return ERROR;
	}

	const LNode* p = Link->next;

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
LNode* LocateSingleLinkElem(LNode* Link, int e) {
	if (Link == nullptr) {
		return nullptr;
	}

	LNode* p = Link->next;

	while (p != nullptr && p->data != e) {
		p = p->next;
	}
	return p;
}

// 插入：在第i个位置插入数据e
void SingleLinkInsertElem(LNode*& Link, int i, int e) {
	if (Link == nullptr) {
		std::cout << "插入失败，单链表未初始化或已销毁" << std::endl;
		return;
	}

	if (i < 1 || i > SingleLinkLength(Link) + 1) {	//i值不合法
		std::cout << "插入失败，i值不合法" << std::endl;
		return;
	}

	LNode* p = Link;

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
void DeleteSingleLinkElem(LNode*& Link, int i) {
	if (Link == nullptr) {
		std::cout << "删除失败，单链表未初始化或已销毁" << std::endl;
		return;
	}

	if (i < 1 || i > SingleLinkLength(Link)) {	//i值不合法
		std::cout << "删除失败，i值不合法" << std::endl;
		return;
	}

	LNode* p = Link;

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
void TraverseSingleLink(const LNode* Link) {
	if (Link == nullptr) {
		std::cout << "遍历失败，单链表未初始化或已销毁" << std::endl;
		return;
	}

	const LNode* p = Link;
	int length = SingleLinkLength(Link);

	for (int j = 1; j <= length; ++j) {
		p = p->next;
		std::cout << p->data << " ";
	}
	std::cout << "遍历完毕！" << std::endl;
}

// 前插法创建单链表
void CreatSingleLink_H(LNode*& Link, int len) {
	if (len < 0) {
		std::cout << "len的值不合法，创建失败" << std::endl;
		return;
	}

	Link = new LNode;			//先建立一个带头结点的空链表

	for (int i = 0; i < len; ++i) {
		LNode* p = new LNode;		//生成新结点*p
		std::cin >> p->data;		//输入元素值赋给*p的数据域

		p->next = Link->next;	//将新结点插入到头结点之后
		Link->next = p;
	}

	std::cout << "创建成功！" << std::endl;
}

// 尾插法创建单链表
void CreatSingleLink_R(LNode*& Link, int len) {
	if (len < 0) {
		std::cout << "len的值不合法，创建失败" << std::endl;
		return;
	}

	Link = new LNode;

	LNode* r = Link;

	for (int i = 0; i < len; ++i) {
		LNode* p = new LNode;
		std::cin >> p->data;

		p->next = nullptr;
		r->next = p;
		r = p;
	}

	std::cout << "创建成功！" << std::endl;
}