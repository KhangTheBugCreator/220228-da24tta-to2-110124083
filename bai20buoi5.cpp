#include <stdio.h>
#define SIZE 10000
void nhapmang(float a[],int n),xuatmang(float a[], int n), invitrile(float a[], int n), inravitricogiatrilakhong(float a[], int n),BurbleSort(float a[], int n), incacvitrimax(float a[], int n);
float tong(float a[],int n),tbcvitrile(float a[], int n),max(float a[],int n);
int demduong(float a[],int n),checktoanam(float a[], int n);
void maxfirst(float a[], int n);
int main(){
	int n;
	do{
		printf("nhap n=");
		scanf("%d",&n);
	}while(n>SIZE||n<=0);
	float a[n];
	/*cau_a*/;nhapmang(a,n);printf("\n");
	/*cau_b*/xuatmang(a,n);printf("\n");
	/*cau_c*/printf("tong cac phan tu cua mang:  %.2f",tong(a,n));printf("\n");
	/*cau_d*/printf("trung binh cong cac phan tu tai vi tri le:  %.2f",tbcvitrile(a,n));printf("\n");
	/*cau_e*/printf("so phan tu duong trong mang la:  %d",demduong(a,n));printf("\n");
	/*cau_f*/BurbleSort(a,n);printf("\n");
	/*cau_g*/invitrile(a,n);printf("\n");
	/*cau_h*/inravitricogiatrilakhong(a,n);printf("\n");
	/*cau_i*/printf("gia tri lon nhat trong mang la: %.2f", max(a,n));printf("\n");
	/*cau_j*/maxfirst(a,n);printf("\n");
	/*cau_k*/incacvitrimax(a,n);printf("\n");
	//cau l;
	if (checktoanam(a,n)){
		printf("mang toan so am");
	}
	else{
		printf("mang khong toan la so am");
	}
	
	return 0;
}
//cau_a;
void nhapmang(float a[],int n){
	for (int i=0;i<n;i++){
		printf("nhap phan tu thu %d: ",i);
		scanf("%f",&a[i]);
	}
}
//cau_b;
void xuatmang(float a[],int n){
	for (int i=0;i<n;i++){
		printf("phan tu thu %d:  %.2f\n ",i,a[i]);
	}
}
//cau_c;
float tong(float a[], int n){
	float kq=0;
	for (int i=0;i<n;i++){
		kq+=a[i];
	}
	return kq;
}
//cau_d;
float tbcvitrile(float a[], int n){
	int dem=0;
	float tong=0;
	for (int i=0;i<n;i++){
		if (i%2!=0){
			dem++;
			tong+=a[i];
		}
	}
	return tong/dem;
}
//cau_e;
int demduong(float a[], int n){
	int dem=0;
	for (int i=0;i<n;i++){
		if (a[i]>0){
			dem++;
		}
	}
	return dem;
}
//cau_f;
void BurbleSort(float a[], int n){
	for (int i=0;i<n-1;i++){
		for (int j=n-1;j>i;j--){
			if (a[j]<a[i]){
				int tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	printf("mang sau khi da sap xep tang dan: \n");
	for (int i=0;i<n;i++){
		printf("%.2f ",a[i]);
	}
}
//cau_g;
void invitrile(float a[], int n){
	printf("gia tri cua cac phan tu tai vi tri le:  ");
	for (int i=0;i<n;i++){
		if (i%2!=0){
			printf("%.2f  " ,a[i]);
		}
	}
}
//cau_h
void inravitricogiatrilakhong(float a[], int n){
	printf("vi tri cua cac phan tu co gia tri la khong: ");
	for (int i=0;i<n;i++){
		if (a[i]==0){
			printf("%d ",i);
		}
	}
}
//cau_i;
float max(float a[], int n){
	int max=-1e9;
	for (int i=0;i<n;i++){
		if(max<a[i]){
			max=a[i];
		}
	}
}
//cau_j;
void maxfirst(float a[], int n){
	printf("vi tri dau tien co gia tri lon nhat trong mang la: ");
	for (int i=0;i<n;i++){
		if (a[i]==max(a,n)){
			printf("%d ",i);
			return;
		}
	}
}
//cau_k;
void incacvitrimax(float a[], int n){
	printf("vi tri cua cac phan tu co gia tri lon nhat: ");
	for (int i=0;i<n;i++){
		if (a[i]==max(a,n)){
			printf("%d ",i);
		}
	}
}
//cau_l;
int checktoanam(float a[], int n){
	for (int i=0;i<n;i++){
		if (a[i]>=0) return 0;
	}
	return 1;
}
