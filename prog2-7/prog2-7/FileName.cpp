#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

/*
struct kolcsonzes
{
	string datum, tipus;
	int ido, sorszam;
};
class Kolcsonzo
{
private:
	const int medianAr = 1000;
	const int magellaAr = 1200;
	int db;
	kolcsonzes* kolcsonzesek;

public:
	Kolcsonzo(char*);
	~Kolcsonzo();
	int Getdb();
	int GetMagellan();
	int GetMedian();
	int MedianBevetel();
	int OsszBevetel();
	kolcsonzes LeghosszabbKolcsonzes();
	void kiir();
};
*/

class Sokszog
	{
	protected:
		int a, b;
	public:
		Sokszog(int a, int b) : a(a), b(b) {}

	};
class Negyzet : public Sokszog {
	public:
		Negyzet(int a) : Sokszog(a, a) {}
		int terulet() { return a * a; }
	};
class Teglalap : public Sokszog {
	public:
		Teglalap(int a, int b) : Sokszog(a, b) {}
		int terulet() { return a * b; }
	};
class Haromszog : public Sokszog {
	public:
		Haromszog(int a, int b) : Sokszog(a, b) {}
		int terulet() { return a * b / 2; }
	};

int main() {
	setlocale(LC_ALL, "hun");
	/*
	char fajlnev[] = "kolcsonzo.txt";
	Kolcsonzo k(fajlnev);
	cout << "A kölcsönzések száma: " << k.Getdb() << endl;
	cout << "A magellán kölcsönzések száma: " << k.GetMagellan() << endl;
	cout << "A magellán kölcsönzések száma: " << k.GetMedian() << endl;
	cout << "A magellán kölcsönzések bevétele: " << k.MedianBevetel() << endl;
	cout << "Az összes bevétele: " << k.OsszBevetel() << endl;
	kolcsonzes max = k.LeghosszabbKolcsonzes();
	cout << "A leghosszab kölcsönzés adatai:" << endl;
	cout << "Sorszám: " << max.sorszam << endl;
	cout << "Dátum: " << max.datum << endl;
	cout << "Idõ: " << max.ido << endl;
	cout << "Típus: " << max.tipus << endl;
	k.kiir();
*/

	Negyzet n(4);
	Teglalap t(3, 5);
	Haromszog h(3, 4);

	cout << "A négyzet területe: " << n.terulet() << endl;
	cout << "A téglalap területe: " << t.terulet() << endl;
	cout << "A háromszög területe: " << h.terulet() << endl;



	return 0;
}

/*
Kolcsonzo::Kolcsonzo(char* fajlnev) {
	ifstream be(fajlnev);
	if (be.fail())
	{
		cerr << "Hiba a fájl megnyitásakor!";
		exit(-1);
	}
	be >> db;
	kolcsonzesek = new kolcsonzes[db];
	for (int i = 0; i < db; i++)
	{
		be >> kolcsonzesek[i].datum >> kolcsonzesek[i].tipus >> kolcsonzesek[i].ido;
		kolcsonzesek[i].sorszam = i + 1;
	}
}
Kolcsonzo::~Kolcsonzo() {
	delete[] kolcsonzesek;
}
int Kolcsonzo::Getdb() {
	return db;
}
int Kolcsonzo::GetMagellan() {
	int db = 0;
	for (int i = 0; i < this->db; i++)
	{
		if (kolcsonzesek[i].tipus == "Magellan")
		{
			db++;
		}
	}
	return db;
}
int Kolcsonzo::GetMedian() {
	int db = 0;
	for (int i = 0; i < this->db; i++)
	{
		if (kolcsonzesek[i].tipus == "Median")
		{
			db++;
		}
	}
	return db;
}
int Kolcsonzo::MedianBevetel() {
	int bevetel = 0;
	for (int i = 0; i < db; i++)
	{
		if (kolcsonzesek[i].tipus == "Median")
		{
			bevetel += medianAr * kolcsonzesek[i].ido;
		}
	}
	return bevetel;
}
int Kolcsonzo::OsszBevetel() {
	int bevetel = 0;
	for (int i = 0; i < db; i++)
	{
		if (kolcsonzesek[i].tipus == "Median")
		{
			bevetel += medianAr* kolcsonzesek[i].ido;
		}
		else if (kolcsonzesek[i].tipus == "Magellan")
		{
			bevetel += magellaAr * kolcsonzesek[i].ido;
		}
	}
	return bevetel;
}
kolcsonzes Kolcsonzo::LeghosszabbKolcsonzes() {
	kolcsonzes leghosszabb;
	for (int i = 0; i < db; i++)
	{
		if (leghosszabb.ido < kolcsonzesek[i].ido) {
			leghosszabb = kolcsonzesek[i];
		}
	}
	return leghosszabb;
}
void Kolcsonzo::kiir() {
	cout.setf(ios::left);
	cout << "A kölcsönzések adatai:" << endl;
	cout << setw(5) << "Ssz" << setw(12) << "Dátum" << setw(10)  << "Típus" << "Idõ" << setw(5) << endl;
	for (int i = 0; i < db; i++)
	{
		cout << setw(5) << kolcsonzesek[i].sorszam << setw(12) << kolcsonzesek[i].datum << setw(10) << kolcsonzesek[i].tipus << setw(5) << kolcsonzesek[i].ido   << endl;
	}
}
*/

