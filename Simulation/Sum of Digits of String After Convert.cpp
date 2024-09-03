class Solution {
public:
    int getLucky(string s, int k) {
        string convert = "";
        for(int i = 0; i < s.length(); i++){
            int temp = (s[i]-'a'+ 1);
            convert = convert + to_string(temp);
        }
        cout<<convert<<" ";
        
        //transforming the number
        while(k>0){
            int newNumber = 0;
            for(int i = 0; i < convert.length(); i++){
                int digit = convert[i] - '0';
                newNumber += digit;
            }
            convert = to_string(newNumber);
            k--;
        }
        int ans = stoi(convert);
        return ans;
    }
};