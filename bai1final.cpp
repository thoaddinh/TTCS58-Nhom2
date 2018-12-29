#include<stdio.h>
#include<conio.h>
#define row 5
#define col 5
 FILE *f;
 int a[row][col];
 char pathin[100], pathout[100];
 void nhaptenfile(){
 	printf("nhap ten file: ");
 	gets(pathin);
 }
 void docfile(char pathin[100]){
 f = fopen(pathin,"r");
 if (f == NULL) printf("khong tim duoc file");
 else{
 	printf("\n tim duoc file\n");
 	for(int i = 0; i < row; i++)
 	for(int j =0; j < col; j++) 
 	fscanf(f,"%d",&a[i][j]);
	fclose(f);
 }}
 void nhaptenfileout(){
 	printf("\nnhap ten file out: ");
 	gets(pathout);
 }
 void finxoan(char pathout[100], int a[5][5], int k, int n){
 	int i;
 	if(k == n) fprintf(f,"%3d",a[k][k]);
 	else{
 		for(i = k; i <= n; i++) fprintf(f,"%3d",a[k][i]);//in dong dau k
 		for(i = k + 1; i <= n; i++) fprintf(f,"%3d",a[i][n]);//in hang cuoi n
 		for(i = n - 1; i >= k; i--) fprintf(f,"%3d",a[n][i]);//in dong cuoi n
 		for(i = n -1 ; i >= k + 1; i--) fprintf(f,"%3d",a[i][k]);//in hang dau k
		finxoan(pathout,a,k+1,n-1);
 	}
 }
 
 void inxoan(int a[5][5], int k, int n){
 	int i;
 	if(k == n) printf("%3d",a[k][k]);
 	else{
 		for(i = k; i <= n; i++) printf("%3d",a[k][i]);//in dong dau k
 		for(i = k + 1; i <= n; i++) printf("%3d",a[i][n]);//in hang cuoi n
 		for(i = n - 1; i >= k; i--) printf("%3d",a[n][i]);//in dong cuoi n
 		for(i = n -1 ; i >= k + 1; i--) printf("%3d",a[i][k]);//in hang dau k
 		inxoan(a,k+1,n-1);
 	}
 }
 int main(){
 	nhaptenfile();
 	docfile(pathin);
 //	int a[5][5] = {7,15,11,20,10,32,14,9,31,26,53,49,0,67,22,46,51,98,54,56,13,8,23,12,34} ;
 	nhaptenfileout();
 	f = fopen(pathout,"w");
 	finxoan(pathout,a,0,4);
// 	inxoan(a,0,4);
 	fclose(f);
 	return 0;
 }
 


