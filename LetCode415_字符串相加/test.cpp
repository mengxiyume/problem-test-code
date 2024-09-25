#define _CRT_SECURE_NO_WARNINGS

/*
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式
*/
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string sumStr;
        //倒序遍历两个字符串
        //字符串长度不同时以0补位
        //结果存放在sum字符串，返回值为逆置后的sum
        int carry = 0;
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        while (end1 >= 0 || end2 >= 0) {
            //数值初始化
            int n1 = 0, n2 = 0;

            //数值提取
            if (end1 >= 0) {
                n1 = num1[end1] - '0';
            }
            if (end2 >= 0) {
                n2 = num2[end2] - '0';
            }
            //单次计算
            sumStr += ('0' + singleAdd(carry, n1, n2));

            //指针迭代
            end1--, end2--;
        }
        //加上最后的进位
        if(carry != 0) 
            (sumStr += (carry + '0'));
        //字符串逆置
        reverse(sumStr.begin(), sumStr.end());
        return sumStr;
    }
private:
    //carry为进位指示符, left与rught都为0~9之间的整形, 返回值为相加之后当前位的和
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