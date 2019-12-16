// rupeBonus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

double razdaljina(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int najblizi(double rupe[20][2], int obidjeni[20], double x, double y) {
	double min = 0;
	int index = -1;
	for (int i = 0; i < 20; i++) {
		if (obidjeni[i] == 1)
			continue;
		else {
			if (min == 0 || razdaljina(x, y, rupe[i][0], rupe[i][1]) < min) {
				min = razdaljina(x, y, rupe[i][0], rupe[i][1]);
				index = i;
			}
		}
	}

	return index;
}

void fja(double rupe[20][2], int index) {
	for (int i = 0; i < 20; i++) {
		cout << i << ":" << razdaljina(rupe[index][0], rupe[index][1], rupe[i][0], rupe[i][1]) << endl;//ispis svih razdaljina za dati index
	}
}

int main()
{

	double rupe[20][2] = {
		62.0, 58.4,//1
		57.5, 56.0,//2
		51.7, 56.0,//3
		67.9, 19.6,//4
		57.7, 42.1,//5
		54.2, 29.1,//6
		46.0, 45.1,//7
		34.7, 45.1,//8
		45.7, 25.1,//9
		34.7, 26.4,//10
		28.4, 31.7,//11
		33.4, 60.5,//12
		22.9, 32.7,//13
		21.5, 45.8,//14
		15.3, 37.8,//15
		15.1, 49.6,//16
		9.1, 52.8, //17
		9.1, 40.3, //18
		2.7, 56.8, //19
		2.7, 33.1 //20
	};

	int obidjeni[20], putanja[20], krajnjaPutanja[20];

	double minimalnaPutanja = 0;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			obidjeni[j] = 0;
		}

		obidjeni[i] = 1;
		putanja[0] = i;

		for (int j = 1; j < 20; j++) {
			int sledeci = najblizi(rupe, obidjeni, rupe[putanja[j - 1]][0], rupe[putanja[j - 1]][1]);
			putanja[j] = sledeci;
			obidjeni[sledeci] = 1;
		}

		double ukupnaPutanja = 0;
		for (int j = 0; j < 19; j++) {
			ukupnaPutanja += razdaljina(rupe[putanja[j]][0], rupe[putanja[j]][1], rupe[putanja[j + 1]][0], rupe[putanja[j + 1]][1]);
		}

		if (ukupnaPutanja < minimalnaPutanja || minimalnaPutanja == 0) {
			for (int j = 0; j < 20; j++) {
				krajnjaPutanja[j] = putanja[j];
			}
			minimalnaPutanja = ukupnaPutanja;
		}

		cout << "Ukupna putanja => " << ukupnaPutanja << "Minimalna putanja" << minimalnaPutanja << endl << "Putanja:" << endl;

		for (int i = 0; i < 20; i++) {
			cout << putanja[i] << " " ;
		}
		cout << endl << "Krajnja putanja:";

		for (int i = 0; i < 20; i++) {
			cout << krajnjaPutanja[i] << " ";
		}
		cout << endl;

	}

	cout << "Ukupna putanja => " << minimalnaPutanja << endl << "Putanja:" << endl;

	for (int i = 0; i < 20; i++) {
		cout << i << ": " << krajnjaPutanja[i] << endl;
	}

	return 0;
}
