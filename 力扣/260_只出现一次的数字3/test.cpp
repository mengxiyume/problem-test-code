#include <vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorSum = 0;
        for (const auto& e : nums)
            xorSum ^= e;
        //�ҵ�����xor�����λ�Ķ�����1
        int botton = xorSum == INT_MIN ? xorSum : (xorSum & (-xorSum)); //INT_MIN��������ʱ���ܻ���������bΪ0�޷�����ִ��
        int v1 = 0, v2 = 0;
        for (const auto& e : nums) {
            //v1 v2 �����Ķ�����λ��Ȼ��ͬ�����Խ��������������򣬷���������͵�ĳһָ��������λ
            if (e & botton)
                v1 ^= e;
            else
                v2 ^= e;
        }
        //��ʼ���б�����ʱ���󷵻�
        return { v1, v2 };
    }
};