
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        long long sum = 0;
        long long maxi = INT_MIN;
        for(long long i = 0; i < arr.size(); i++){
            sum += arr[i];
            maxi = max(sum,maxi);
            if(sum < 0){
                sum = 0;
            }
        }
        return maxi;
    }
};



int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
}
