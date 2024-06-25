class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
        int n  = v.size();
        int i =0 ,j = n - 1;
        while(i <= j){
            int mid = (i + j )/2;

            int correctInd = v[mid] - 1;
            int missing = correctInd - mid;
            cout << mid << " " << v[mid]  << " " << missing << endl;
            if(missing >= k){
                j = mid - 1;
            }
            else{
                i = mid + 1; 
            }
        }
        if(i == n)i = n - 1;
        int ans = v[i];

        int missing = v[i] - 1 - i;
        if(missing>=k){
            ans -= (missing - k + 1);
        }
        else{
            ans += (k -missing);
        }
            
        
        return ans;
    }
};

// [2,3,4,7,11]
// [1,2,3,4,5,6,7,8,9,10]
// v[i] -> (i - 1) index

