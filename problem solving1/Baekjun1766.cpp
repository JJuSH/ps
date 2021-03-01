#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
int N, M;
int pre, after;
int entry[32001] = {0};
std::vector<int> order[32001];
std::queue<int> q;
std::priority_queue<int, std::vector<int> , std::greater<int> > pq;
std::queue<int> head;
void make_head(){
    for(int i = 1 ; i <= N ; i++){
        if(entry[i] == 0) pq.push(i);
    }
}
/*
void top_order(){
    make_head();
    while(head.size() != 0){
        q.push(head.front());
        head.pop();
        while(q.size() != 0){
            int cur = q.front();
            q.pop();
            printf("%d ", cur);
            for(unsigned int i = 0 ; i < order[cur].size() ; i++){
                int next = order[cur][i];
                entry[next]--;
                if(entry[next] == 0) q.push(next);
            }
        }
    }
}*/
void top_order(){
    make_head();
    while(pq.size() != 0){
        int cur = pq.top();
        pq.pop();
        printf("%d ", cur);
        for(unsigned int i = 0 ; i < order[cur].size() ; i++){
            int next = order[cur][i];
            entry[next]--;
            if(entry[next] == 0) pq.push(next);
        }
    }
    
}

int main(){
    scanf("%d %d", &N , &M);
    for(int i = 0 ; i < M ; i++){
        scanf("%d %d", &pre, &after);
        order[pre].push_back(after);
        entry[after]++;
    }
    for(int i = 1 ; i <= N ; i++) std::sort(order[i].begin() , order[i].end());
    top_order();
    printf("\n");
    return 0;
}
