#include <iostream>
#include<stdlib.h>
using namespace std;
#define max 100
int a[max][max];
int n;
void taoMT(int a[][max],int &n);
void inMT(int a[][max],int n,int m);
void xoaDong(int a[][max], int n, int m);
void xoaCot(int a[][max], int n, int m);
int kiemTraDX(int a[][max],int n);
void kqktdx(int a[][max], int n);
int main() {
//int	a[3][3] = {1,2,3,4,5,6,7,8,9};
	taoMT(a,n);
	inMT(a,n,n);
	xoaDong(a,n,n);
	xoaCot(a,n,n);
	kqktdx(a,n);
}
void taoMT(int a[][max],int &n){
	int i, j;
	do{
	printf("\nnhap vao so nguyen n -> ma tran n*n : ");
	cin>>n;}
	while(n < 3 || n > 10 );
	for(i = 0; i < n; i++)
	for(j = 0; j < n; j++)
	 a[i][j] = rand()%100;
	 }
void inMT(int a[][max],int n, int m){
	int i,j;
	for(i = 0; i < n; i++){
	for(j = 0; j < m; j++)
	 cout<<a[i][j]<<"\t";
	 cout<<"\n";
	 }
}
void xoaDong(int a[][max], int n, int m){
	int d;
	do{	printf("\n nhap dong i can xoa: ");
		cin>>d;
	}while(d < 0  || d >= n);
	for(int i = d; i < n; i++)
	for(int j = 0; j < m; j++)
	a[i][j] = a[i + 1][j];
	n--;
	inMT(a,n,m);
}
void xoaCot(int a[][max], int n, int m){
	int c;
	do{	printf("\n nhap cot j can xoa: ");
		cin>>c;
	}while(c < 0  || c >= m);
	for(int i = 0; i < n; i++)
	for(int j = c; j < m; j++)
	a[i][j] = a[i][j + 1];
	m--;
	inMT(a,n,m);
}
//kiem tra ma tran co doi xung ko
int kiemTraDX(int a[][max],int n){
	for(int i = 0; i < n - 1; i++)
	for(int j = i + 1; j < n; j++)
	if(a[i][j] != a[j][i]) return 0;
	return 1;
}
void kqktdx(int a[][max], int n){
	if(kiemTraDX(a,n) == 1) cout<<"\nma tran vua nhap doi xung";
	else cout<<"\n ma tran vua nhap ko doi xung";
}
//tim so hoang hau 


