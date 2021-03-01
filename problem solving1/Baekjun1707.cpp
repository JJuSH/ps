#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
int num_test;
std::vector<int> grp[20001];
std::queue<int> q;
bool explored[20001];
bool bi;
void bfs(int start){
    int color[20001] = {0,};
    q.push(start);
    color[start] = 1;
    explored[start] = true;
    bi = true;
    while(q.size() != 0){
        int cur_node = q.front();
        int cur_color = color[cur_node];
        explored[cur_node] = true;
        q.pop();
        for(int i = 0 ; i < grp[cur_node].size() ; i++){
            if(explored[grp[cur_node][i]] == false){
                q.push(grp[cur_node][i]);
                color[grp[cur_node][i]] = -cur_color;
                explored[grp[cur_node][i]] = true;
            }
            else{
                if(color[grp[cur_node][i]] == cur_color){
                    bi = false;
                }
            }
        }
    }
}
int main(){
    scanf("%d" , &num_test);
    for(int i = 0 ; i < num_test ; i++){
        for(int k = 0 ; k <= 20000 ; k++) grp[k].clear();
        int V, E;
        scanf("%d %d", &V, &E);
        for(int j = 0 ; j < E ; j++){
            int a, b;
            scanf("%d %d" , &a , &b);
            grp[a].push_back(b);
            grp[b].push_back(a);
        }
        memset(explored, 0, sizeof(explored));
        for(int j = 1 ; j <= V ; j++){
            if(explored[j] == false){
                bfs(j);
                if(bi == false) break;
            }
            else continue;
        }
        if(bi) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
