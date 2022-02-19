class Solution {
public:
    int firstUniqChar(string s) {
	//taking array size of 123 as ascii value of lower alphabets lies between 97 to 123--
        int arr[26]={0};
        for(int i=0;i<s.size();i++){
            arr[s[i] -'a']++;
        }
        cout << arr[0]; 
        for(int i = 0;i<s.size();i++){
            if(arr[s[i] - 'a']==1)return i;
        }
        return -1;
    }
};
