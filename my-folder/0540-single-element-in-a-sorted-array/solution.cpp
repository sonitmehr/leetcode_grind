class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int n = v.size();
        int l = 0,r = n -1 ;
        if(n == 1)return v.back();
        while(l <= r){
            int mid = (l + r)/2;
            //cout << l << " " << r << endl;
            if((mid == 0 || v[mid] != v[mid - 1]) && (mid == n -1 || v[mid] != v[mid + 1]))return v[mid];

            if(mid%2 == 1 && v[mid] == v[mid - 1])l = mid + 1;
            else if(mid%2 == 0 && v[mid] == v[mid + 1])l = mid + 1;
            else r = mid - 1;
            //cout << l << " " << r << endl <<endl;
        }
        return -1;
    }
};
