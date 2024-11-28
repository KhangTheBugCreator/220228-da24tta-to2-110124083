#include <stdio.h>
#include <math.h>
#define COL 500
#define ROW 500
#define ll long long
ll tong(int a[][COL], int m, int n),tongdongk(int a[][COL],int m, int n, int k),tongcotk(int a[][COL], int m,int n,int k);
int checknt(int n), checkamdongk(int a[][COL], int m, int n,int k),checkntcotk(int a[][COL], int m, int n, int k);
int checklecotk(int a[][COL], int m, int n, int k), check_x(int a[][COL], int m, int n, int x);
void nhapmang(int a[][COL],int m,int n), xuatmang(int a[][COL],int m, int n), BurbleSort(int a[][COL],int m, int n, int k), find_x(int a[][COL], int m, int n, int x),
maxdongk(int a[][COL], int m, int n, int k), mindongk(int a[][COL], int m, int n, int k), nguyentotrendongk(int a[][COL], int m, int n, int k);

int main(){
	int n,m,k,x;
	do{
		printf("nhap m dong va n cot: ");
		scanf("%d %d",&m,&n);
	}while(m>COL || m<=0 || n>ROW || n<=0);
	do{
		printf("nhap gia tri K(1<=k<=n,m):  ");
		scanf("%d",&k);
	}while(k<=0 || k>n || k>m);
	k--;
	printf("nhap gia tri x=");scanf("%d",&x);
	int a[ROW][COL];
	nhapmang(a,m,n);printf("\n");//cau_a
	xuatmang(a,m,n);printf("\n");//cau_b
	printf("tong mang vua nhap la: %lld",tong(a,m,n));printf("\n");//cau_c
	printf("tong gia tri tren dong K=%d la: %lld",k+1,tongdongk(a,m,n,k));printf("\n");//cau_d
	printf("tong gia tri tren cot K=%d la: %lld",k+1,tongcotk(a,m,n,k));printf("\n");//cau_e
	if (checkamdongk(a,m,n,k)) printf("dong K=%d co ton tai so am",k+1);
	else printf("dong K=%d khong ton tai so am",k+1);printf("\n");//cau_f
	if (checkntcotk(a,m,n,k)) printf("cot K=%d co ton tai so nguyen to",k+1);printf("\n");//cau_g
	BurbleSort(a,m,n,k);//cau_h
	if (checklecotk(a,m,n,k)) printf("cot K=%d toan gia tri le",k+1);
	else printf("cot K=%d khong toan gia tri le",k+1);printf("\n");//cau_i
	if (check_x(a,m,n,x)) printf("mang co ton tai so X=%d",x);
	else printf("mang khong ton tai so X=%d",x);printf("\n");//cau_j
	find_x(a,m,n,x);printf("\n");//cau_k
	maxdongk(a,m,n,k);printf("\n");//cau_l
	mindongk(a,m,n,k);printf("\n");//cau_m
	nguyentotrendongk(a,m,n,k);printf("\n");//cau_n
	return 0;
}

//check so nguyen to
int checknt(int n){
	for (int i=2;i<=sqrt(n);i++){
		if (n%i==0) return 0;
	}
	return n>1;
}

//cau_a
void nhapmang(int a[][COL],int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
}
//cau_b
void xuatmang(int a[][COL],int m, int n){
	printf("mang vua nhap la: \n");
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
//cau_c
ll tong(int a[][COL], int m, int n){
	ll kq=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			kq+=a[i][j];
		}
	}
	return kq;
}
//cau_d
ll tongdongk(int a[][COL],int m, int n, int k){
	ll kq=0;
	for (int i=0;i<n;i++){
		kq+=a[k][i];
	}
	return kq;
}
//cau_e
ll tongcotk(int a[][COL], int m,int n,int k){
	ll kq=0;
	for (int i=0;i<m;i++){
		kq+=a[i][k];
	}
	return kq;
}
//cau_f
int checkamdongk(int a[][COL], int m, int n,int k){
	for (int i=0;i<n;i++){
		if (a[k][i]<0) return 1;
	}
	return 0;
}
//cau_g
int checkntcotk(int a[][COL], int m, int n, int k){
	for (int i=0;i<m;i++){
		if (checknt(a[i][k])){
			return 1;
		}
	}
	return 0;
}
//cau_h
//ham sap xep giam dan
void BurbleSort(int a[][COL],int m, int n, int k){
	for (int i=0;i<n-1;i++){
		for (int j=n-1;j>i;j--){
			if (a[k][j]>a[k][i]){
				int t=a[k][j];
				a[k][j]=a[k][i];
				a[k][i]=t;
			}
		}
	}
	printf("mang sau khi da sap xep dong K=%d theo gia tri giam dan: \n",k+1);
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
//cau_i
int checklecotk(int a[][COL], int m, int n, int k){
	for (int i=0;i<m;i++){
		if (a[i][k] % 2 ==0) return 0;
	}
	return 1;
}
//cau_j
int check_x(int a[][COL], int m, int n, int x){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (a[i][j]==x){
				return 1;
			}
		}
	}
	return 0;
}
//cau_k
void find_x(int a[][COL], int m, int n, int x){
	printf("cac vi tri cua x=%d trong mang la: \n",x);
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (a[i][j]==x){
				printf("[%d;%d]\n",i+1,j+1);
			}
		}
	}	
}
//cau_l
void maxdongk(int a[][COL], int m, int n, int k){
	int max=a[k][0];
	for (int i=1;i<n;i++){
		if (max<a[k][i]){
			max=a[k][i];
		}
	}
	printf("so lon nhat tren dong k=%d la: %d",k+1,max);
}
//cau_m
void mindongk(int a[][COL], int m, int n, int k){
	int min=a[k][0];
	for (int i=1;i<n;i++){
		if (min>a[k][i]){
			min=a[k][i];
		}
	}
	printf("so nho nhat tren dong k=%d la: %d",k+1,min);
}
//cau_n
void nguyentotrendongk(int a[][COL], int m, int n, int k){
	printf("cac so nguyen to tren dong k=%d la: ",k+1);
	for (int i=0;i<n;i++){
		if (checknt(a[k][i])){
			printf("%d ", a[k][i]);
		}
	}
}

