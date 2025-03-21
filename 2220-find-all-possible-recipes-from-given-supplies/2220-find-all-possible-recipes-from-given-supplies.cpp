class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string, int>items2Index;
        map<int, string>index2Items;
        map<string, bool>isRecipe;
        map<string, bool>supplyPresent;
        int index = 0;

        for(int i=0;i<supplies.size();i++){
            //items2Index[supplies[i]] = index;
            //index2Items[index] = supplies[i];
            supplyPresent[supplies[i]] = true;
            //index++;
        }

        for(int i=0;i<recipes.size();i++){
            items2Index[recipes[i]] = index;
            index2Items[index] = recipes[i];
            isRecipe[recipes[i]] = true;
            index++;

            for(int j=0;j<ingredients[i].size();j++){
                items2Index[ingredients[i][j]] = index;
                index2Items[index] = ingredients[i][j];
                index++;
            }
        }


        vector<vector<int>>graph(index);
        vector<int>indeg(index, 0);

        for(int i=0;i<recipes.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                graph[items2Index[ingredients[i][j]]].push_back(items2Index[recipes[i]]);
                indeg[items2Index[recipes[i]]]++;
            }
        }

        for(int i=0;i<indeg.size();i++){
            cout<<indeg[i]<<"\n";
        }
        
        queue<int>q;

        for(int i=0;i<indeg.size();i++){
            if(indeg[i] == 0 && supplyPresent[index2Items[i]]){
                cout<<index2Items[i];
                q.push(i);
            }
        }
        vector<string>recipesPossible;
        while(!q.empty()){
            int item = q.front();
            q.pop();

            if(isRecipe[index2Items[item]]){
                recipesPossible.push_back(index2Items[item]);
            }

            for(int i=0;i<graph[item].size();i++){
                //cout<<"came here\n";
                indeg[graph[item][i]]--;

                if(indeg[graph[item][i]] == 0){
                    q.push(graph[item][i]);
                }
            }

        }
        return recipesPossible;

    }
};