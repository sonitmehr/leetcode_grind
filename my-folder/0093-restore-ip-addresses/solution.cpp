class Solution {
public:
    string s;
    int n;
    vector<string> ans;

    void f(int i,int dots,string curIP){
        if(i == n && dots == 4){
            curIP.pop_back();
            ans.push_back(curIP);
            return;
        }
        else if(i == n || dots>4)return;
        
        for(int j = i;j<i+3 && j < n;j++){
            if(stoi(s.substr(i,j-i + 1)) <= 255 && (i == j || s[i] != '0')){
                string t = curIP;
                curIP += s.substr(i, j-i+1);
                curIP += ".";
                f(j+1,dots+1,curIP);
                curIP = t;
                // curIP.pop_back();
                // curIP.pop_back();
            }
        }


    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        if(n > 12)return {};

        this->s = s;
        this -> n = n;
        f(0,0,"");
        return ans;

    }
};
