class Solution {
public:

    bool vow(char c){
        if(tolower(c) == 'a')return true;
        if(tolower(c) == 'e')return true;
        if(tolower(c) == 'i')return true;
        if(tolower(c) == 'o')return true;
        if(tolower(c) == 'u')return true;
        return false;
    }
    string sortVowels(string s) {
        int n =s.size();
        vector<char> vec;
        for(char &c : s){
            if(vow(c)){
                vec.push_back(c);
            }
        }
        sort(vec.begin(),vec.end());
        // for(auto &i : vec)cout << i<< " ";
        // cout << endl;
        int cnt = 0;
        for(char &c : s){
            if(vow(c)){
                c = vec[cnt];
                cnt++;
            }
        }
        return s;
    }
};