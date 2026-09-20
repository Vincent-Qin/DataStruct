#include "ReturnValue.h"

#include <iostream>
#include <cstdlib>

struct SqList{
	int *elem;
	int length;
};

// 初始化顺序表
static int InitSqList(SqList& L) {
	L.elem = new int[MAXSIZE];	//分配一个数组空间

	if (!L.elem) {				//分配空间失败 退出
		std::exit(FLOW);
	}

	L.length = 0;				//空表数据为0

	return SUCCESS;
}

// 销毁顺序表
static void DestroySqList(SqList& L) {
	if (L.elem) {
		delete[] L.elem;
	}

	L.elem = nullptr;			//将指针置空，杜绝指针悬空和二次释放
	L.length = 0;
}

// 清空顺序表
static void ClearSqList(SqList& L) {
	L.length = 0;
}

// 判断顺序表是否为空
static bool SqListIsEmpty(const SqList& L) {
	return L.length == 0;
}

// 返回顺序表中元素的个数
static int SqListLength(const SqList& L) {
	return L.length;
}

// 若cur_e是顺序表的元素，且不是第一个元素，则返回其前驱pre_e
static int PriorElem(const SqList& L, int cur_e, int &pre_e) {
	if (L.length == 0) return ERROR;

	for (int i = 1; i < L.length; ++i) {
		if (L.elem[i] == cur_e) {
			pre_e = L.elem[i - 1];
			return SUCCESS;
		}
	}
	return ERROR;
}

// 若cur_e是顺序表的元素，且不是最后一个元素，则返回其后继next_e
static int NextElem(const SqList& L, int cur_e, int &next_e) {
	if (L.length == 0) return ERROR;

	for (int i = 0; i < L.length - 1; ++i) {
		if (L.elem[i] == cur_e) {
			next_e = L.elem[i + 1];
			return SUCCESS;
		}
	}
	return ERROR;
}

// 取值：取第i个元素e
static int GetElem(const SqList& L, int i, int &e) {
	if (i < 1 || i > L.length) {
		return ERROR;
	}

	e = L.elem[i - 1];
	return SUCCESS;
}

// 查找：在顺序表中查找元素e
static int LocateElem(const SqList& L, int e) {
	for (int i = 0; i < L.length; ++i) {
		if (L.elem[i] == e) {
			return i + 1;
		}
	}
	return ERROR;
}

// 插入：在顺序表的第i个位置插入数据e
static int ListInsert(SqList& L, int i, int &e) {
	if (i < 1 || i >= L.length) {	//i值不合法
		return ERROR;
	}

	if (L.length == MAXSIZE) {		//顺序表已满
		return ERROR;
	}

	for (int j = L.length - 1; j >= i; --j) {
		L.elem[j + 1] = L.elem[j];
	}

	L.elem[i - 1] = e;
	++L.length;

	return SUCCESS;
}

// 删除：删除第i个元素
static int DeleteElem(SqList& L, int i) {
	if (i < 1 || i > L.length) {		//i值不合法
		return ERROR;
	}

	for (int j = i; j < L.length; ++j) {
		L.elem[j - 1] = L.elem[j];
	}

	--L.length;
	return SUCCESS;
}

// 遍历访问
static void TraverseSqList(const SqList& L) {
	if (L.length == 0) {
		std::cout << "The SqList is empty" << std::endl;
	}
	else {
		for (int i = 0; i < L.length; ++i) {
			std::cout << L.elem[i] << " ";
		}
		std::cout << "Traversal and output complete" << std::endl;
	}
}
