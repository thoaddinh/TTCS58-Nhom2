#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
#define max 100
//cau truc thong tin khach hang
struct khachHang{
	string MKH;	
	string ten;	
	float soduTK;
};
khachHang a[max];
//cau truc thong tin giao dich
struct  giaoDich{
	string MKH;
	int loaiGD;
	float tienGD;
};
giaoDich b[max];

fstream f;
int n,k;

//hàm doc danh sach kahch han tu file
void docfile(int &n);
void inDS(int n);
void them1KH(int id);
void themKH(int &n,int k);
void thuchienGD();
void saoKe(int &k);
void inSK(int k);
void menu();
int main(){
	menu();
	return 0;
}
// doc file tu tap tin customer.txt
/*
input: customer.txt
output: doc du lieu vào mang a[], và truyen so luong ds vao bien n.
*/
void docfile(int &n){
	f.open("customer.txt", ios::in);
		int i = 0;
		while(!f.eof()){
		getline(f,a[i].MKH,'\t');
		getline(f,a[i].ten,'\t');
		f>>a[i].soduTK;
		string temp;
		getline(f,temp);
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
// nhap thong tin khach hang tu ban phim
void them1KH(int id){
	cin.ignore();
	cout<<"Nhap ma khach hang: "<<endl;
	getline(cin,a[id].MKH);
	cout<<"Nhap ten khach hang: "<<endl;
	getline(cin,a[id].ten);
	cout<<"Nhap so tien du trong tai khoan: "<<endl;
	cin>>a[id].soduTK;
}
// them khach hnag vao ds khach hang và ghi tiep tuc vào file
void themKH(int &n,int k){
	f.open("customer.txt",ios::app);	
	for(int i = n + 1; i <= n + k; i++){
		them1KH(i);
		}	
	for(int i = n + 1; i <= n + k; i++){
	f<<a[i].MKH<<"\t"<<a[i].ten<<"\t"<<a[i].soduTK<<endl;
	}
	n = n + k;
	f.close();
}
//-ham thuc hien thoa tac giao dich rut tien va goi tien
void thuchienGD(){
	f.open("giaoDich.txt",ios::app);
	string makh;
	float tien;
	int tam,i;
    cout<<"-------------------------------------"<<endl;
   	cout<<"chon 1: goi tien"<<endl;
   	cout<< "chon 2:rut tien "<<endl;
   	cout<<"an phim bat ki de thoat giao dich"<<endl;
   	cout<<"-------------------------------------"<<endl;
   	do{
   	cin>>tam;
   	if(tam == 1){
   	cout<<"Nhap vao ma khach hang : "<<endl;
	fflush(stdin);
	getline(cin,makh);
	for(i=0;i<=n;i++)
	{	if(a[i].MKH == makh)// neu co ten trong danh sach 
		{	cout<<"Nhap vao so tien can gui:"<<endl;
	        cin>>tien;
	        a[i].soduTK = a[i].soduTK + tien; 
	        f<<makh<<"\t"<<1<<"\t"<<tien<<endl;
	        cout<<"Goi tien thanh cong"<<endl;
	        break;
		}}
	if(i > n) {
		cout<<"ko co ma trong danh sach khach hang"<<endl;
		break;
		}
	}
	if(tam == 2){
	cout<<"Nhap vao ma khach hang : "<<endl;
	fflush(stdin);
	getline(cin,makh);
	for(i=0;i<=n;i++){
		if(a[i].MKH == makh){
		cout<<"nhap vao so tien can rut:"<<endl;
	    cin>>tien;
		{if(tien < a[i].soduTK){
			a[i].soduTK = a[i].soduTK - tien;
			f<<makh<<"\t"<<2<<"\t"<<tien<<endl;
			cout<<"rut tien thanh cong :"<<endl;
			break;
		}
		else
		{
		   cout<<"so du tk ko du"<<endl;
		   break;
		}
		}
	}
 }		
	if(i > n) {
		cout<<"ko co ma trong danh sach khach hang"<<endl;
		break;
		}
}	}
	while(tam == 1 || tam == 2);
}
//-----------------------------------
void saoKe(int &k){
	f.open("giaoDich.txt", ios::in);
		int i = 0;
		while(!f.eof()){
		getline(f,b[i].MKH,'\t');
		f>>b[i].loaiGD;
		f>>b[i].tienGD;
		i++;
		}
		k = i - 2; // i = 4 _"2 ki tu xuong dong \n"
		f.close();
}
void inSK(int k){
	string makh;
	cout<<"ma khach hang can in sao ke: \n";
	fflush(stdin);
	getline(cin,makh);
	for(int i = 0; i <= k; i++){
	if(b[i].MKH == makh){
	if(b[i].loaiGD == 1)
		cout<<"\n thuc hien giao dich goi tien"<<"\t"<<b[i].tienGD;
	if(b[i].loaiGD == 2)
		cout<<"\n thuc hen gioa dich rut tien"<<"\t"<<b[i].tienGD;
		}		
	}
	}

//-------------------------------
void menu(){
	docfile(n);
	int tam;
	cout<<"\nchon de thuc hien chuc nang: "<<endl;
	cout<<"---------------------------------"<<endl;
	cout<<"1. Them moi khach hang"<<endl;
	cout<<"2. Thuc hien giao dich"<<endl;
	cout<<"3. In danh sach khach hang"<<endl;
	cout<<"4. In sao ke cho mot khach hang"<<endl;
	cout<<"An phim bat ki de ket thuc"<<endl;
	cout<<"---------------------------------"<<endl;
	do
	{
		cout<<"Nhap chon: ";
		cin>>tam;
		switch(tam)
		{
			case 1:
				int sl;
				cout<<"\nNhap vao so luong khach hang can them: ";
				cin>>sl;
				themKH(n,sl);
				break;
			case 2:
				thuchienGD();
				break;
			case 3:
				inDS(n);			
				break;
			case 4:
				saoKe(k);
				inSK(k);
				break;
	}}
	while (tam > 0 && tam < 5);
}

