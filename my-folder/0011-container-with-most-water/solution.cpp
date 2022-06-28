class Solution {
public:
    int maxArea(vector<int>& v) {
        int n = v.size();
        
        int l = 0, r = n - 1;
        
        int area = 0;
    
        while(l < r){
            int ele = min(v[l],v[r])*(r-l);
            area = max(area,ele); 
            if(v[r] < v[l])r--;
            
            else l++;
            
        }
        return area;
    }
};
