#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = nums.end() - 1;
        int val = *it;
        while (it > nums.begin()) {
            if (*(it - 1) == val) {
                //�ظ�Ԫ��ɾ��
                it = nums.erase(it);
            }
            else {
                //���ظ�����valֵ
                val = *(it - 1);
            }
            --it;
        }
        return nums.size();
    }
};