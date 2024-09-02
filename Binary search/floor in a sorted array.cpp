class Solution {
  public:
  
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &v, long long n, long long x) {
        long long start = 0;
        long long end = n-1;
        int ans = -1;
        while(start <= end){
            long long mid = start + (end - start)/2;
            if(v[mid] <= x){
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
};