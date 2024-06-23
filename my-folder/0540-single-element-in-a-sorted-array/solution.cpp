class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int n = v.size();
        int i = 0,j = n -1;

        while(i <= j){
            int mid = (i + j)/2;
            int curr = v[mid];
            int prev = -1,next = -1;

            if(mid > 0)prev = v[mid - 1];
            if(mid < n - 1)next = v[mid + 1];

            if(prev != curr && next != curr)return curr;

            if(prev == curr){
                if((mid - 1) % 2 == 0)i = mid + 1;
                else j = mid - 1;
            }
            else if(next == curr){
                if(mid % 2 == 0) i = mid + 1;
                else j = mid - 1;
            }
        }
        return -1;
    }
};
