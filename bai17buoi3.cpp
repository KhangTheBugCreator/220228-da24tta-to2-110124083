#include <stdio.h>
#include <math.h>
#define ll long long
//ham kiem tra mot so co phai la so nguyen to hay khong
int is_prime(int n){
	if (n<2) return 0;
	for (int i=2;i<=sqrt(n);i++){
		if (n%i==0) return 0;
	}
	return 1;
}
//cau_a
void cau_a(int n){
	for (int i=1;i<=n;i++){
		printf("%d ",i);
	}
}
//cau_b
void cau_b(int n){
	for (int i=2;i<=n/2*2;i+=2){
		printf("%d ",i);
	}
}
//cau_c
void cau_c(int n){
	for (int i=5;i<=n/5*5;i+=5){
		printf("%d ",i);
	}
}
//cau_d
void cau_d(int n){
	for (int i=2;i<n;i++){
		if (is_prime(i)) printf("%d ",i);
	}
}
//cau_e
ll cau_e(int n){
	return 1ll*(n+1)*n/2;
}
//cau_f
ll cau_f(int n){
	ll tong=0;
	if (n%2==0){
		n--;
	}
	for (int i=1;i<=n;i+=2){
		tong+=i;	
	}
	return tong;
}
//cau_g
ll cau_g(int n){
	ll tong=0;
	for (int i=2;i<n;i++){
		if (is_prime(i)){
			tong+=i;
		}
	}
	return tong;
}
//cau_h
double cau_h(int n){
	ll tongsole=cau_f(n);
	ll dem=0;
	for (int i=1;i<=n;i++){
		if (i%2!=0){
			dem++;
		}
	}
	return tongsole/dem;
}
//cau_i
double cau_i(int n){
	ll tongnguyento=cau_g(n);
	ll demngto=0;
	for (int i=2;i<n;i++){
		if (is_prime(i)) demngto++;
	}
	return tongnguyento/demngto;
}
int main(){
	int n;
	do{
		printf("nhap n=");
		scanf("%d",&n);
	}while(n>=100 || n<=0);
	printf("cac gia tri tu 1 den %d:   ",n);
	cau_a(n);printf("\n");
	printf("cac gia tri chan tu 1 den %d:   ",n);
	cau_b(n);printf("\n");
	printf("cac gia tri chia het cho 5 tu 1 den %d:  ",n);
	cau_c(n);printf("\n");
	printf("cac so nguyen to nho hon %d la:  ",n);
	cau_d(n);printf("\n");
	printf(" tong cac gia tri tu 1 den %d=%lld\n",n,cau_e(n));
	printf("tong cac so le tu 1 den %d=%lld\n",n,cau_f(n));
	printf("tong cac so nguyen to nho hon %d=%lld\n",n,cau_g(n));
	printf("trung binh cong cac so le tu 1 den %d=%.2lf\n",n,cau_h(n));
	printf("trung binh cong cac so nguyen to nho hon %d=%.2lf\n",n,cau_i(n));
	return 0;
}
