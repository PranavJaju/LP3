//Write a program to solve a 0-1 Knapsack problem using dynamic programming or branch and bound strategy.
#include<bits/stdc++.h>
using namespace std;

struct Item{
	int weight;
	int value;
};

int KnapsackDynamicProgram(int W,vector<Item>& items){
	int n = items.size();
	vector<vector<int>>dp(n+1,vector<int>(W+1,0));
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=W;j++){
			if(items[i-1].weight <= j){
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-items[i-1].weight] + items[i-1].value);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	int totalWeight = W;
    vector<int> selectedItems;
    
    for (int i = n; i > 0 && totalWeight > 0; i--) {
        // Check if this item was included in the optimal solution
        if (dp[i][totalWeight] != dp[i - 1][totalWeight]) {
            selectedItems.push_back(i - 1); // Add the item's index
            totalWeight -= items[i - 1].weight; // Reduce the weight
        }
    }
    
    // Output the selected items
    cout << "Selected item indices: ";
    for (int idx : selectedItems) {
        cout << items[idx].value << " ";
    }
    cout << endl;
	return dp[n][W];
}
struct Node{
	int level;
	int profit;
	int bound;
	float wt;
};
bool sortcmp(Item a,Item b){
	return (float)a.value / a.weight > (float)b.value / b.weight;
}
struct cmp {
    bool operator()(Node const &a, Node const &b) {
        return a.bound < b.bound;
    }
};
float bound(Node u, int n, int W, vector<Item>& items) {
	if(u.wt>=W) return 0;
	float profit_bound = u.profit;
	int j = u.level + 1;
	int total_wt = u.wt;
	while((j<n) && (total_wt + items[j].weight <= W)){
		total_wt += items[j].weight;
		profit_bound += items[j].value;
		j++;
	}
	if(j<n) profit_bound += (W-total_wt) * 	(float)items[j].value / items[j].weight;
	return profit_bound;
}
int knapsackBranchAndBound(int W,vector<Item>& items){
	int n = items.size();
	sort(items.begin(),items.end(),sortcmp);
	priority_queue<Node,vector<Node>,cmp>pq;
	Node u,v;
	u.level = -1;
	u.profit = u.wt = 0;
	u.bound = bound(u,n,W,items);
	pq.push(u);
	
	int maxProfit = 0;
	while(!pq.empty()){
		u = pq.top();
		pq.pop();
		if(u.level == n - 1) continue;
		v.level = u.level + 1;
		v.wt = u.wt + items[v.level].weight;
		v.profit = u.profit + items[v.level].value;
		
		if(v.wt <= W && v.profit > maxProfit){
			maxProfit = v.profit;
		}
		
		v.bound = bound(v,n,W,items);
		if(v.bound > maxProfit){
			pq.push(v);
		}
		
		v.wt = u.wt;
		v.profit = u.profit;
		v.bound = bound(v,n,W,items);
		if(v.bound > maxProfit){
			pq.push(v);
		}
	}
	return maxProfit;
}
int main(){
	int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<Item> items(n);
    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
    }
    
    cout << "Enter maximum capacity of knapsack: ";
    cin >> W;
    cout << "\nDynamic Programming Approach: Maximum Profit = " << KnapsackDynamicProgram(W, items) << endl;
	cout << "Branch and Bound Approach: Maximum Profit = " << knapsackBranchAndBound(W, items) << endl;
	return 0;
}



















