#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;

        vector<int> countA(26, 0);
        vector<int> countB(26, 0);

        for (char c : s1)
        {
            countA[c - 'a']++;
        }

        // first window of size s1
        for (int i = 0; i < s1.length(); i++)
        {
            countB[s2[i] - 'a']++;
        }
        if (countA == countB)
            return true;

        for (int i = s1.length(); i < s2.length(); i++)
        {
            // Adding new character to the window
            countB[s2[i] - 'a']++;
            countB[s2[i - s1.length()] - 'a']--;
            if (countA == countB)
                return true;
        }

        return false;
    }
};
