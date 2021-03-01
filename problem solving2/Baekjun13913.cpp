#include<iostream>
#include<queue>
#include<utility>
#include<stack>
std::queue<std::pair<int , int> > pos;
std::stack<int> track;
int dp[100001] = {0,};
bool explored[100001] = {false,};
int N, K;
int tot_step;
void bfs(){
    pos.push(std::make_pair(N, 0));
    explored[N] = true;
    dp[N] = -1;
    
    while(pos.size() != 0){
        int cur_pos = pos.front().first;
        int cur_step = pos.front().second;
        //std::cout << "while " << cur_pos << " " << cur_step << "\n";
        pos.pop();
        if(cur_pos == K){
            tot_step = cur_step;
            break;
        }
        if(2*cur_pos <= 100000 && explored[2*cur_pos] == false){
            pos.push(std::make_pair(2*cur_pos , cur_step + 1));
            dp[2*cur_pos] = cur_pos;
            explored[2*cur_pos] = true;
        }
        if(cur_pos + 1 <= 100000 && explored[cur_pos + 1] == false){
            pos.push(std::make_pair(cur_pos + 1 , cur_step + 1));
            dp[cur_pos + 1] = cur_pos;
            explored[cur_pos + 1] = true;
            
        }
        if(cur_pos - 1 >= 0 && explored[cur_pos - 1] == false){
            pos.push(std::make_pair(cur_pos - 1 , cur_step + 1));
            dp[cur_pos - 1] = cur_pos;
            explored[cur_pos - 1] = true;
        }
    }
}
int main(){
    std::cin >> N >> K;
    bfs();
    std::cout << tot_step << "\n";
    
    int flag = K;
    while(flag != -1){
        //std::cout << "while " << flag << "\n";
        track.push(flag);
        flag = dp[flag];
    }
    while(track.size() != 0){
        std::cout << track.top() << " ";
        track.pop();
    }
    std::cout << "\n";
    return 0;
}
