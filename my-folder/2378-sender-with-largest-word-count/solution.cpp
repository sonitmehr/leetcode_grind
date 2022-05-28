class Solution {
public:

    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        vector<string> v1 = messages,v2 = senders;
        int n= messages.size();
        map<string,int>m;
        int maxi = 0;
        string prev;
        for(int i = 0;i<n;i++){
            
           // string previous
            int words = count(begin(messages[i]), end(messages[i]), ' ') + 1;
            m[v2[i]] += words;
       //     maxi = max(maxi,m[v2[i]]);
            if (m[v2[i]] > maxi || (maxi == m[v2[i]] && v2[i] > prev)) {
                maxi = m[v2[i]];
                prev = v2[i];
            }
            
        }
        
       return prev;
    }
};
