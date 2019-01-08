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
//ham them moi khach hang
//n: ds khach hang, k: so khach hang can them vao
void themKH(int &n, int k){
	int i;
	f.open("bai3.txt",ios::out);
	for(int i = n + 1; i <= n + k; i++)
		{	them1KH(i);
			fhienthi1KH(i);
			i++;
		}
	f<<"da ghi dc file";
	n = i;
	f.close();
	}
//them mot khach hang
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
int main(){
	int n;
	docfile(n);
	themKH(n,1);
}


