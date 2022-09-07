#include <stdio.h>

int main(){
    int a =0,i=0,j=0;
    scanf("%d",&a);

    for(i=0;i<a;i++){
        int b=0,c=0,num=1;
        scanf("%d %d",&b,&c);
        for(j=0;j<c;j++){
            num*=b;
            num%=10;
        }
        if(num==0){
            printf("10\n");
        }
        else{
            printf("%d\n",num);
        }
    }

    return 0;
}