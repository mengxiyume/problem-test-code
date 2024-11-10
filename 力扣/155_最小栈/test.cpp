#define _CRT_SECURE_NO_WARNINGS
#include <stack>
using namespace std;
class MinStack {
private:
    stack<int> st, minSt;
public:
    MinStack() {
        //保证最小栈第一次入栈能够进行
        minSt.push(INT_MAX);
    }

    void push(int val) {
        //数据栈直接入栈，对比最小栈栈顶数据，如果val更小，则最小栈入val，否则入栈最小栈栈顶元素
        st.push(val);
        minSt.push(min(val, minSt.top()));
    }

    void pop() {
        if (!st.empty()) {
            //栈非空时弹栈
            st.pop();
            minSt.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */