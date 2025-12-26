class Solution {
public:
    int bestClosingTime(string customers) {
        int upcomingCustomers = 0, freeTime = 0;
        
        for(int i=0;i<customers.size();i++) {
            if (customers[i] == 'Y') {
                upcomingCustomers++;
            }
        }
        int time = 0, penalty = upcomingCustomers;

        for(int i=1;i<=customers.size();i++) {
            if (customers[i-1] == 'N') {
                freeTime++;
            } else {
                upcomingCustomers--;
            }


            int currentPenalty = freeTime + upcomingCustomers;

            if(currentPenalty < penalty) {
                time = i;
                penalty = currentPenalty;
            }
        }

        return time;
    }
};