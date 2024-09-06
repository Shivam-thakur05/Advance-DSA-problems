class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int s = rolls.size();
        long long sum = 0;
        vector<int> ans;

        // Calculate the sum of the given rolls
        for(int i = 0; i < s; i++){
            sum += rolls[i];
        }

        // Calculate the total remaining sum needed for the missing rolls
        int remaining_digit = (s + n) * mean - sum;

        // Check if the remaining sum is possible within the bounds of dice values (1 to 6)
        if(remaining_digit < n || remaining_digit > 6 * n) return ans;  // return empty array if impossible

        // Initialize all missing rolls to the minimum valid value of 1
        vector<int> temp(n, 1);
        remaining_digit -= n;  // Subtract the base 1s from the remaining sum

        // Distribute the remaining sum across the temp array
        int k = 0;
        while(remaining_digit > 0) {
            int add = min(remaining_digit, 5);  // Each dice value can increase by at most 5 (since it starts from 1)
            temp[k] += add;
            remaining_digit -= add;
            k++;
        }
        return temp;
    }
};
