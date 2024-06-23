class Solution {
public:
    int search(vector<int>& v, int target) {
        int n = v.size();

        int i = 0,j =  n - 1;

        while(i <= j){
            int mid = (i + j)/2;
            int curr = v[mid];
            cout << i << " " << j << " ";
            cout << mid << " " <<curr << " ";
            int left = v[i],right = v[j];
            if(curr == target)return mid;
            if(curr >= left){
                cout << "Enter 1 " << endl;
                if(target >= left && target <= curr)j = mid - 1;
                else i = mid + 1;

            }
            else{
                cout << "Enter 2 " << endl;
                if(target >= curr && target <= right)i = mid + 1;
                else j = mid -1;
            }

        }
        return -1;
    }
};
