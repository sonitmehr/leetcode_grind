class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevFreq = 0,devices=0,lasers = 0;
        int rows = bank.size();
        int col  = bank[0].size();
        
        for(int i = 0;i<rows;i++){
            devices=0;
            for(int j = 0;j<col;j++){
                if(bank[i][j] == '1') devices++;
            }if(devices == 0) continue;
            else{
                lasers += prevFreq*devices;
                prevFreq = devices;
            }
            
        }
        return lasers;
    }
};
