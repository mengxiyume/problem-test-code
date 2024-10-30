#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < 32; ++i) {
            //遍历数组中每一个元素的第i位
            int n = 0;
            for (auto e : nums) {
                //第i位为1或0
                n += (e >> i) % 2;
            }
            //如果某一位并非三的倍数个1，则该位为结果的一部分
            if (n % 3 != 0) {
                //1往左移动i位
                ret += (1 << i);
            }
        }
        //经历32次遍历数组的结果hhh
        return ret;
    }
};