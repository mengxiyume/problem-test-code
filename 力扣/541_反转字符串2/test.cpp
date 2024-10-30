#include <string>
#include <cstddef>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (size_t i = 0; i < s.size(); i += k * 2) {
            //在范围内进行反转                      //末尾数值<=K个时反转全部
            reverse(s.begin() + i, s.begin() + ((i + k) < s.size() ? (i + k) : s.size()));
        }
        return s;
    }
};

int main() {
    string str1 = "abcdefghijklmnopqrstuvwxyz";
    //string str1 = "abcdefg";
    cout << str1 << endl;
    cout << Solution().reverseStr(str1, 3) << endl;
    return 0;
}