#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	int coef;
	int exp;
}elementtype;

typedef struct node{
	elementtype term;
	struct node *next;
} node;
node *poly[5];

node *makenode(int coef,int exp);
node* insert(node *r,int coef,int exp);
void display(node *r);
int compare_exp(node *n1,node *n2);
int compare_coef(node *n1,node *n2);
void sort_gen(node *r,int (*compare)(node*,node*));
void sort_exp(node *r);
void sort_coef(node *r);
node* add(node *r1,node *r2);
node *multiply(node *r1,node *r2);
void reset(node *r);
