#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<math.h>
std::vector<std::string> v;
std::priority_queue<std::pair<int, int> > q;
int count[26] = {0};
int val[26];
int N;

int main(){
    std::cin >> N;
    for(int i = 0 ; i < 26 ; i++) val[i] = -1;
    for(int i = 0 ; i < N ; i++){
        std::string s;
        std::cin >> s;
        v.push_back(s);
        for(unsigned j = 0 ; j < s.length() ; j++){
            int cur_char = s[j] - 65;
            count[cur_char] += pow(10,s.length() - j - 1);
        }
    }
    for(int i = 0 ; i < 26 ; i++){
        if(count[i] != 0) {
            //std::cout << char(i + 65) << " " << count[i] << "\n";
            q.push(std::make_pair(count[i], i));
        }
    }
    
    int cur_val = 9;
    int sum = 0;
    while(q.size() != 0){
        int cur_char = q.top().second;
        if(cur_val >= 0){
            sum += cur_val * q.top().first;
            cur_val--;
        }
        q.pop();
    }
    std::cout << sum << "\n";
    return 0;
}
