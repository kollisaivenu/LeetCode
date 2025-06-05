class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int>parent(26);

        for(int i=0;i<26;i++){
            parent[i] = i;
        }

        for(int i=0;i<s1.size();i++){
            un(s1[i]-'a', s2[i]-'a', parent);
        }

        string ans = "";

        for(int i=0;i<baseStr.size();i++){
            ans += (char)(find(baseStr[i]-'a', parent)+97);
        }

        return ans;
    }

    int find(int i, vector<int>parent){
        if(parent[i] == i){
            return i;
        }
        return find(parent[i], parent);
    }

    void un(int i, int j, vector<int>&parent){
        int a = find(i, parent);
        int b = find(j, parent);

        if(a<=b){
            parent[b] = a;
        } else {
            parent[a] = b;
        }
    }
};