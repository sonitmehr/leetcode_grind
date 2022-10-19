class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        // [2,9,9]
        // [3,0,0]
        int n = v.size();
        int i = n - 1;
        
        while(i >=0){
            v[i]++;
            if(v[i] == 10){
                v[i] = 0;
                i--;
            }
            else break;
        }
        if(i == -1)v[0] = 1, v.push_back(0);
        return v;
    }
};
