#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

int main(){
    int N;
    scanf("%d", &N);
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
    
    for(int i = 0 ; i < N ; i++){
        int temp;
        std::cin >> temp;
        pq.push(temp);
    }
    
    long long int sum = 0;
    
    while(pq.size() != 1){
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        sum += num1 + num2;
        pq.push(num1 + num2);
    }
    std::cout << sum << "\n";
    return 0;
}
