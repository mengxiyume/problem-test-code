#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        size_t pos = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                reverse(s.begin() + pos, s.begin() + i);
                pos = i + 1;    //posµü´ú,ÂÔ¹ý¿Õ¸ñ
            }
        }
        reverse(s.begin() + pos, s.end());
        return s;
    }
};

int main() {
    string str1 = "Let's take LeetCode contest";
    cout << Solution().reverseWords(str1) << endl;
    return 0;
}