#include<iostream>
#include<queue>
int N,K;
bool visited[100001] = {false,};
std::queue<std::pair<int,int> > q;
int step = 1;

void bfs(){
    while(q.size() != 0){
        int current_node = q.front().first;
        int current_step = q.front().second;
        q.pop();
        if(current_node == K){
            step = current_step;
            return;
        }
        if( (2*current_node <= 100000) && (visited[2*current_node] == false) ){
            q.push(std::make_pair(2*current_node,current_step + 1));
            visited[2*current_node] = true;
        }
        if( (current_node + 1 <= 100000) && (visited[current_node + 1] == false) ){
            q.push(std::make_pair(current_node + 1, current_step + 1));
            visited[current_node + 1] = true;
        }
        if( (current_node - 1 >= 0) && (visited[current_node - 1] == false) ){
            q.push(std::make_pair(current_node - 1, current_step + 1));
            visited[current_node - 1] = true;
        }
    }
    return;
}
int main(){
    std::cin >> N >> K;
    visited[N] = true;
    q.push(std::make_pair(N,step));
    bfs();
    std::cout << step - 1  << "\n";
    return 0;
    
}
