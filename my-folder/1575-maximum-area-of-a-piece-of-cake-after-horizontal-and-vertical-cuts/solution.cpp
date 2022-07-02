#define ll long long
class Solution {
public:
    int M = 1e9+7;
    
    int maxArea(int h, int w, vector<int>& v, vector<int>& v3) {
        v.push_back(h%M);
        v.push_back(0);
        sort(v.begin(), v.end());
        
        v3.push_back(0);
        v3.push_back(w%M);
        sort(v3.begin(), v3.end());
        
        vector<int> diff;
        vector<int> diff3;
        
        for (int i = 1; i < v.size(); ++i) {
            diff.push_back((v[i] - v[i-1])%M);
        }
        
        for (int i = 1; i < v3.size(); ++i) {
            diff3.push_back((v3[i] - v3[i-1])%M);
        }
        
        sort(diff.begin(),diff.end());
        sort(diff3.begin(),diff3.end());
        
        return ((ll)diff3[diff3.size()-1]%M * diff[diff.size()-1]%M)%M; 
    }
};
