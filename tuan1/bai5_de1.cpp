#include <stdio.h>
#include <conio.h>
#include<math.h>
struct co {
int tren, duoi;
};
co a[29];	//du lieu cua cac con co
int tt[29];	//trang thai cac con co
int n; 		//so con co can xu li
int cl = 168;
int ttluu[28];
//-------------------
char pathin[50], pathout[50];
FILE *f;
//---------------------
void nhaptenfile();
void docfile(char pathin[50]);
void nhap(int &n);
void nhaptenfileout();
void infile(char pathout[100]);
void ktra();
void kqua();
void thu(int i);
//------------nhap tu file----------------
//
int main(){
//	nhap(n);
	nhaptenfile();
	docfile(pathin);
	thu(1);
	kqua();
	nhaptenfile();
	infile(pathout);
}

void nhaptenfile(){
	printf("nhap ten file: ");
 	gets(pathin);
}
void docfile(char pathin[50]){
	f = fopen(pathin,"r");
	if(f == NULL) printf("\n ko tim thay file");
	else{
	fscanf(f,"%d",&n);
	for(int i = 1; i <= n; i++){
	fscanf(f,"%d",&a[i].tren);
	fscanf(f,"%d",&a[i].duoi);
	}
	}
}
//-------------nhap cac con co tu ban phim-----------------
void nhap(int &n){
	int i;
	printf("\nnhap vao so quan co: ");
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		printf("\ngia tri tren duoi cua quan co thu %d",i);
		printf("\n mat tren: ");
		scanf("%d",&a[i].tren);
		printf("\n mat duoi: ");
		scanf("%d",&a[i].duoi);
	}
}
//---------------xuat ra file--------------------
void nhaptenfileout(){
 	printf("\nnhap ten file out: ");
 	gets(pathout);
 }
void infile(char pathout[100]){
	f = fopen(pathout,"w");
	int i;
	int demtt = 0;
	fprintf(f, "\ndo chenh lech nho nhat la: %d",cl);
	for(i = 1; i <= n; i++) 
	if(ttluu[i] == 1 ) 
		demtt = demtt + 1;
	fprintf(f,"\nso luong quan co phai quay la: %d \n", demtt);
	for(i = 1; i <= n; i++) 
	fprintf(f,"%3d",ttluu[i]);
}
//-------------------------------------------------------
void ktra(){
	int j;
	int dochenh = 0;
	int s1 = 0, s2 = 0;// s1: tong tren, s2: tong duoi
	for(j = 1; j <=n; j++){
		if (tt[j]==0){
		s1 = s1 + a[j].tren;
		s2= s2 + a[j].duoi;}
		else{
		s1 = s1 + a[j].duoi;
		s2= s2 + a[j].tren;
		}
	dochenh = abs(s1-s2);
	}
	if(dochenh < cl){
	 cl = dochenh;
	 for(j =1; j <=n; j++)
	 ttluu[j] = tt[j];
	}
}
void kqua(){
	int i;
	int demtt = 0;
	printf("\ndo chenh lech nho nhat la: %d",cl);
	for(i = 1; i <= n; i++) 
	if(ttluu[i] == 1 ) 
		demtt = demtt + 1;
	printf("\nso luong quan co phai quay la: %d \n", demtt);
	for(i = 1; i <= n; i++) 
	printf("%3d",ttluu[i]);
}
void thu(int i){
	int j;
	for(j = 0; j <= 1; j++){
		tt[i] = j;
		if(i < n) thu(i + 1);
		else  ktra();
		tt[i] = 0;
	}
}

