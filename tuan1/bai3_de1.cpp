#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
struct nut{
	int info;
	nut *left, *right;
};
typedef nut Node;
Node *root, *root1;
void khoiTao(Node *&root);
void mocNut(Node *&root, int x);
void taoCay(Node *&root);
void duyetLNR(Node *root);
int max(int a, int b);
int chieuCao(Node *root);
void inMuci(Node *root, int i, int muc);
void saoChep(Node *root, Node *&root1);
void xoaNut(Node *&root, int x);

int main(){
	khoiTao(root);
	taoCay(root);
	duyetLNR(root);
	printf("\n Chieu cao cua cay: %d \n ",chieuCao(root));
	inMuci(root,3,1);
	khoiTao(root1);
	saoChep(root,root1);
	xoaNut(root,5);
}
void khoiTao(Node *&root){
	root = NULL;
}
void mocNut(Node *&root, int x){
	if(root == NULL ){
		root = new Node;
		root->info = x;
		root->left = NULL;
		root->right = NULL;}
	else{ if(root->info >= x) 
		mocNut(root->left,x);
		else mocNut(root->right,x);
		} 
	}
void taoCay(Node *&root){
	int tam;
	do{
		printf("\nnhap vao so nguyen, nhap 0: dung: ");
		scanf("%d",&tam);
		if(tam != 0)
			mocNut(root,tam);
	}
	while (tam != 0);
}
void duyetLNR(Node *root){
	if(root!= NULL){
		duyetLNR(root->left);
		printf("%3d",root->info);
		duyetLNR(root->right);
	}
}
int max(int a, int b){
	if( a >= b ) 
	return a;
	return b;
}
int chieuCao(Node *root){
	if(root == NULL) return 0;
	else return 1 + max(chieuCao(root->left),chieuCao(root->right));
}
void inMuci(Node *root, int i, int muc = 1){
	if(root != NULL){
		if(muc == i) 
		printf("%3d",root->info);
	else {
		inMuci(root->left,i,muc + 1);
		inMuci(root->right,i,muc + 1);
	}
	}
}
void saoChep(Node *root, Node *&root1){
	if(root == NULL) 
	 root1 = NULL;
	else{
	root1 = new Node;
	root1->info = root->info;
	saoChep(root->left,root1->left);
	saoChep(root->right,root1->right);
	}
}
//doi vs node co 2 cay con tien hanh xoa nut phai nhat cua cay con trai
void xoaNut(Node *&root, int x){
	if(root != NULL){
		if(root->info > x) 
		xoaNut(root->left,x);
		if(root->info < x)
		xoaNut(root->right,x);
		if(root->info == x){
			Node *p = root;
			if(root->left == NULL) root = root->right;
			if(root->right==NULL) root = root->left;
			else{
			Node *s = root, *q = s->left;
		// s la cha cua q, q se la node phai nhat cua cay con trai p
			while (q->right != NULL){
				s = q;
				q= q->right;
			}
			p->info = q->info;
			s->right = q->left;
			delete q;
			}
			}
		}
	}



