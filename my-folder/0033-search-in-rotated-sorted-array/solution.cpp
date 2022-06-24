class Solution {
public:
    int search(vector<int>& v, int target) {
        int n = v.size();
        
        int i = 0;
        int j = n-1;
        
        while(i <= j){
            
            int mid = i + (j - i)/2;
            int ele = v[mid];
            if( ele == target)return mid;
            
            // Check left.
            // If mid >= leftmost, then mid is in left part of rotated array.
            
            else if(ele >= v[i]){ // v[i] is left most element. 
                
                // Is the leftmost element in left part >= target element?
                if(target >= v[i] && ele >= target){
                    j = mid -1;
                }
                else i = mid + 1;
                
            }
            
            // This is when mid is in right part of rotated array.
            else { // v[j] is the right most element
                if(target <= v[j] && ele <= target){
                    i = mid +1;
                }
                else j = mid - 1;
                    
            }
            
        }
        return -1;
        
    }
};
