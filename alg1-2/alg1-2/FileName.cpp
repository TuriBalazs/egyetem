#include <iostream>


using namespace std;

int main() {

	//t�mb l�trehoz�sa, felt�lt�se
	int pontok[15] = { 7, 34, 56, 4, 57, 45, 67, 6, 43, 32, 33, 99, 33, 100, 11 }; 
	int i = 15;

	//pontok ki�r�sa
	for (i = 0; i < 15; i++)
	{
		cout << i+1 << ". hallgato: " << pontok[i] << endl;
		
	}

	// pontsz�mok �tlaga - �sszegz�s t�tele
	int avg = 0;
	for (i = 0; i < 15; i++) {
	avg = avg + pontok[i];
	}
	cout << "A pontszamok atlaga: " << (float)avg / i << endl;

	//volt-e 100 pont - eld�nt�s t�tele
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

	// 57 pontos - kiv�laszt�s t�tele
	i = 0;
	while (pontok[i] != 57) {
		i++;
	}
	cout << "57 pontos: " << i + 1 << ". hallgato" << endl;

	//bek�rt pontsz�m k�r�se - line�ris keres�s t�tele
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

	// sikeres vizsg�k sz�ma - megsz�ml�l�s t�tele
	int siker = 0;
	for (i = 0; i < 15; i++)
	{
		if (pontok[i] > 50)
		{
			siker++;
		}
	}
	cout << "A skiresen viszgazok szama: " << siker << endl;

	// legal�bb 4-est el�r� hallgat�k - kiv�logat�s t�tele
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

	//legkevesebb pontot el�rt hallgat� - minimum kiv�laszt�s t�tele
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
	h�zi 
	K�t kock�val dobunk egyszerre, egym�sut�n 100 � szor.
	A dob�sok �rt�keit[2;12] t�lts�nk fel egy t�mbbe �s �rassuk ki a k�perny�re
	(soronk�nt 10 dob�s)!
	10, 9, 11, 3, 7, 12, 5, 4, 2, 6
	9, 5, 11, � stb.
	Sz�m�tsuk ki a dob�sok �tlag�t!
	Volt-e 10-es dob�s?
	P�ratlan, p�ros dob�sok sz�ma?
	Melyik dob�sb�l, h�ny darab volt?
	2: 3 db
	3: 1 db �
	H�nyadik dob�s a legnagyobb?
	Gy�jts�k �ssze egy t�mbbe majd �rassuk ki, a 12-s dob�sok sorsz�mait!
	*/
	return 0;
}