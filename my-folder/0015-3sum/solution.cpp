class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        for(int k=0;k<=n-3;k++){
            int i = k+1,j = n-1,target = -1*nums[k];
            if(k > 0 && nums[k] == nums[k-1])continue;
            while(i<j){ 
                if(nums[i]+nums[j]==target){
                    v.push_back({nums[k],nums[i],nums[j]});
                    int low = i,high = j;
                    int last_low_occurence = nums[low] , last_high_occurence = nums[high];
                    while(low < high && nums[low] == last_low_occurence){   
                        low++;i++;
                    }
                    while(low < high && nums[high] == last_high_occurence){
                        high--;j--;
                    }
                }
                else if(nums[i]+nums[j]>target)j--; 
                else i++;
            }
        }
        return v;
            
        //[-4,-1,-1,0,1,2]
    }
};
