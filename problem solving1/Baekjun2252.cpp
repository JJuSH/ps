#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
int N, M;
int income[32001] = {0};
std::queue<int> ans;
std::queue<int> q;
std::vector<int> v[32001];
void make_q(){
    for(int i = 1 ; i <= N ; i++){
        if(income[i] == 0){
            q.push(i);
        }
    }
}
void topo_sort(){
    make_q();
    while(q.size() != 0){
        int cur_node = q.front();
        ans.push(cur_node);
        q.pop();
        while(v[cur_node].size() != 0){
            int size = v[cur_node].size();
            int to = v[cur_node][size - 1];
            income[to]--;
            if(income[to] == 0) q.push(to);
            v[cur_node].pop_back();
        }
    }
}
int main(){
    scanf("%d %d", &N , &M);
    for(int i = 0 ; i < M ; i++){
        int from, to;
        scanf("%d %d", &from , &to);
        v[from].push_back(to);
        income[to]++;
    }
    topo_sort();
    while(ans.size() != 0){
        printf("%d ", ans.front());
        ans.pop();
    }
    printf("\n");
    return 0;
}
