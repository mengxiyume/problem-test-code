#define _CRT_SECURE_NO_WARNINGS

/*
���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺͲ�ͬ�����ַ�����ʽ���ء�

�㲻��ʹ���κ΃Ƚ������ڴ���������Ŀ⣨���� BigInteger���� Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ
*/
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string sumStr;
        //������������ַ���
        //�ַ������Ȳ�ͬʱ��0��λ
        //��������sum�ַ���������ֵΪ���ú��sum
        int carry = 0;
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        while (end1 >= 0 || end2 >= 0) {
            //��ֵ��ʼ��
            int n1 = 0, n2 = 0;

            //��ֵ��ȡ
            if (end1 >= 0) {
                n1 = num1[end1] - '0';
            }
            if (end2 >= 0) {
                n2 = num2[end2] - '0';
            }
            //���μ���
            sumStr += ('0' + singleAdd(carry, n1, n2));

            //ָ�����
            end1--, end2--;
        }
        //�������Ľ�λ
        if(carry != 0) 
            (sumStr += (carry + '0'));
        //�ַ�������
        reverse(sumStr.begin(), sumStr.end());
        return sumStr;
    }
private:
    //carryΪ��λָʾ��, left��rught��Ϊ0~9֮�������, ����ֵΪ���֮��ǰλ�ĺ�
    int singleAdd(int& carry, int left, int right) {
        int sum = carry + left + right;
        carry = sum /10;
        return sum % 10;
    }
};

int main() {
    string a, b;
    cin >> a >> b;
    cout << Solution().addStrings(a, b);
}