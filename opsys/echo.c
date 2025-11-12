#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
 if( argc < 2) {
        printf("Hiányzó paraméter");
        return 1;
 }

 int i = 1;
 while( i < argc && strcmp(argv[i], "-h") != 0) i++;
 if ( i < argc ){
        printf("#### HELP ####\n");
        printf("%s -h\t\tHELP\n", argv[0]);
        printf("%s TEXT\t\tTEXT -> STDOUT\n", argv[0]);
 } else {
        for( i = 1; i < argc; i++ ) {
                printf("%s ", argv[i]);
        }
 printf("\n");
 }

 return 0;
}
