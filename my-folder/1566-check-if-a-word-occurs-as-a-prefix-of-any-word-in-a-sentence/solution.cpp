class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int word = 1;
        if(sentence.substr(0,searchWord.size()).compare(searchWord)==0)return 1;
        for (int i = 0;i<sentence.size();i++){
            
            if(sentence[i] == ' ' ){
                word ++;
            }
            
            if(sentence.substr(i,searchWord.size()).compare(searchWord)==0 && sentence[i-1] == ' '){
                return word;
            }
            
        }
            
        return -1;
        
    }
};
