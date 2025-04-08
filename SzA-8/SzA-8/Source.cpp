#include <iostream>

int main() {
	/*
	int t[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	// *(t + 1)
	// *(t + i * sizeof(int))
	int value = 0;
	const char* fmt_kiir = "t[%d] = %d\n";
	
	for (int i = 10; i > 0; i--)
	{
		value = t[10 - i];
		printf("t[%d] = %d\n", 10 - i, value);
	}
	*/
	int t[10];
	const char *fmt_beker = "Add meg a %d. elemet: ", *fmt_int = "%d", *fmt_result = "Osszeg: %d\nAtlag: %d";
	/*
	// adatbekérés
	for (int i = 0; i < 10; i++)
	{
		printf("Add meg a %d. elemet: ", i + 1);
		scanf_s("%d", &t[i]);
	}
	// összegzés
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += t[i];
	}
	int avg = sum / 10;

	//eredmény kiírása
	printf("Osszeg: %d\nAtlag: %d", sum, avg);
	*/
	_asm{
		/*
		mov ecx, 10;
		mov esi, 0;
	CIKLUS:
		
		mov eax, 10;
		sub eax, ecx;
		mov ebx, 4;
		mul ebx;
		

		mov ebx, [t + esi];
		mov value, ebx;

		//mov esi, ecx;
		push ecx;
		push esi;
		// mov esi, 9999;
	
		mov esi, 10;
		sub esi, ecx;
		push value;				// }
		push esi;				// }
		push fmt_kiir;			// }
		call dword ptr printf;	// } ---> printf("value: %d\n", value);
		pop fmt_kiir;			// }
		pop esi;				// }
		pop value;				// }

		//mov ecx, esi;
		pop esi;
		add esi, 4;
		pop ecx;
		loop CIKLUS;
		*/
		mov ecx, 10;
		mov esi, 0;
	CIKLUS:
		push ecx;
		mov eax, esi;
		add eax, 1;
		push eax;
		push fmt_beker;
		call dword ptr printf;
		pop fmt_beker;
		pop eax;

		mov eax, esi;
		mov ebx, 4;
		mul ebx;
		lea eax, [t + eax];
		push eax;
		push fmt_int
		call dword ptr scanf;
		pop fmt_int;
		pop eax;

		inc esi;
		pop ecx;
		loop CIKLUS;

		mov esi, 0;
		mov ecx, 10;
		mov edi, 0;
	CIKLUS_SUM:
		mov eax, edi;
		mov ebx, 4;
		mul ebx;
		add esi, [t + eax];
		inc edi;
		loop CIKLUS_SUM;

		mov eax, esi;
		mov edx, 0;
		mov ebx, 10;
		div ebx;
		push eax;
		push esi;
		push fmt_result;
		call dword ptr printf;
		pop fmt_result;
		pop esi;
		pop eax;
	}

}