#include<iostream>
#include<queue>
#include<utility>
#include<string.h>

int N;
bool visited[300][300] = {false,};
int count;
int target_r, target_c;
int start_r, start_c;
int len;
std::queue<std::pair<int,int> > q;
std::queue<int> step;
std::queue<int> ans;

int bfs(){
    int final_step;
    while(q.size() != 0){
        //std::cout << "while" << "\n";
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        int cur_step = step.front();
        
        q.pop();
        step.pop();
        
        if((cur_r == target_r) && (cur_c == target_c)){
            final_step = cur_step;
            break;
        }
        
        if(cur_r - 2 >= 0){
            if((cur_c + 1 <= len - 1) && (visited[cur_r - 2][cur_c + 1] == false)){
                q.push(std::make_pair(cur_r-2, cur_c + 1));
                step.push(cur_step + 1);
                visited[cur_r - 2][cur_c + 1] = true;
            }
            if((cur_c - 1 >= 0) && (visited[cur_r - 2][cur_c - 1] == false)){
                q.push(std::make_pair(cur_r - 2,cur_c - 1));
                step.push(cur_step + 1);
                visited[cur_r - 2][cur_c - 1] = true;
            }
        }
        if(cur_r + 2 <= len-1){
            if((cur_c + 1 <= len - 1) && (visited[cur_r + 2][cur_c + 1] == false)){
                q.push(std::make_pair(cur_r + 2, cur_c + 1));
                step.push(cur_step + 1);
                visited[cur_r + 2][cur_c + 1] = true;
            }
            if((cur_c - 1 >= 0) && (visited[cur_r + 2][cur_c - 1] == false)){
                q.push(std::make_pair(cur_r + 2, cur_c - 1));
                step.push(cur_step + 1);
                visited[cur_r + 2][cur_c - 1] = true;
            }
        }
        if(cur_c - 2 >= 0){
            if((cur_r + 1 <= len - 1) && (visited[cur_r + 1][cur_c - 2] == false)){
                q.push(std::make_pair(cur_r + 1, cur_c - 2));
                step.push(cur_step + 1);
                visited[cur_r + 1][cur_c - 2] = true;
            }
            if((cur_r - 1 >= 0) && (visited[cur_r - 1][cur_c - 2] == false)){
                q.push(std::make_pair(cur_r - 1, cur_c - 2));
                step.push(cur_step + 1);
                visited[cur_r - 1][cur_c - 2] = true;
            }
        }
        if(cur_c + 2 <= len-1){
            if((cur_r + 1 <= len - 1) && (visited[cur_r + 1][cur_c + 2] == false)){
                q.push(std::make_pair(cur_r + 1, cur_c + 2));
                step.push(cur_step + 1);
                visited[cur_r + 1][cur_c + 2] = true;
            }
            if((cur_r - 1 >= 0) && (visited[cur_r - 1][cur_c + 2] == false)){
                q.push(std::make_pair(cur_r - 1, cur_c + 2));
                step.push(cur_step + 1);
                visited[cur_r - 1][cur_c + 2] = true;
            }
        }
    }
    return final_step;
}

int main(){
    std::cin >> N;
            
    for(int i = 0 ; i < N ; i++){
        while(q.size() != 0){
            q.pop();
            step.pop();
        }
        memset(visited,0,sizeof(visited));
        std::cin >> len;
        std::cin >> start_r >> start_c;
        std::cin >> target_r >> target_c;
        
        q.push(std::make_pair(start_r,start_c));
        step.push(0);
        visited[start_r][start_c] = true;
        ans.push(bfs());
    }
    while(ans.size() != 0){
        std::cout << ans.front() << "\n";
        ans.pop();
    }
    return 0;
}
