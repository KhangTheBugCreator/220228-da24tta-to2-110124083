#include <stdio.h>
int tongchusodequy(int n){
	if (n<10) return n;
	else return n%10+tongchusodequy(n/10);
}
int main(){
	int n;
	scanf("%d",&n);
	printf("tong chu so cua n=%d",tongchusodequy(n));
	return 0;
}
