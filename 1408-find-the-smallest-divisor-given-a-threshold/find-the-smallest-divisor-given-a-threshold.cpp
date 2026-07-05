class Solution {
public:
    int addi(vector<int> &nums, int m){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += (nums[i] + m - 1)/m;
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int div = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            int sum = addi(nums, mid);
            if(sum <= threshold){
                div = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return div;
    }
};