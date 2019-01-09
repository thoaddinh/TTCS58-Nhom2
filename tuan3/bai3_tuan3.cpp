#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
#define max 100

struct khachHang{
	string MKH;	
	string ten;	
	float soduTK;
};
khachHang a[max];

struct  giaoDich{
	string MKH;
	bool loaiGD;
	float tienGD;
};
giaoDich b[max];

fstream f;

void docfile(khachHang a[], int &n);
void inDS(int n);
void them1KH(int id);
void ghifileKH(int id);
void themKH(khachHang a[],int &n,int k);
int main(){
	int n;
	docfile(a,n);
	inDS(n);
	themKH(a,n,1);
	inDS(n);
	return 0;
}
void docfile(khachHang a[], int &n){
	f.open("customer.dat", ios::in);
		int i = 0;
		while(!f.eof()){
		getline(f,a[i].MKH,'\t');
		getline(f,a[i].ten,'\t');
		f>>a[i].soduTK;
		i++;
		}
		n = i - 2; // i = 4 _"2 ki tu xuong dong \n"
		f.close();
}
void inDS(int n){
	for(int i = 0; i <= n ; i++){
	cout<<a[i].MKH<<"\t"<<a[i].ten<<"\t"<<a[i].soduTK<<endl;
	}
}
void them1KH(int id){
	cin.ignore();
	string temp;
	getline(cin,temp);
	cout<<"\nNhap ma khach hang: ";
	getline(cin,a[id].MKH);
	cout<<"\nNhap ten khach hang: ";
	getline(cin,a[id].ten);
	cout<<"\nNhap so tien du trong tai khoan: ";
	cin>>a[id].soduTK;
}
void ghifileKH(int id){
	f<<a[id].MKH<<"\t"<<a[id].ten<<"\t"<<a[id].soduTK<<endl;
}
void themKH(khachHang a[],int &n,int k){
	ofstream f;
	f.open("customer.dat", fstream::app);
	for(int i = n + 1; i <= n + k; i++){
		them1KH(i);
}
	for(int i = n + 1; i <= n + k; i++){
		ghifileKH(i);
	}
	n = n + k; 
	f.close();
}


