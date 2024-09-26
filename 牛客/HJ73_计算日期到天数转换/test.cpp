#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

inline bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
    int year, month, day;
    while (cin >> year >> month >> day) { // 注意 while 处理多个 case
        int date = 0;
        int monthArr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        //if leap-year	闰年将二月的天数替换为29
        //能被4整除但不能被100整除，或者能被400整除
        if (isLeapYear(year)) {
            monthArr[1] = 29;
        }
        //累加前N项和
        for (int i = 0; i < month - 1; i++) {
            date += monthArr[i];
        }
        //加上末尾的日
        date += day;

        cout << date;
    }
}
// 64 位输出请用 printf("%lld")