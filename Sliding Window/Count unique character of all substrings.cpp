#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> mapping(26);
        int n = s.length();

        for(int i = 0; i < 26; i++){
            mapping[i].push_back(-1);
        }
        for(int i = 0; i < n; i++){
            mapping[s[i] - 'A'].push_back(i);
        }
        for(int i = 0; i < 26; i++){
            mapping[i].push_back(n);
        }

        long long count = 0;
        for(int i = 0; i < 26; i++){
            for(int j = 1; j < mapping[i].size()-1; j++){
                count += ((mapping[i][j] - mapping[i][j-1]) * (mapping[i][j+1] - mapping[i][j]));
            }
        }
        return count;
    }
};