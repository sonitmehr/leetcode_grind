class Solution {
public:
    int rev(int n){
        int reverse = 0,rem;
        while(n!=0)   
      {    
         rem=n%10;      
         reverse=reverse*10+rem;    
         n/=10;    
      }
        return reverse;
    }
    
    int countDistinctIntegers(vector<int>& v) {
        int n = v.size();
        map<int,int> m;
        for(int i = 0;i<n;i++){
            int t = v[i];
            t= rev(t);
            v.push_back(t);
        }
       // cout << rev(10);
        for(int i = 0;i<v.size();i++)m[v[i]]++;
        //for(auto i : m)cout << i.first << " " << i.second << endl;
        return m.size();
        
    }
};
