#include <stdio.h>
int min(int a, int b){
	if (a<b) return a;
	return b;
}
int main(){
	int a,b;
	printf("nhap hai so nguyen: ");
	scanf("%d %d",&a,&b);
	printf("so nho nhat trong hai so la: %d",min(a,b));
	return 0;
}
