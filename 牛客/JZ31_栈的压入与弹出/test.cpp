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
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pushV int整型vector
     * @param popV int整型vector
     * @return bool布尔型
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        // write code here
        stack<int> st;
        size_t pushPos = 0, popPos = 0;
        size_t n = popV.size();
        //遍历出栈数组
        for (popPos = 0; popPos < n; ++popPos) {
            //空栈或者栈顶元素不等于出栈数组则持续入栈
            while (pushPos < n && (st.empty() || st.top() != popV[popPos])) {
                st.push(pushV[pushPos]);
                ++pushPos;
            }
            //栈顶数组与出栈数组相同时直接出栈
            if (st.top() == popV[popPos]) {
                st.pop();
            }
        }
        //空队列完全匹配，非空队列则不匹配
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