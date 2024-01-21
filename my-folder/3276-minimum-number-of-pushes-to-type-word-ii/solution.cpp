class Solution {
public:
    int minimumPushes(string word) {
        
        int n = word.size();
        // aabbccddeeffgghhiiiiiij
        map<char,int> mp;
        for(auto &i : word){
            mp[i] ++;
        }
        string word_new = "";
        vector<pair<int,char>> vec;
        for(auto &i : mp){
            vec.push_back({i.second,i.first});
        }
        sort(vec.begin(),vec.end());
                reverse(vec.begin(),vec.end());
        
        for(auto &i : vec){
            for(int j = 0;j<i.first;j++){
                word_new += i.second;
            }
        }
        // cout << word_new << endl;
        word = word_new;        
        int curr_num = 2;
        int num_presses = 1;
        int ans = 0;
        map<char,int> seen_char;
        
        for(int i =0 ;i <n;i++){
            char c = word[i];
            
            if(seen_char.find(c) == seen_char.end()){
                if(curr_num == 10){
                    // cout << "Entered " << " " <<i << endl;
                    curr_num = 2;
                    num_presses ++;
                }
                seen_char[c] = num_presses;
                ans += num_presses;
                curr_num++;                
                // cout << "Seeing First Time " << c << endl;

            }
            else{
                ans += seen_char[c];
                // cout << "Seen Already " << c << endl;
            }
            // cout << curr_num << " ";
                            // cout  << i  << " " << ans << endl; 

            
            
            
            
        }
        return ans;
        
        
    }
};
