#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>


using namespace std;

struct Csapat1
{
	string nev;
	int pont, mag, mez;
};

struct Csapat2
{
	string nev;
	int pont, mag, mez;
};


int main() {
	setlocale(LC_ALL, "");
	// Adatok inicializ�l�sa
	Csapat1 kecskem[12];
	Csapat2 szeged[12];
	srand((unsigned)time(NULL));
	int cs1 = 0, cs2 = 0;

	// F�jl beolvas�s

	ifstream be("csapat1.txt");
	while (!be.eof()) {
		be >> kecskem[cs1].nev >> kecskem[cs1].pont >> kecskem[cs1].mag;
		kecskem[cs1].mez = rand() % 89 + 10;
		//	// ellen�rz�s
		cs1++;
	}
	be.close();

	be.open("csapat2.txt");
	while (!be.eof()) {
		be >> szeged[cs2].nev >> szeged[cs2].pont >> szeged[cs2].mag;
		szeged[cs2].mez = rand() % 89 + 10;
		//	// ellen�rz�s
		cs2++;
	}
	be.close();

	// Ki�rat�s

	cout << "\tA m�rk�z�s adatai\n" << endl;
	cout << "\tKecskem�t j�t�kosai:" << endl;
	cout << "N�v" << "\t" << "pont" << "\t" << "mag." << "\t" << "mez" << endl;
	for (int i = 0; i < cs1; i++)
	{
		cout << kecskem[i].nev << "\t" << kecskem[i].pont << "\t" << kecskem[i].mag << "\t" << kecskem[i].mez << endl;
	}

	cout << "\Szeged j�t�kosai:" << endl;
	cout << "N�v" << "\t" << "pont" << "\t" << "mag." << "\t" << "mez" << endl;
	for (int i = 0; i < cs2; i++)
	{
		cout << szeged[i].nev << "\t" << szeged[i].pont << "\t" << szeged[i].mag << "\t" << szeged[i].mez << endl;
	}

	// Az els� csapat legjobb j�t�kosa
	cout << "\n";
	Csapat1 seged;
	for (int i = 0; i < cs1; i++)
	{
		if (kecskem[i].pont > seged.pont) { seged = kecskem[i]; }
	}

	cout << "A kecskem�t legjobb j�t�kosa: " << seged.nev << endl;

	// Volt e aki nem dobot pontot

	int nemDob = 0;
	for (int i = 0; i < cs1; i++)
	{
		if (kecskem[i].pont == 0 ) { nemDob++; }
		if (szeged[i].pont == 0) { nemDob++; }
	}

	if (nemDob != 0)
	{
		cout << "Volt" << endl;
	}
	else
	{
		cout << "Nem volt" << endl;
	}


	return 0;
}