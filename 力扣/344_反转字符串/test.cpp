#define _CRT_SECURE_NO_WARNINGS
#include <vector>
using namespace std;

//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char>::iterator it1 = s.begin(), it2 = s.end() - 1;
        while (it1 <= it2) {
            swap(*it1, *it2);
            ++it1, --it2;
        }
    }
};