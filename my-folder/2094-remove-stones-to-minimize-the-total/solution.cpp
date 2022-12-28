class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> q;
        for(int i= 0;i<n;i++){
            q.push(piles[i]);
        }
        while(!q.empty() && k > 0){
            int top = q.top();
            q.pop();
            top -= (top)/2;
            if(top > 0)q.push(top);
            k--;
        }
        int sum = 0;
        while(!q.empty()){
            sum += q.top();
            q.pop();
        }
        return sum;


    }
};
 // 4 -> 0100
 // 5 -> 0101
 // 9 -> 1001
 // 7 -> 0111
