class Solution {
public:
    int arithmeticTriplets(vector<int>& v, int diff) {
        int n = v.size();
        int cnt = 0;
        map<int,int> m;
        
        for(int i =0;i<n;i++){
            m[v[i]]++;
        }
        for(int i = 0;i<n;i++){
            int one = v[i] + diff;
            int two = v[i] + 2*diff;
            
            if(m[one] > 0 && m[two] > 0){
                cnt++;
                
            }
            //m[v[i]]--;
            
        }
        return cnt;
    }
};
