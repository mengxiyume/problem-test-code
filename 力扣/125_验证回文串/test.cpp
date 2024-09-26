#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;

//如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
//字母和数字都属于字母数字字符。
//给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。

class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        //转换为纯小写字母字符数组
        for (auto e : s)
            if (isupper(e))
                str += (e + 32);
            else if (islower(e) || isdigit(e))
                str += e;
        //回文检测
        int begin = 0, end = str.size() - 1;
        while (begin < end) {
            if (str[begin] != str[end])
                return false;
            ++begin, --end;
        }
        return true;
    }
};

int main() {

    cout << Solution().isPalindrome("A man, a plan, a canal: Panama") << endl;
}