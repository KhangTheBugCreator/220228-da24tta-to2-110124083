#include <stdio.h>
int main(){
	char pt;
	int a,b;
	printf("nhap vao hai so nguyen(a>b): ");
	scanf("%d %d",&a,&b);
	printf("nhap vao phep tinh( + - * /): ");
	fflush(stdin);
	scanf("%c",&pt);
	switch(pt){
		case '+':
			printf("%d+%d=%d",a,b,a+b);
			break;
		case '-':
			printf("%d-%d=%d",a,b,a-b);
			break;
		case '*':
			printf("%d*%d=%lld",a,b,1ll*a*b);
			break;
		case '/':
			printf("%d/%d=%.2f",a,b,1.0*a/b);
			break;
	}
	return 0;
}
