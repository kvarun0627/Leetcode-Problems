class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    // Build a graph mapping each ingredient to the recipes that require it.
    unordered_map<string, vector<string>> gr;
    // Track the number of ingredients needed for each recipe.
    unordered_map<string, int> indeg;
    // Create a set of supplies for fast lookup.
    unordered_set<string> supply(supplies.begin(), supplies.end());
    queue<string> q;
    vector<string> ans;

    // Build the dependency graph and initialize indegree for each recipe.
    for (int i = 0; i < recipes.size(); i++) {
        for (const string& s : ingredients[i]) {
            gr[s].push_back(recipes[i]);
        }
        indeg[recipes[i]] = ingredients[i].size();
    }

    // Seed the queue with all the initial supplies (guaranteed to be available).
    for (const string& s : supplies) {
        q.push(s);
    }

    // Process the queue in a topological sort manner.
    while (!q.empty()) {
        string item = q.front();
        q.pop();
        // For each recipe that depends on the current item:
        for (const string& neigh : gr[item]) {
            indeg[neigh]--;  // One less ingredient required.
            // If all ingredients for a recipe are now available:
            if (indeg[neigh] == 0) {
                ans.push_back(neigh);  // Add the recipe to the answer.
                q.push(neigh);         // Treat the recipe as a new available supply.
                supply.insert(neigh);  // Mark it as available.
            }
        }
    }
    
    return ans;
}

};