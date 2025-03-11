#include <iostream>
#include <stdlib.h>
#include <time.h>

int random(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int main() {
	srand(time(NULL));
	char a = random(0, 255), b = random(0, 255);

	// 00010000
	// 00001010
	// xor
	// 00011010
	//
	// 8, 10
	// 00001000
	// 00001010
	// 00000010

/*
	_asm {
		rdrand al;
		and eax, 0xFF;
		mov bl, 255;	// max
		sub bl, 100;	// max - min
		inc bl;			// max - min + 1
		mov edx, 0;
		idiv bl;			// rand() % (max - min + 1)
		mov bl, ah;
		add bl, 100;	// rand() % (max - min + 1) + min

		mov ebx, 0;
		rdrand al;
		mov ah, 0;
		mov cl, 255;	// max
		sub cl, 100;	// max - min
		inc cl;			// max - min + 1
		mov edx, 0;
		idiv cl;			// rand() % (max - min + 1)
		mov al, ah;
		add al, 100;	// rand() % (max - min + 1) + min

		xor al, bl;

		mov ecx, 8;
		mov ebx, 0;
	CIKLUS:
		rcr al, 1;
		adc ebx, 0;
		loop CIKLUS;

	}
*/

	_asm {
		mov eax, 96;
		mov ebx, 17;
		mov edx, 0;
		div bx;

		mov ax, 500;
		mov bx, 1700;
		mul bx;

		shl edx, 16;
		and eax, 0xFFFF;
		or eax, edx;
	}

}