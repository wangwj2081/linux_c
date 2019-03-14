#include <stdio.h>
#include <stdlib.h>
extern int add(int a, int b);
extern int sub(int a, int b);

int main(void){
    int a = 5;
    int b = 3;
    printf("Hello: %d+%d=%d, %d-%d=%d\n", a,b,add(a,b), a,b,sub(a,b));  
    return 0;  
}  

