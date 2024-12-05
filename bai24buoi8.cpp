#include <stdio.h>
#include <string.h>

struct PHAN_SO{
	int tu;
	int mau;
};
typedef struct PHAN_SO PS;

void nhap(PS *a);
void xuat(PS a);
int ucln(int a, int b);
void rutgon(PS a);
void tong(PS a, PS b);
void tru(PS a, PS b);

int main(){
	PS a,b;
	printf("nhap phan so thu nhat: \n");nhap(&a);
	printf("nhap phan so thu hai: \n");nhap(&b);
	printf("phan so thu nhat la: \n");xuat(a);
	printf("phan so thu hai la: \n");xuat(b);
	printf("phan so thu nhat sau khi rut gon: \n");rutgon(a);
	printf("phan so thu hai sau khi rut gon: \n");rutgon(b);
	tong(a,b);	
	tru(a,b);
	return 0;
}


void nhap(PS *a){
	printf("nhap tu so: ");
	scanf("%d",&a->tu);
	do{
		printf("nhap mau so: ");
		scanf("%d",&a->mau);
	}while (a->mau == 0);

}

void xuat(PS a){
	printf("%d/%d\n",a.tu,a.mau);
}

void rutgon(PS a){
	int t=ucln(a.tu,a.mau);
	if (a.mau/t==1){
		printf("%d\n",a.tu/t);
	}else printf("%d/%d\n",a.tu/t,a.mau/t);
}
int ucln(int a, int b){
	while (b!=0){
		int t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int bcnn(int a,int b){
	return a/ucln(a,b)*b;
}
void tong(PS a, PS b){
	int mauchung=bcnn(a.mau,b.mau);
	int tu=a.tu*(mauchung/a.mau)+b.tu*(mauchung/b.mau);
	
	//rut gon phan so tong vua tim dc;
	int t=ucln(mauchung,tu);
	if (mauchung/t==1){
		printf("tong la: %d\n",tu/t);
	}else{
		printf("tong la: %d/%d\n",tu/t,mauchung/t);
	}
	
}
void tru(PS a, PS b){
	int mauchung=bcnn(a.mau,b.mau);
	int tu=a.tu*(mauchung/a.mau)-b.tu*(mauchung/b.mau);
	
	//rut gon phan so tong vua tim dc;
	int t=ucln(mauchung,tu);
	if (mauchung/t==1){
		printf("hieu la: %d\n",tu/t);
	}else{
		printf("hieu la: %d/%d\n",tu/t,mauchung/t);
	}
	
}
