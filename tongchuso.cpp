#include <stdio.h>
int main(){
	int n;
	printf("nhap n=");
	scanf("%d",&n);
	int s=0;
	while (n!=0){
		s+=n%10;
		n/=10;
	}
	printf("%d",s);
	return 0;
}
