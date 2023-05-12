class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        
        vector<int> nums(n,0);
        int val = 0;
        vector<int> ans;
        if(n == 1){
            for(int i = 0;i<queries.size();i++)ans.push_back(0);
            return ans;
        }
        for(int i = 0;i<queries.size();i++){
            int a = queries[i][0],b = queries[i][1];
            int p = a - 1,q = a + 1;
            if(a == 0){
                if(nums[a] != nums[q] && b == nums[q])val++;                
                else if(nums[a] != 0 && nums[a] == nums[q] && b != nums[q])val--;
                
                nums[a] = b;
            }
            else if(a == n - 1){
                if(nums[a] != nums[p] && b == nums[p])val++;
                else if(nums[a] != 0 && nums[a] == nums[p] && b!=nums[p])val--;
                
                nums[a] = b;
            }
            else{
                if(nums[a] != nums[q] && b == nums[q])val++;                
                else if(nums[a] != 0 && nums[a] == nums[q] && b != nums[q])val--;
                
                if(nums[a] != nums[p] && b == nums[p])val++;
                else if(nums[a] != 0 && nums[a] == nums[p] && b!=nums[p])val--;
                
                nums[a] = b;
            }
            
            ans.push_back(val);
        }
        return ans;
        
    }
};
