#define _CRT_SECURE_NO_WARNINGS
#include <vector>
using namespace std;

//��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� s ����ʽ������
//��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣
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