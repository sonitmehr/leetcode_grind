class Solution {
public:
    int minimumPartition(string s, int k) {
        int n =s.size();
        int maxi = 0;
        
        for(int i = 0;i<n;i++){
            int c = s[i] - '0';
            maxi = max(maxi,c);
        }
        if(maxi > k)return -1;
        int y = k,sz = 0;
        while (y > 0){
            y/=10;
            sz++;
        }
        int j = sz;
        string t;
        int cnt = 0;
        for(int i = 0;i<n;){
            // "165462"

            t = s.substr(i,sz);
            //cout << t <<  " " << i << " ";
            if(stoi(t) > k){
                i += (sz - 1);
            }
            else i += sz;
            cnt++;
            //cout << i << endl;
            
        }
        return cnt;
    }
};
