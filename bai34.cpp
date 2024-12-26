#include <stdio.h>
#include <string.h>
struct NGAY_THANG{
	int ngay,thang,nam;
};
struct MON_HOC{
	char mamon[50];
	float diem;
};

typedef struct MON_HOC MON_HOC;
typedef struct NGAY_THANG NGAY_THANG;
struct SINH_VIEN{
	char mssv[10],hoten[100],gioitinh[4],diachi[100];
	MON_HOC mon[100];
	NGAY_THANG ngaysinh;
	int somonhoc;
};
typedef struct SINH_VIEN sv;
struct LOP_HOC{
	char malop[20];
	char tenlop[20];
	int siso;
	sv a[100];
	
	
};
typedef LOP_HOC LOP_HOC;
void nhap(sv a[], int n){
	for (int i=0;i<n;i++){
		printf("\nnhap thong tin cho sinh vien thu %d\n",i+1);
		printf("nhap mssv: ");scanf("%s",&a[i].mssv);
		printf("nhap ho ten: ");fflush(stdin);gets(a[i].hoten);
		printf("gioi tinh: ");scanf("%s",&a[i].gioitinh);
		printf("ngay sinh, thang sinh, nam sinh(dd/mm/yy):  ");scanf("%d%d%d",&a[i].ngaysinh.ngay,&a[i].ngaysinh.thang,&a[i].ngaysinh.nam);
		fflush(stdin);
		printf("dia chi: ");gets(a[i].diachi);
		printf("nhap so mon: ");scanf("%d",&a[i].somonhoc);
		int somon=a[i].somonhoc;
		for (int j=0;j<somon;j++){
			printf("nhap ma mon hoc thu %d:   ",j+1);scanf("%s",&a[i].mon[j].mamon);
			printf("nhap diem cua mon hoc thu %d:  ",j+1);scanf("%f",&a[i].mon[j].diem);
		}
		
	}
}
void nhaplophoc(LOP_HOC* lop){
	printf("nhap ma lop: ");scanf("%s",&lop->malop);
	printf("\nnhap ten lop: ");scanf("%s",&lop->tenlop);
	printf("\nnhap si so: ");scanf("%d",&lop->siso);
	nhap(lop->a,lop->siso);
	
}
void xuat(sv a[], int n,FILE *p){
	for (int i=0;i<n;i++){
		fprintf(p,"\nthong tin cua sinh vien %d\n",i+1);
		fprintf(p,"mssv: %s\n",a[i].mssv);
		fprintf(p,"ho ten: %s\n",a[i].hoten);
		fprintf(p,"gioi tinh: %s\n",a[i].gioitinh);
		fprintf(p,"ngay sinh:   ");fprintf(p,"ngay %d, thang %d, nam %d\n",a[i].ngaysinh.ngay,a[i].ngaysinh.thang,a[i].ngaysinh.nam);
		fprintf(p,"dia chi:%s \n",a[i].diachi);
		for (int j=0;j<a[i].somonhoc;j++){
			fprintf(p,"ma mon hoc thu %d: %s\n",j+1,a[i].mon[j].mamon);
			fprintf(p,"diem cua mon hoc thu %d: %.1f\n",j+1,a[i].mon[j].diem);
		}
		
	}
}
void xuatlophoc(LOP_HOC lop, FILE *p){
	fprintf(p,"ma lop: %s",lop.malop);
	fprintf(p,"\nten lop: %s",lop.tenlop);
	fprintf(p,"\nsi so: %d",lop.siso);
	fprintf(p,"\nthong tin cua cac sinh vien \n");
	xuat(lop.a,lop.siso,p);
	
}

int main(){
	int n;
	printf("nhap so luong lop: ");scanf("%d",&n);
	LOP_HOC lop[n];
	for (int i=0;i<n;i++){
		printf("nhap thong tin lop hoc thu %d\n",i+1);
		nhaplophoc(&lop[i]);
	}
	FILE *p;
	char path[100];
	printf("nhap duong dan: ");
	scanf("%s",path);
	p=fopen(path,"wb");
	for (int i=0;i<n;i++){
		fprintf(p,"\nthong tin lop hoc thu %d\n",i+1);
		xuatlophoc(lop[i],p);
	}
	fclose(p);
	return 0;
}
