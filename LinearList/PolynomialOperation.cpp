#include "LinearList.h"

// 创建多项式
void CreatePolynomial(PLNode*& Poly, int n) {
	while (Poly != nullptr) {				//如果原来已经有多项式，先销毁
		PLNode* p = Poly;
		Poly = Poly->next;
		delete p;
	}
	
	Poly = new PLNode;						//创建一个空链表

	for (int i = 0; i < n; ++i) {
		PLNode* s = new PLNode;

		std::cout << "请依次输入第" << i + 1 << "个单项式的系数和指数(用空格隔开)" << std::endl;
		std::cin >> s->coef >> s->expn;
		
		PLNode* pre = Poly;
		PLNode* q = Poly->next;

		while (q && q->expn < s->expn) {	//遍历寻找第一个比输入项指数大的项
			pre = q;
			q = q->next;
		}

		if (q && q->expn == s->expn) {		//找到与输入项指数相同的项
			q->coef += s->coef;				//系数相加

			if (q->coef == 0) {				//若相加后系数为零
				pre->next = q->next;		//删除结点q
				delete q;
			}

			delete s;						//删除结点s
		}
		else {								//找到第一个比输入项指数大的项
			s->next = q;					//插入到此结点(项)之前
			pre->next = s;
		}
	}

	return;
}

// 多项式相加
void AddPolynomial(PLNode*& Poly_a, PLNode*& Poly_b) {
	PLNode* p1 = Poly_a->next;
	PLNode* p2 = Poly_b->next;

	PLNode* p3 = Poly_a;

	PLNode* r = nullptr;
	while (p1 != nullptr && p2 != nullptr) {	//当p1和p2均未到达相应表尾时
		if (p1->expn == p2->expn) {				//情况一：p1所指指数等于p2所指指数
			p1->coef += p2->coef;				//系数相加

			if (p1->coef != 0) {				//相加后系数不为零
				p3->next = p1;					//将修改后的pa当前结点链在p3之后
				p3 = p1;						//p3指向p1
				p1 = p1->next;					//p1指针后移
				r = p2;							//临时指针r保存pb当前节点
				p2 = p2->next;					//p2指针后移
				delete r;						//删除pb当前节点
				r = nullptr;					//置空防止悬空指针
			}
			else {								//系数和为零
				r = p1;							//临时指针r保存pa当前节点
				p1 = p1->next;					//p1指针后移
				delete r;						//删除pa当前结点
				r = nullptr;					//置空防止悬空指针

				r = p2;							//临时指针r保存pb当前节点
				p2 = p2->next;					//p1指针后移
				delete r;						//删除pb当前结点
				r = nullptr;					//置空防止悬空指针
			}
		}
		else if (p1->expn < p2->expn) {			//情况二：p1所指指数小于p2所指指数
			p3->next = p1;						//“摘取”p1所指结点插入到p3
			p3 = p1;
			p1 = p1->next;
		}
		else {									//情况三：p1所指指数大于p2所指指数
			p3->next = p2;						//“摘取”p2所指结点插入到p3
			p3 = p2;
			p2 = p2->next;
		}
	}

	p3->next = p1 ? p1 : p2;					//插入非空多项式的剩余段
	delete Poly_b;								//释放Poly_b的头结点
	Poly_b = nullptr;
	return;
}