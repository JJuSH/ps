#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>
int test_num, N, K;
int t[1001];
int income[1001];
int X, Y, target;
int ans_step = 0;
std::vector<int> v[1001];
std::queue<int> q;
int result_time[1001];
bool flag;
void make_q(){
    for(int i = 1 ; i <= N ; i++){
        if(income[i] == 0){
            q.push(i);
            result_time[i] = t[i];
        }
    }
}

void top_order(){
    make_q();
 
    while(q.size() != 0){
        int cur = q.front();
        q.pop();
        for(unsigned int i = 0 ; i < v[cur].size() ; i++){
            int next = v[cur][i];
            result_time[next] = std::max(result_time[next], result_time[cur] + t[next]);
            income[next]--;
            if(income[next] == 0) q.push(next);
        }
    }
    std::cout << result_time[target] << "\n";
}

int main(){
    scanf("%d" , &test_num);
    for(int i = 0 ; i < test_num ; i++){
        scanf("%d %d", &N , &K);
        
        memset(income , 0 , sizeof(income));
        memset(result_time, 0 , sizeof(result_time));
        memset(t, 0 , sizeof(t));
        for(int j = 0 ; j <= 1000 ; j++){
            v[j].clear();
        }
        while(q.size() != 0) q.pop();
        
        for(int j = 1 ; j <= N ; j++){
            scanf("%d", &t[j]);
        }
        for(int j = 0 ; j < K ; j++){
            scanf("%d %d", &X , &Y);
            v[X].push_back(Y);
            income[Y]++;
        }
        scanf("%d" , &target);
        top_order();
    }
    return 0;
}
