class Solution {
public:
    bool search(vector<int>& v, int target) {
        int n = v.size();

        int i = 0,j =  n - 1;

        while(i <= j){
            int mid = (i + j)/2;
            int curr = v[mid];
            int left = v[i],right = v[j];
            cout << i << " " << j << " ";
            cout << mid << " " <<curr << " ";
           if(curr == target)return true;
           if(curr == left && left == right){
                i++;
                j--;
           }
            else if(curr >= left && curr >= right){cout << "Enter 1 " << endl;
                if(target == left)return true;
                if(target >= left && target <= curr)j = mid - 1;
                else i = mid + 1;

            }
            else{cout << "Enter 2 " << endl;
                if(target == right)return true;
                if(target >= curr && target <= right)i = mid + 1;
                else j = mid -1;
            }

        }
        return false;
    }
};
