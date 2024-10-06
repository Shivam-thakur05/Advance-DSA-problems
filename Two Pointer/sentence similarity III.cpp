class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1;
        vector<string> s2;
        if(sentence1.length() < sentence2.length()) swap(sentence1, sentence2);

        string word = "";
        for(int i = 0; i <= sentence1.length(); i++){
            if(i < sentence1.length() && sentence1[i] != ' ') word += sentence1[i];
            else{
                s1.push_back(word);
                word = "";
            }
        }
        word = "";
        for(int i = 0; i <= sentence2.length(); i++){
            if(i < sentence2.length() && sentence2[i] != ' ') word += sentence2[i];
            else{
                s2.push_back(word);
                word = "";
            }
        }

        int i = 0, j = s1.size()-1;
        int k = 0, l = s2.size()-1;

        // Check prefix-wise
        while(i <= j && k <= l){
            if(s1[i] == s2[k]){
                i++;
                k++;
            }
            else{
                break;
            }
        } 

        // Check suffix-wise
        while(j >= i && l >= k){
            if(s1[j] == s2[l]){
                j--;
                l--;
            }
            else{
                break;
            }
        }

        return l < k;
    }
};
