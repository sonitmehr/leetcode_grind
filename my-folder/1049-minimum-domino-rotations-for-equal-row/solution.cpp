class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n1 = tops.size();
        int n2 = bottoms.size();
        
        int count1  =0,count2=0,ind=0;
        int ptr1 = 0,ptr2 = 0;
        int value = tops[ind];
        while(ind < n1){
            value= tops[ind];
            count1=count2 = 0;
            ptr1=ptr2=0;
            while(ptr1 < n1 && (tops[ptr1] == value || bottoms[ptr1] == value)){
                if(tops[ptr1] != value && bottoms[ptr1] == value)count1++;
                if(tops[ptr1] == value && bottoms[ptr1] != value)count2++;
                ptr1++;ptr2++;
            }
            if(ptr1 == n1){
                return min(count1,count2);
            }
            
            ind++;
        }
        return -1;
        
    }
};
