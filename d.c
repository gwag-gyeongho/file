#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 16

void descending_order_sort(int list[],int size);
int binary_search(int list[],int n, int key);

int main(){
    int key=0;
    int list[SIZE]={2,6,11,13,18,20,22,27,29,30,34,38,41,42,45,47};
    descending_order_sort(list,SIZE);
    scanf("%d",&key);
    printf("Å½»ö°á°ú: %d",binary_search(list,SIZE,key));

    
    return 0;
}

void descending_order_sort(int list[], int size){
    int i,j,temp,max;

	for(i=0;i<size-1;i++){
		max=i;
		for(j=i+1;j<size;j++){
			if(list[j]>list[max]){
				max=j;
			}
		}
		temp=list[i];
		list[i]=list[max];
		list[max]=temp;

	}
	for(i=0;i<size;i++){
		printf("%d ",list[i]);
	}
	printf("\n");

}

int binary_search(int list[],int n,int key){
    int low,high,middle;

    low =0;
    high=n-1;

    while(low<=high){
        printf("[%d %d]\n", low,high);
        middle = (low+high)/2;
        if(key==list[middle]){
            return middle;
        }
        else if(key<list[middle]){
            low = middle +1;}
        else{
            high=middle -1;
    }
    }
    return -1;
}