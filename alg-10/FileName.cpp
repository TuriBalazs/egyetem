#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct Versen
{
	string id, valaszok;
	int pont[14], osszPont, ido;
};

int main() {
	setlocale(LC_ALL, "hun");
	Versen verseny[500];
	string helyesValaszok;
	int db = 0;
	ifstream be("valaszok.txt");
	if (be.fail())
	{
		cerr << "Hiba a fájl megnyinásakor" << endl;
		exit(-1);
	}

	be >> helyesValaszok;
	
	while (!be.eof()) {
		be >> verseny[db].id >> verseny[db].valaszok >> verseny[db].ido;
	
		for (int j = 0; j < 14; j++)
		{
		
			if (verseny[db].valaszok[j] == helyesValaszok[j] && j < 7)
			{
				verseny[db].pont[j] = 3;
			}
			else if (verseny[db].valaszok[j] == helyesValaszok[j] && j < 11 && j> 6) {
				verseny[db].pont[j] = 5;
			}
			else if (verseny[db].valaszok[j] == helyesValaszok[j] &&  j > 10) {
				verseny[db].pont[j] = 7;
			}
			else if (verseny[db].valaszok[j] == 'X'){
				verseny[db].pont[j] = 0;
			}
			else {
				verseny[db].pont[j] = -1;
			
			}
			verseny[db].osszPont += verseny[db].pont[j];
		
		}
		
		db++;
	}

	be.close();

	cout << "Megoldások: " << helyesValaszok << endl;
	cout.setf(ios::left);
	cout << setw(6) << "Id" << setw(15) << "Válaszok" << setw(32) << "Pontok" << setw(4) << "ÖP" << "Idõ" << endl;
	for (int i = 0; i < db; i++)
	{
		cout << setw(6) << verseny[i].id << setw(15) << verseny[i].valaszok << setw(32) << verseny[i].pont << setw(4) << verseny[i].osszPont << verseny[i].ido << endl;
	}

	string azonosito;
	cout << "Irja be a keresett versenyzõ azonosítóját: ";
	cin >> azonosito;
	for (int i = 0; i < db; i++)
	{
		if (azonosito == verseny[i].id)
		{
			cout << "A " << verseny[i].id << " versenyzõ eredménye: " << 66 / 100 * verseny[i].osszPont << "%" << endl;
			cout << setw(6) << verseny[i].id << setw(15) << verseny[i].valaszok <<  setw(4) << verseny[i].osszPont << verseny[i].ido << endl;
			break;
		}
	}

	int temp = 0;
	for (int i = 1; i < db; i++)
	{
		if (verseny[temp].osszPont < verseny[i].osszPont)
		{
			temp = i;
		}
	}

	cout << "A legtöbb pontot elért versenyzö adatai:" << endl;
	cout << setw(6) << verseny[temp].id << setw(15) << verseny[temp].valaszok << setw(4) << verseny[temp].osszPont << verseny[temp].ido << endl;

	return 0;
}