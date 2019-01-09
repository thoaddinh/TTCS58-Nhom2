#include <iostream>
#include <fstream>
using namespace std;
#define max 100
//cau truc thong tin cua mot khach hang
struct thongtinKH{
	string MKH;	//ma khach hang
	string ten;	//ten khach hang
	float soduTK;	//so du trong tai khoan 
};
thongtinKH a[max];
//cau truc thong tin giao dich
struct giaodich{
	string MKH;
	bool loaiGD;
	float tienGD;
};
giaodich b[max];

fstream f;

void them1KH(int i);
void fhienthi1KH(int i);
//doc file thong tin khach hang
void docfile(int &n){
	f.open("bai3.txt",ios::in);
	int i = 0;
	while(!f.eof()){
		string s;
		int l;
		getline(f,s);
		a[i].MKH = s;
		getline(f,s);
		a[i].ten = s;
		f>>l;
		a[i].soduTK = l;
		i++;
	}
	n = i;
	f.close();
}
//ham them khach hang
//n: ds khach hang, k: so khach hang can them vao
void themKH(int &n, int k){
	int i;
	f.open("bai3.txt",ios::out);
	for(int i = n + 1; i <= n + k; i++)
		{	them1KH(i);
			fhienthi1KH(i);
		}
	n = i;
	f.close();
	}
//them mot khach hang tu ban phim
void them1KH(int i){
	string s;
	int l;
	cout<<"\nNhap ma so khach hang: ";
	getline(cin,s);
	a[i].MKH = s;
	cout<<"\nNhap ten khach hang: ";
	getline(cin,s);
	a[i].ten = s;
	cout<<"\nNhap so tien du torng tai khoan: ";
	cin>>l;
	a[i].soduTK = l; 
}
//hien thi thong tin khach hang them tren file
void fhienthi1KH(int i){
	f<<a[i].MKH<<endl;
	f<<a[i].ten<<endl;
	f<<a[i].soduTK<<endl;	
}

//ham giao dich rut tien
void ruttien(int i, int k){
	if(a[i].soduTK > k){
		cout<<"\n thuc hien giao dich rut tien";
		a[i].soduTK = a[i].soduTK - k;
	}
	else cout<<"\n ko thuc hien duoc giao dich rut tien";
}

//ham giao dich gui tien
void goitien(int i, int k){
	cout<<"thuc hien giao dich goi tien";
	a[i].soduTK = a[i].soduTK + k;
}
//in danh sach khach hang
void inDS(int n){
	for(int i = 0; i < n; i++)
		cout<<a[i].MKH<<"\t"<<a[i].ten<<endl;
}
//in sao ke cho mot khach hang
void menu(){
}
void insaoke(int i){
	
}
int main(){
	int n;
	docfile(n);
	themKH(n,1);
}


