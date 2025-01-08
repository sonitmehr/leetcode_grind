class Solution {
public:

    bool check(string s1,string s2){
        int n1= s1.size();
        int n2 = s2.size();

        if(n2 < n1)return false;

        string pre = s2.substr(0,n1);
        string suff = s2.substr(n2 - n1,n1);
        // cout << pre << " " << suff << endl; 
        return suff == s1 && pre == s1;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++){
                if(check(words[i],words[j]))ans++;
            }
        }
        return ans;
    }
};
