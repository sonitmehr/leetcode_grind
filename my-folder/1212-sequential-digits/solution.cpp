class Solution {
public:
    int getDigit(int n) {
        int digit = 0;
        while (n > 0) {
            n /= 10;
            digit++;
        }
        return digit;
    }
    int makeFirstDigit(int i) {
        int val = 2;
        int first = 1;
        i--;
        while (i--) {
            first = 10 * first + val;
            val++;
        }
        return first;
    }
    int getNext(int first, int sz) {
        sz--;
        int val = 1;
        while (sz--) {
            val = 10 * val + 1;
        }
        return val;
    }
    vector<int> sequentialDigits(int low, int high) {
        unordered_map<int, vector<int>> mp;
        int val = 8;
        for (int i = 2; i <= 9; i++) {
            int first = makeFirstDigit(i);
            int next = getNext(first, i);
            // cout << first << " ";
            vector<int> arr;
            int eight = 8;
            while (first%10 != 0) {
                arr.push_back(first);
                first += next;
                // cout << first << " ";
            }
            // cout << endl;
            mp[i] = arr;
            // cout << first <<" "<< next  << endl;
        }

        int one = getDigit(low);
        int two = getDigit(high);
        vector<int> ans;
        for (int i = one; i < two; i++) {
            for (auto& val : mp[i]) {
                if(val >= low && val <= high){
                ans.push_back(val);
            }
            }
        }
        for(auto& val : mp[two]){
            if(val >= low && val <= high){
                ans.push_back(val);
            }
        }
        return ans;
    }
};
