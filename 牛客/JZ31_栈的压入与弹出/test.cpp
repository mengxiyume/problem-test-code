#define _CRT_SECURE_NO_WARNINGS

#include <stack>
#include <list>
#include <vector>
#include <iostream>
using namespace std;
#include <stack>
#include <list>
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param pushV int����vector
     * @param popV int����vector
     * @return bool������
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        // write code here
        stack<int> st;
        size_t pushPos = 0, popPos = 0;
        size_t n = popV.size();
        //������ջ����
        for (popPos = 0; popPos < n; ++popPos) {
            //��ջ����ջ��Ԫ�ز����ڳ�ջ�����������ջ
            while (pushPos < n && (st.empty() || st.top() != popV[popPos])) {
                st.push(pushV[pushPos]);
                ++pushPos;
            }
            //ջ���������ջ������ͬʱֱ�ӳ�ջ
            if (st.top() == popV[popPos]) {
                st.pop();
            }
        }
        //�ն�����ȫƥ�䣬�ǿն�����ƥ��
        if (st.empty())
            return true;
        else
            return false;
    }
};
int main() {
    vector<int> pushV = { 1, 2, 3, 4, 5 };
    vector<int> popV = { 4, 3, 5, 1, 2 };
    cout << Solution().IsPopOrder(pushV, popV) << endl;
}