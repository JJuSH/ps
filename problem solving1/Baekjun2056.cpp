#include<iostream>
#include<vector>
#include<queue>
int N;
int t[10001];
int entry[10001];
int time_sum[10001] = {0};
std::queue<int> q;
std::vector<int> v[10001];
int ans = 0;
void make_q(){
    for(int i = 1 ; i <= N ; i++){
        if(entry[i] == 0) q.push(i);
        time_sum[i] = t[i];
    }
}

void top_order(){
    make_q();
    while(q.size() != 0){
        int cur_node = q.front();
        int cur_time = time_sum[cur_node];
        q.pop();
        ans = std::max(ans, cur_time);
        int size_ = v[cur_node].size();
        
        for(int i = 0 ; i < size_ ; i++){
            int next = v[cur_node][i];
            entry[next]--;
            if(entry[next] == 0) q.push(next);
            time_sum[next] = std::max(time_sum[next], cur_time + t[next]);
        }
    }
}

int main(){
    std::cin >> N;
    
    for(int i = 1 ; i <= N ; i++){
        std::cin >> t[i];
        
        int num_par;
        std::cin >> num_par;
        entry[i] = num_par;
        
        for(int j = 0 ; j < num_par ; j++){
            int par;
            std::cin >> par;
            v[par].push_back(i);
        }
        
    }
    top_order();
    std::cout << ans << "\n";
    
    return 0;
}
