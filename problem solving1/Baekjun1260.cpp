#include<iostream>
#include<vector>
#include<utility>
#include<queue>

int num_node;
int num_line;
int start_node;
bool explored_dfs[1001] = {false,};
bool explored_bfs[1001] = {false,};

int line[1001][1001] = {0};
std::queue<int> q;
void dfs(int node){
  
    std::cout << node << " ";
    explored_dfs[node] = true;
    for(int i = 1 ; i <= num_node ; i++){
        if(node == i) continue;
        if((explored_dfs[i] == false) && (line[node][i] == 1)){
            dfs(i);
        }
    }
}

void bfs(int start){
    std::cout << start << " ";
    explored_bfs[start] = true;
    q.push(start);
    while(q.size() != 0){
        int node = q.front();
        q.pop();
        for(int i = 1 ; i <= num_node ; i ++){
            if(i == node) continue;
            if((explored_bfs[i] == false) && (line[node][i] == 1)){
                std::cout << i << " ";
                explored_bfs[i] = true;
                q.push(i);
            }
        }
    }
    return;
}


int main(){
  std::cin >> num_node >> num_line >> start_node;
  for(int i = 0 ; i < num_line ; i++){
    int a , b;
    std::cin >> a >> b;
    line[a][b] = 1;
    line[b][a] = 1;
  }
  dfs(start_node);
  std::cout << "\n";
  bfs(start_node);
  std::cout << "\n";
  return 0;
}
