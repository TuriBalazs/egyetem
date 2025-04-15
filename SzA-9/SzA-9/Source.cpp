#include <iostream>

// FPU


int main() {
	int a = 10, b = 5, c = 3, d = 2;
	double alap;
	double result = 3.0 - 2 + 1;
	_asm {
		/*
		
		fldz; - 0-át rak a verem tetejére
		fld1; - 0.1-et rak a verembe
		fldpi; - PI-t rak a verembe
		fild; - intet rak a verembe
		fstp a; - leveszi a stack tetejéröl az ertéket
		fistp c;
		fst b;
		fmul;
		fdiv;
		fadd;
		fsubb;

		3 - 2 + 1:
		fild a;
		fild b;
		fsub;
		fld1;
		fadd;

		3 - ( 2 + 1 ):
		fild a;
		fild b;
		fld1;
		fadd;
		fsub;

		fld1;
		fild d;
		fild c;
		fsub;
		fdiv;
		fild b;
		fild a;
		fild a;
		fmul;
		fadd;
		fmul;
		fsqrt;
		

		*/

		fild c;
		fild d;
		fsub;
		fild c;
		fild d;
		fadd;
		fild c;
		fild d;
		fadd;
		fmul;
		fmul;
		fild a;
		fild b;
		fdiv;
		fdiv;
		fsqrt;

		fst alap;
		fld alap;
		
		fmul


		
		fstp result
	}
	printf("Result=%.2lf\n", result);
	return 0;
}