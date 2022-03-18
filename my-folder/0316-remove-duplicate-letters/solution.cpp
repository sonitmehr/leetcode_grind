class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        int a[26]={0};
        int last[26] = {0};
        
        for(int i = n-1;i>=0;i--){
            if(last[s[i]-'a']==0){
                last[s[i]-'a'] = i;
            }
        }
        stack<char> stack;
        for(int i = 0;i<n;i++){
            
            int c = s[i]-'a';
            if(a[c])continue;
            while(!stack.empty() && stack.top() > s[i] && i < last[stack.top()-'a']){
                a[stack.top() - 'a'] = 0;
                stack.pop();
            }
            stack.push(s[i]);
            a[c] = 1;
            
        }string s1;
        while(!stack.empty()){
            s1.push_back(stack.top());
            stack.pop();
        }reverse(s1.begin(),s1.end());
        return s1;
    }
};
/*
"abbccccd"
stack = [c,b,a,c,d,c,b,c]
*/
