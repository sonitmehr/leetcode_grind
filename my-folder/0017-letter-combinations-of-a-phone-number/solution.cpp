class Solution {
public:

    void solve(int i,string digits,string currString,vector<string> &ans,vector<string> &keys){
        if(i > digits.size())return ;

        if(i == digits.size()){
            ans.push_back(currString);
            return;
        }

        int currDigit = digits[i] - '0';
        
        for(int k = 0;k<keys[currDigit].size();k ++){
            currString.push_back(keys[currDigit][k]);
            // cout << currString << " " << i << " " << keys[currDigit].size() << endl;
            solve(i + 1,digits,currString,ans,keys);
            currString.pop_back();
        }


    }

    vector<string> letterCombinations(string digits) {
        if(digits.size () == 0)return {};
        vector<string> keys = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        solve(0,digits,"",ans,keys);
        return ans;
        


    }
};
