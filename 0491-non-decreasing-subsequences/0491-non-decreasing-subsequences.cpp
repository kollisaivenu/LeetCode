class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>list_of_subseq;
        map<string, bool>subseq_present;
        vector<int>curr_subseq;
        backtrack(nums, 0, curr_subseq, list_of_subseq, subseq_present);
        return list_of_subseq;


        
    }
    void backtrack(vector<int>nums, int index, vector<int>curr_subseq, vector<vector<int>>& list_of_subseq, map<string, bool>&subseq_present){
        if(index == nums.size()){
            string serialized_vector = serialize(curr_subseq);

            if(!subseq_present[serialized_vector] && curr_subseq.size() >= 2){
                subseq_present[serialized_vector] = true;
                list_of_subseq.push_back(curr_subseq);
            }
            return;
        }

        backtrack(nums, index+1, curr_subseq, list_of_subseq, subseq_present);
        if(curr_subseq.size() == 0 || curr_subseq[curr_subseq.size()-1] <= nums[index]){
            curr_subseq.push_back(nums[index]);
            backtrack(nums, index+1, curr_subseq, list_of_subseq, subseq_present);
        }

    }
    string serialize(vector<int>v){
        string serialized_vector = ",";

        for(int i=0;i<v.size();i++){
            serialized_vector = serialized_vector + to_string(v[i]) + ",";
        }

        return serialized_vector;
    }
};