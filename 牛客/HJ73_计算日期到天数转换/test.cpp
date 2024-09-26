#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

inline bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
    int year, month, day;
    while (cin >> year >> month >> day) { // ע�� while ������ case
        int date = 0;
        int monthArr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        //if leap-year	���꽫���µ������滻Ϊ29
        //�ܱ�4���������ܱ�100�����������ܱ�400����
        if (isLeapYear(year)) {
            monthArr[1] = 29;
        }
        //�ۼ�ǰN���
        for (int i = 0; i < month - 1; i++) {
            date += monthArr[i];
        }
        //����ĩβ����
        date += day;

        cout << date;
    }
}
// 64 λ������� printf("%lld")