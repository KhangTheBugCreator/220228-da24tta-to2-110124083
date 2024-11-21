#include  <stdio.h>
#define SIZE 1000
#define ll long long
#include <math.h>
int checkngto(int a[], int n),slsoam(int a[],int n),slsole(int a[],int n),slngto(int a[],int n),checksoam(int a[],int n),checkx(int a[], int n, int x);
void firstngto(int a[],int n),nhapmang(int a[], int),xuatmang(int a[],int n),soduongle(int a[],int n);
ll tongMang(int a[],int n),tongDuong(int a[], int n),tongvitrile(int a[], int n );


int main(){
	int n;
	int a[SIZE];
	do{
		printf("nhap so luong phan tu:  ");
		scanf("%d",&n);
	}while(n<=0||n>=1001);
	
	nhapmang(a,n);//cau_a;
	xuatmang(a,n);//cau_b
	printf("tong phan tu trong mang la:  %lld\n",tongMang(a,n));//cau_c;
	printf("tong phan tu la so duong trong mang la:  %lld\n",tongDuong(a,n));//cau_d
	printf("tong phan tu tai vi tri le la: %lld\n",tongvitrile(a,n));//cau_e
	printf("so luong so am co trong mang la:  %d\n",slsoam(a,n));//cau_f
	printf("so luong so le co trong mang la:  %d\n",slsole(a,n));//cau_g
	printf("so luong so nguyen to  co trong mang la:  %d\n",slngto(a,n));//cau_h
	firstngto(a,n);//cau_i
	soduongle(a,n);//cau_j
	if (checksoam(a,n)) printf("mang A co ton tai so am\n ");
	else printf("mang A khong ton tai so am\n");//cau_k
	
	
	int x;
	printf("nhap X=");scanf("%d",&x);
	if (checkx(a,n,x)) printf("mang A ton tai so nguyen X");
	else printf("mang A khong ton tai so nguyen X");//cau_l
	
	return 0;
}


int checkngto(int n){
	if (n<2) return 0;
	for (int i=2;i<=sqrt(n);i++){
		if (n%i==0) return 0;
	}
	return 1;
}
void nhapmang(int a[],int n){
	
	for (int i=0;i<n;i++){
		printf("nhap phan tu thu %d: ",i);
		scanf("%d",&a[i]);
	}
}
void xuatmang(int a[], int n){
	for (int i=0;i<n;i++){
		printf("A[%d]=%d\n",i,a[i]);
	}
}
ll tongMang(int a[],int n){
	int tong=0;
	for (int i=0;i<n;i++){
		tong+=a[i];
	}
	return tong;
}

ll tongDuong(int a[],int n){
	int tong=0;
	for (int i=0;i<n;i++){
		if (a[i]>0) tong+=a[i];
	}
	return tong;
}
ll tongvitrile(int a[],int n){
	int tong=0;
	for (int i=0;i<n;i++){
		if (i%2!=0) tong+=a[i];
	}
	return tong;
}
int slsoam(int a[], int n){
	int dem=0;
	for (int i=0;i<n;i++){
		if (a[i]<0) dem++;
	}
	return dem;
}
int slsole(int a[],int n){
	int dem=0;
	for (int i=0;i<n;i++){
		if (a[i]>0 && a[i]%2!=0) dem++;
	}
	return dem;
}
int slngto(int a[],int n){
	int dem=0;
	for (int i=0;i<n;i++){
		if (checkngto(a[i])) dem++;
	}
	return dem;
}
//caui
void firstngto(int a[],int n){
	int res;
	int check=0;
	for (int i=0;i<n;i++){
		if (checkngto(a[i])){
			res=a[i];
			check=1;
			break;
		}
	}
	if (check==1) printf("so nguyen to dau tien trong mang la:  %d\n",res);
	else printf("mang khong co so nguyen to nao\n");
}
void soduongle(int a[], int n){
	for (int i=0;i<n;i++){
		if (a[i]>0 && a[i]%2!=0) printf("%d  ",a[i]);
	}
}
int checksoam(int a[],int n){
	for (int i=0;i<n;i++){
		if (a[i]<0) return 1;
	}
	return 0;
}
int checkx(int a[],int n,int x){
	for (int i=0;i<n;i++){
		if (a[i]==x) return 1;
	}
	return 0;
}
