class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> d = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int arriveAliceMonth = stoi(arriveAlice.substr(0,2));
        int leaveAliceMonth = stoi(leaveAlice.substr(0,2));
        
        int arriveAliceDay = stoi(arriveAlice.substr(3,5));
        int leaveAliceDay = stoi(leaveAlice.substr(3,5));
        
        
        int arriveBobMonth = stoi(arriveBob.substr(0,2));
        int leaveBobMonth = stoi(leaveBob.substr(0,2));
        
        int arriveBobDay = stoi(arriveBob.substr(3,5));
        int leaveBobDay = stoi(leaveBob.substr(3,5));
        
        
        
        int minEnd = min(leaveBobMonth,leaveAliceMonth);
        int maxStart = max(arriveAliceMonth,arriveBobMonth);
        
        string start = "a";
        string end = "a";
        if(arriveAliceMonth == arriveBobMonth){
            if(arriveAliceDay < arriveBobDay)start = "b";
            else start = "a";
            
            if(leaveAliceDay < leaveBobDay) end = "a";
            else end = "b";
        }
        else{
            if(arriveAliceMonth < arriveBobMonth)start = "b";
            else start = "a";            
        }
        
        if(leaveAliceMonth == leaveBobMonth){
            if(leaveAliceDay < leaveBobDay)end = "a";
            else end = "b";
        }
        else{
            if(leaveAliceMonth < leaveBobMonth)end = "a";
            else end = "b";
        }
        
        int days = 0;
        int startMonth = (start == "a") ? arriveAliceMonth : arriveBobMonth;
        int endMonth = (end == "b") ?  leaveBobMonth : leaveAliceMonth;
        for(int i = startMonth;i<endMonth;i++){
            days += (d[i-1]);
        }
        if(startMonth > endMonth)return 0;
        
        cout << startMonth << " " << endMonth << endl;
        int minus = (start == "a") ? arriveAliceDay : arriveBobDay;
        int plus = (end == "a") ? leaveAliceDay : leaveBobDay;
        if(startMonth == endMonth && minus > plus)return 0;
        days -= minus;
        days += plus;
        
        
        return days+1;
    }
};
