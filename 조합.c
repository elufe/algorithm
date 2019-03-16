#include <stdio.h>

void f(int arr[],int n,int m,int index,int c);

int main(){

	int n,m;
	scanf("%d %d",&n,&m);
	int arr[n];
	for(int i=0;i<n;i++){
		arr[i]=0;
	}
	f(arr,n,m,0,0);
}

void f(int arr[],int n,int m, int index,int c){
	if(c==m){
		for(int i=0;i<n;i++){
			if(arr[i]!=0)
			printf("%c",i+'A');
		}
		printf("\n");
		return;

	}
	else if(index>=n)
		return;
	
	
	arr[index]=1;
	f(arr,n,m,index+1,c+1);
	arr[index]=0;
	f(arr,n,m,index+1,c);

}
