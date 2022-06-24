class Solution {
public:
    bool search(vector<int>& v, int target) {
        int n = v.size();
        
        int i  =0,j = n-1;
        
        while(i <=j){
            
            int mid = i + (j-i)/2;
            
            int curr = v[mid];
            
            if(curr == target)return true;
            else if(v[i] == curr  && curr == v[j]){
                if(curr == target)return true;
                i++;j--;
            }
            // Left part.
            else if(curr >= v[i]){
                if(target >= v[i] && curr >= target){
                    j = mid-1;
                }
                else i =mid + 1; 
            }
            
            else{
                if(target <= v[j] && target >= curr){
                    i = mid + 1;
                }
                else j = mid - 1;
            }
        }
        return false;
        
    }
}; // [1,0,1,1,1]

