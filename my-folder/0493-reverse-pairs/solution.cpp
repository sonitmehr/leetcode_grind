class Solution {
public:
long long ans = 0,N;
    void merge(int low,int mid,int high,vector<int>& arr){
        
        vector<int> temp;
        // cout << low << " " << mid << " " << high << endl;
        int left = low;
        int right = mid + 1;
        

        for(int i= low;i<=mid;i++){
            while(right <= high && arr[i]> 2 * (long long)arr[right] )right++;
            ans += (right - mid - 1);
        }

        left = low;
        right = mid + 1;

        while(left <= mid && right <= high){
            
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left <= mid){
            temp.push_back(arr[left]);
                left++;
        }
        while(right <= high){
            temp.push_back(arr[right]);
                right++;
        }
        
        for(int i= low;i<=high;i++){
            // cout << temp[i] << " ";
            arr[i] = temp[i - low];
        }
        // cout << endl;
        
    }
    
    void mergeSort(int low,int high,vector<int>& arr){
        if(low >= high)return;
        long long mid = (low + high)/2;
        
        mergeSort(low,mid,arr);
        mergeSort(mid + 1,high,arr);
        
        merge(low,mid,high,arr);
        
        
    }
    int reversePairs(vector<int>& arr) {
        int n = arr.size();
        ans = 0;
        mergeSort(0,n-1,arr);
        // for(int i= 0;i<n;i++)cout << arr[i] << " ";
        
        return ans;
    }
};
