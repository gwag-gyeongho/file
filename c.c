#include <stdio.h>
int gcd(int x,int y);
int lcm(int x,int y);
void getGcdLcm(int x,int y,int *gcd,int *lcm);

int main(){
    int x,y,ggcd,llcm;
    scanf("%d %d",&x,&y);
    
    getGcdLcm(x,y,&ggcd,&llcm);
    printf("gcd: %d, lcm:%d\n",ggcd,llcm);

	return 0;
}

int gcd(int x,int y){
    while(x!=y){
        if(x>y){
            x-=y;
        }
        else{
            y-=x;  
        }
    }
    return x;
}

int lcm(int x,int y){
    int ggcd;
    return x*y/gcd(x,y);
}

void getGcdLcm(int x,int y,int *gcd,int *lcm){
    int a,b;
    a=x;
    b=y;
    while(x!=y){
        if(x>y){
            x-=y;
        }
        else{
            y-=x;  
        }
    }
    *gcd=x;

    *lcm=a*b/x;
}