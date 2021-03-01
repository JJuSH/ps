#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
#include<utility>
std::vector<int> grph[555];
std::vector<int> ans;
std::queue<std::pair<int,int> > q;
bool tree_;
int tree_count;
bool explored[555] = {false,};
void dfs(int node, int from){
    explored[node] = true;
    for(int i = 0 ; i < grph[node].size() ; i++){
        if(grph[node][i] == from) continue;
        if(explored[grph[node][i]] == false) dfs(grph[node][i], node);
        else if(explored[grph[node][i]] == true) tree_ = false;
    }
}
void bfs(int start){
    q.push(std::make_pair(start, 0));
    while(q.size() != 0){
        int cur_node = q.front().first;
        int cur_par = q.front().second;
        explored[cur_node] = true;
        q.pop();
        for(int i = 0 ; i < grph[cur_node].size() ; i++){
            if(explored[grph[cur_node][i]] == false){
                q.push(std::make_pair(grph[cur_node][i], cur_node));
            }
            else if(explored[grph[cur_node][i]] == true && grph[cur_node][i] != cur_par) tree_ = false;
        }
    }
}
int main(){
    int V, E;
    while(std::cin >> V >> E && V != 0){
        for(int i = 0 ; i < 555 ; i++) grph[i].clear();
        for(int i = 0 ; i < E ; i++){
            int a, b;
            std::cin >> a >> b;
            grph[a].push_back(b);
            grph[b].push_back(a);
        }
        tree_count = 0;
        memset(explored, 0 , sizeof(explored));
        for(int i = 1 ; i <= V ; i++){
            if(explored[i] == false){
                tree_ = true;
                //dfs(i,0);
                bfs(i);
                if(tree_) tree_count++;
            }
        }
        ans.push_back(tree_count);
    }
    for(int i = 0 ; i < ans.size() ; i++){
        int tree_count = ans[i];
        if(tree_count == 0) std::cout << "Case " << i+1 << ": "<< "NO trees." << "\n";
        else if(tree_count == 1) std::cout << "Case " << i+1 << ": There is one tree." << "\n";
        else std::cout << "Case " << i+1 << ": A forest of " << tree_count << " trees." << "\n";
    }
    return 0;
}

