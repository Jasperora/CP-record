class FoodRatings {
public:
    // cuisine: food1,   food2
    //          rating1, rating2
    // cuisine to set of {rating, food}
    unordered_map<string, map<int, set<string>>> cuisine_to_foods;
    // food to {rating, cuisine}
    unordered_map<string, pair<int, string>> food_info;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; ++i){
            cuisine_to_foods[cuisines[i]][ratings[i]].insert(foods[i]);
            // use food_info only to find the item and delete it
            food_info[foods[i]] = {ratings[i], cuisines[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        auto& p = food_info[food];
        cuisine_to_foods[p.second][p.first].erase(food);
        if(cuisine_to_foods[p.second][p.first].empty())
            cuisine_to_foods[p.second].erase(p.first);
        p.first = newRating;
        cuisine_to_foods[p.second][newRating].insert(food);
    }
    
    string highestRated(string cuisine) {
        int max_score = cuisine_to_foods[cuisine].rbegin()->first;
        for(auto& food: cuisine_to_foods[cuisine][max_score])
            return food;
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */