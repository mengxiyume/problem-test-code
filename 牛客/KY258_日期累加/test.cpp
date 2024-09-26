#define _CRT_SECURE_NO_WARNINGS

//����
//���һ�������ܼ���һ�����ڼ������������ʲô���ڡ�
//����������
//�����һ�б�ʾ��������m��������m��ÿ���ĸ������ֱ��ʾ�����պ��ۼӵ�������
//���������
//���m�У�ÿ�а�yyyy - mm - dd�ĸ������

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
    while (scanf("%d", &m) != EOF) { // ע�� while ������ case
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
// 64 λ������� printf("%lld")

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