#include <stdio.h>

int main(){
	FILE *fo;
	char path[50];
	int n;
	printf("nhap n=");scanf("%d",&n);
	int a[n];
	for (int i=0;i<n;i++){
		printf("nhap phan tu thu %d: ",i+1);scanf("%d",a+i);
	}
	printf("nhap duong dan: ");
	fflush(stdin);
	gets(path);
	fo=fopen(path,"w");
	if (fo==NULL) printf("khong tim thay file");
	else{
		fprintf(fo,"so luong phan tu la: %d\n",n);
		for (int i=0;i<n;i++){
			fprintf(fo,"A[%d]=%d\n",i+1,a[i]);
		}
	}
	fclose(fo);
	return 0;
}
