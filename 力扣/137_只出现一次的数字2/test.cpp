#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < 32; ++i) {
            //����������ÿһ��Ԫ�صĵ�iλ
            int n = 0;
            for (auto e : nums) {
                //��iλΪ1��0
                n += (e >> i) % 2;
            }
            //���ĳһλ�������ı�����1�����λΪ�����һ����
            if (n % 3 != 0) {
                //1�����ƶ�iλ
                ret += (1 << i);
            }
        }
        //����32�α�������Ľ��hhh
        return ret;
    }
};