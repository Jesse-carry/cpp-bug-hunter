#include <iostream>
#include (string)
int compare(ElemType a,ElemType b){
	if(strcmp(a,b)==0){
		reutn 1;
	else return0
	}
}
Status LoacteElem(List* L,ElemType e, int(compare(ElemType,ElemType))){
	Lnode *p=L->next;
	int i=1;
	while(p!=NULL){
		if(compare(e,p->data))
			return i;
		}
		else {
			p=p->next;
			i++;
		}
	}
	return 0;
}


void visit(ElemType e){
	printf("%d ",e)
}
Status ListTraverse(List L,void(*visit(ElemType e))){
	Lnode *p=L->next;
	while(p!=NULL){
		visit(p->data);
		p=p->next;
	}
	return OK;
}


Status ListEmpty(List L){
	Lnode *p=L->next;
	if(*p=NULL){
		return 1;
	}
	else return 0;
} 


Status ClearList(List L){
	Lnode *p,*q;
	p=L->next;
	while(p!=NULL){
		q=p;
		p=p->next;
		free(q);
	}
	L->next=NULL;
	return OK;
}


Status PutList(List* L,ElemType e,int pos){
	Lnode *p=L->next;
	int i=1;
	while(p!=NULL && i<pos){
		p=p->next;
		i++;
	}
	if(p!=NULL&&i>pos){
		return ERROR;
	}
	p->data=e;
	return OK;
}


Status ListInsret(List *L,ElemType e,int pos){
	Lnode *p=L;
	int i=0;
	while(p!=NULL&&i<pos-1){
		p=p->next;
		i++;
	}
	if(p==NULL&&i>pos){
		return ERROR;
	}
	Lnode *s=(Lnode *)malloc(sizeof(Lnode));
	if(!s){
		return ERROR;
	}
	s->data=e;
	s->next=p->next;
	p->next=s;
}


Status ListDelete(List *L,ElemType *e,int pos){
	Lnode *p=L,*q;
	int i=0;
	while(p!=NULL&&i<pos-1){
		p=p->next;
		i++;
	}
	if(p==NIll&&p->next==NULL){
		return ERROR;
	}
	q=p->next;
	*e=q->data;
	p->next=q->next;
	free(q);
	return OK;
}




 
