#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#include "./Date.h"

int main() {
	Date d;
	//d = d + 36;
	//cout << d._year << ' ' << d._month << ' ' << d._day << endl;

	d = d - 1;
	cout << d << endl;

	return 0;
}