#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;

//����ڽ����д�д�ַ�ת��ΪСд�ַ������Ƴ����з���ĸ�����ַ�֮�󣬶������Ŷ��ͷ��Ŷ���һ�����������Ϊ�ö�����һ�� ���Ĵ� ��
//��ĸ�����ֶ�������ĸ�����ַ���
//����һ���ַ��� s��������� ���Ĵ� ������ true �����򣬷��� false ��

class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        //ת��Ϊ��Сд��ĸ�ַ�����
        for (auto e : s)
            if (isupper(e))
                str += (e + 32);
            else if (islower(e) || isdigit(e))
                str += e;
        //���ļ��
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