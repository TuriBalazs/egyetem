#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>

using namespace std;

struct Csapat
{
	string nev;
	int height, score;
};

struct Foci
{
	int g1, g2;
	string cs1, cs2;
};

int main() {
	//KOSARAS FELAGAT

	//adatok
	Csapat csapat[12];
	srand((unsigned)time(NULL));
	int letszam, i;

	//a létszám ellenörzött bekérés
	do
	{
		cout << "Adja meg a letszamot 5-12 kozott!" << endl;
		cin >> letszam;
	} while (letszam > 12 || letszam < 5);

	//a csapat feltöltése

	for (i = 0; i < letszam; i++)
	{
		cout << "adja meg az " << i + 1 << ". jatekos nevet:" << endl;
		cin >> csapat[i].nev;
		csapat[i].height = rand() % 51 + 170;
		csapat[i].score = rand() % 101;
	}

	//átlagszámítás és kiírás
	int avg = 0;

	for (i = 0; i < letszam; i++)
	{
		avg += csapat[i].score;
	}

	cout << "A csapat atlag potja: " << avg / letszam << endl;

	//a legmagasabb játékos kiírása
	int legmag = 0;

	for (i = 0; i < letszam; i++)
	{
		if (csapat[i].height < csapat[i+1].height) {
			legmag = i + 1;
		}
	}
	cout << "A legmagasabb jatekos nev: " << csapat[legmag].nev << " magassaga: " << csapat[legmag].height << endl;

	//77 pont kiválasztása és kiírása

	i = 0;
	while (i < letszam && csapat[i].score != 77)
	{
		i++;
	}
	if (i < letszam)
	{
		cout << "\nvolt 77 pontot dobo: " << csapat[i].nev << endl;
	}
	else
	{
		cout << "\nnem volt 77 pontot dobo" << endl;
	}

	//50 pont fellet dobók számának kiírása

	int db50 = 0;
	for (int i = 0; i < letszam; i++)
	{
		if (csapat[i].score > 50)
		{
			db50++;
		}
	}
	cout << "\nAz otven pont felett dobok szama: " << db50 << endl;

	// Rendezés, kiírás
	int j;
	for (int i = 0; i < letszam - 1; i++)
	{
		for (j = i + 1; j < letszam; j++)
		{
			if (csapat[i].score > csapat[j].score)
			{
				Csapat seged = csapat[i];
				csapat[i] = csapat[j];
				csapat[j] = seged;
			}
		}
	}
	cout << "\nRendezett kiiras: " << endl;
	for (int i = 0; i < letszam; i++)
	{
		cout << csapat[i].nev << " " << csapat[i].score << endl;
	}

	//FOCIS FELADAT
	// adatbeolvasás 
	setlocale(LC_ALL, "");
	ifstream be("merkozes.txt");
	if (be.fail()) { cerr << "hiba"; system("pause"); exit(1); }
	int i, db = 0;
	Foci eredm[8];
	for (i = 0; i < 8 && !be.eof(); i++)
	{
		be >> eredm[i].g1;
		be >> eredm[i].g2;
		be >> eredm[i].cs1;
		be >> eredm[i].cs2;
		db++;
	}
	be.close();

	// kiíratás
	cout.setf(ios::left); //balra igazítás(string)
	cout << "\t" << setw(12) << "otthoni " << setw(12) << "vendég " << "eredmény" << endl;
	for (i = 0; i < db; i++)
	{
		cout << "\t" << setw(12) << eredm[i].cs1 << setw(12) << eredm[i].cs2 << setw(2) << eredm[i].g1
			<< ": " << setw(2) << eredm[i].g2 << endl;
	}
	cout << endl << endl;
	//  Hány csapat nyert otthon? - megszámlálás tétel 
	int nyert = 0;
	for (i = 0; i < db; i++)
	{
		if (eredm[i].g1 > eredm[i].g2)
		{
			nyert++;
		}
	}
	cout << nyert << " Csapat gyõzõtt otthon" << endl;

	//  Melyik csapat rugta a legtöbb gólt?   - maximum kiválasztás 
	string maxcs;
	int max = 0;
	for (i = 0; i < db; i++)
	{
		if (eredm[i].g1 > max);
		{
			max = eredm[i].g1;
			maxcs = eredm[i].cs1;
		}
		if (eredm[i].g2 > max)
		{
			max = eredm[i].g2;
			maxcs = eredm[i].cs2;
		}
	}
	cout << "\nA legtöbb gólt a " << maxcs << " lõtte" << endl;

	//  Volt-e döntetlen? - eldöntés tétele
	i = 0;
	while (i < db && eredm[i].g1 != eredm[i].g2)
	{
		i++;
	}
	if (i < db)
	{
		cout << "\nVolt";
	}
	else
	{
		cout << "\nNem volt";
	}
	cout << " döntetlen mérkõzés" << endl << endl;

	//  Hány golt lõtt a Haladás? - kiválasztás tétele
	i = 0;
	while (eredm[i].cs1 != "Haladás" && eredm[i].cs2 != "Haladás")
	{
		i++;
	}
	if (eredm[i].cs1 == "Haladás")
	{
		cout << eredm[i].g1;
	}
	else
	{
		cout << eredm[i].g2;
	}
	cout << " gólt lõtt a Haladás" << endl << endl;

	//Rendezze acsapatokat névsor szerint növekvõ sorrendben
	//és írja ki képernyõre és a csapatok.txt állományba!
	string seged[16];
	//csapatnevek leválogatása
	int j = 0;
	for (i = 0; i < db; i++)
	{
		seged[j] = eredm[i].cs1;
		j++;
		seged[j] = eredm[i].cs2;
		j++;
	}
	//rendezés
	string temp;
	for (i = 0; i < 2 * db - 1; i++)
	{
		for (j = i + 1; j < 2 * db; j++)
		{
			if (seged[i] > seged[j])
			{
				temp = seged[i];
				seged[i] = seged[j];
				seged[j] = temp;
			}
		}
	}
	//	kiíratás
	ofstream ki("csapatok.txt");
	if (ki.fail()) { cerr << "hiba"; system("pause"); exit(1); }
	for (i = 0; i < 2 * db; i++)
	{
		cout << seged[i] << endl;
		ki << seged[i] << endl;
	}
	ki.close();
	cout << endl << endl;

	return 0;
}