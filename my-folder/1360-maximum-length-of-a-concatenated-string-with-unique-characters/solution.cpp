class Solution {
public:
    bool check(string s1,string s2){
        map <char,int> m1,m2;
        for(auto i : s1){
            if(m1[i] > 0)return false;
            m1[i]++;
        }
        for(auto i : s2){
            if(m2[i] > 0)return false;
            m2[i]++;
        }
        for(int i = 0;i<26;i++){
            //cout << i << " ";
            if(m1[i + 'a'] > 0 && m2[i + 'a'] > 0 )return false;
        }
        return true;
    }
    int maxi = 0;
    void f(int i,vector<string>&a,string s,int size){
        //if(i >= a.size())return;
        
        if(i >= a.size()){
            //cout << s << " "<< size << endl;
            maxi = max(size,maxi);
            return;
        }
        
        for(int ind = i;ind <a.size();ind++){
            if(check(s,a[ind])== false){
                maxi = max(maxi,size);
                continue;
            }
            //cout << s << " " << a[ind] << endl;
            s = s + a[ind];
            //cout << s << " hi ";
            f(ind+1,a,s,size + a[ind].size());
            for(int k = 0;k<a[ind].size();k++)s.pop_back();
        }
        
        
        
    }
    
    int maxLength(vector<string>& a) {
        int n = a.size();
        //int maxi = 0;
        map<char,int> m;
        string s ;
        f(0,a,s,0);
        return maxi;
        
        
        
    }
};
