#include <iostream>
#include<stdlib.h>
#include <math.h>
using namespace std;
int a[100];
int n = 10;
//tao mnag ngau nhien n phan tu
void nhapNN(int a[], int &n){
	cout<<"\nnhap vao so phan tu n mang: ";
	cin>>n;
	for(int i = 0; i < n; i++)
	a[i] = rand()%100;
}
//xây dung max heap
void chinhHeap(int a[], int n, int i){
	int vt = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	if(left < n && a[left] > a[vt] )
		vt = left;
	if(right < n && a[right] > a[vt])
		vt = right;
	if(vt != i)
	{
		swap(a[i], a[vt]);
		chinhHeap(a,n,vt);}
}
//xay dung cay heap 
void xoayHeap(int a[], int n){
	for(int i = n/2 - 1; i >= 0; i--)
	chinhHeap(a,n,i);
}
void heapShort(int a[], int n){
	xoayHeap(a,n);//xay dung cay heap ban dau
	for(int i = n -1; i >= 0; i--){
		swap(a[0],a[i]);
		chinhHeap(a,i,0);
	}
}
//xuat mang
void xuat(int a[], int n){
	for(int i = 0; i < n; i++)
		cout<<" "<<a[i];
	printf("\n");
}
void moPhong(){
	
}
int main(){
	nhapNN(a,n);
	xuat(a,n);
	heapShort(a,n);
	xuat(a,n);
}
