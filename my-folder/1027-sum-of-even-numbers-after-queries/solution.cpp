class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& v1, vector<vector<int>>& v2) {
        vector<int> ans;
        
        int n1 = v1.size();
        
        int sum = 0;
        for(auto i : v1)if(i%2 == 0) sum += i;
        
        for(auto i : v2){
            int ele = v1[i[1]];
            int add = i[0];
            if(abs(ele + add) %2 == 0){
                if(ele%2==0)sum -= ele;
                sum += (add + ele);                
            }
            else{
                if(ele%2==0)sum -= ele;                
            }
            
            v1[i[1]] = (ele + add);
            // for(auto ii: v1)cout << ii << " ";
            // cout <<sum<< endl;
            ans.push_back(sum);
        }
        return ans;
        
    }
};
