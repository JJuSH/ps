#include<iostream>
#include<stack>
#include<vector>
#include<utility>
std::stack<std::pair<int, int> > st;
std::vector<int> ans;
int N;

int main(){
    std::cin >> N;
    for(int i = 1 ; i <= N ; i++){
        int temp;
        std::cin >> temp;
        while(true){
            if(st.size() == 0){
                ans.push_back(0);
                st.push(std::make_pair(temp, i));
                break;
            }
            else{
                int cur_height = st.top().first;
                int cur_index = st.top().second;
                
                if(cur_height > temp){
                    ans.push_back(cur_index);
                    st.push(std::make_pair(temp, i));
                    break;
                }
                else st.pop();
            }
        }
    }
    for(int i = 0 ; i < ans.size() ; i++){
        std::cout << ans[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
