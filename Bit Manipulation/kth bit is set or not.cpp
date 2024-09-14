class Solution {
  public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k) {
        if((n & (1<<k)) != 0) return 1;
        else return 0;
        
    }
};


class Solution {
  public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k) {
        if((1 & (n>>k)) != 0) return 1;
        else return 0;
        
    }
};
