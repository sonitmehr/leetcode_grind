class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long>v;
        if(finalSum %2==1)return v;
        for(long long i = 2;i<=finalSum;i+=2){
            v.push_back(i);
            finalSum-=i;
        }
        v.back() += finalSum;
        return v;
    }
};
