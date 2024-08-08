#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Item {
    int weight, profit;
};

bool ratio(Item a, Item b){
    double r1 = (double)a.profit/a.weight;
    double r2 = (double)b.profit/b.weight;
    return r1 > r2;
}

double fractional_knapsack(int w, vector<Item>& items){
    sort(items.begin(), items.end(),ratio);
    double totalProfit = 0.0;
    int currentWeight = 0;

    for(int i = 0; i < items.size(); ++i){
        if(currentWeight + items[i].weight <= w){
            //If knapsack has space to store whole item
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;
        }
        else{
            //If knapsack cannot store whole item -> store fraction
            int remWeight = w - currentWeight;  //remaining weight of knapsack
            totalProfit += items[i].profit * ((double)remWeight/items[i].weight);
            break;
        }
    }
    return totalProfit;
}




int main(){
    int w;
    cout<<"Enter capacity of knapsack :";
    cin>>w;
    int n;
    cout<<"Enter no. of items:";
    cin>>n;

    vector<Item>items(n);
    for(int i = 0; i < n; ++i){
        cout<<"Enter profit and weight of item"<<i + 1<<":"<<endl;
        cin>>items[i].profit>>items[i].weight;
    }
    int ans = fractional_knapsack(w,items);
    cout<<"Maximum Profit of knapsack :"<<ans<<endl;
    return 0;
}
