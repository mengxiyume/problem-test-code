#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int GetMonthDay(int year, int month) {
    int arr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 30 };
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        arr[1] = 29;
    return arr[month - 1];
}
int compare(
    int year1, int year2,
    int month1, int month2,
    int day1, int day2) {
    if (year1 != year2) {
        return year1 - year2;
    }
    else if (month1 != month2) {
        return month1 - month2;
    }
    else {
        return day1 - day2;
    }
}

int main() {
    int year1, month1, day1;
    int year2, month2, day2;
    while (scanf("%4d%2d%2d%4d%2d%2d",
        &year1, &month1, &day1,
        &year2, &month2, &day2) != EOF) { // 注意 while 处理多个 case

        int ret = 0;
        //找极值
        if (compare(year1, year2, month1, month2, day1, day2) < 0) {
            swap(year1, year2); swap(month1, month2); swap(day1, day2);
        }

        while (compare(year1, year2, month1, month2, day1, day2) >= 0) {
            //最大值循环减去一日
            day1--;
            if (day1 <= 0) {
                month1--;
                if (month1 <= 0) {
                    year1--;
                    month1 = 12;
                }
                day1 = GetMonthDay(year1, month1);
            }

            ret++;
        }
        ret++;
        cout << ret << endl;

    }
}
// 64 位输出请用 printf("%lld")