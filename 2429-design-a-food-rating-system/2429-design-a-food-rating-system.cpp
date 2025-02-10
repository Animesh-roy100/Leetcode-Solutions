class FoodRatings {
public:
    unordered_map<string, pair<int, string>> foodDetails; // {food -> {rating, cuisine}}
    unordered_map<string, set<pair<int, string>>> cuisineRating; // {cuisine -> [{rating, food}]}

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0; i<n; i++) {
            foodDetails[foods[i]] = {ratings[i], cuisines[i]};
            cuisineRating[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldRating = foodDetails[food].first;
        string cuisine = foodDetails[food].second;

        cuisineRating[cuisine].erase({-oldRating, food});
        cuisineRating[cuisine].insert({-newRating, food});

        foodDetails[food] = {newRating, cuisine};
    }
    
    string highestRated(string cuisine) {
        return (*cuisineRating[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */