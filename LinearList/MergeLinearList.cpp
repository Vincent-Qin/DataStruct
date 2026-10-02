#include "ReturnValue.h"
#include "LinearList.h"

// 顺序表的合并，合并后LA和LB可以复用，LC是全新的顺序表
void MergeSqList(const SqList& LA, const SqList& LB, SqList& LC) {
	delete LC.elem;								//若LC.elem原来已有空间，先释放
	LC.elem = nullptr;

	LC.length = LA.length + LB.length;
	LC.elem = new int[LC.length];				//为合并后的新表分配一段数组空间

	int* pc = LC.elem;							//pc指向新表的第一个元素
	int* pa = LA.elem;							//pa、pb分别指向两个表的第一个元素
	int* pb = LB.elem;

	int* pa_end = LA.elem + LA.length;			//pa_end、pb_end分别指向两个表最后一个元素的下一个地址
	int* pb_end = LB.elem + LB.length;

	while (pa != pa_end && pb != pb_end) {		//pa、pb均未到达表尾
		if (*pa <= *pb) {
			*pc++ = *pa++;
		}
		else {
			*pc++ = *pb++;
		}
	}

	while (pa != pa_end) {						//pb已到达标尾
		*pc++ = *pa++;
	}

	while (pb != pb_end) {						//pa已到达标尾
		*pc++ = *pb++;
	}
	
	std::cout << "合并成功！" << std::endl;
	return;
}

//顺序链表的合并，合并后LA和LB不可复用，LC接管LA并且LB已释放
void MergeSqLink(LNode*& LA, LNode*& LB, LNode*& LC) {
	if (LA == nullptr || LB == nullptr) {
		std::cout << "合并失败，链表未初始化或已销毁" << std::endl;
		return;
	}

	LNode* pa = LA->next;				//pa和pb分别指向两个表的第一个元素
	LNode* pb = LB->next;

	LC = LA;							//用LA的头结点作为LC的头结点

	LNode* pc = LC;						//pc指向LC的头结点

	while (pa && pb) {					//LA、LB均未到达表尾
		if (pa->data <= pb->data) {		//“摘取”pa所指元素
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {							//“摘取”pb所指元素
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}

	pc->next = pa ? pa : pb;			//将非空表的剩余段插入pc所指的结点后面

	delete LB;							//释放LB的头结点
	LB = nullptr;						//置空防止悬空指针

	LA = nullptr;						//LA已经被LC接管

	std::cout << "合并成功！" << std::endl;
	return;
}