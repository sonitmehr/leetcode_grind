class MyQueue {
private:
    stack<int> temp, qStack;
public:
    // TRY QUESTION AGAIN ON YOUR OWN
    void push(int x) {
        for (; !qStack.empty(); qStack.pop()) {
            temp.push(qStack.top());
        }
        qStack.push(x);
        for (; !temp.empty(); temp.pop()) {
            qStack.push(temp.top());
        }
    }
    
    int pop() {
        int elem = peek();
        qStack.pop();
        return elem;
    }
    
    int peek() {
        return qStack.top();
    }
    
    bool empty() {
        return qStack.empty();
    }
};
