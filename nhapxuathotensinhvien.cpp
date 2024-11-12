#include <stdio.h>

int main(){
	char mssv[20], hoten[50], lop[10];
	int namsinh;
	float diemxettuyen;
	printf("nhap ma so sinh vien: ");
	fflush(stdin);
	gets(mssv);
	printf("nhap ho ten: ");
	fflush(stdin);
	gets(hoten);
	printf("nhap lop: ");
	gets(lop);
	printf("nhap nam sinh: ");
	scanf("%d",&namsinh);
	printf("nhap diem xet tuyen: ");
	scanf("%f",&diemxettuyen);
	printf("%s %s %s %d %.2f ",mssv,hoten,lop,namsinh,diemxettuyen);
	return 0;
	
}
