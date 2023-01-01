class Solution {
public:
    vector<string> vec;
    void f(string s){
        
        int n = s.size();
        for(int i = 0;i<n;i++){
            int j = i;
            while( j < n && s[j] != ' ')j++;
            vec.push_back(s.substr(i,j- i));
            i = j;

        }
        

    }
    bool wordPattern(string pattern, string s) {
        map<char,string> m1;
        map<string,char> m2;
        int n = pattern.size();
        f(s);
        for(auto i : vec)cout << i << " ";
        //cout << vec.size() << " " << n << endl;
        if(vec.size() != n)return false;
        for(int i = 0 ;i<n;i++){
            //cout << pattern[i] << " " << vec[i] << endl;
            if(m1.find(pattern[i]) == m1.end() && m2.find(vec[i]) == m2.end()){
                m1[pattern[i]] = vec[i];
                m2[vec[i]] = pattern[i]; 
            }
            else if(m1[pattern[i]] != vec[i] || m2[vec[i]] != pattern[i])return false;
        }
        return true;
    }
};
