#include <stdio.h>
void hanoi_tower(int n, char from, char tmp, char to)
{
   if( n==1 ) 
        printf("Move disc 1 from %c to %c.\n", from, to); 
   else {
        hanoi_tower(n-1, from, to, tmp);
        printf("Move %d disc(s) from %c to %c.\n", n, from, to);
        hanoi_tower(n-1, tmp, from, to);
   }
}

int main(){
    hanoi_tower(3,'a','b','c');
    return 0;
}