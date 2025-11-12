#include <stdio.h>
#include <stdlib.h>

typedef int (*opHandler)(int, int);

struct Operands {
        char op;
        opHandler handler;
};

int add( int a, int b) { return a + b; }
int sub( int a, int b) { return a - b; }
int mul( int a, int b) { return a * b; }
int div2( int a, int b) { return a / b; }


int main(int argc, char** argv) {
 if( argc != 4) {
        printf("hiba, pontosan 3 paraméterszükséges");
        printf("%s N op M\n", argv[0]);
        return 1;
 }

 struct Operands ops[] = {
        {'+', add},
        {'-', sub},
        {'*', mul},
        {'/', div2}
 };

 const unsigned N = sizeof(ops) / sizeof(struct Operands);

 int a = atoi(argv[1]);
 int b = atoi(argv[3]);
 int result;

 int i = 0;
 while( i < N && ops[i].op != argv[2][0] ) i++;
 if( i < N ) {
        result = ops[i].handler(a, b);
        printf("result: %d\n", result);
 }
 else {
        printf("nem ismertmüvelet!\n");
        return 2;
 };
/*
 switch( argv[2][0] ) {
        case '+': {
        result = a + b;
        break;
        }
        case '-': {
        result = a - b;
        break;
        }
        case '*': {
        result = a * b;
        break;
        }
        case '/': {
        result = a / b;
        break;
        }
        default: {
        printf("nem ismertmüvelet!\n");
        return 2;
 }

 }
*/

 return 0;
}

