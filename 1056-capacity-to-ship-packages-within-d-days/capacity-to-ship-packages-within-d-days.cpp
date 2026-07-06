class Solution {
public:
    bool check(vector<int> &weights, int cap, int days){
         int sum = 0, count = 1;
        for(int w : weights){
           if(sum + w > cap){
               count++;
               sum = 0;
           }
           sum += w;
        }
        return count <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for(int i = 0; i < weights.size(); i++){
            high += weights[i];
        }
        int cap = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(weights, mid, days)){
                cap = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return cap;
    }
};