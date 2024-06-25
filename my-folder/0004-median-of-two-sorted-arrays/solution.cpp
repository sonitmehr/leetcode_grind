class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size(),n2 = v2.size();
        if(n1 > n2)return findMedianSortedArrays(v2,v1);

        int low = 0,high = n1;
        int tot = (n1 + n2 + 1)/2;
        int n = n1 + n2;
        while(low <= high){
            int mid1 = (low + high)/2;
            int mid2 = tot - mid1;

            int l1 = INT_MIN,l2=INT_MIN;
            int r1 = INT_MAX,r2=INT_MAX;
            cout << mid1 << " " << mid2 << endl;
            if(mid1 < n1)r1 = v1[mid1];
            if(mid2 < n2)r2 = v2[mid2];

            if(mid1 - 1 >= 0)l1 = v1[mid1 - 1];
            if(mid2 - 1 >= 0)l2 = v2[mid2 - 1];
cout << l1 << " " << l2 << " " << r1 << " " << r2 << endl;
            if(l1 <= r2 && l2 <= r1){
                if(n % 2 == 1)return max(l1,l2);
                else {
                    return (max(l1,l2) + min(r1,r2))/2.0;
                }
            }
            else if(l1 > r2){
                high = mid1-1;
            }
            else low = mid1 + 1;
        }
        return -1;
//  return (v1[l1] + v2[r2])/2.0;

    }
};
