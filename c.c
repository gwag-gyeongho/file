#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

void pnp (char x, char y, char z, int n){
    if (n>0){
        printf("%c%d ",y,n);
        pnp(y,z,x,n-1);
        printf("%c%d ",z,n);
    }
}

int main(){
    pnp('A','B','C',3);
    printf("\n");
    int i, *pi,a[20],n=20,k;
    i=123;
    pi=&i;
    *pi=314;
    for(k=0;k<n;k++)
    a[k]=2*k;
    printf("i:%d, pi:%d, a[7]:%d, *(a+20):%d",i,pi,a[7],*(a+20));
    return 0;
}