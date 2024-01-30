class MyQueue {
private:
    std::stack<int> input, output;

    void transferStacks() {
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
    }

public:
    void push(int x) {
        input.push(x);
    }

    int pop() {
        if (output.empty()) {
            transferStacks();
        }
        int front = output.top();
        output.pop();
        return front;
    }

    int peek() {
        if (output.empty()) {
            transferStacks();
        }
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
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