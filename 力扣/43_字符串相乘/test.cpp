#include <string>
#include <iostream>
using namespace std;

//�����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��
//ע�⣺����ʹ���κ����õ� BigInteger ���ֱ�ӽ�����ת��Ϊ������

class Solution {
public:
    string multiply(string num1, string num2) {
        //�ҳ����ȵļ�ֵ
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