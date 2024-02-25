class Solution {
public:

    void convertToBits(string s,unordered_set<int> &uniqueBits){
        int stringToBit = 0;
        bool flag = true;
        for(char &c : s){
            int charToBit = (1 << (c - 'a'));

            if(stringToBit & charToBit){
                flag = false;
                continue;
            }
            stringToBit |= charToBit;
        }
        if(flag){
            int len = (s.size() << 26);
            stringToBit |= len;
            uniqueBits.insert(stringToBit);
            
        }

    }

        
    int solve(int i,int oldResult,vector<int> &uniqueBits){

        int oldValue = oldResult & ((1 << 26) - 1);
        int oldValueLen = oldResult >> 26;
        int best = oldValueLen;
        if(i >= uniqueBits.size()){
            return oldValueLen;
        }

        int newValue = uniqueBits[i] & ((1 << 26) - 1);
        int newValueLen = uniqueBits[i] >> 26;

        int mergedResult = oldValue & newValue;
        
        if(mergedResult == 0){
            int mergedResultLen = oldValueLen + newValueLen;

            int mergedResultWithLen = (oldValue | newValue) | (mergedResultLen << 26);

            best = solve(i + 1,mergedResultWithLen,uniqueBits);
        }

        best = max(best,solve(i + 1,oldResult,uniqueBits));
        return best;


    }

    int maxLength(vector<string>& arr) {
        
        unordered_set<int> uniqueBit;
        for(auto &a : arr){
            convertToBits(a,uniqueBit);
        }

        
        vector<int> uniqueBits(uniqueBit.begin(),uniqueBit.end());
        
        return solve(0,0,uniqueBits);

    }
};
