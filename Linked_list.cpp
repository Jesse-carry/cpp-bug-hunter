#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

// 链表结点结构体 带头结点
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

//1.初始化链式线性表（创建头结点）
Status InitList(LinkList &L){
	L=new LNode;
	if(!L){
		return ERROR;
	}
	L->next=nullptr;
	return OK;
}

//2.清空链式线性表，保留头结点
Status ClearList(LinkList &L){
	LNode *p,*q;
	p=L->next;
	while(p!=nullptr){
		q=p->next;
		delete p;
		p=q;
	}
	L->next=nullptr;
	return OK;
}

//3.判断链表是否为空
Status ListEmpty(const LinkList &L){
	if(L->next==nullptr){
		return OK;
	} 
	else{
		return FALSE;
	}
}

//4.获取链表长度
Status ListLength(const LinkList &L){
	LNode *p=L->next;
	int count=0;
	while(p->next!=nullptr){
		count++;
		p=p->next;
	}
	return count;
}

//5.按位查找，第pos个元素存入e，pos从1开始
Status GetElem(const LinkList &L, int pos, ElemType &e){
	if(pos<1){
		return ERROR;
	}
	LNode *p=L->next;
	int count=1;
	while(count<pos&&p){
		p=p->next;
		count++;
	}
	if(!p){
		return ERROR;
	}
	e=p->data;
	return OK;
}

//6.按值查找，返回位序；不存在返回0
int LocateElem(const LinkList &L, ElemType e){
	LNode *p=L->next;
	int count=1;
	while(p!=nullptr){
		if(p->data!=e){
			p=p->next;
			count++;
			retutn count;
		}
	}	
	return 0;
}

//7.在pos位置插入元素e
Status ListInsert(LinkList &L, int pos, ElemType e){
	if(pos<1){
		return ERROR;
	}
	LNode *p=L;
	int count=0;
	while(p&&count<pos-1){
		p=p->next;
		count++;
	}
	if(!p){
		return ERROR;
	}
	LNode s=new LNode;
	s->next=p->next;
	p->next=s;
	return OK;
}

//8.删除pos位置元素，被删元素存入e带回
Status ListDelete(LinkList &L, int pos, ElemType &e){
	if(pos<1){
		return ERROR;
	}
	LNode *p=L;
	int count=0;
	while(p&&count<pos-1){
		p=p->next;
		count++;
	} 
	if(!p){
		return ERROR;
	}
	LNode *q=p->next;
	e=q->data;
	p-next=q->next;
	delete q;
	return OK;
}

//9.按值删除第一个值等于e的结点
Status DeleteElem(LinkList &L, ElemType e){
	LNode *p=L,*q=L->next;
	while(p&&p->data!=e){
		q=p;
		p=p->next;
	}
	if(!p){
		return ERROR;
	}
	p->naet=q->next;
	delete q;
	return OK;
}

//10.修改pos位置元素的值为e
Status ListUpdate(LinkList &L, int pos, ElemType e){
	if(pos<1){
		return ERROR;
	}
	LNode *p=L->next;
	int count=1;
	while(p&&count!=pos){
		p=p->next;
		count++;
	}
	if(!p){
		return ERROR;
	}
	p-data=e;
	return OK;
}

//11.遍历打印链表所有元素
void ListTraverse(const LinkList &L){
	LNode *p=L->next;
	while(p){
		cout<<p->data;
		p=p->next;
	}
	return OK;
}

//12.获取cur_e的前驱元素pre
Status GetPriorElem(const LinkList &L, ElemType cur_e, ElemType &pre){
	LNode *P=L;
	LNode *q=L->next;
	if(q==nullptr) return ERROR;
	while(q&&q->data!=cur_e){
		p=q;
		q=q->next;
	}
	if(!q||p==L){
		return ERROR;
	}
	pre=p;
	return OK;
}

//13.获取cur_e的后继元素next
Status GetNextElem(const LinkList &L, ElemType cur_e, ElemType &next){
	LNode *p=L;
	while(p&&p->data!=cur_e){
		p=p->next;
	}
	if(!p){
		return ERROR;
	}
	if(p->next==nullptr){
		return ERROR;
	}
	next=p->next;
	return OK;
}

#endif







