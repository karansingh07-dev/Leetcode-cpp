class Solution {
public:
    bool canAliceWin(int n) {
        int take=10;
        int step=0;

        while(n>=take){
            n=n-take;
            take--;
            step++;
        }

        if(step%2==0){
            return false;
        }else 

        return true;
    }
};