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
void nhap(SINH_VIEN a[], int n){
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
void xuat(SINH_VIEN a[], int n){
	for (int i=0;i<n;i++){
		printf("\nthong tin cua sinh vien %d\n",i+1);
		printf("mssv: %s\n",a[i].mssv);
		printf("ho ten: %s\n",a[i].hoten);
		printf("gioi tinh: %s\n",a[i].gioitinh);
		printf("ngay sinh:   ");printf("ngay %d, thang %d, nam %d\n",a[i].ngaysinh.ngay,a[i].ngaysinh.thang,a[i].ngaysinh.nam);
		printf("dia chi:%s \n",a[i].diachi);
		for (int j=0;j<a[i].somonhoc;j++){
			printf("ma mon hoc thu %d: %s\n",j+1,a[i].mon[j].mamon);
			printf("diem cua mon hoc thu %d: %.1f\n",j+1,a[i].mon[j].diem);
		}
		
	}
}
int find(SINH_VIEN a[], int n, char mssvcantim){
	int check=-1;
	for (int i=0;i<n;i++){
		if ((long long)mssvcantim==(long long)a[i].mssv){
			check=i;
			break;
		}
	}
	return check;
}
void xuatsinhvienthu_i(SINH_VIEN a[], int i){
	printf("\nthong tin cua sinh vien %d\n",i+1);
	printf("mssv: %s\n",a[i].mssv);
	printf("ho ten: %s\n",a[i].hoten);
	printf("gioi tinh: %s\n",a[i].gioitinh);
	printf("ngay sinh:   ");printf("ngay %d, thang %d, nam %d\n",a[i].ngaysinh.ngay,a[i].ngaysinh.thang,a[i].ngaysinh.nam);
	printf("dia chi:%s \n",a[i].diachi);
	for (int j=0;j<a[i].somonhoc;j++){
		printf("ma mon hoc thu %d: %s\n",j+1,a[i].mon[j].mamon);
		printf("diem cua mon hoc thu %d: %.1f\n",j+1,a[i].mon[j].diem);
	}
}
int main(){
	int n;
	printf("nhap so luong sinh vien: ");
	scanf("%d",&n);
	printf("                        nhap thong tin cho cac sinh vien                       \n");
	SINH_VIEN a[n];
	nhap(a,n);
	printf("\n			thong tin cua cac sinh vien vua nhap                    \n");
	xuat(a,n);
	char mssvcantim;
	printf("\nnhap ma so sinh vien cua thong tin can tim: ");scanf("%s",&mssvcantim);
	if (find(a,n,mssvcantim)==-1){
		printf("\nkhong tim thay sinh vien nay");
	}
	else{
		xuatsinhvienthu_i(a,find(a,n,mssvcantim));
	}
	
	return 0;
}
