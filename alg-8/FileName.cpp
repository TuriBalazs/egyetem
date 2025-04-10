#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


struct Szinhaz
{
	string fogl, kat;
};

int main() {
	setlocale(LC_ALL, "hun");
	const int sorsz = 15;
	const int szekek = 20;	
	int i = 0, j = 0;
	Szinhaz nezter[sorsz];

	// 1. Beolvasás, kiírás

	ifstream be1("foglaltsag.txt"), be2("kategoria.txt");

	for (int i = 0; i < sorsz; i++)
	{
		be1 >> nezter[i].fogl;
		be2 >> nezter[i].kat;
		cout << nezter[i].fogl << "\t" << nezter[i].kat << endl;
	}

	
	//2. Kérje be egy sor és azon belül egy szék számát ellenõrzötten, majd írassa ki, hogy az adott hely szabad vagy foglalt!
	int sor = 0, szek = 0;;
	
	do
	{
		cout << "Adja meg az ellenõrizni kívánt sort(1-15): ";
		cin >> sor;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
	} while (sor < 1 || sor > sorsz);
	do
	{
		cout << "Adja meg az ellenõrizni kívánt széket(1-20): ";
		cin >> szek;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
	} while (szek < 1 || szek > szekek);

	if (nezter[sor-1].fogl[szek-1] == 'x')
	{
		cout << "A(z) " << sor << ". sor " << szek << ". széke foglalt." << endl;
	}
	else
	{
		cout << "A(z) " << sor << ". sor " << szek << ". széke szabad." << endl;
	}

	//3. Hány jegyet adtak el eddig, és ez a nézõtér befogadóképességének hány százaléka ?
	
	int jegyek = 0;
	int osszes = 0;
	for ( i = 0; i < sorsz; i++)
	{
		for ( j = 0; j < szekek; j++)
		{
			if (nezter[i].fogl[j] == 'x')
			{
				jegyek++;
			}
			osszes++;
		}
	}
	float szazalek = (float)jegyek / ((float)osszes / 100);
	cout << "Az elõadásra eddig " << jegyek << " jegyet adtak el, ez az összed jegy " << szazalek << "%-a" << endl;

	cout << "\nLegtöbb jegyeladás";
	string konv;
	int katdb[5] = { 0, 0, 0, 0, 0 };
	for ( i = 0; i < sorsz; i++)
		for ( j = 0; j < szekek; j++)
		{
			if (nezter[i].fogl[j] == 'x')
			{
				konv = nezter[i].kat[j];
				katdb[stoi(konv) - 1]++;  //stoi() - string=>int 
			}
		}
	int maxead = 0;
	cout << "\n 1k" << "\t 2k" << "\t 3k" << "\t 4k" << "\t 5k" << endl;
	for (i = 0; i < 5; i++)
	{
		cout << " " << katdb[i] << "\t";
		if (katdb[i] > katdb[maxead])
			maxead = i;
	}
	cout << "\n A legtöbb jegyet (" << katdb[maxead] << ") a(az) " << maxead + 1
		<< " árkategoriában adták el." << endl;

	//jegyek ára, bevétel - kategóriánként, összes bevétel - összegzés tétele
	cout << "\nBevételek";
	int bevet = 0, arak[5] = { 5000, 4000, 3000, 2000, 1500 };
	cout << "\n 5000" << "\t 4000" << "\t 3000" << "\t 2000" << "\t 1500" << endl;
	for (i = 0; i < 5; i++)
	{
		cout << " " << katdb[i] * arak[i] << "\t";
		bevet = bevet + katdb[i] * arak[i];
	}
	cout << "\n A jelenlegi bevetel " << bevet << " Ft" << endl;

	//"egyedülálló" üres hely - megszámlálás tétele
	cout << "\nEgyedülálló üres hely";
	int euh = 0;
	for (i = 0; i < sorsz; i++)
	{
		if (nezter[i].fogl.substr(0, 2) == "ox")	//sor elején
		{
			euh++;
		}
		for (j = 0; j < szekek - 2; j++)
		{
			if (nezter[i].fogl.substr(j, 3) == "xox")	 //a sorban
			{
				euh++;
			}
		}

		if (nezter[i].fogl.substr(18, 2) == "xo")	//sor végén
		{
			euh++;
		}
	}
	cout << "\n Egyadülálló üreshelyek száma: " << euh << endl;

	//szabad.txt 
	cout << "\nFoglalt helyek -> szabad.txt";
	ofstream out("szabad.txt");
	if (out.fail())
	{
		cout << "hiba"; system("pause"); exit(1);
	}
	int sorki = 0;
	for (i = 0; i < sorsz; i++)
	{
		for (j = 0; j < szekek; j++)
		{
			if (nezter[i].fogl[j] == 'x')
			{
				out << nezter[i].fogl[j];
			}
			else
			{
				out << nezter[i].kat[j];
			}
		}
		out << endl;
		sorki++;
	}
	out.close();
	cout << "\n " << sorki << " sor kiírva" << endl;

	system("pause");

	return 0;
}