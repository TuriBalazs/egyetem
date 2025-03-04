#include <iostream>
#include <ctime>

using namespace std;

//double Atlag(int*, int);
//void Csere(int& , int& );
//void Feltolt(int[], int);
//void Kiir(int[], int);
//int Max(int[], int);
void Beker(int*, int);
float Kiir(int*, int);
void Rendez(int*, int);

int main() {
	srand((unsigned)time(NULL));
	/*int jegyek[10] = {1, 1, 1, 1, 2, 2, 3, 4 ,5 ,5};
	int pontok[10] = {15, 25, 35, 45, 55, 65, 75, 85, 95, 100 };
	cout << "A jegyek atlaga: " << Atlag(jegyek, 10) << endl;
	cout << "A pontok atlaga: " << Atlag(pontok, sizeof(pontok)/sizeof(pontok[0])) << endl;
	int szam1, szam2;

	cout << "Agy meg 2 szamot: ";
	cin >> szam1 >> szam2;
	cout << "A szamok csere elöt: " << szam1 << ", " << szam2 << endl;
	Csere(szam1, szam2);
	cout << "A szamok csere utan: " << szam1 << ", " << szam2 << endl;
	
	int db;

	do
	{
		cout << "Adja meg a letszamot: (1-10) ";
		cin >> db;
	} while (db > 10 || db < 1);

	int* pontok = new int[db];
	Feltolt(pontok, db);
	Kiir(pontok, db);
	cout << "\nA legjobb pont: " << Max(pontok, db) << endl;

	delete[] pontok;*/
	int* tmb, lsz;
	do
	{
		cout << "Adja meg a letszamot: (1-15) ";
		cin >> lsz;
	} while (lsz > 10 || lsz < 1);
	
	tmb = new int[lsz];
	Beker(tmb, lsz);
	system("cls");
	cout << "Magassagok: " << endl;
	cout << "A csoport atlagos magassaga: " << Kiir(tmb, lsz);
	cout << "A rendezett magassagok: " << endl;
	Rendez(tmb, lsz);
	Kiir(tmb, lsz);
	delete[] tmb;


	return 0;
}
/*double Atlag(int* t, int db) {
	double osszeg = 0;
	for (int i = 0; i < db; i++)
	{
		osszeg += t[i];
	}
	return osszeg / db;
}
void Csere(int& a, int& b) {
	int seged = a;
	a = b;
	b = seged;
}
void Feltolt(int t[], int n) {
	for (int i = 0; i < n; i++)
	{
		t[i] = rand() % 100 + 1;
	}
}

void Kiir(int t[], int n) {
	cout << "A csoport pontjai: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << t[i] << "\t";
	}
}

int Max(int t[], int n) {
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (t[i] > max) { max = t[i]; }		
	}
	return max;
}*/

void Beker(int* t, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "Adja meg az " << i + 1 << ". szemely magassagat: ";
		cin >> t[i];
	}
}

float Kiir(int* t, int n) {
	float osszeg = 0;
	for (int i = 0; i < n; i++)
	{
		osszeg += t[i];
		cout << i + 1 << ". szamely magassaga: " << t[i] << endl;
	}
	return osszeg / n;
}

void Rendez(int* t, int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++) {
			if (t[i] > t[j])
			{
				int csere = t[i];
				t[i] = t[j];
				t[j] = csere;
			}
		}
	}
}