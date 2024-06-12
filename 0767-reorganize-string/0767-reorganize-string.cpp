class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        vector<int> count(26, 0);
        int maxFreq=0;
        for(int i=0; i<n; i++) {
            count[s[i]-'a']++;
            if(count[maxFreq] < count[s[i]-'a']) {
                maxFreq = s[i]-'a';
            } 
        }
        
        // cout<<maxFreq;
        if(count[maxFreq] > (n+1)/2) return "";
        int i=0;
        string ans(n, ' ');
        while(i<n and count[maxFreq]) {
            ans[i] = maxFreq+'a';
            count[maxFreq]--;
            i+=2;
        }
        cout<<ans;
        
        for(int j=0; j<26; j++) {
            while(count[j]) {
                count[j]--;
                if(i>=n) i=1;
                ans[i] = j+'a';
                i+=2;
            }
        }
        
        return ans;
    }
};