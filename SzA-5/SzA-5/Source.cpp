#include <iostream>

int main() {

	// **Gondoltam Egy Sz�mra**
	// kital�lunk gy sz�mot 1-100 k�z�tt
	// v�rakozunk egy tipp be�rkez�s�re (bek�r�s)
	// Eld�ntj�k hogy a kital�ltsz�m egyenl� e a kapott �rt�kkel
	// Ha igen, akkor nyert
	// ha nem, akkor megmongyuk hogy kissebb vagy nagyobb e a kapot sz�m �sa j�t�k megy tov�bb
	// vissza a bek�r�sig
	/*
	srand((unsigned)time(NULL));
	int MyNmb = rand() % 100 + 1;
	int choice;
	printf("Gondoltam Egy Szamra!\n");
	do
	{
		scanf_s("%d", &choice);
		if (MyNmb == choice)
		{
			printf("Gratulalok nyertel!\n");
			break;
		}
		else
		{
			if (MyNmb < choice)
			{
				printf("Kisseb ennel!\n");
			}
			else
			{
				printf("Nagyobb ennel!\n");
			}
		}
	} while (1);
	*/


	int MyNmb;
	_asm {
		rdrand eax;
		mov edx, 0;
		mov ebx, 100;
		div ebx;
		inc edx;
		mov MyNmb, edx;
	}
	int choice;
	printf("Gondoltam Egy Szamra!\n");
	
	_asm {
	CIKLUS:
	}
	scanf_s("%d", &choice);
	_asm {
		mov eax, MyNmb;
		mov ebx, choice;
		cmp eax, ebx;
		je MNE_TRUE;
		jl MNL_TRUE;
		jg MNL_FALSE;
	MNE_TRUE:
	}
	printf("Gratulalok nyertel!\n");
	_asm {
		jmp END_OF_MNE;

	MNL_FALSE:
	}
	printf("Nagyobb ennel!\n");
	_asm {
		jmp END_OF_MNL;

	MNL_TRUE:
	}
	printf("Kissebb ennel!\n");
	_asm {
	END_OF_MNL:
		jmp CIKLUS;

	END_OF_MNE:
	}


	return 0;
}