#define _CRT_SECURE_NO_WARNINGS

//描述
//给出年分m和一年中的第n天，算出第n天是几月几号。
//输入描述：
//输入包括两个整数y(1 <= y <= 3000)，n(1 <= n <= 366)。
//输出描述：
//可能有多组测试数据，对于每组数据， 按 yyyy - mm - dd的格式将输入中对应的日期打印出来

#include <iostream>
using namespace std;

int main() {
    int year, n;
    while (scanf("%d%d", &year, &n) != EOF) { // 注意 while 处理多个 case
        int month = 1;
        int day = n;
        int monthArr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            monthArr[1] = 29;
        }
        while (day / monthArr[month - 1] > 0) {
            day -= monthArr[month - 1];
            ++month;
        }
        if (day == 0) {
            month--;
            day = monthArr[month - 1];
        }
        printf("%d-%02d-%02d\n", year, month, day);
    }
}
// 64 位输出请用 printf("%lld")