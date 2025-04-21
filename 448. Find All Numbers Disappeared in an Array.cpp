class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> final;
        unordered_set<int> st;
        for(int x : nums){
            st.insert(x);
        }

        for(int i=1; i<=nums.size(); i++){
            if(!st.count(i)) final.push_back(i);
        }

        return final;
    }
};
