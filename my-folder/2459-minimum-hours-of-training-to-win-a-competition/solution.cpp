class Solution {
public:
    int minNumberOfHours(int iEnergy, int iExp, vector<int>& e, vector<int>& ex) {
        int n = e.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(iEnergy <= e[i]){
                int t = (e[i] + 1 - iEnergy);
                ans += t;
                iEnergy += t;
                    //iEnergy -= e[i];
            }
            
            
            //cout << "ans1 " << ans << endl;
            if(iExp <= ex[i]){
                int t = (ex[i] + 1 - iExp);
                ans += t;
                iExp += t;
            }
            iEnergy -= e[i];
            
            iExp += ex[i];
            
            //cout << "ans2 " << ans << endl;
        }
        return ans;
    }
};
