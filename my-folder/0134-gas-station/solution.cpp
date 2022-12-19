class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0;
        int sum1 = 0,sum2 = 0;
        for(int i = 0;i<n;i++){
            sum1 += gas[i],sum2 += cost[i];
            gas[i] -= cost[i];
        }
        if(sum1 < sum2)return -1;
        int last = 0;
        for(int i = 0;i<n;i++){
            total += gas[i];
            if(total < 0){
                total = 0;
                last = (i + 1)%n;
            }


        }
        if(total >= 0)return last;
        return -1; 
    }
};
