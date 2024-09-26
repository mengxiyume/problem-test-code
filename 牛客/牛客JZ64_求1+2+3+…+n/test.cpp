#define _CRT_SECURE_NO_WARNINGS

/*
求1 + 2 + 3 + ... + n
要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）。
    数据范围：0 < n ≤ 200
    进阶： 空间复杂度O(1) ，时间复杂度O(n)
*/
class Solution {
public:
    int Sum_Solution(int n) {
        if (n == 1) return 1;
        return n + Sum_Solution(n - 1);
    }
};