#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//����һ���ַ��� s ���ҵ� ���ĵ�һ�����ظ����ַ����������������� ����������ڣ��򷵻� - 1

class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = { 0 };
        //��ϣӳ�䷽ʽ����
        //������ɺ��ٴα��������ҵ����λ��
        for (auto e : s) {
            count[e - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (count[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};