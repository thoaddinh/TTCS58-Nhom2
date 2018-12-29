#include <iostream>
using namespace std;
#include <string.h>
struct xe
{
char soXe[12];
char loaiXe[10];
char hieuXe[20];
xe *tx;
};
struct con
{
char MNKC[9];
char hoTenC[30];
char gioiTinh[4];
con *tc;
};
struct HK 
{
char soHK[6];
char MNK[9];
char hoTenCH[30];
char diaChi[30];
con *dsc;
xe *dsx;
HK *th;
};
HK *dauhk;
void khoiTao(HK *&dauhk);
void nhapCon(con *&dauc);
void nhapXe(xe *&daux);
void nhapHo(HK *&dsh);
void hienThi(con *dau);
void inHK(HK *dauhk);//in thanh vien trong ho
int timXe(xe *dau);
void timHX(HK *dauhk);//tim ho co xe co hieu 
void xoaXe(xe *&dau);
void xoaXeHK(HK *&dau);//xoa xe dau danh sach lien ket
void xoaXe1(xe *&dau);
void xoaXeHo1(HK *&dauhk);//xoa 1 xe cua 1 ho gia dinh
int main(){
	khoiTao(dauhk);
	nhapHo(dauhk);
	inHK(dauhk);
	timHX(dauhk);//tim mot ho co xe nhu hang
	printf("\nchu ho co xe nhu hang:");
	xoaXeHK(dauhk);//xoa dau ds
	xoaXeHo1(dauhk);//xoa 1 xe cua 1 ho
}
void khoiTao(HK *&dauhk)
{
	dauhk = NULL;
}
void nhapCon(con *&dauc){
	con *p, *q;
	char MNKCt[9], hoTenCt[30],gioiTinht[4]; 
	do {
	printf("\n Nhap ma so nhan khau con, Enter -> dung: ");
	fflush(stdin);
	gets(MNKCt);
	if(strcmp(MNKCt,"\0")!= 0){
		p = new con;
		strcpy(p -> MNKC, MNKCt);
		printf("\nNhap ho ten con: ");
		fflush(stdin); gets(hoTenCt);
		printf("\nNhap gioi tinh con: ");
		fflush(stdin); gets(gioiTinht);
		strcpy(p -> hoTenC, hoTenCt);
		strcpy(p -> gioiTinh, gioiTinht);
		p->tc = NULL;
	//móc vao ds con
		if(dauc == NULL)
		dauc = p;
		else q->tc=p;
		q = p;
	}}
	while (strcmp(MNKCt,"\0")!= 0);
}
void nhapXe(xe *&daux){
	char soXet[12];
	char loaiXet[10];
	char hieuXet[20];
	xe *p, *q;
	do	{
	printf("\n Nhap ma so xe, Enter -> dung: ");
	fflush(stdin);
	gets(soXet);
	if(strcmp(soXet,"\0")!= 0){
		p = new xe;
		strcpy(p -> soXe, soXet);
		printf("\nNhap loai xe con: ");
		fflush(stdin); gets(loaiXet);
		printf("\nNhap hieu xe con: ");
		fflush(stdin); gets(hieuXet);
		strcpy(p -> loaiXe, loaiXet);
		strcpy(p -> hieuXe, hieuXet);
		p->tx = NULL;
	//móc vao ds con
		if(daux == NULL)
		daux = p;
		else q->tx=p;
		q = p;
	}}
	while (strcmp(soXet,"\0")!= 0);
	}
void nhapHo(HK *&dsh){
	char soHKt[6];
	char MNKt[9];
	char hoTenCHt[30];
	char diaChit[30];
	HK *p, *q;
    do{
    	printf("\n nhap so ho khau: ");
    	fflush(stdin); gets(soHKt);
    	if(strcmp(soHKt,"\0")!= 0){
    		p= new HK; 
    		strcpy(p -> soHK, soHKt);
			printf("\nNhap ma nhan khau: ");
			fflush(stdin); gets(MNKt);
			printf("\nNhap ho ten chu ho: ");
			fflush(stdin); gets(hoTenCHt);
			printf("\nNhap dia chi chu ho: ");
			fflush(stdin); gets(diaChit);
			strcpy(p -> MNK, MNKt);
			strcpy(p -> hoTenCH, hoTenCHt);
			strcpy(p -> diaChi, diaChit);
			p->dsc = NULL;
			p->dsx= NULL;
			printf("\nNhap ds xe: ");
			nhapXe(p->dsx);
			printf("\nNhap ds con: ");
			nhapCon(p->dsc);
			if(dsh == NULL)
				dsh = p;
			else p ->th = p; 
				 q = p;
    	}
    }
	while(strcmp(soHKt,"\0")!= 0);
}
void hienThi(con *dau){
	if(dau != NULL){
	printf("\n %s",dau->hoTenC);
	hienThi(dau->tc);
	} 
}

void inHK(HK *dauhk){
	char tam[9];
	printf("\n Nhap so ho khau can in ds thanh vien: ");
	fflush(stdin); gets(tam);
	if(dauhk != NULL){
	if(strcmp(dauhk->soHK,tam)== 0) {
	printf("\nThanh vien chu ho: ");
	printf("\n %s",dauhk->hoTenCH);}
	hienThi(dauhk->dsc);
	}
}
int timXe(xe *dau){
	char tam[20];
	fflush(stdin); gets(tam);
	if(dau != NULL){
	if(strcmp(dau->hieuXe,tam) == 0)
	return 1;
	timXe(dau->tx);}
	} 
void timHX(HK *dauhk){
	printf("\n Nhap hang xe can tim: ");
	if(dauhk != NULL){
	if(timXe(dauhk->dsx) == 1) {
	printf("\nthong tin chu ho co xe nhu hang:");
	printf("\n %s %s",dauhk->MNK,dauhk->hoTenCH);}
	timHX(dauhk->th);
	}
}
void xoaXe(xe *&dau){//Xoa xe
	if(dau != NULL)
	{
		dau = dau->tx;
	}
}
void xoaXeHK(HK *&dau){//Xoa xe cua mot ho khau
	if(dau!= NULL)
	{
		xoaXe(dau->dsx);
	}
}
//xe can xoa;
void xoaXe1(xe *&dau){
	char tam[12];
	printf("\n Nhap ma xe can xoa: ");
	fflush(stdin); gets(tam);
	if(dau != NULL){
	if(strcmp(dau->soXe,tam) == 0)
	dau = dau->tx;
	xoaXe1(dau->tx);	
	}
} 
// xe cua ho gia dinh nao
void xoaXeHo1(HK *&dauhk){
	char mt[12];//ma tam
	printf("\n Nhap ma ho can xoa: ");
	fflush(stdin); gets(mt);
	if(dauhk != NULL){
	if(strcmp(dauhk->MNK,mt) == 0)
		xoaXe1(dauhk->dsx);
	xoaXeHo1(dauhk->th);	}
	} 



