#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

// adat stukrúra
struct Tanulok
{
	string nev;
	int II, III;
};

struct Ugynok
{
	string varos;
	int tav;
};


int main()
{
	//tanulok
	Tanulok osztaly[12];

	// Beolvasás
	ifstream be("jegyek.txt");
	if (be.fail()) {
		cerr << "Hiba a fajl megnyitasakor!" << endl;
		return -1;
	}	

	int db = 0;

	while (be >> osztaly[db].II >> osztaly[db].nev >> osztaly[db].III) {
		db++;
	}

	be.close();

	for (int i = 0; i < db; i++)
	{
		cout << "Nev: " << osztaly[i].nev << "\t 2.ev: " << osztaly[i].II << "\t 2.ev: " << osztaly[i].III << endl;
	}
	//F2
	cout << db << endl;

	//F3
	int avg = 0;
	for (int i = 0; i < db; i++)
	{
		avg += osztaly[i].II;
	}

	cout << "A 2.ev vegyi csoportatlag: " << avg / db << endl;

	//F4
	int avg2 = 0;
	for (int i = 0; i < db; i++)
	{
		avg2 += osztaly[i].III;
	}

	if (avg > avg2)
	{
		cout << "Az 2.ev atlaga nagyobb volt" << endl;
	}
	else
	{
		cout << "Az 3.ev atlaga nagyobb volt" << endl;
	}

	//F5
	int bukas = 0;
	for (int i = 0; i < db;  i++)
	{
		if (osztaly[i].III == 1) { bukas++; }
	}

	if (bukas == 0)
	{
		cout << "Nem volt bukas!" << endl;
	} 
	else
	{
		cout << "Volt bukas!" << endl;
	}

	//F6

	Tanulok legjobb;

	for (int i = 0; i < db - 1; i++)
	{
		for (int j = i + 1; j < db; j++)
		{
			if (osztaly[i].III > legjobb.III)
			{
				legjobb = osztaly[i];
			}
		}
	}
	cout << "A 3.ev legjobb tanuloja: " << legjobb.nev << endl;

	//F7
	Tanulok temp;

	for (int i = 0; i < db - 1; i++)
	{
		for (int j = i + 1; j < db; j++)
		{
			if (osztaly[i].nev > osztaly[j].nev)
			{
				temp = osztaly[i];
				osztaly[i] = osztaly[j];
				osztaly[j] = temp;
			}
		}
	}

	//F8
	ofstream ki("tankor.txt");
	for (int i = 0; i < db; i++)
	{
		ki <<  osztaly[i].nev << " " << osztaly[i].II << " " << osztaly[i].III << endl;
		cout << "Nev: " << osztaly[i].nev << "\t 2.ev: " << osztaly[i].II << "\t 2.ev: " << osztaly[i].III << endl;
	}
	ki.close();

	//varosok tav
	//F1

	Ugynok ugynok[20];

	be.open("vartav.txt");
	if (be.fail()) {
		cerr << "Hiba a fajl megnyitasakor!" << endl;
		return -1;
	}

	db = 0;
	while (be >> ugynok[db].varos >> ugynok[db].tav)
	{
		cout << ugynok[db].varos << "\t" << ugynok[db].tav << endl;
		db++;
	}
	be.close();

	//F2
	cout << db << ". varosban jart" << endl;	

	//F3
	int ossz = 0;
	for (int i = 0; i < db; i++)
	{
		ossz += ugynok[i].tav;
	}

	cout << ossz << " km-t utazot az ugynok januarban." << endl;

	//F4
	int max = 0;
	for (int i = 0; i < db; i++)
	{
		if (ugynok[i].tav > ugynok[max].tav)
		{
			max = i;
		}
	}
	cout << ugynok[max].varos << " a legtavolabbi varos." << endl;

	//F5

	int min = 0;
	for (int i = 0; i < db; i++)
	{
		if (ugynok[i].tav < ugynok[min].tav)
		{
			min = i;
		}
	}
	cout << ugynok[min].varos << " a legkozelebbi varos." << endl;

	//F6
	int ketszaz = 0;
	for (int i = 0; i < db; i++)
	{
		if (ugynok[i].tav > 200)
		{
			ketszaz++;
		}
	}
	if (ketszaz == 0)
	{
		cout << "Nem volt 200 km-nel tavolabbi varos!" << endl;
	}
	else
	{
		cout << "Volt 200 km-nel tavolabbi varos!" << endl;
	}

	//F7
	for (int i = 0; i < db; i++)
	{
		if (ugynok[i].varos == "Vac")
		{
			cout << "Igen volt vacon a " << i << ". allomas volt." << endl;
		}
	}

	//F8
	int tav = 0;
	for (int i = 0; i < db; i++)
	{
		if (ugynok[i].tav < 80)
		{
			tav++;
		}
	}
	cout << "Kozeli varosok szama: " << tav << endl;

	// Rendezés, Fájlba írás
	Ugynok seged;
	ki.open("rendezettTavolsag.txt");
	if (ki.fail())
	{
		cerr << "Hiba a fajl letrehozasakor!" << endl;
		exit(-2);
	}
	for (int i = 0; i < db - 1; i++)
	{
		for (int j = i + 1; j < db; j++)
		{
			if (ugynok[i].tav > ugynok[j].tav)
			{
				seged = ugynok[i];
				ugynok[i] = ugynok[j];
				ugynok[j] = seged;
			}
		}

	}
	for (int i = 0; i < db; i++)
	{
		ki << ugynok[i].varos << "\t" << ugynok[i].tav << endl;
		cout << ugynok[i].varos << "\t" << ugynok[i].tav << endl;
	}
	ki.close();

	return 0;
}