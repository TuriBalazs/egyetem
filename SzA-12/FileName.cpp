#include <iostream>


int main() {
	int A, B;
	int meret = 1000;
	double TMB[1000];
	int temp;
	double result;
	const char* fmt_kiir = "%d\t", * fmt_result = "Result=%.2lf\n", * fmt_be = "%d", * fmt_szovegA = "A: ", * fmt_szovegB = "B: ";


	_asm {
	ADAT_BEKER:
		mov esi, esp;
		push fmt_szovegA;
		call dword ptr printf;
		pop fmt_szovegA;
		lea eax, A;
		push eax;
		push fmt_be;
		call dword ptr scanf;

		push fmt_szovegB;
		call dword ptr printf;
		pop fmt_szovegB;
		lea eax, B;
		push eax;
		push fmt_be;
		call dword ptr scanf;
		mov esp, esi;


		mov ecx, A;
		cmp ecx, B;
		jge ADAT_BEKER;

		mov ecx, 1000;
		mov esi, 0;
	CIKLUS_FELTOLT:
		push ecx;
		push esi;
		rdrand eax;
		mov ebx, B;
		sub ebx, A;
		inc ebx;
		mov edx, 0;
		div ebx;
		add edx, A;
		mov temp, edx;
		fild temp;
		fstp TMB[esi];

		push edx;
		push fmt_kiir;
		call dword ptr printf;
		pop fmt_kiir;
		pop edx;

		pop esi;
		pop ecx;
		add esi, 8;
		loop CIKLUS_FELTOLT;
	
		fild TMB[0];
		fild TMB[0];
		fmul;
		mov ecx, 999;
		mov esi, 8;
	CIKLUS_SUM:
		fild TMB[esi];
		fild TMB[esi];
		fmul;
		fadd;
		add esi, 8;
		loop CIKLUS_SUM;
		
		fild meret;
		fdiv;
		fsqrt;
		fstp result;



	}
	printf("\nResult=%.2lf\n", result);

	return 0;
}