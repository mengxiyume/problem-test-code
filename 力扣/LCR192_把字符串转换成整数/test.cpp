#define _CRT_SECURE_NO_WARNINGS

//请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C / C++ 中的 atoi 函数）
//函数 myAtoi(string s) 的算法如下：
//
//读入字符串并丢弃无用的前导空格
//检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
//读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
//将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
//如果整数数超过 32 位有符号整数范围[−231, 231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
//返回整数作为最终结果

#include <string>
#include <stdint.h>
#include <iostream>
using namespace std;
//class Solution {
//public:
//    int myAtoi(string str) {
//        long long tempSum = 0;
//        bool flag = true;
//        for (auto it = str.begin(); it != str.end(); ++it) {
//            if (*it == '-' || *it >= '0' && *it <= '9') {
//                if (it != str.end() && *it == '-') {
//                    flag = false;
//                    ++it;
//                }
//                //删除前导0
//                while (it != str.end() && *it == '0') {
//                    ++it;
//                }
//                while (it != str.end() && *it >= '0' && *it <= '9') {
//                    tempSum *= 10;  //减去以及截断
//                    tempSum += ((long long)*it - '0') * (flag ? 1 : -1);
//                    if (flag == true && tempSum > INT32_MAX)
//                        return INT32_MAX;
//                    else if (flag == false && tempSum < INT32_MIN)
//                        return INT32_MIN;
//
//                    ++it;
//                }
//                return tempSum;
//            }
//        }
//
//        return tempSum;
//    }
//};

#include <string>
#include <stdint.h>
class Solution {
public:
    int myAtoi(string str) {
        bool flag = true;
        long long secont = 1;
        long long tempSum = 0;
        int pos = 0;
        while (pos < str.size() && str[pos] == ' ') {
            ++pos;
            //前导空格
        }
        if (pos < str.size() && str[pos] == '-') {
            flag = false;
            ++pos;
            //符号位
        }
        else if (str[pos] == '+')
            ++pos;
        while (pos < str.size() && isdigit(str[pos])) {
            //数值累加
            tempSum *= 10;
            tempSum += ((long long)str[pos] - '0') * (flag ? 1 : -1);
            if (flag == true && tempSum > INT32_MAX) {
                return INT32_MAX;
            }
            if (flag == false && tempSum < INT32_MIN) {
                return INT32_MIN;
            }
            ++pos;
        }
        return tempSum;
    }
};

int main() {
    string str = "words and 987";
    cout << Solution().myAtoi(str);

    return 0;
}