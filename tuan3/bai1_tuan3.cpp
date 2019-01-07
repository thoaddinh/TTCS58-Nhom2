#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
/*input: gia tri dau vao n, m
  outut: day so nguyen ngau nhien tu 1 den m */
//ham nhap cac gia tri dau vao n, m
void input(int &n, int &m){
	do{
	cout<<"\nnhap vao so n (n: so luong so can in ra): ";	//n so ngau nhien
	cin>>n;
	cout<<"\nnhap vao so m (m: gioi han so nguyen): ";	//so ngau nhien tu 1 den m
	cin>>m;	} 
	while( n >= m);
}
//ham xuat cac gia tri ngau nhien
void xuatNN(int n, int m){
	time_t t;	
// Khoi tao bo sinh so ngau nhien 
   srand((unsigned) time(&t));
	for(int i = 1; i <= n; i++)
		cout<<rand()%m<<"\t";
}

int main(){
	int n, m;
	input(n,m);
	xuatNN(n,m);
}

