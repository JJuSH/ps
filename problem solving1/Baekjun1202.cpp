#include<iostream>
#include<stdio.h>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>

int N, K;
long long int sum = 0;
std::vector<std::pair<int ,int> > v;
std::vector<int> bag;
std::priority_queue<int> q;

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0 ; i < N ; i++){
        int m, val;
        scanf("%d %d" , &m, &val);
        v.push_back(std::make_pair(m, val));
    }
    std::sort(v.begin(), v.end());
    for(int i = 0 ; i < K ; i++){
        int max_weight;
        scanf("%d" , &max_weight);
        bag.push_back(max_weight);
    }
    std::sort(bag.begin(), bag.end());
    int j = 0;
    long long int ans = 0;
    for(int i = 0 ; i < K ; i++){
        while(j < N && v[j].first <= bag[i] ){
            q.push(v[j].second);
            j++;
        }
        if(q.size() != 0){
            ans += q.top();
            q.pop();
        }
    }
    std::cout << ans << "\n";
    return 0;
}
