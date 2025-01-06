class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> mp;

        for(int i = 0;i<n;i++){
            if(boxes[i] == '1'){

                mp.push_back(i);
            }
        }
        vector<int> ans;
        for(int i = 0;i<n;i++){
            int val = 0;
            for(auto &p : mp){
               
                val += abs(i - p);
            }
            ans.push_back(val);
        }
        return ans;
        

    }
};
