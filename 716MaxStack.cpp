#include <vector>
#include <stack>
#include <stdexcept>

class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {

    }

    void push(int x) {
        if(data.empty() || x>=maxima.top())
            maxima.push(x);
        data.push(x);
    }

    int pop() {
        if(data.top() == maxima.top())
            maxima.pop();
        int res=data.top();
        data.pop();
        return res;
    }

    int top() {
        return data.top();
    }

    int peekMax() {
        return maxima.top();
    }

    int popMax() {
        std::stack<int> cache;
        while(data.top() != maxima.top()) {
            cache.push(data.top());
            data.pop();
        }
        int res=data.top();
        data.pop();
        maxima.pop();

        while(!cache.empty()) {
            push(cache.top());
            cache.pop();
        }
        return res;
    }

private:
    std::stack<int> data;
    std::stack<int> maxima;
};

int main() {
    MaxStack test;
    std::vector<int> inputs = {1, 2, 5, 3, 6, 7, 10, 4, 6, 7};
    for(int x : inputs){
        test.push(x);
        std::cout << test.top() << " " << test.peekMax() << std::endl;
    }
    for(std::size_t i=0; i<inputs.size(); ++i) {
        std::cout << test.peekMax() << std::endl;
        test.popMax();
    }
    //test.popMax();
}
