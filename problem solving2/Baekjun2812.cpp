#include<iostream>
#include<string>
#include<deque>
#include<utility>
#include<algorithm>
int N, K;
std::deque<char> dq;
std::string s;

int main(){
    std::cin >> N >> K;
    std::cin >> s;
    
    for(unsigned int i = 0 ; i < s.length() ; i++){
        while(K && !dq.empty() && dq.back() < s[i]){
            dq.pop_back();
            K--;
        }
        dq.push_back(s[i]);
    }
    for(unsigned int i = 0 ; i < dq.size() - K; i++){
        std::cout << dq[i];
    }
    std::cout << "\n";
    return 0;
}
