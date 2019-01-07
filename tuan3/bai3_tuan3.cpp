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
void them1KH(int n);
//doc file thong tin khach hang
void docfile(int &n){
	fstream f;
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
}
//ham them moi khach hang
//n: ds khach hang, k: so khach hang can them vao
void themKH(int &n, int k){
	fstream f;
	int i;
	f.open("bai3.txt",ios::out);
	
	for(int i = n; i <= n + k; i++)
		{	them1KH(i);
			i++;
		}
	n = i;
	}
//them mot khach hang
void them1KH(int n){
	
	string s;
	int l;
	cout<<"\nNhap ma so khach hang: ";
	getline(cin,s);
	f<<a[n + 1].MKH;
	a[n + 1].MKH = s;
	cout<<"\nNhap ten khach hang: ";
	getline(cin,s);
	a[n + 1].ten = s;
	f<<a[n+1].ten;
	cout<<"\nNhap so tien du torng tai khoan: ";
	cin>>l;
	a[n+1].soduTK = l; 
	f<<a[n+1].soduTK;
}
int main(){
	int n;
	docfile(n);
	themKH(n,1);
	
}


