class Solution {
private:
    
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string> ans;
        unordered_set<string> sup;
        for(int i=0; i<supplies.size(); i++) {
            sup.insert(supplies[i]);
        }
        
        vector<bool> recipeDone(n, false);
        bool recipeFound = true;
        while(recipeFound) {   // if atleast one recipe done
            recipeFound = false;
            for(int i=0; i<n; i++) {
                bool recipeFinished=true;
                for(auto &ingredient: ingredients[i]) {
                    if(sup.find(ingredient) == sup.end()) {
                        recipeFinished = false;
                        break;
                    }                
                }
                if(recipeFinished==true and recipeDone[i]==false) {
                    sup.insert(recipes[i]);
                    // ans.push_back(recipes[i]);
                    recipeDone[i]=true;
                    recipeFound = true;
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            if(recipeDone[i]) ans.push_back(recipes[i]);
        }
        
        return ans;
    }
};