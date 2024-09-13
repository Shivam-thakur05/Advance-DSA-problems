//brute force solution 

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
         vector<int>ans;
         int n = queries.size();
         for(int i = 0; i < n; i++){

            int XorVal = 0;
            int a = queries[i][0];
            int b = queries[i][1];

            for(int j = a; j <= b; j++){
                XorVal ^= arr[j];
            }
            ans.push_back(XorVal);
        }
    return ans;
    }
};



//optimize solution

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>cumXor(n,0);

        cumXor[0] = arr[0];

        for(int i = 1; i < n; i++){
            cumXor[i] = cumXor[i-1]^arr[i];
        }

        vector<int>ans;
        for(int i = 0; i < queries.size(); i++){
            int left = queries[i][0];
            int right = queries[i][1];

            int xorVal = cumXor[right] ^ (left == 0 ? 0 : cumXor[left-1]);
            ans.push_back(xorVal);
        }
        
    return ans;
    }
};