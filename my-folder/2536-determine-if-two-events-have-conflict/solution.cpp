class Solution {
public:
    int f(string s){
        int val = 0;
        for(int i = 0;i<s.size();i++){
            val = 10*val + (s[i] - '0');
        }
        return val;
            

    }
    
    bool haveConflict(vector<string>& v1, vector<string>& v2) {
        string hr1,hr2,hr3,hr4;
        hr1 = v1[0].substr(0,2);hr2 = v1[1].substr(0,2);
        hr3 = v2[0].substr(0,2);hr4 = v2[1].substr(0,2);
        
        string min1,min2,min3,min4;
        min1 = v1[0].substr(3,4);min2 = v1[1].substr(3,4);
        min3 = v2[0].substr(3,4);min4 = v2[1].substr(3,4);
        //cout << min1 << " " << min2 << " " << min3  << " " << min4 << endl;
        int time1 = 60*(f(hr1)) + f(min1);
        int time2 = 60*(f(hr2)) + f(min2);
        int time3 = 60*(f(hr3)) + f(min3);
        int time4 = 60*(f(hr4)) + f(min4);
        //cout << time1 << " " << time2 << " " << time3  << " " << time4 << endl;
        for(int i = time3;i<=time4;i++){
            if(i >= time1 && i <= time2)return true;
        }
        for(int i = time1;i<=time2;i++){
            if(i >= time3 && i <= time4)return true;
        }
        return false;
        
    }
};
