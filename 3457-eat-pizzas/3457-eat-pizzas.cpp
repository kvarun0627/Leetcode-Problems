class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(),pizzas.end());
        int n=pizzas.size();
        int total_days=n/4;
        long long max_weight=0;
        int current_index=n-1;
        for(int day=1;day<=total_days;day+=2)
        {
            max_weight+=pizzas[current_index];
            current_index--;
        }
        current_index--;
        for(int day=2;day<=total_days;day+=2)
        {
            max_weight+=pizzas[current_index];
            current_index-=2;
        }
        return max_weight;
    }
};