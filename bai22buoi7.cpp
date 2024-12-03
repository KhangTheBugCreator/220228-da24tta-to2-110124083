#include <stdio.h>
#include <stdlib.h>
#define ll long long
void nhapgiatri(int *a, int n),xuatgiatri(int *a,int n),tonggiatri(int *a, int n),SoLanXuatHienCuaMax(int *a, int n),SoLanXuatHienCuaX(int *a, int n, int x);
void KiemTraTonTaiSoDuong(int *a,int n),SapXepNoiBot(int *a, int n), LocSoAm(int *a, int n);
int max(int *a,int n);

int main(){
	int n;
	do{
		printf("nhap n=");scanf("%d",&n);
	}while(n>=50 || n<=0);
	int *a=(int *)malloc(n*sizeof(int));
	nhapgiatri(a,n);
	xuatgiatri(a,n);
	tonggiatri(a,n);
	printf("gia tri lon nhat trong day: %d\n",max(a,n));
	SoLanXuatHienCuaMax(a,n);
	int x;printf("nhap X=");scanf("%d",&x);
	SoLanXuatHienCuaX(a,n,x);
	KiemTraTonTaiSoDuong(a,n);
	SapXepNoiBot(a,n);
	LocSoAm(a,n);
	free(a);
	return 0;
}

void nhapgiatri(int *a, int n){
	for (int i=0;i<n;i++){
		printf("A[%d]=",i);
		scanf("%d",(a+i));
	}
}
void xuatgiatri(int *a,int n){
	printf("cac gia tri vua nhap la: \n");
	for (int i=0;i<n;i++){
		printf("A[%d]=%d\n",i,*(a+i));
	}
}
void tonggiatri(int *a, int n){
	ll s=0;
	for (int i=0;i<n;i++){
		s+=*(a+i);
	}
	printf("tong cua n gia tri vua nhap la: %lld\n",s);
}
int max(int *a,int n){
	int kq=*a;
	for (int i=1;i<n;i++){
		if (kq<*(a+i)){
			kq=*(a+i);
		}
	}
	return kq;
}
void SoLanXuatHienCuaMax(int *a, int n){
	int dem=0;
	for (int i=0;i<n;i++){
		if (*(a+i)==max(a,n)){
			dem++;
		}
	}
	printf("so lan xuat hien cua phan tu lon nhat (%d) la: %d\n",max(a,n),dem);
}
void SoLanXuatHienCuaX(int *a, int n, int x){
	int dem=0;
	for (int i=0;i<n;i++){
		if (x==*(a+i)){
			dem++;
		}
	}
	printf("so lan xuat hien cua X trong mang la: %d\n",dem);
}
void KiemTraTonTaiSoDuong(int *a,int n){
	for (int i=0;i<n;i++){
		if (*(a+i)>0){
			printf("mang co ton tai so duong\n");
			return;
		}
	}
	printf("mang khong ton tai so duong\n");
}
void SapXepNoiBot(int *a, int n){
	for (int i=0;i<n-1;i++){
		for (int j=n-1;j>i;j--){
			if (a[i]>a[j]){
				int tam=a[i];
				a[i]=a[j];
				a[j]=tam;
			}
		}
	}
	printf("mang sau khi da sap xep tang dan: \n");
	for (int i=0;i<n;i++){
		printf("%d ",*(a+i));
	}
	printf("\n");
}
void LocSoAm(int *a, int n){
	printf("cac so am co trong day: ");
	for (int i=0;i<n;i++){
		if (*(a+i)<0){
			printf("%d ",*(a+i));
		}
	}
	printf("\n");
}
	
