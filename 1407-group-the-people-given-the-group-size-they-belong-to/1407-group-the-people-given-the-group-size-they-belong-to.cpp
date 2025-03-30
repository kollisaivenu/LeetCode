class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>>groups;
        for(int i=0;i<groupSizes.size();i++){
            groups[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto itr = groups.begin();itr != groups.end();itr++){
            if(itr->first == (itr->second).size()){
                ans.push_back(itr->second);
            } else {
                vector<int>subGroup;
                for(int i=1;i<=(itr->second).size();i++){
                    if((i%itr->first) == 0){
                        subGroup.push_back((itr->second)[i-1]);
                        ans.push_back(subGroup);
                        subGroup.clear();
                    } else {
                        subGroup.push_back((itr->second)[i-1]);
                    }
                }
            }
        }
        return ans;
    }
};