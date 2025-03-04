#include <iostream>

int main() {

	
	// léptetõ / forgató utasítások
	//char a = 128 << 7;
	/*
	_asm {
		
		mov al, 128;
		shl al, 1;

		mov bl, 128;
		sal bl, 1;

		mov al, 128;
		shr al, 2;
		mov a, al;

		mov bl, 128;
		sar bl, 2;
		mov b, bl;
		

		mov al, 128;
		ror al, 3;
		ror al, 2;
		ror al, 1;
		ror al, 2;

		mov bl, 128;
		rol bl, 3;
		rol bl, 2;
		rol bl, 1;
		rol bl, 2;

		mov al, 128;
		rcr al, 1;
		rcr al, 1;
		rcr al, 2;
		rcr al, 4;

		mov bl, 128;
		rcl bl, 1;
		rcl bl, 1;
		rcl bl, 2;
		rcl bl, 4;

	}
	*/
	//printf("%d", a);
	//printf("\n%d", b);

	// hamming-súly számítás
	// C
	char nmb = 120, hamming = 0;
	printf("%d (10) = (2): ", nmb);
	for (int i = 0; i < sizeof(char) * 8; i++)
	{
		char bit = (nmb << i >> 7) & 1;
		printf("%d ", bit);
		hamming += bit;
	}
	printf("\nHamming-suly: %d\n", hamming);
	
	// asm
	_asm {
		mov al, 120;
		clc;
		stc;
		mov ebx, 0;

		mov ecx, 8;
	CIKLUS:
		rcr al, 1;
		adc ebx, 0;
		loop CIKLUS;

	}

}