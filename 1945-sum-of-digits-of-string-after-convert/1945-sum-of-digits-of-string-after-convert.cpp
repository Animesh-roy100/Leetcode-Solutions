class Solution {
public:
    int getLucky(string s, int k) {
        vector<int> v;
        for(int i=0; i<s.length(); i++) {
            int num = (s[i]-'a')+1;
            while(num > 0) {
                v.push_back(num%10);
                num /= 10;
            }
        }
        int sum = accumulate(v.begin(), v.end(), 0);
        while(--k > 0) {
            int sum1 = 0;
            while(sum > 0) {
                sum1 += sum%10;
                sum /= 10;
            }
            sum = sum1;
        }
        
        return sum;
    }
};