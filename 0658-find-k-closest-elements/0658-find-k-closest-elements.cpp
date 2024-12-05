class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // find floor of x
        // use two pointers to check closest k elements
        int n=arr.size();
        int start=0, end=n-1;
        int floor = 0; // storing the floor
        while(start<=end) {
            int mid = start + (end-start)/2;
            
            if(arr[mid] == x) {
                floor = mid;
                break;
            }
            if(arr[mid] > x) {
                end = mid-1;
            } else if(arr[mid] < x) {
                floor = mid;
                start = mid+1;
            }
        }
        
        int i=floor, j=floor+1;
        vector<int> ans;
        while(i>=0 and j<n and k>0) {
             if(abs(arr[i]-x) <= abs(arr[j]-x)) {
                ans.push_back(arr[i]);
                i--;
            } else {
                ans.push_back(arr[j]);
                j++;
            }
            k--;
        }
        
        while(j<n and k>0) {
            ans.push_back(arr[j]);
            j++;
            k--;
        }

        while(i>=0 and k>0) {
            ans.push_back(arr[i]);
            i--;
            k--;
        }
 
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};