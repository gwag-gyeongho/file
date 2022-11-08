#include <stdio.h>
#define SIZE 10

int main(){
	int list[SIZE]={3,2,9,7,1,4,8,0,6,5};

	int i,j,temp,max;

	for(i=0;i<SIZE-1;i++){
		max=i;
		for(j=i+1;j<SIZE;j++){
			if(list[j]>list[max]){
				max=j;
			}
		}
		temp=list[i];
		list[i]=list[max];
		list[max]=temp;

	}
	for(i=0;i<SIZE;i++){
		printf("%d ",list[i]);
	}
	printf("\n");

	return 0;
}

