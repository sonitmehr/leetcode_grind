class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        
        // VERY GOOD LOGIC. TOPPER CODE.
        
        if (finalSum % 2) return {};
        vector<long long> v;
        for (long long i = 2; i <= finalSum; i += 2) { // final = 8
                                                       // v = [2,4,6,16]
            v.push_back(i);
            finalSum -= i;
        }
        v.back() += finalSum;
        return v;
    }
};
