#define _CRT_SECURE_NO_WARNINGS

/*
��1 + 2 + 3 + ... + n
Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A ? B : C����
    ���ݷ�Χ��0 < n �� 200
    ���ף� �ռ临�Ӷ�O(1) ��ʱ�临�Ӷ�O(n)
*/
class Solution {
public:
    int Sum_Solution(int n) {
        if (n == 1) return 1;
        return n + Sum_Solution(n - 1);
    }
};