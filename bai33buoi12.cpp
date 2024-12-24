#include <stdio.h>

struct PHAN_SO{
	int tu;
	int mau;
};
typedef struct PHAN_SO PS;

void nhapPS(PS *a),inPS(PS a,FILE *p),inPSmanhinh(PS a),rutgonPS(PS *a),inPSmin(PS a[],int n),demmin(PS a[], int n),sort(PS a[],int n);
int ucln(int a, int b);
float minPS(PS a[],int n);


int main(){
	int n;
	FILE *p;
	char path[50];
	printf("nhap duong dan file output: ");gets(path);
	p=fopen(path,"wt");
	printf("nhap so luong phan so: ");
	scanf("%d",&n);
	PS a[n];
	for (int i=0;i<n;i++){
		printf("   -NHAP PHAN SO THU %d ",i+1);
		nhapPS(&a[i]);
	}
	for (int i=0;i<n;i++){
		inPS(a[i],p);//cau a;
	}
	fclose(p);
	for (int i=0;i<n;i++){
		rutgonPS(&a[i]);//caub
	}
	printf("   -CAC PHAN SO SAU KHI DA RUT GON\n");
	for (int i=0;i<n;i++){
		printf("     +PHAN SO THU %d: ",i+1);inPSmanhinh(a[i]);printf("\n");
	}
	inPSmin(a,n);//cau c;
	demmin(a,n);//cau d;
	sort(a,n);//cau e;
	printf("\n	-CAC PHAN SO SAU KHI DA SAP XEP GIAM DAN\n ");
	for (int i=0;i<n;i++){
		inPSmanhinh(a[i]);printf("\t");
	}
	return 0;
}

void nhapPS(PS *a){
	printf("\n     +nhap tu so: ");scanf("%d",&a->tu);
	do{
	printf("     +nhap mau so: ");scanf("%d",&a->mau);
	}while (a->mau==0);
}
void inPS(PS a,FILE *p){
	fprintf(p,"%d %d\n",a.tu,a.mau);
}
int ucln(int a, int b){
	while (b!=0){
		int tmp=a%b;
		a=b;
		b=tmp;
	}
	return a;
}
void inPSmanhinh(PS a){
	if (a.mau==1) printf("%d",a.tu);
	else printf("%d/%d",a.tu,a.mau);
}
void rutgonPS(PS *a){
	int uc=ucln(a->tu,a->mau);
	a->tu/=uc;
	a->mau/=uc;
}
float minPS(PS a[],int n){
	float min=1e9;
	for (int i=0;i<n;i++){
		if ((float)a[i].tu/a[i].mau<min){
			min=(float)a[i].tu/a[i].mau;
		}
	}
	return min;
}
void inPSmin(PS a[],int n){
	printf("cac phan so co gia tri nho nhat: ");
	for (int i=0;i<n;i++){
		if ((float)a[i].tu/a[i].mau==minPS(a,n)){
			inPSmanhinh(a[i]);printf("\t");
		}
	}
}
void demmin(PS a[], int n){
	int dem=0;
	for (int i=0;i<n;i++){
		if ((float)a[i].tu/a[i].mau==minPS(a,n)){
			dem++;
		}
	}
	printf("\nso luong phan so co gia tri nho nhat: %d",dem);
}
void sort(PS a[],int n){
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (((float)a[i].tu/a[i].mau<(float)a[j].tu/a[j].mau)){
				PS tmp;
				tmp.tu=a[i].tu;tmp.mau=a[i].mau;
				a[i].tu=a[j].tu;a[i].mau=a[j].mau;
				a[j].tu=tmp.tu;a[j].mau=tmp.mau;
			}	
		}							
	}	

}
