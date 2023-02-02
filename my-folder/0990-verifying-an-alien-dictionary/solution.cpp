class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> m;
        for(int i= 0;i<order.size();i++)m[order[i]] = i;
/*hello
  leetcode*/
            m['*'] = -1;
        for(int i= 0;i<words.size()-1;i++){
            int n1 = words[i].size();
            int n2 = words[i+1].size();
            int mini = min(words[i].size(),words[i+1].size());
            while(n1!=n2){
                if(n1 < n2)words[i] += "*";
                else if(n2 < n1)words[i+1] += "*";
                n1 = words[i].size();
                n2 = words[i+1].size();
            }
            for(int j =0;j<n1;j++){
                char a = words[i][j];
                char b = words[i+1][j];
                if(a == b)continue;
                int pos1 = m[a];
                int pos2 = m[b];

                if(a!=b && pos1 > pos2){
                    cout << i << " " << j << " " << pos1 << " " << pos2;
                    return false;
                }
                else break;

            }
        }
        return true;
    }
};
