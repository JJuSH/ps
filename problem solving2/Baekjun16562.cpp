#include<iostream>
#include<stdio.h>
#include<vector>
int N, M, k;
int cost[10001];
int par[10001];
bool took[10001] = {false,};
int find(int a){
    if(par[a] == a) return a;
    else{
        int pa = find(par[a]);
        par[a] = pa;
        return par[a];
    }
}

void uni(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa == pb) return;
    else{
        if(cost[pa] > cost[pb]) par[pa] = pb;
        else par[pb] = pa;
    }
}
int main(){
    scanf("%d %d %d", &N, &M, &k);
    for(int i = 1 ; i <= N ; i++){
        scanf("%d", &cost[i]);
        par[i] = i;
    }
    for(int i = 0 ; i < M ; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        uni(a,b);
    }
    long long int sum = 0;
    for(int i = 1 ; i <= N ; i++){
        int cur_par = find(i);
        if(took[cur_par] == false){
            sum += cost[cur_par];
            took[cur_par] = true;
        }
        
    }
    if(sum <= k) printf("%lld\n", sum);
    else printf("Oh no\n");
    return 0;
}
