#include <vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorSum = 0;
        for (const auto& e : nums)
            xorSum ^= e;
        //找到两数xor后最低位的二进制1
        int botton = xorSum == INT_MIN ? xorSum : (xorSum & (-xorSum)); //INT_MIN单独出现时可能会溢出，造成b为0无法继续执行
        int v1 = 0, v2 = 0;
        for (const auto& e : nums) {
            //v1 v2 两数的二进制位必然不同，所以将两数分组进行异或，分组根据异或和的某一指定二进制位
            if (e & botton)
                v1 ^= e;
            else
                v2 ^= e;
        }
        //初始化列表构造临时对象返回
        return { v1, v2 };
    }
};