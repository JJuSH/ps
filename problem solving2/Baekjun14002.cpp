#include<iostream>
#include<queue>
#include<stack>
std::stack<int> q;
int seq[1001];
int length[1001] = {0};
int track[1001] = {0};
int N;

int max_idx = 0;
void LIS(int n){
    for(int i = 1; i <= n ; i++){
        int count = 1;
        int prev = i;
        for(int j = 1; j <= i ; j++){
            if(seq[i] > seq[j]){
                count = std::max(count , length[j] + 1);
                if(count == length[j] + 1) prev = j;
            }
        }
        length[i] = count;
        track[i] = prev;
        if(length[max_idx] < count){
            max_idx = i;
        }
    }
}

int main(){
    std::cin >> N;
    for(int i = 1; i <= N ; i++){
        std::cin >> seq[i];
    }
    length[1] = 1;
    track[1] = 1;
    LIS(N);
    
    
    int flag = max_idx;
    q.push(max_idx);
    while(length[flag] != 1){
        flag = track[flag];
        q.push(flag);
    }
    std::cout << length[max_idx] << "\n";
    while(q.size() != 0){
        std::cout << seq[q.top()] << " ";
        q.pop();
    }
    std::cout << "\n";
    return 0;
}
