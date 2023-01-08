class Solution {
public:
    bool isItPossible(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        
        map<char,int> m1,m2;
        for(int i= 0;i<n1;i++)m1[s1[i]]++;
        for(int i= 0;i<n2;i++)m2[s2[i]]++;
        int a = m1.size(),b = m2.size();
        int diff = abs(a-b);
        if(diff >= 3)return false;
        
        for(char c1 = 'a';c1<='z';c1++){
            for(char c2 = 'a';c2<='z';c2++){
                if(m1[c1] > 0 && m2[c2] > 0){
                    //a = m1.size(),b = m2.size();
                    //if(m2[c2] == 1)a--;
                    m1[c1]--;
                   // if(m1[c1] == 1)b--;
                    m2[c2]--;
                    
                    //if(m1[c2] == 0)a++;
                    m1[c2]++;
                    //if(m2[c1] == 0)b++;
                    m2[c1]++;
                    
                    //cout << a << " " << b << endl;
                    int unique1 = 0,unique2 = 0;
                    for(char c = 'a';c<='z';c++){
                        if(m1[c] > 0)unique1++;
                        if(m2[c] > 0)unique2++;
                    }
                    if(unique1 == unique2)return true;
                    m2[c1]--;
                    m1[c2]--;
                    m1[c1]++;
                    m2[c2]++;
                }
            }
        }
        return false;
        
    }
};
