#include<stdio.h>

void f(int arr[],  int n, int m, int index, int aaa);

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int arr[n];
	for(int i=0;i<n;i++){
		arr[i]=0;
	}
	f(arr,n,m,0,0);
}

void f(int arr[], int n, int m, int index,int aaa){


	if(index==m){
		for(int i=0;i<n;i++){
			if(arr[i]!=0){
				printf("%c",arr[i]+'A'-1);
			}
		}
		printf("\n");
		return;
	}
	else if(index>m)
		return;

	for(int i=1;i<=n;i++){
		for(int j=0;j<index;j++){
		if(arr[j]==i)
			aaa=1;
		}
		if(aaa==0){
		arr[index]=i;
		f(arr,n,m,index+1,0);
		}
		aaa=0;
	}
}

