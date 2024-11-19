#include <stdio.h>
#include <math.h>
#define ll long long
int cau_a(int),cau_b(int),cau_c(int),cau_d(int),cau_e(int),cau_f(int);
int main(){
	int n;
	do{
		printf("nhap n=");
		scanf("%d",&n);
	}while(n<100 || n>=10000);
	printf("tong cac chu so cua n=%d\n",cau_a(n));
	printf("tong cac chu so le cua n=%d\n",cau_b(n));
	printf("tong cac chu so nguyen to cua n=%d\n",cau_c(n));
	printf("so chu so 0 cua n=%d\n",cau_d(n));
	printf("so chu so chia het cho 3 cua n=%d\n",cau_e(n));
	printf("so chu so chia het cho 5 cua n=%d\n",cau_f(n));
	return 0;
		
}
//ham check nguyen to
int checknt(int n){
	if (n<2) return 0;
	for (int i=2;i<=sqrt(n);i++){
		if (n%i==0) return 0;
	}
	return 1;
}
//cau_a: tong cac chu so cua n
int cau_a(int n){
	if (n<10) return n;
	else return n%10+cau_a(n/10);
}
//cau_b: tong cac chu so le cua n
int cau_b(int n){
	
	if (n<10 && n%2!=0) return n;
	else if (n<10 && n%2==0) return 0;
	else if (n>10 && n%10%2==0) return cau_b(n/10);
	else if (n>10 && n%10%2!=0) return n%10+cau_b(n/10);
}
//cau_c: tong cac chu so la so nguyen to cua n
int cau_c(int n){
	if (n<10 && checknt(n)) return n;
	else if (n<10 && checknt(n)==0) return 0;
	else if (n>10 && checknt(n%10)) return n%10+cau_c(n/10);
	else if (n>10 && checknt(n%10)==0) return cau_c(n/10);
}
//cau_d: dem so chu so 0 cua n
int cau_d(int n){
	int dem=0;
	while (n!=0){
		if (n%10==0) dem++; 
		n/=10;
	}
	return dem;
}
//cau_e: dem so chu so cua n chia het cho 3
int cau_e(int n){
	int dem=0;
	while (n!=0){
		if (n%10%3==0) dem++;
		n/=10;
	}
	return dem;
}

//cau_f: dem so chu so cua n chia het cho 5
int cau_f(int n){
	int dem=0;
	while (n!=0){
		if (n%10%5==0) dem++;
		n/=10;
	}
	return dem;
}
