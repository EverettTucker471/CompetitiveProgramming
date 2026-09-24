#include <bits/stdc++.h>

using namespace std;

struct recipe {
    int base;
    int price;
    int prestige;
};

map<string, int> recipe_name_map;
vector<vector<recipe>> recipies;

// Hitting some index error in the tracing
pair<int, int> trace_recipe(int recipe_idx) {
    // Returns (price, prestige) pairs
    if (recipies[recipe_idx].empty()) {
        // This means that this is a base recipe
        return {0, 0};  // Zero price and zero prestige
    } else {
        vector<pair<int, int>> res;
        for (auto recipe : recipies[recipe_idx]) {
            pair<int, int> temp = trace_recipe(recipe.base);
            res.emplace_back(temp.first + recipe.price, temp.second + recipe.prestige);
        }
        int min_price = INT_MAX;
        int max_prestige = INT_MIN;

        for (auto p : res) {
            if (p.first < min_price) {
                min_price = p.first;
                max_prestige = p.second;
            } else if (p.first == min_price) {
                max_prestige = p.second;
            }
        }
        return {min_price, max_prestige};
    }
}

int main() {
    int b, n;
    cin >> b >> n;

    if (b == 0 || n == 0) {cout << "0\n0\n"; exit(0);}

    int num_recipes = 0;
    int num_ings = 0;
    recipies.reserve(n);

    for (int i = 0; i < n; i++) {
        string recipe, base, ing;
        cin >> recipe >> base >> ing;
        int price, prestige, recipe_idx, base_idx;
        cin >> price >> prestige;

        if (!recipe_name_map.count(recipe)) {
            recipe_name_map[recipe] = num_recipes;
            num_recipes++;
        }
        if (!recipe_name_map.count(base)) {
            recipe_name_map[base] = num_recipes;
            num_recipes++;
        }
        recipe_idx = recipe_name_map[recipe];
        base_idx = recipe_name_map[base];
        
        recipies[recipe_idx].push_back({base_idx, price, prestige});
    }

    vector<pair<int, int>> recipe_data;
    for (int i = 0; i < n; i++) {
        // Digging down and finding all the recipes
        if (recipies[i].empty()) continue;
        recipe_data.push_back(trace_recipe(i));
    }
    n = recipe_data.size();

    // Now we can do knapsack
    vector<int> dp(b + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = b; j >= recipe_data[i - 1].first; j--) {
            dp[j] = max(dp[j], dp[j - recipe_data[i - 1].first] + recipe_data[i - 1].second);
        }
    }

    int max_prestige = INT_MIN;
    int max_idx = 0;

    for (int i = 0; i < b + 1; i++) {
        if (dp[i] > max_prestige) {
            max_prestige = dp[i];
            max_idx = i;
        }
    }

    // for (auto x : recipe_data) {
    //     cout << x.first << " " << x.second << '\n';
    // }

    cout << max_prestige << '\n' << max_idx << '\n';
}