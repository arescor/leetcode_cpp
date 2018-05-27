#include <stack>
#include <vector>
#include <iostream>
#include <stdexcept>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if(data.empty() || x<= minima.top())
            minima.push(x);
        data.push(x);
    }

    void pop() {
        if(data.empty())
            throw std::out_of_range("Error: pop on empty stack.");
        if(data.top() == minima.top())
            minima.pop();
        data.pop();
    }

    int top() {
        if(data.empty())
            throw std::out_of_range("Error: top on empty stack.");
        return data.top();
    }

    int getMin() {
        if(data.empty())
            throw std::out_of_range("Error: getMin on empty stack.");
        return minima.top();
    }

private:
    std::stack<int> data;
    std::stack<int> minima;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
int main() {
    MinStack test;
    std::vector<int> input = {5, 7, 4, 5, 2, 4, 2, 1, -10, 9, 1};
    for (int x : input){
        test.push(x);
        std::cout << test.top() << " " << test.getMin() << std::endl;
    }
    for (int x : input){
        std::cout << test.getMin() << std::endl;
        test.pop();
    }
    // test.pop();
}
