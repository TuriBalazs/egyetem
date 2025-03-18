#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;
/*
#define PI 3.14159


struct Tanulok
{
	char nev[25];
	int szEv, tankor;
};


int darab();
int* letrehoz(int);
void beker(int*, int);
void kiir(int*, int);
int otos(int*, int);
void jegyek(int*, int);


inline double atvalt(double fok);
double terulet(double a, double b, double gamma);


double terulet(int a, int b);
double terulet(float a, float b);
double terulet(double a, double b);
*/

int* LottoHuzas(int);
void kiir(int*, int);


int main() {
/*
	int db = darab();
	int* p = letrehoz(db);

	beker(p, db);
	kiir(p, db);

	cout << "Otosok szama: " << otos(p, db) << endl;

	jegyek(p, db);

	delete[] p;


	ifstream be("tanulo.dat", ios::binary);
	if (be.fail())
	{
		cerr << "Hiba a fajl megnyitasakor!" << endl;
		return -1;
	}
	Tanulok tanulo;

	while (!be.eof()) {
		be.read((char*)&tanulo, sizeof(tanulo));
		if (be.eof())
		{
			cout << setw(25) << tanulo.nev << setw(6) << tanulo.szEv << setw(6) << tanulo.tankor << endl;
		}
	}
	be.close();
	double a, b, gamma;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "gamma = ";
	cin >> gamma;
	cout << "Terulet = " << terulet(a, b, gamma) << endl;
	

	cout << terulet(20, 5) << endl;
	cout << terulet(20.5, 5.5) << endl;
	float x = 20.55, y = 5.55;
	cout << terulet(x, y) << endl;
	//cout << terulet((float)20.5, (float)5) << endl;
	*/
	while (true) {
	int lotto;

	cout << "Hanyas lottot jatszik? (5,6,7): ";
	do
	{
		cin >> lotto;
	} while (lotto > 7 || lotto < 5);
	

	int* p = LottoHuzas(lotto);

	kiir(p, lotto);

	delete[] p;
	}
	

	return 0;
}

/*

int darab() {
	int n;
	cout << "Adja meg a jegyek szamat: ";
	cin >> n;
	return n;
}

int* letrehoz(int n) {
	int* t = new int[n];
	return t;
}

void beker(int* t, int n) {
	for (int i = 0; i < n; i++)
	{
		do
		{
			cout << " Adja meg a(z) " << i + 1 << ". jegyet: ";
			cin >> t[i];

		} while (t[i]>5 || t[i] < 1);
	}
}

void kiir(int* t, int n){
	system("cls");
	cout << "A rogzitet jegyek: " << endl;
	cout.setf(ios::left);
	cout << setw(5) << "Ssz" << setw(5) << "Jegy" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(5) << i + 1 << setw(5) << t[i] << endl;
	}
	cout << endl;
}

int otos(int* t, int n) {
	int otosok = 0;
	for (int i = 0; i < n; i++)
	{
		if (t[i] == 5)
		{
			otosok++;
		}
	}
	return otosok;
}

void jegyek(int* t, int n) {
	int *jegy = new int[5];
	for (int i = 0; i < 5; i++) { jegy[i] = 0; }

	for (int i = 0; i < n; i++)
	{
		switch (t[i])
		{
		case 1: jegy[0]++; break;
		case 2: jegy[1]++; break;
		case 3: jegy[2]++; break;
		case 4: jegy[3]++; break;
		case 5: jegy[4]++; break;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << " Jegybol: " << jegy[i] << " db kerult rogzitesre!" << endl;
	}
	delete[] jegy;
}

inline double atvalt(double fok) {
	return fok * PI / 180;
}

double terulet(double a, double b, double gamma) {
	return a * b * sin(atvalt(gamma)) /2;
}


double terulet(int a, int b) { return a * b; }
double terulet(float a, float b) { return a * b; }
double terulet(double a, double b) { return a * b; }
*/

int* LottoHuzas(int t) {
	srand((unsigned)time(NULL));
	int* lottoszamok = new int[t];
	if (!lottoszamok)
	{
		cerr << "Hiba nincs eleg memoria!" << endl;
		exit(-1);
	}
for (int i = 0; i < t; i++)
		{
	switch (t)
	{
	case 5: lottoszamok[i] = rand() % 90 + 1; break;
	case 6: lottoszamok[i] = rand() % 45 + 1; break;
	case 7: lottoszamok[i] = rand() % 35 + 1; break;
	}
	for (int j = 0; j < i; j++)
	{
		if (lottoszamok[i] == lottoszamok[j]) { i--; break; }
	}

}
	return lottoszamok;
}

void kiir(int* t, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << t[i] << "\t";
	}
	cout << endl;
}