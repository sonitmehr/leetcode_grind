class FreqStack {
    
public:
    // WHTA IS HAPPENING.
    unordered_map<int,int> m;
    unordered_map<int,stack<int>>m1;
    int max_frequency;
    
    FreqStack() {
        max_frequency = 0;
    }
    
    void push(int val) {
        m[val]++;
        if(m[val] > max_frequency) max_frequency = m[val];
        m1[m[val]].push(val);
    }
    
    int pop() {
        int curr = m1[max_frequency].top();
        m1[max_frequency].pop();
        m[curr]--;
        if(m1[max_frequency].empty()){
            m1.erase(max_frequency);
            max_frequency--;
        }
        return curr;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
