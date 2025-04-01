#include <iostream>


/*
void sum(int a, int b) {
	_asm {
		mov eax, a;
		add eax, b;
	}
}
*/


int main() {
	/*
	int s;
	char b;
	sum(10, 20);
	_asm {
		mov s, eax;
	}


	_asm {
		mov eax, 10;
		mov ebx, 20;
		mov esi, esp;
		push s;
		push b;
		call sum;
		mov esp, esi;
		pop ah;
		pop ebx;


	}
	*/

	int t[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	// int* t = new int[1];
	printf("%d", t[0]);
	printf("\n%d", *t);
	printf("\n%d", *t + 1);
	//printf("\n%d", *(t + 1 * sizeof(int)));
	printf("\n%d", *(9 + t));
	printf("\n%d", 9[t]);						// Ne használjátok csak érdekesség




	return 0;
}