#define _CRT_SECURE_NO_WARNINGS

//����
//�������m��һ���еĵ�n�죬�����n���Ǽ��¼��š�
//����������
//���������������y(1 <= y <= 3000)��n(1 <= n <= 366)��
//���������
//�����ж���������ݣ�����ÿ�����ݣ� �� yyyy - mm - dd�ĸ�ʽ�������ж�Ӧ�����ڴ�ӡ����

#include <iostream>
using namespace std;

int main() {
    int year, n;
    while (scanf("%d%d", &year, &n) != EOF) { // ע�� while ������ case
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
// 64 λ������� printf("%lld")