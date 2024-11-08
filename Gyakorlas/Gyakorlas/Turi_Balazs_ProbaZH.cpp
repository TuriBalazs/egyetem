#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

struct Utazas
{
	double IndulasiKM, ErkezesiKM;
	string IndulasiTelepules, ErkezesiTelepules;
	int Ora, Perc;
	float Fogyasztas;
};



int main() {
	
	Utazas utazas[10];
	int m = 0;
	cout << endl << "____________________________" << endl;

	
	ifstream be("utazas.txt");
	if (be.fail())
	{
		cerr << "hiba a file megnyitasakor!";
	}
	while (be >> utazas[m].IndulasiKM >> utazas[m].ErkezesiKM >> utazas[m].IndulasiTelepules >> utazas[m].ErkezesiTelepules >> utazas[m].Ora >> utazas[m].Perc >> utazas[m].Fogyasztas)
	{
		m++;
	}
	cout << m << " utazas tortent" << endl;
	be.close();
	int megtettut = 0;
	int uzemanyagar = 0;
	int felhuzemanyag = 0;
	for (int i = 0; i < m; i++)
	{
		megtettut += utazas[i].ErkezesiKM - utazas[i].IndulasiKM;
		felhuzemanyag += ((utazas[i].ErkezesiKM - utazas[i].IndulasiKM) / 100) * utazas[m].Fogyasztas;
		uzemanyagar += felhuzemanyag * 637.90;
	}
	cout << "utazas koltsege: " << uzemanyagar << " ft" << endl;



	cout << endl << "____________________________" << endl;
	

	cout << setw(20) << "Kezdo km allas" << setw(20) << "Vegso km allas" << setw(20) << "Indulasi varos" << setw(20) << "Erkezesi varos" << setw(12) << "Ora" << setw(12) << "Perc" << setw(12) << "Fogyasztas" << endl;

	for (int i = 0; i < m; i++)
	{
		cout << setw(20) << utazas[i].IndulasiKM << setw(20) << utazas[i].ErkezesiKM << setw(20) << utazas[i].IndulasiTelepules << setw(20) << utazas[i].ErkezesiTelepules << setw(12) << utazas[i].Ora << setw(12) << utazas[i].Perc << setw(12) << utazas[i].Fogyasztas << endl;
	}

	cout << endl << "____________________________" << endl;
	
	cout << "osszesen felhasznalt uzemanyag: " << felhuzemanyag << " l" << endl;
	float atlag = felhuzemanyag / m;
	cout << "atlagosan felhasznalt uzemanyag: " << atlag << " l" << endl;
	cout << endl << "____________________________" << endl;
	
	int seged = 0;

	for (int i = 0; i < m; i++)
	{
		if ((utazas[seged].ErkezesiKM - utazas[seged].IndulasiKM) > (utazas[i].ErkezesiKM - utazas[i].IndulasiKM))
			seged = i;

	}
	cout << "leghosszabb ut osszes adata\n";
	cout << setw(20) << utazas[seged].IndulasiKM << setw(20) << utazas[seged].ErkezesiKM << setw(20) << utazas[seged].IndulasiTelepules << setw(20) << utazas[seged].ErkezesiTelepules << setw(12) << utazas[seged].Ora << setw(12) << utazas[seged].Perc << setw(12) << utazas[seged].Fogyasztas << endl;

	cout << endl << "____________________________" << endl;
	
	int kezdokm = 0;
	int vegsokm = 0;

	for (int i = 0; i < m; i++)
	{
		if (utazas[kezdokm].IndulasiKM > utazas[i].IndulasiKM)
			kezdokm = i;

		if (utazas[vegsokm].ErkezesiKM < utazas[i].ErkezesiKM)
			vegsokm = i;

	}

	cout << "A kezdo km: " << utazas[kezdokm].IndulasiKM << endl;
	cout << "Az utolso km: " << utazas[vegsokm].ErkezesiKM << endl;
	cout << "osszesen megtett km: " << utazas[vegsokm].ErkezesiKM - utazas[kezdokm].IndulasiKM << endl;

	cout << endl << "____________________________" << endl;
	//7
	cout << "10km nel nagyobb utak:\n";
	ofstream ki;
	ki.open("utazas2.txt");
	for (int i = 0; i < m; i++)
	{
		if ((utazas[i].ErkezesiKM - utazas[i].IndulasiKM) > 10)
		{
			cout << setw(20) << utazas[i].IndulasiKM << " " << utazas[i].ErkezesiKM << setw(20) << utazas[i].IndulasiTelepules << setw(20) << utazas[i].ErkezesiTelepules << setw(12) << utazas[i].Ora << setw(12) << utazas[i].Perc << setw(12) << utazas[i].Fogyasztas << endl;
			ki << utazas[i].IndulasiKM << " " << utazas[i].ErkezesiKM << " " << utazas[i].IndulasiTelepules << " " << utazas[i].ErkezesiTelepules << " " << utazas[i].Ora << " " << utazas[i].Perc << " " << utazas[i].Fogyasztas << " " << endl;
		}

	}
	ki.close();

	cout << endl << "____________________________" << endl;


	return 0;
}