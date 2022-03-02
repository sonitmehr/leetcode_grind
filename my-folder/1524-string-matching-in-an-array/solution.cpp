class Solution {
public:
    
    static bool compare(string a,string b){
        if(a.size()>b.size()){
            return true;
            
        }
        return false;
            
    }
//      ["superhero","^","mass","as","ero"]  
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),compare);
        vector<string>v;
        for(int i = 0;i<n-1;i++){
            if(words[i]!="^"){
                for(int j =i+1;j<words.size();j++){
                    if(words[i].find(words[j])!=string::npos){
                        v.push_back(words[j]);
                        words[j] = "^";
                    }

                }
            }
        }
        return v;
    }
};
