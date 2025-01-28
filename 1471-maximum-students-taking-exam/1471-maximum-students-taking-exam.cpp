class Solution {
public:
    bool checkIfGoodMask(int currMask, int prevMask, int row, vector<vector<char>> &seats, int n) {  
        int prevBit=0;
        for (int i = 0; i < n; i++) {
            bool set = (1 << i) & currMask;
            if (!set) {
                prevBit = 0; // Reset prevBit if this seat is not occupied
                continue;
            }

            // If the seat is broken or the previous seat in the current row is occupied
            if (seats[row][i] == '#' || prevBit) return false;

            // Check left neighbor in prevMask
            if (i > 0 && ((1 << (i - 1)) & prevMask)) return false;

            // Check right neighbor in prevMask
            if (i < n - 1 && ((1 << (i + 1)) & prevMask)) return false;

            prevBit = 1; // Mark this seat as occupied
        }

        return true;
    }

    int countBits(int mask) {
        int count=0;
        while(mask) {
            if(mask&1) count++;
            mask = mask>>1;
        }

        return count;
    }

    int solve(int row, int mask, int n, vector<vector<char>> &seats, vector<vector<int>> &dp) {
        if(row == seats.size()) return 0;

        if(dp[row][mask] != -1) return dp[row][mask];

        int ans=0;
        for(int i=0; i<(1<<n); i++) {
            int currMask = i;
            if(checkIfGoodMask(currMask, mask, row, seats, n)) {
                ans = max(ans, countBits(currMask) + solve(row+1, currMask, n, seats, dp));
            }
        }

        return dp[row][mask] = ans;
    }

    int maxStudents(vector<vector<char>>& seats) {
        int m=seats.size(), n=seats[0].size();
        vector<vector<int>> dp(m, vector<int> (1<<n , -1));

        return solve(0, 0, n, seats, dp);
    }
};