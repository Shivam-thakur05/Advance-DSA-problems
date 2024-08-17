class Solution {
public:
    int maxVowels(string s, int k) {
        int Vowel = 0;
        int maxVowl = 0;
        for(int i = 0; i < k; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i'||s[i] == 'o' || s[i] == 'u'){
                Vowel++;
            }
        }
        //if all elements in window size is vowel then it is max size
        if(Vowel == k) return Vowel;

        maxVowl = max(Vowel,maxVowl);
        for(int i = k; i < s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i'||s[i] == 'o' || s[i] == 'u'){
                Vowel++;
            }
            if(s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i'||s[i-k] == 'o' || s[i-k] == 'u'){
                Vowel--;
            }
            maxVowl = max(maxVowl,Vowel);
        }
        return maxVowl;
    }
};