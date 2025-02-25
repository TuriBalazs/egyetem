#include <iostream>

int main() {

	/*
	Registerek:
		- EAX -> akkumulátor (worker)
		- EBX -> 
		- ECX -> counter (ciklus)
		- EDX -> dest.
		- ESI/EDI -> 
		- EIP -> IP (instr. pointer)
		- ESP -> stack pointer
		- EBP -> Bázis pointer
		- EFL -> flag register
		
	

	// int age; // -2*10^9 -> 2*10^9
	// char age; // -128 -> 127

	unsigned char age;  // 0 -> 255

	age = 99;
	printf("jucus: %hhu\n", age);
	age += 199;
	printf("jucus 99 ev mulva: %hhu\n", age);
	
	_asm {
		mov al, 99;
		mov bl, 156;
		add al, bl;
		add al, 1;
		add al, 1;
		add al, 1;
	}
	*/


	srand(time(NULL));
	char name[16];

	printf("Udvozollek a gondoltam egy szamra jatekba!\n");
	printf("Add meg a neved(max 15 karakter): ");

	//scanf_s("%s", &name);
	//getchar();

	//gondolunk egy szamot
	int number = rand() % 100 + 1;

	printf("Gondoltam egy szamot 1 es 100 kozott!\n");

	//jatek
	unsigned char choice, step = 0;
	do
	{
		printf("Tipp: ");
		scanf_s("%hhu", &choice);
		getchar();
		if (choice < number)
		{
			printf("Kissebb mint amit gondoltam\n");
		}
		else if (choice > number) {
			printf("Nagyobb mint amit gondoltam\n");
		}
		step++;
	} while (choice != number);

	printf("Nyertélt\nLepesek szama %hhu", step);

	return 0;

}