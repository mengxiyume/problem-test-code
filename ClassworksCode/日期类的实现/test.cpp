#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#include "./Date.h"

int main() {
	Date d;
	//d = d + 36;
	//cout << d._year << ' ' << d._month << ' ' << d._day << endl;

	//d = d++;
	//cout << d << endl;

	//d = d--;
	//cout << d << endl;

	//cout << (d > d + 3) << endl;
	//cout << (d == (d - 3)) << endl;


	cout << d - (d + 180) << endl;

	

	return 0;
}