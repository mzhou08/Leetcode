#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class MinStack {
public:
    vi stack;
    vvi min_elems_stack;

    MinStack() {
        stack = vi(0);
        min_elems_stack = vvi(0, vi(0));
    }
    
    void push(int val) {

        if (stack.size() != 0) {
            if (val < getMin()) {
                vi new_min_track {val, 1};
                min_elems_stack.push_back(new_min_track);
            } else if (val == getMin()) {
                min_elems_stack.back()[1]++;
            }
        } else {
            vi new_min_track {val, 1};
            min_elems_stack.push_back(new_min_track);
        }

        stack.push_back(val);
    }
    
    void pop() {
        if (stack.size() != 0) {
            if (stack.back() == min_elems_stack.back()[0]) {
                if (min_elems_stack.back()[1] == 1) {
                    min_elems_stack.pop_back();
                } else {
                    min_elems_stack.back()[1]--;
                }
            }
            stack.pop_back();
        }
    }
    
    int top() {
        if (stack.size() != 0) {
            return stack.back();
        }
        return INT_MAX;
    }
    
    int getMin() {
        if (stack.size() != 0) {
            return min_elems_stack.back()[0];
        }
        return INT_MAX;
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