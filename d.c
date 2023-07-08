#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    
    int i,*p,a[4]={11,22,33,44};
    p=a;
    *p++=66;
    *++p=77;
    (*p)--;
    *(p+1)=55;
    for (i=0;i<4;i++)
        printf("%d  ",a[i]);
    return 0;
    
}
