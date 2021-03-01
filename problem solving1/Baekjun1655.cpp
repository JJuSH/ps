#include<iostream>
#include<stdio.h>
#include<queue>
#define INF 987654321

std::priority_queue<int, std::vector<int> , std::greater<int> > min_q;
std::priority_queue<int, std::vector<int> , std::less<int> > max_q;
int N;
int main(){
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        int temp;
        scanf("%d", &temp);
        if(min_q.size() < max_q.size()) min_q.push(temp);
        else max_q.push(temp);
        if(min_q.empty() == false && max_q.empty() == false){
            if(min_q.top() < max_q.top()){
                int from_min = min_q.top();
                int from_max = max_q.top();
                
                min_q.pop();
                max_q.pop();
                
                min_q.push(from_max);
                max_q.push(from_min);
            }
        }
        printf("%d\n", max_q.top());
    }
    return 0;
}
