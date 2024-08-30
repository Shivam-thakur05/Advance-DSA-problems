class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        //find the max bananas which could she eat per hour
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] > high){
                high = piles[i];
            }
        }
        
        int ans = -1;

        while(low <= high){
            long int currHour = 0;
            int mid = low + (high - low)/2;

            for (int i = 0; i < piles.size(); i++) {
                // Calculate the time to eat each pile
                currHour = ((piles[i]) / mid) + currHour;
                if(piles[i] % mid != 0) currHour++;
            }

            if(currHour <= h){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
    return ans; 
    }
};