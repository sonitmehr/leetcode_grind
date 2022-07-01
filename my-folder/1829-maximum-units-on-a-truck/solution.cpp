class Solution {
public:
    static bool sortcol(vector<int>& v1, vector<int>& v2)
    {
        return v1[1] > v2[1];
    }
    int maximumUnits(vector<vector<int>>& v, int k) {
        int n = v.size();
        
        sort(v.begin(),v.end(),sortcol);
        
        int sum = 0;
        
        for(int i = 0;i<n;i++){
            if(k >= v[i][0])sum += (v[i][0]*v[i][1]);
            else{
                sum += k*v[i][1];
                break;
            }
            k-= v[i][0];
            
        }
        return sum;
    }
};//[[2,5],[3,9],[4,7],[5,10]]; 10 + 27 + 28 + 10
