#include "function.h"

// MAKE NODE
node *makenode(int coef,int exp){
	node *p=(node*)malloc(sizeof(node));
	p->term.coef=coef;
	p->term.exp=exp;
	p->next=NULL;
	return p;
}

//	INSERT
node* insert(node *r,int coef,int exp){
	node *p=makenode(coef,exp);
	node *cur;

	if(r==NULL) return p;
	else{
		for(cur=r;cur!=NULL;cur=cur->next)
		if(cur->term.exp==exp) {										
 			cur->term.coef+=coef; 
			return r;
		}
			p->next=r;
			r=p;
			return r;
	}			
}

//	DISPLAY
void display(node *r){
	node *cur;
	if(r==NULL){
		printf("\n");
		return;
	}
	for(cur=r;cur!=NULL;cur=cur->next)
	if(cur->term.coef==0) continue; 
	else printf("%d %d ",cur->term.coef,cur->term.exp);
	printf("\n");
}

int compare_exp(node *n1,node *n2){
	node *t1,*t2;
	t1=n1;
	t2=n2;
	if(t1->term.exp==t2->term.exp) return 0;
	return t1->term.exp>t2->term.exp ? 1 : -1;
}

int compare_coef(node *n1,node *n2){
	node *t1,*t2;
	t1=n1;
	t2=n2;
	if(t1->term.coef==t2->term.coef) return 0;
	return t1->term.coef>t2->term.coef ? 1 : -1;
}

// Generic sort
void sort_gen(node *r,int (*compare)(node*,node*)){
	node *cur1,*cur2;
	int p;
	for(cur1=r;cur1!=NULL;cur1=cur1->next)
	for(cur2=cur1;cur2!=NULL;cur2=cur2->next){
		if(compare(cur1,cur2)==-1){
			p=cur1->term.exp;
			cur1->term.exp=cur2->term.exp;
			cur2->term.exp=p;
			
			p=cur1->term.coef;
			cur1->term.coef=cur2->term.coef;
			cur2->term.coef=p;
		}
	}
}

// Sort_exp
void sort_exp(node *r){
	sort_gen(r,compare_exp);
}

// Sort_coef
void sort_coef(node *r){
	sort_gen(r,compare_coef);
}

//	ADD
node* add(node *r1,node *r2){
	node *cur;
	node *p=NULL;
	for(cur=r1;cur!=NULL;cur=cur->next){
		if(cur!=NULL) p=insert(p,cur->term.coef,cur->term.exp);
	}
		
	for(cur=r2;cur!=NULL;cur=cur->next)
		if(cur!=NULL) p=insert(p,cur->term.coef,cur->term.exp);
	return p;
}

//	MULTIPLY
node *multiply(node *r1,node *r2){
	node *cur1,*cur2;
	node *p=NULL;
	for (cur1=r1;cur1!=NULL;cur1=cur1->next)
	for(cur2=r2;cur2!=NULL;cur2=cur2->next)
	p=insert(p,cur1->term.coef*cur2->term.coef,cur1->term.exp+cur2->term.exp);
	return p;
}

//	FREE
void reset(node *r){
	node *p=r;
	while(r!=NULL){
		r=r->next;
		free(p);
		p=r;
	}
}