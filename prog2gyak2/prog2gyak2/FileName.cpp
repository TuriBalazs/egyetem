#include <iostream>
#include <vector>

using namespace std;

int main(int argdb, char* argtmb[]) {
	/*
	
	int f = 10;
	int* mut;
	int& fi = f;
	mut = &f;

	cout << "f: " << f << " fi: " << fi << " mut: " << *mut << endl;
	fi = 20;
	cout << "f: " << f << " fi: " << fi << " mut: " << *mut << endl;
	cout << &f << " " << &fi << " " << mut << " " <<  &mut << endl;
	
	
	-------------------------------------------------------------------------
	

	vector<int> jegyek(3);
	char betu;
	int szam;

	for (int i = 0; i < 3; i++)
	{
		cout << "Adja meg a(z) " << i + 1 << ". tanulo nevet" << endl;
		cin >> jegyek[i];
	}

	cout << "Szeretne meg jegyet rogziteni? (I/N): ";
	cin >> betu;
	betu = toupper(betu);
	if (betu == 'I') {
		do
		{
			cout << "Adja meg a kovetkezo jegyet: " << endl;
			cin >> szam;
			jegyek.push_back(szam);
			cout << "Szeretne meg jegyet rogziteni? (I/N): ";
			cin >> betu;
			betu = toupper(betu);
		} while (betu == 'I');

	}

	cout << "Jegyek szama: " << jegyek.size() << endl;

	for (int i = 0; i < jegyek.size(); i++)
	{
		cout << i + 1 << ". jegy: " << jegyek[i] << endl;
	}

	jegyek.pop_back();
	cout << "\nAz aktualis jegyek: " << jegyek.size() << endl;

	for (int i = 0; i < jegyek.size(); i++)
	{
		cout << i + 1 << ". jegy: " << jegyek.at(i) << endl;
	}

	cout << "Kivanja torolni a jegyeket? (I/N): ";
	cin >> betu;
	betu = toupper(betu);
	if (betu == 'I') {
		jegyek.clear();
		cout << "\nSikeres toroles!" << endl;
	}
	-------------------------------------------------------------------------


	

	cout << "*** Hagyomanyos (statikus) memoriakezeles! ***" << endl;
	int jegy[5] = { 5,4,3 };
	cout << "A tomb merete: " << sizeof(jegy) << endl;
	cout << "jegy[0] = " << jegy[0] << endl;
	cout << "jegy[2] = " << jegy[2] << endl;

	cout << "\n*** dinamikus memoriakezeles! ***" << endl;

	int* szam;
	szam = new int;
	if (szam == NULL)
	{
		cerr << "Nem sikerult a letrehozas!" << endl;
		return -1;
	}
	*szam = 20;
	cout << "szam = " << *szam << endl;
	delete szam;

	cout << "\n*** dinamikus tombkezeles! ***" << endl;
	int db = 0;
	cout << "Adja meg a tomb meretet: n = ";
	cin >> db;
	int* tmb = new int[db];
	if (tmb == NULL)
	{
		cerr << "Hiba a letrehozaskor!" << endl;
		return -1;
	}
	cout << "A tomb merete:  " << sizeof(tmb) << endl;
	*tmb = 15;
	tmb[3] = 10;
	*(tmb + 1) = 20;

	cout << "tmb[0] = " << tmb[0] << endl;
	cout << "tmb[1] = " << *(tmb+1) << endl;

	delete[] tmb;

	int tomb[5] = { 1,2,3,4,5 };
	int i = 3;

	cout << tomb[i] << endl;
	cout << i[tomb] << endl;
	cout << &tomb[i] << endl;
	cout << &i[tomb] << endl;
	cout << "tomb[3] = " << *(tmb + 3) << endl;
	
	--------------------------------------------------------------
	*/

if (argdb != 3)
{
	cerr << " Hiba, a program nem indithato! helyes parameterezes " << argtmb[0] << " szam1, szam2" << endl;
	return -2;
}

float a, b;
a = atof(argtmb[1]);
b = atof(argtmb[2]);
cout << a << " * " << b << " = " << a * b << endl;





	return 0;
}