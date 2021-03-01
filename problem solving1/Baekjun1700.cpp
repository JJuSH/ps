#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#define INF 987654321
int N, K;
int seq[101];
int change_count = 0;
std::vector<int> v;
std::priority_queue<std::pair<int , int> > q;

bool used[101];
int count = 0;

int main(){
    std::cin >> N >> K;
    for(int i = 0 ; i < K ; i++){
        std::cin >> seq[i];
    }
    
    for(int i = 0 ; i < K ; i++){
        if(used[seq[i]] == false){
            if(v.size() < N){
                used[seq[i]] = true;
                v.push_back(seq[i]);
            }
            else{
                while(q.size() != 0) q.pop();
                for(int k = 0 ; k < v.size() ; k++){
                    
                    bool in_ = false;
                    for(int j = i + 1 ; j < K ; j++){
                        if(v[k] == seq[j]){
                            in_ = true;
                            q.push(std::make_pair(j , k));
                            break;
                        }
                    }
                    if(!in_) q.push(std::make_pair(INF, k));
                }
                int target = q.top().second;
                change_count++;
                used[v[target]] = false;
                used[seq[i]] = true;
                v[target] = seq[i];
            }
        }
    }
    std::cout << change_count << "\n";
    return 0;
}
