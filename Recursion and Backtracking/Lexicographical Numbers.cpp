class Solution {
private:
    void solve(int curr, int limit, vector<int> &ans){
        if(curr > limit) return;
        ans.push_back(curr);
        for(int append = 0; append <= 9; append++){
            int num = curr*10 + append;
            if(num > limit) return;

            solve(num, limit, ans); 
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int startNum = 1; startNum <= 9; startNum++){
            solve(startNum, n, ans);
        }
        return ans;
    }
};