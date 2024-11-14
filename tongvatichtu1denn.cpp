#include <stdio.h>
int main(){
	long long s=0,p=1;
	int n;
	do{
		printf("nhap n=");
		scanf("%d",&n);
	}while(n<=0);
	s=(n+1)*n/2;
	for (int i=1;i<=n;i++){
		p*=i;
	}
	printf("tong la: %lld\n",s);
	printf("tich la: %lld",p);
	return 0;	
}
