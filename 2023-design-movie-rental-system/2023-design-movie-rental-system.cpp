class MovieRentingSystem {
public:
    unordered_map<int, set<pair<int, int>>> movies;  // map[movie] = {{price, shop}, ...}
    set<tuple<int, int, int>> rented; // set[{price, shop, movie}] 
    unordered_map<int, unordered_map<int, int>> shopMovieToPrice;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &it: entries) {
            int shop = it[0], movie = it[1], price = it[2];

            movies[movie].insert({price, shop});
            shopMovieToPrice[shop][movie] = price;
        }
    }
    
    vector<int> search(int movie) {
        if(movies.find(movie) == movies.end()) return {};
        vector<int> cheapShops;
        int count=0;
        for(auto &it: movies[movie]) {
            if(count == 5) {
                break;
            }
            cheapShops.push_back(it.second);
            count++;
        }

        return cheapShops;
    }
    
    void rent(int shop, int movie) {
        if(movies.find(movie) == movies.end()) return;

        int price = shopMovieToPrice[shop][movie];
        movies[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        if(movies.find(movie) == movies.end()) return;

        int price = shopMovieToPrice[shop][movie];
        movies[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int count=0;
        for(auto &[price, shop, movie]: rented) {
            if(count==5) break;
            res.push_back({shop, movie});
            count++;
        }

        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */