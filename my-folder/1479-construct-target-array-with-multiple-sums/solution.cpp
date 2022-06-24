class Solution {
public:
    bool isPossible(vector<int>& t) {
        long long n=t.size();

        long long sum=0,mx=0;
        for(int i=0;i<n;i++){
            sum+=t[i];
            if(t[mx]<t[i])
                mx=i;
        }

        long long diff=sum-t[mx];
        if(t[mx]==1||diff==1)return true;
        if(diff>t[mx]||diff==0||t[mx]%diff==0)return false;

        t[mx]%=diff;


        return isPossible(t);
    
    
    }
};
