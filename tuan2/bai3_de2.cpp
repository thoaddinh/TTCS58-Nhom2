#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#define max 100
FILE *f;
struct NhanVien
{
	int msnv;
	char hoten[30];
	char chucvu[50];
	int HSL;
	int HSCV;
	float luong;
	int thang;
	int nam;
};
typedef NhanVien nhanvien;
struct DanhSach
{
	nhanvien a[max];
	int n;
};
typedef DanhSach danhsach;
//--------------------------------------
void doc1nv(nhanvien &nv);
void docfileds(danhsach &ds);
void xuat1nv(nhanvien nv);
void xuatdanhsach(danhsach ds);
float Luong(nhanvien nv);
void sapxep(danhsach ds);
int timMSNV(danhsach ds,int ms);
void xoanv(danhsach ds,int ms);
void menu();
//======================================
int main(){
	danhsach ds;
	nhanvien nv;
	docfileds(ds);
	xuatdanhsach(ds);
	sapxep(ds);
	xoanv(ds,1001);
	menu();
}

/*void docfileds(danhsach &ds)
{	f = fopen("inputb3.txt","r");
	fscanf(f,"%d",&ds.n); //so luong nhan vien
	for(int i=0;i<ds.n;i++)
	{	
		doc1nv(ds.a[i]);
	}
	fclose(f);
}
void doc1nv(nhanvien &nv)
{	fflush(stdin);
	fscanf(f,"%d",&nv.msnv);	//msnv
	fflush(stdin);
	fgets(nv.hoten,30,f);	//hotennhanvien
	fgets(nv.chucvu,50,f);	//chuc vu
	fflush(stdin);
	fscanf(f,"%d",&nv.HSL);
	fflush(stdin);
	fscanf(f,"%d",&nv.HSCV);
	fflush(stdin);
	fscanf(f,"%d",&nv.thang);
	fflush(stdin);
	fscanf(f,"%d",&nv.nam);
}*/
void docfileds(danhsach &ds)
{
	scanf("%d",&ds.n); //so luong nhan vien
	for(int i=0;i<ds.n;i++)
	{	
		doc1nv(ds.a[i]);
	}
}
void doc1nv(nhanvien &nv)
{	fflush(stdin);
	scanf("%d",&nv.msnv);	//msnv
	fflush(stdin);
	gets(nv.hoten);	//hotennhanvien
	gets(nv.chucvu);	//chuc vu
	fflush(stdin);
	scanf("%d",&nv.HSL);
	fflush(stdin);
	scanf("%d",&nv.HSCV);
	fflush(stdin);
	scanf("%d",&nv.thang);
	fflush(stdin);
	scanf("%d",&nv.nam);
	nv.luong = Luong(nv);
}
void xuatdanhsach(danhsach ds)
{
	printf("\n-----------danh sach nhan vien-----------");
	for(int i=0;i< ds.n;i++)
	{
		printf("\n\t nhan vien thu %d",i+1);
		xuat1nv(ds.a[i]);
	}
}
void xuat1nv(nhanvien nv)
{
	printf("\nma so nhan vien: %d",nv.msnv);
	printf("\nho va ten nhan vien: %s",nv.hoten);
	printf("\nchuc vu nhan vien: %s",nv.chucvu);
	printf("\nthang nam sinh : %d - %d ",nv.thang, nv.nam);
	printf("\nluong: %8.2f",Luong(nv));
}
float Luong(nhanvien nv)
{
	float LCB = 150000;//Luong co ban
    nv.luong = 0;
    nv.luong = LCB*(nv.HSL + nv.HSCV);
	return nv.luong;
}

void sapxep(danhsach ds){
	for(int i = 0; i < ds.n-1; i++)
	for(int j = i + 1; j < ds.n; j++){
		if(ds.a[i].luong > ds.a[j].luong) 
		{
			float t = ds.a[i].luong;
			ds.a[i].luong = ds.a[j].luong;
			ds.a[j].luong = t ;
		}
	}
	printf("\n-----------------bang luong tang dan: ");
	for(int i = 0; i < ds.n; i++)
	printf("\n%8.2f",ds.a[i].msnv,ds.a[i].luong);
}
int timMSNV(danhsach ds,int ms)
{
	for(int i=0;i<ds.n;i++)
	{
		if(ds.a[i].msnv==ms)
		{
			return i;
			break;
		}
	}
	return -1;
}
void timnv(danhsach ds,int ms){
	printf("\n\tNhap ma so can tim: ");
	scanf("%d",&ms);
	int t =timMSNV(ds,ms);
	if(timMSNV(ds,ms)==-1)
		printf("\nkhong tim thay");
	else
		printf("\nTim thay nhan vien thu %d",t+1);
}
void xoanv(danhsach ds,int ms)
{	
	printf("\n \nNhap Msnv can xoa:");
	scanf("%d",&ms);
	int vt=timMSNV(ds,ms);
	if(vt==-1)
		printf("\nkhong tim thay msnv %d muon xoa",ms );
	else
		for(int i=vt;i < ds.n;i++)
		{
			ds.a[i]=ds.a[i+1];
			
		}
		ds.n--;
	xuatdanhsach(ds);
}

void menu()
{
	int ch;
	int ms,k;
	danhsach ds;
	nhanvien nv;
	printf("\n\t\t--------------MENU--------------");
	printf("\n\t1.Tim nhan vien theo ma so");
	printf("\n\t2.Bang luong cua  nhan vien tang dan");
	printf("\n\t3.Xoa 1 nhan vien");
	printf("\n *************************************************");
	printf("\n\tChon 1 trong chuc nang tren: ");
	scanf("%d",&ch);
	switch(ch)
	{
		
		case 1:
			{
				timnv(ds,ms);
				break;
			}
	
		case 2:
			{
			sapxep(ds);
				break;
			}
		case 3:
			{
				xoanv(ds,ms);
				break;
			}
		default: printf("\nkhong co chuc nang nay");
			break;
	}
}

