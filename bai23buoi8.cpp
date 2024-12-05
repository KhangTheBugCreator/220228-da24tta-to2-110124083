#include<string.h>
#include<stdio.h>
struct CON_NGUOI{
	char hoten[30], diachi[100], gioitinh[4];
	int tuoi;
	float thunhap;
};
typedef struct CON_NGUOI CN;

void nhap(CN *a);
void xuat(CN a);

int main()
{
	CON_NGUOI a, b;
	nhap(&a);
	printf("\nThong tin vua nhap la: \n");
	xuat(a);
	return 0;
}
void xuat(CN a)
{
	printf("ten: %s\n",a.hoten);
	printf("dia chi: %s\n",a.diachi);
	printf("gioi tinh: ");
	puts(a.gioitinh);
	printf("tuoi: %d\n",a.tuoi);
	printf("thu nhap: %.2f\n",a.thunhap);
	
}
void nhap(CN *a)
{
	//Nhap thanh phan ho ten
	printf("\nNhap vao ho ten: ");
	fflush(stdin);
	gets(a->hoten);
	//Nhap thanh phan dia chi
	printf("nhap vao dia chi: ");
	gets(a->diachi);
	//Nhap thanh phan gioi tinh
	printf("nhap vao gioi tinh: ");
	scanf("%s",&a->gioitinh);
	//Nhap thanh phan tuoi
	printf("Hay cho biet tuoi: ");
	scanf("%d", &a->tuoi);
	//Nhap thanh phan thu nhap
	printf("Hay cho biet thu nhap: ");
	scanf("%f",&a->thunhap);
}
