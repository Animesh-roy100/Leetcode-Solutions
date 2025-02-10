class FoodRatings {
public:
    unordered_map<string, int> foodRating; // {food -> rating}
    unordered_map<string, set<pair<int, string>>> cuisineRating; // {cuisine -> [{rating, food}]}
    unordered_map<string, string> foodCuisine; // {food -> cuisine}

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0; i<n; i++) {
            foodRating[foods[i]] = ratings[i];
            foodCuisine[foods[i]] = cuisines[i];
            cuisineRating[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldRating = foodRating[food];
        string cuisine = foodCuisine[food];

        cuisineRating[cuisine].erase({-oldRating, food});
        cuisineRating[cuisine].insert({-newRating, food});

        foodRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        // cuisine -> (rating, name)
        return (*cuisineRating[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */