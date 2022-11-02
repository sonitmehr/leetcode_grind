#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree <int, null_type, less_equal <int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Solution {
public:
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        pbds st;
        
        vector <int> vec;
        
        for(int i = n-1; i >= 0; i--){
            
            vec.push_back(st.order_of_key(nums[i]));
            st.insert(nums[i]);
            
        }
        
        reverse(vec.begin(), vec.end());
        return vec;
    }
};
