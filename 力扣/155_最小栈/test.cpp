#define _CRT_SECURE_NO_WARNINGS
#include <stack>
using namespace std;
class MinStack {
private:
    stack<int> st, minSt;
public:
    MinStack() {
        //��֤��Сջ��һ����ջ�ܹ�����
        minSt.push(INT_MAX);
    }

    void push(int val) {
        //����ջֱ����ջ���Ա���Сջջ�����ݣ����val��С������Сջ��val��������ջ��Сջջ��Ԫ��
        st.push(val);
        minSt.push(min(val, minSt.top()));
    }

    void pop() {
        if (!st.empty()) {
            //ջ�ǿ�ʱ��ջ
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