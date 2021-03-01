#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<stack>
int N;
int max_idx = 0;
int max_len = 0;
std::vector<std::pair<long long int, long long int> > ans;
std::vector<long long int> lis;
std::stack<long long int> st;
void print_ans(){
    for(int i = 0 ; i < ans.size() ; i++){
        std::cout << ans[i].first << " " << ans[i].second << "\n";
    }
}
int main(){
    std::cin >> N;
    long long int temp;
    std::cin >> temp;
    ans.push_back(std::make_pair(0,temp));
    lis.push_back(temp);
    for(int i = 2 ; i <= N ; i++){
        
        std::cin >> temp;
        if(temp > lis[lis.size()-1]){
            lis.push_back(temp);
            ans.push_back(std::make_pair(lis.size() - 1, temp));
        }
        else{
            int pos = std::lower_bound(lis.begin() , lis.end() , temp) - lis.begin();
            lis[pos] = temp;
            ans.push_back(std::make_pair(pos,temp));
        }
        if(max_len < ans[ans.size()-1].first){
            max_len = ans[ans.size()-1].first;
            max_idx = ans.size() - 1;
        }
    }
    //print_ans();
    std::cout << max_len + 1 << "\n";
    while(max_len >= 0){
        if(ans[max_idx].first == max_len){
            st.push(ans[max_idx].second);
            max_len--;
            max_idx--;
        }
        else{
            max_idx--;
        }
    }
    while(st.size() != 0){
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << "\n";
    
}
