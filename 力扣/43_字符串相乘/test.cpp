#include <string>
#include <iostream>
using namespace std;

//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。

class Solution {
public:
    string multiply(string num1, string num2) {
        //找出长度的极值
        string& longStr = num1.size() > num2.size() ? num1 : num2;
        string& shortStr = num1.size() < num2.size() ? num1 : num2;


    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << Solution().multiply(s1, s2);

    return 0;
}