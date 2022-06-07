class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1,j =n-1,ptr =n+m-1;
        if(m==0) nums1 = nums2;
        while(i>=0 && j>=0){
            if(nums2[j] >= nums1[i]){
                nums1[ptr] = nums2[j];
                j--;
                ptr--;
                
            }
            else if(nums2[j] < nums1[i]){
                nums1[ptr] = nums1[i];
                i--;
                ptr--;
                
            }
            
        }
        while(j >=0){
            nums1[ptr] = nums2[j];
            j--;
            ptr--;
        }
        
            
    }
};
