#include <iostream>
#include <cstdlib>
using namespace std;

// 宏定义（严严对齐数据结构课本）
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define LIST_INIT_SIZE 100   // 初始容量
#define LISTINCREMENT 10     // 扩容增量

typedef int ElemType;
typedef int Status;

struct SqList
{
	ElemType* elem;     // 动态数组指针（没有内存！需要手动开辟）
	int length;         // 当前元素个数
	int listsize;       // 当前总容量
};

//1初始化顺序表
void InitList(Sqlist &L){
	L.elem=new ElemType[LIST_INIT_SIZE];
	if(!L.elem) return ERROR;
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return OK;
} 

//2.清空顺序表
void ClearList(Sqlist &L){
	L.length=0;
	return OK;
} 

//3.判空顺序表
Status ListEmpty(Sqlist L){
	if(L.length==0){
		return TURE;
	}
	else return FALSE;
} 

//4.获取表长list length
Status ListLength(SqList L){
	return L.length;
} 

//5.按位查找getelem
Status GetElem(Sqlist L,int pos,ElemType &e){
	if(pos>L.length||pos<1){
		return ERROR;
	}
	e=L.elem[pos-1];
	return OK;
} 

//6.按值查找locateelem
Status LocateElem(Sqlist L,ElemType e){
	for(int i=0;i<L.length;i++){
		if(L.elem[i+1]==e){
			return OK;
		}
	}
	return 0;
} 

//7.指定位置插入listinsert
Status ListInsert(Sqlist &L,int pos,ElemType e){
	if(pos>L.length||L<1){
		return ERROR;
	}
	if(L.length==MAXSIZE){
		return ERROR;
	}
	for(int i=L.length;i>=pos-1;i--){
		L.elem[i]=L.elem[i-1];
	}
	L.elem[pos-1]=e;
	return OK;
}

//8.指定位置删除listdelete
Status ListDelete(SqList &q,int pos,&ElemType e){
	if(pos>L.length||pos<1){
		return ERROR;
	}
	e=L.elem[pos-1];
	for(int i=pos-1;i<L.length;i++){
		L.elem[i]=L.elem[i+1]
	}
	L.length--;
	return OK;
} 

//9.按值删除元素
Status DeleteElem(Sqlist &L,ElemType e){
	for(int i=0;i<L.length;i++){
		if(L.elem[i]==e){
			for(int j=i;j<L.length-1;j++){
				L.elem[j]=L.elem[j+1];
			}
			L.length--;
			return OK;
		}
	}
	return ERROR;
} 

//10.修改指定位置的元素
Status ListUpdate(Sqlist &L,int pos,ElemType e){
	if(pos>L.length||pos<1){
		return ERROR;
	}
	L.elem[pos-1]=e;
	return OK;
} 

//11.打印遍历顺序表list traverse
void ListTraverse(Sqlist L){
	for(int i=0;i<L.length;i++){
		cout<<L.elem[i]<<" ";
	}
} 

//12.元素前驱
Status GetPriorElem(SqList L,ElemType e,ElemType &pre){
	for(int i=0;i<L.length;i++){
		if(L.elem[i]==e){
			pre=L.elem[i-1];
			return OK;
		}
	}
	return ERROR;
} 

//13.元素后继
Status GetNextElem(SqList L,ElemType e,ElemType &next){
	for(int i=0;i<L.length;i++){
		if(L.elem[i]==e){
			next=L.elem[i+1];
			return OK;
		}
	}
	return ERROR;
} 














































































