class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> map;
        vector<int> v;
        int n1 = nums1.size(),n2 = nums2.size();
        for(auto i : nums1){
            map[i] = -1;
        }
        for(auto i : nums2){
            while(!st.empty() && st.top() < i){
                map[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for(int i = 0;i<n1;i++){
            v.push_back(map.find(nums1[i])->second);
        }
        return v;
            
    }
};
