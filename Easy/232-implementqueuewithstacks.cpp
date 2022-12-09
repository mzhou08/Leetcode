#include <stack>

using namespace std;

typedef stack<int> si;

class MyQueue {
public:
    si s1;
    si s2;
    int top;
    
    MyQueue() {
        si s1;
        si s2; // reversed ordering, basically queue
        int top;
    }
    
    void push(int x) {
        if (s1.empty()) top = x;
        s1.push(x);
    }
    
    int pop() {
        if (!s1.empty() || !s2.empty()) {
            int x;
            if (s2.empty()) {
                while (!s1.empty()) {
                    x = s1.top(); s1.pop();
                    s2.push(x);
                }
            }
            x = s2.top(); s2.pop();
            return x;
        } else {throw -1;}
    }
    
    int peek() {
        if (!s2.empty()) {
            return s2.top();
        }
        
        return top;
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */