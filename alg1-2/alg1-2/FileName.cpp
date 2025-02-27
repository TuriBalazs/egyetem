#include <iostream>


using namespace std;

int main() {

	//tömb létrehozása, feltöltése
	int pontok[15] = { 7, 34, 56, 4, 57, 45, 67, 6, 43, 32, 33, 99, 33, 100, 11 }; 
	int i = 15;

	//pontok kiírása
	for (i = 0; i < 15; i++)
	{
		cout << i+1 << ". hallgato: " << pontok[i] << endl;
		
	}

	// pontszámok átlaga - összegzés tétele
	int avg = 0;
	for (i = 0; i < 15; i++) {
	avg = avg + pontok[i];
	}
	cout << "A pontszamok atlaga: " << (float)avg / i << endl;

	//volt-e 100 pont - eldöntés tétele
	i = 0;
	while (i < 15 && pontok[i] != 100) {
		i++;
	}
	if (i < 15) {
		cout << "Van ";
	}
	else {
		cout << "Nincs ";
	}
	cout << "100 pontos" << endl;

	// 57 pontos - kiválasztás tétele
	i = 0;
	while (pontok[i] != 57) {
		i++;
	}
	cout << "57 pontos: " << i + 1 << ". hallgato" << endl;

	//bekért pontszám kérése - lineáris keresés tétele
	int p = 0;
	do
	{
		cout << "kerek egy pontszamot(0-100): ";
		cin >> p;
	} while (p<0 || p > 100);
	i = 0;
	while (i < 15 && pontok[i] != p) {
		i++;
	}
	if (i < 15) {
		cout << "A keresett (" << p << ") pontszamu hallgato sorszama: " << i + 1 << endl;
	}
	else {
		cout << "Nincs ilyen pontszam a tombbe." << endl;
	}

	// sikeres vizsgák száma - megszámlálás tétele
	int siker = 0;
	for (i = 0; i < 15; i++)
	{
		if (pontok[i] > 50)
		{
			siker++;
		}
	}
	cout << "A skiresen viszgazok szama: " << siker << endl;

	// legalább 4-est elérõ hallgatók - kiválogatás tétele
	int t4[15];
	int j = 0;
	for (i = 0; i < 15; i++)
	{
		if (pontok[i] > 75)
		{
			t4[j] = i + 1;
			j++;
		}
	}
	cout << "a 4-est elero tanulok sorszamai: ";
	for (i = 0; i < j; i++)
	{
		cout << t4[i] << ". ";
	}
	cout << endl;

	//legkevesebb pontot elért hallgató - minimum kiválasztás tétele
	int mini = 0;
	for (i = 0; i < 15; i++)
	{
		if (pontok[i] < pontok[mini]) {
			mini = i;
		}
	}
	cout << "legkevesebb pont: " << mini + 1 << ". hallgato, " << pontok[mini] << endl;

	// csere
	int temp = 0;
	temp = pontok[2];
	pontok[2] = pontok[9];
	pontok[9] = temp;
	for (i = 0; i < 15; i++)
	{
		cout << i + 1 << ". hallgato: " << pontok[i] << endl;

	}
	/*
	házi 
	Két kockával dobunk egyszerre, egymásután 100 – szor.
	A dobások értékeit[2;12] töltsünk fel egy tömbbe és írassuk ki a képernyõre
	(soronként 10 dobás)!
	10, 9, 11, 3, 7, 12, 5, 4, 2, 6
	9, 5, 11, … stb.
	Számítsuk ki a dobások átlagát!
	Volt-e 10-es dobás?
	Páratlan, páros dobások száma?
	Melyik dobásból, hány darab volt?
	2: 3 db
	3: 1 db …
	Hányadik dobás a legnagyobb?
	Gyûjtsük össze egy tömbbe majd írassuk ki, a 12-s dobások sorszámait!
	*/
	return 0;
}