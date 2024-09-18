class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert each integer to string
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }
        
        // Custom comparator to sort numbers based on concatenated result
        sort(strNums.begin(), strNums.end(), [](string &a, string &b) {
            return a + b > b + a; // Compare concatenated results
        });
        
        // If the largest number is "0", just return "0"
        if (strNums[0] == "0") return "0";
        
        // Concatenate all strings to form the largest number
        string result = "";
        for (string &num : strNums) {
            result += num;
        }
        
        return result;
    }
};