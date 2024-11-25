#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

struct Hallgatok
{
	string Nev;
	int ae1, ea2, gy, ossz, jegy;
	bool  m1, m2, m3;
};

int main() {
	Hallgatok csoport[15];
	ifstream be("adatok.txt");
	if (be.fail()) { cerr << "Hiba a fajl betoltesekor!" << endl; return -1; }

	srand((unsigned)time(NULL));
	int fo = 0;

	while (be >> csoport[fo].Nev >> csoport[fo].ae1 >> csoport[fo].m1 >> csoport[fo].m2 >> csoport[fo].m3) {

		csoport[fo].ea2 = rand() %16;

		do {
			cout << "Adja meg " << csoport[fo].Nev << " gyakorlati ZH- eredményeit (0-50): " << endl;
			cin >> csoport[fo].gy;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
			}
		} while (csoport[fo].gy > 50 || csoport[fo].gy < 0);

		if (csoport[fo].m1 && csoport[fo].m2 && csoport[fo].m3) {
			csoport[fo].ossz = csoport[fo].ae1 + csoport[fo].ea2 + csoport[fo].gy;
		}
		else {
			csoport[fo].ossz = 0;
		}

		fo++;
	}

	system("cls");

	cout << fo << " fo jar a csoportba" << endl;

	for (int i = 0; i < fo; i++)
	{
		if (csoport[i].ossz > 85) { csoport[i].jegy = 5; }
		else if (csoport[i].ossz > 75) { csoport[i].jegy = 4; }
		else if (csoport[i].ossz > 62) { csoport[i].jegy = 3; }
		else if (csoport[i].ossz > 49) { csoport[i].jegy = 2; }
		else { csoport[i].jegy = 1; }
	}

	cout.setf(ios::left);
	cout << endl << setw(25) << "Nev" << setw(5) << "EA1" << setw(5) << "EA2" << setw(5) << "Gyak" << setw(5) << "M1" << setw(5) << "M2" << setw(5) << "M3" << setw(5) << "Ossz" << setw(5) << "Jegy" << endl;

	for (int i = 0; i < fo; i++)
	{
		cout << setw(25) << csoport[i].Nev << setw(5) << csoport[i].ae1 << setw(5) << csoport[i].ea2 << setw(5) << csoport[i].gy << setw(5) << csoport[i].m1 << setw(5) << csoport[i].m2 << setw(5) << csoport[i].m3 << setw(5) << csoport[i].ossz << setw(5);

		switch (csoport[i].jegy){
			case 1:cout << "1 - Elegtelen"; break;
			case 2:cout << "2 - Elegseges"; break;
			case 3:cout << "3 - Kozepes"; break;
			case 4:cout << "4 - Jo"; break;
			case 5:cout << "5 - Jeles"; break;
		}
		cout << endl;

	}

	int max = 0, min = 0, nemMoodle = 0;
	float atlag = 0;

	for (int i = 0; i < fo; i++)
	{
		if (csoport[i].ossz > csoport[max].ossz) { max = i; }
		if (csoport[i].ossz < csoport[min].ossz) { min = i; }
		if (!csoport[i].m1 || !csoport[i].m2 || !csoport[i].m3) { nemMoodle++; }

		atlag += csoport[i].ossz;
	}
	
	cout << "Logjobb pontszam: " << csoport[max].ossz << " pont, " << csoport[max].Nev << " Hallgato erte el!" << endl;
	cout << "Logrosszabb pontszam: " << csoport[min].ossz << " pont, " << csoport[min].Nev << " Hallgato erte el!" << endl;
	cout << nemMoodle << " Fo nem teljesitette a Moodle teszteket!" << endl;
	cout << "A csoport atlaga: " << atlag / fo << endl;



	return 0;
}