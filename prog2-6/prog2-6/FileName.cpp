#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
/*
struct Kocsi
{
	char nev[25];
	int kor, ar;
};
class Kereskedes {
public:
	int db;
	Kocsi* kocsik;
	Kereskedes(char*);
	void Kiir();
	double Atlag();
	Kocsi legfiatalabb();
	~Kereskedes();
};
*/

struct Olimpia
{
	int hely, versenyszam;
	string sportag, versenynev;
};

class Helsinki {
private:
	Olimpia* adatok;
	int db;
public:
	Helsinki(char*);
	~Helsinki();
	void Kiir();
	int elsokszama();
	string legtobbsportag();
	void ermesuszok();
};

int main()
{
	setlocale(LC_ALL, "hun");
	/*
	char fajlnev[] = "auto.dat";
	Kereskedes k(fajlnev);
	k.Kiir();
	cout << "Az aut�k �tlag�ra: " << setprecision(10) << k.Atlag() << endl;
	Kocsi lf = k.legfiatalabb();
	cout << "A legfiatalabb kocsi adatai:" << endl;
	cout << "N�v: " << lf.nev << endl;
	cout << "KOr: "<< lf.kor << endl;
	cout << "�r:  " << lf.ar << endl;
	*/

	char fajlnev[] = "helsinki.txt";
	Helsinki h(fajlnev);
	h.Kiir();
	cout << h.elsokszama() << " db els� helyez�st �rtek el." << endl;
	cout << "A legt�bb sport�gban versenyz�k: " << h.legtobbsportag() << endl;
	cout << "Az �sz� versenysz�mok legjobb eredm�nyei: " << endl;
	h.ermesuszok();

	return 0;
}

/*
Kereskedes::Kereskedes(char* fajlnev) {
	ifstream be(fajlnev, ios::binary);
	if (be.fail())
	{
		cerr << "hiba a f�jl megnyit�sakor!" << endl;
		exit(-1);
	}
	db = 0;
	Kocsi k;
	while (!be.eof()) {
		be.read((char*)&k, sizeof(k));
		if (!be.eof()) { db++; }
	}
	be.clear();
	be.seekg(0, ios::beg);
	kocsik = new Kocsi[db];
	for (int i = 0; i < db; i++)
	{
		be.read((char*)&kocsik[i], sizeof(kocsik[i]));
	}
	be.close();
}
Kereskedes::~Kereskedes()
{
		delete[] kocsik;
}
void Kereskedes::Kiir() {
	cout << "Az aut�k sz�ma" << db << endl;
	cout << "Az aut�k adatai:" << endl;
	cout.setf(ios::left);
	cout << setw(25) << "N�v" << setw(10) << "Kor" << setw(10) << "�r" << endl;
	for (int i = 0; i < db; i++)
	{
		cout << setw(25) << kocsik[i].nev << setw(10) << kocsik[i].kor << setw(10) << kocsik[i].ar << endl;
	}

}
double Kereskedes::Atlag() {
	double atlag = 0;
	for (int i = 0; i < db; i++)
	{
		atlag += kocsik[i].ar;
	}
	return atlag / db;
}
Kocsi Kereskedes::legfiatalabb() {
	Kocsi k;
	k = kocsik[0];
	for (int i = 0; i < db; i++)
	{
		if (kocsik[i].kor > k.kor)
		{
			k = kocsik[i];
		}
	}
	return k;
}
*/

Helsinki::Helsinki(char* fajlnev) {
	ifstream be(fajlnev);
	if (be.fail())
	{
		cerr << "hiba a f�jl megnyit�sakor!" << endl;
		exit(-1);
	}
	int i = 0;
	string sor;
	while (getline(be, sor)) {
		i++;
	}
	db = i;
	adatok = new Olimpia[db];
	be.clear();
	be.seekg(0, ios::beg);
	for (i = 0; i < db; i++)
	{
		be >> adatok[i].hely >> adatok[i].versenyszam >> adatok[i].sportag >> adatok[i].versenynev;
	}
	be.close();
}
Helsinki::~Helsinki() {
	delete[] adatok;
}
void Helsinki::Kiir() {
	cout << "Az helyez�st el�rt versenyv�k sz�ma:" << db << endl;
	cout.setf(ios::left);
	cout << setw(5) << "Hely" << setw(5) << "VSz" << setw(20) << "Sport�g" <<setw(30) << "Versenyn�v" << endl;
	for (int i = 0; i < db; i++)
	{
		cout << setw(5) << adatok[i].hely << setw(5) << adatok[i].versenyszam << setw(20) << adatok[i].sportag << setw(30) << adatok[i].versenynev << endl;
	}
}
int Helsinki::elsokszama() {
	int elsok = 0;
	for (int i = 0; i < db; i++)
	{
		if (adatok[i].hely == 1) { elsok++; }
	}
	return elsok;
}
string Helsinki::legtobbsportag() {
	int max = 0;
	for (int i = 1; i < db; i++)
	{
		if (adatok[i].versenyszam > adatok[max].versenyszam)
		{
			max = i;
		}
	}
	return adatok[max].sportag;
}
void Helsinki::ermesuszok() {
	cout.setf(ios::left);
	for (int i = 0; i < db; i++)
	{
		if (adatok[i].hely < 4 && adatok[i].sportag == "uszas")
		{
			cout << setw(30) << adatok[i].versenynev << " " << adatok[i].hely << endl;
		}
	}
}