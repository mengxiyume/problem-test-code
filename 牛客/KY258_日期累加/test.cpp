#define _CRT_SECURE_NO_WARNINGS

//描述
//设计一个程序能计算一个日期加上若干天后是什么日期。
//输入描述：
//输入第一行表示样例个数m，接下来m行每行四个整数分别表示年月日和累加的天数。
//输出描述：
//输出m行，每行按yyyy - mm - dd的个数输出

#include <iostream>
#include <stdio.h>
using namespace std;

int GetMonthDay(int year, int month) {
    int monthArr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        monthArr[1] = 29;
    return monthArr[month - 1];
}

int main() {
    int m;
    while (scanf("%d", &m) != EOF) { // 注意 while 处理多个 case
        for (int i = 0; i < m; i++) {
            int year, month, day, addNum;
            scanf("%d%d%d%d", &year, &month, &day, &addNum);
            day += addNum;
            while (day > GetMonthDay(year, month)) {
                day -= GetMonthDay(year, month);
                month++;
                if (month > 12) {
                    year++;
                    month = 1;
                }
            }

            printf("%04d-%02d-%02d\n", year, month, day);
        }
    }
}
// 64 位输出请用 printf("%lld")

//10
//1941 12 11 100
//2069 5 9 158
//2062 9 6 145
//1981 4 2 91
//2095 3 23 236
//2091 1 28 153
//1992 11 22 316
//2018 12 23 126
//2071 7 10 312
//1967 8 17 294