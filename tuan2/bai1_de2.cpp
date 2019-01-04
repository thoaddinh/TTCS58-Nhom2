#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define max 100

int a[max][max];
int n;
char pathout[100];
FILE *f;
void nhaptenfileout(){
 	printf("\nnhap ten file out: ");
 	gets(pathout);
 }
void taoMT(int a[][max],int &n);
void inMT(int a[][max],int n,int m);
void xoaDong(int a[][max], int n, int m);
void xoaCot(int a[][max], int n, int m);
int kiemTraDX(int a[][max],int n);
void kqktdx(int a[][max], int n);
int checkQueen(int a[][max], int dong, int cot, int vtd, int vtc);
void Queen(char pathout[100],int a[][max], int n);
int main() {
//int	a[3][3] = {1,2,3,4,5,6,7,8,9};
	nhaptenfileout();
 	f = fopen(pathout,"w");
	taoMT(a,n);
	inMT(a,n,n);
	xoaDong(a,n,n);
	xoaCot(a,n,n);
	kqktdx(a,n);
	Queen(pathout,a,n);
}

void taoMT(int a[][max],int &n){
	int i, j;
	do{
	printf("\nnhap vao so nguyen n -> ma tran n*n : ");
	cin>>n;}
	while(n < 3 || n > 10 );
	for(i = 0; i < n; i++)
	for(j = 0; j < n; j++){
	a[i][j] = rand()%100;}
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

int checkQueen(int a[][max], int dong, int cot, int vtd, int vtc)
{
	int x = a[vtd][vtc];
	//Kiem tra max dong
	for (int i = 0; i < cot; i++)
		if (a[vtd][i] > x)
			return 0;
	//Kiem tra max cot
	for (int j = 0; j < dong; j++)
		if (a[j][vtc] > x)
			return 0;
	//Kiem tra max duong cheo chinh
	int vtd1 = vtd + 1;
	int vtc1 = vtc + 1;
	while (vtd1 < dong && vtc1 < cot)
	{
		if (a[vtd1][vtc1] > x)
			return 0;
		vtd1++;
		vtc1++;
	}
	vtd1 = vtd - 1;
	vtc1 = vtc - 1;
	while (vtd1 >= 0  && vtc1 >= 0)
	{
		if (a[vtd1][vtc1] > x)
			return 0;
		vtd1--;
		vtc1--;
	}
	//Kiem tra max tren duong cheo phu
	vtd1 = vtd + 1;
	vtc1 = vtc - 1;
	while (vtd1 < dong  && vtc1 >= 0)
	{
		if (a[vtd1][vtc1] > x)
			return 0;
		vtd1++;
		vtc1--;
	}
	vtd1 = vtd - 1;
	vtc1 = vtc + 1;
	while (vtd1 >= 0  && vtc1 < cot)
	{
		if (a[vtd1][vtc1] > x)
			return 0;
		vtd1--;
		vtc1++;
	}
	return 1;
}
void Queen(char pathout[100],int a[][max], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (checkQueen(a,n,n,i,j) == 1)
			{
				fprintf(f,"\n so hoang hau: %d, hang : %d, co: %d",a[i][j],i,j);
				printf("\n so hoang hau: %d, hang : %d, co: %d",a[i][j],i,j);
			}
}
