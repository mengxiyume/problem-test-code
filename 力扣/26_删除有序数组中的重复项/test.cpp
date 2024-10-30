#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = nums.end() - 1;
        int val = *it;
        while (it > nums.begin()) {
            if (*(it - 1) == val) {
                //重复元素删除
                it = nums.erase(it);
            }
            else {
                //不重复更新val值
                val = *(it - 1);
            }
            --it;
        }
        return nums.size();
    }
};