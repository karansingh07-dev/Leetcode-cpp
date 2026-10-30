class Solution {
public:
 

    int findDayofYear(string date,vector<int>cumDays){
        int month=stoi(date.substr(0,2));
        int days=stoi(date.substr(3));

        return cumDays[month-1] + days;
    }

    
     
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
     vector<int>monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

     vector<int>cumDays(13,0);

      cumDays[1]=31;

     for(int i=2;i<=12;i++){
         cumDays[i]=cumDays[i-1] + monthDays[i-1];
     }

     int arriveAliceDay = findDayofYear(arriveAlice, cumDays);
     int leaveAliceDay= findDayofYear(leaveAlice , cumDays);
     int arriveBobDay= findDayofYear(arriveBob, cumDays);
     int leaveBobDay= findDayofYear(leaveBob , cumDays);
   
     int overlap = min(leaveAliceDay,leaveBobDay)-max(arriveAliceDay,arriveBobDay) + 1;

     return overlap<0 ? 0 : overlap;


    }
};