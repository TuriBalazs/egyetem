#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

/*
struct Tanulok
{
	string nev;
	int fk, tk, jegyek[5];
	float atlag = 0.0;
};

struct ugynok
{
	string varos;
	int tav;
};

int beolvas(char*, ugynok*);
int ossztav(ugynok*, int);
string legtavolabbi(ugynok*, int);
int kozeli(ugynok*, int);
void rendez(ugynok*, int);
*/

void Hanoi(int, char, char, char);

int main()
{
	/*
	Tanulok osztaly[5];

	ifstream be("tanulok.txt");
	if (be.fail()) {
		cerr << "Hiba a fajl megnyitasakor!" << endl;
		return -1;
	}

	Tanulok legjobb(Tanulok[], int);

	string seged;
	int db = 0;
	while (getline(be, seged, ',')) {
		osztaly[db].nev = seged;
		be >> osztaly[db].fk;
		be.ignore();
		be >> osztaly[db].tk;
		be.ignore();
		for (int i = 0; i < 5; i++)
		{
			be >> osztaly[db].jegyek[i];
			osztaly[db].atlag += osztaly[db].jegyek[i];
		}
		osztaly[db].atlag /= 5;
		db++;
	}

	be.close();

	for (int i = 0; i < db; i++)
	{
		cout << osztaly[i].nev << "\t" << osztaly[i].fk << "\t" << osztaly[i].tk << "\t" << osztaly[i].atlag << "\t";
		for (int j = 0; j < 5; j++)
		{
			cout << osztaly[i].jegyek[j] << " ";
		}
		cout << endl;
	}

	Tanulok lj = legjobb(osztaly, db);
	cout << "A legjobb tanulo: " << lj.nev << ", atlag: " << setprecision(3) << lj.atlag << endl;


	char fnev[] = "vartav.txt";
	ugynok u[20];
	int n = beolvas(fnev, u);

	cout << n << "db varosban jart januarban az ugynok." << endl;
	cout << ossztav(u, n) << " km-t utazot az ugynok januarban." << endl;
	cout << legtavolabbi(u, n) << " a legtavolabbi varos." << endl;
	cout << "Kozeli varosok szama: " << kozeli(u, n) << endl;
	rendez(u, n);
*/

	Hanoi(3, 'A', 'B', 'C');




	return 0;
}


void Hanoi(int N, char Honnan, char Mivel, char Hova)
{
	if (N > 0)
	{
		Hanoi(N - 1, Honnan, Mivel, Hova);
		cout << N << ". korongot tegye a(z) " << Honnan << " rudrol, a " << Hova << " rudra!" << endl;
		Hanoi(N - 1, Mivel, Honnan, Hova);
	}
}

/*
int beolvas(char* fajl, ugynok* t)
{
	ifstream be(fajl);
	if(be.fail())
	{
		cerr << "Hiba a  fajl megnyitasakor!" << endl;
		exit(-1);
	}
	int db = 0;
	while (be >> t[db].varos >> t[db].tav)
	{
		cout << t[db].varos << "\t" << t[db].tav << endl;
		db++;
	}
	be.close();
	return db;
}

int ossztav(ugynok* t, int n)
{
	int ossz = 0;
	for (int i = 0; i < n; i++)
	{
		ossz += t[i].tav;
	}
	return 2 * ossz;
}

string legtavolabbi(ugynok* t, int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (t[i].tav > t[max].tav)
		{
			max = i;
		}
	}
	return t[max].varos;
}

int kozeli(ugynok* t, int n)
{
	int tav = 0;
	for (int i = 0; i < n; i++)
	{
		if (t[i].tav < 80)
		{
			tav++;
		}
	}
	return tav;
}

void rendez(ugynok* t, int n)
{
	ugynok seged;
	ofstream ki("rendezettTavolsag.txt");
	if (ki.fail())
	{
		cerr << "Hiba a fajl letrehozasakor!" << endl;
		exit(-2);
	}
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (t[i].tav > t[j].tav)
			{
				seged = t[i];
				t[i] = t[j];
				t[j] = seged; 
			}
		}

	}
	for (int i = 0; i < n; i++)
	{
		ki << t[i].varos << "\t" << t[i].tav << endl;
		cout << t[i].varos << "\t" << t[i].tav << endl;
	}
	ki.close();
}


Tanulok legjobb(Tanulok t[], int n) {
	Tanulok legjobb;
	for (int i = 0; i < n; i++)
	{
		if (t[i].atlag > legjobb.atlag) { legjobb = t[i]; }
	}
	return legjobb;
}
*/