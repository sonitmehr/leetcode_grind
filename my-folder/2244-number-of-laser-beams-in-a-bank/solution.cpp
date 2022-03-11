class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        int count,prev=0,finalSum=0;
        
        for(int i = 0;i<n;i++){
            count = 0;
            for(int j = 0;j<m;j++){
                if(bank[i][j]=='1'){
                    count++;
                }
            }
            finalSum += (prev*count);
            if(count!=0)prev = count;
        }
        return finalSum;
    }
};
