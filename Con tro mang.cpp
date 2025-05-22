#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int tong( int *a, int n){
	int s=0;
	for(int i=0; i<n; i++){
		s+= *(a+i);
	}
	return s;
}
void nhap(int *a, int n){
	printf("Nhap mang:\n");
	for(int i=0; i<n; i++){
		printf("a[%d]= ",i+1); 
		scanf("%d",a+i);
	}
}
void xuat(int *a, int n){
	for( int i=0; i<n; i++){
		printf("%d\t",*(a+i));
	}
}
int snt(int n){
	for(int i=2; i<=sqrt(n); i++){
		if(n%i == 0){
			return 0;
		}
	}
	return 1;
}
int sohoanhao(int n){
	int s=0;
	for(int i=1; i<n; i++){
		if(n%i==0){
			s+=i;
		}
	}
	if(s==n) return 1;
	else return 0;
}

void sapXep( int *a, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i-1; j++){
			if(*(a+j)>*(a+j+1)){
				int tam= *(a+j);
				*(a+j)= *(a+j+1);
				*(a+j+1)= tam;
			}
		}
	}
}
int demSnt(int *a, int n){
	int dem=0;
	for(int i=0; i<n ; i++){
		if(snt(*(a+i))==1){
			dem++;
		}
	}
	return dem;
}
void insnt(int *a, int n){
	for(int i=0; i<n ; i++){
		if(snt(*(a+i))==1){
			printf("%d\t",*(a+i));
		}
	}
}
int demshh(int *a, int n){
	int dem=0;
	for(int i=0; i<n ; i++){
		if(sohoanhao(*(a+i))==1){
			dem++;
		}
	}
	return dem;
}
void inshh(int *a, int n){
	for(int i=0; i<n ; i++){
		if(sohoanhao(*(a+i))==1){
			printf("%d\t",*(a+i));
		}
	}
}
int main(){
	int n;
	printf("Nhap n= ");
	scanf("%d",&n);
	int *a	=(int*)malloc(n*sizeof(int));
	nhap(a,n);	
	printf("Tong day la: %d\n",tong(a,n));
	printf("Mang da sap xep la: \n");
	sapXep(a,n);
	xuat(a,n);
	if(demSnt(a,n)==0){
		printf("\nMang khong ton tai so nguyen to.\n");
	} else{
		printf("So nguyen to co trong mang la: %d\n",demSnt(a,n));
		insnt(a,n);
	}
	if(demshh(a,n)==0){
		printf("\nMang khong ton tai so hoan hao.\n");
	} else{
		printf("So hoan hao co trong mang la: %d\n",demshh(a,n));
		inshh(a,n);
	}
	free(a);
	
	return 0;
}

