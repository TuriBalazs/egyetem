#include <stdio.h>
#include <unistd.h>

int main() {

 printf("Hello [%u] -> [%u]\n", getppid(), getpid());


 int i = 0;
 for( ; i < 20 && fork(); i++ );
 if(i == 2){
        printf("Szülő %d [%u] -> [%u]\n", i, getppid(), getpid());
 }
else if(i % 2 == 0){
        printf("Páros %d [%u] -> [%u]\n", i, getppid(), getpid());
 }
else{
        printf("Páratlan %d [%u] -> [%u]\n", i, getppid(), getpid());
 }



 return 0;
 }
