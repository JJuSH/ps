#include<iostream>
#include<string>
#include<stack>

int st_to_int(std::stack<int> &s){
    int deci = 1;
    int sum = 0;
    while(s.size() != 0){
        sum += (s.top() - 48) * deci;
        deci = deci * 10;
        s.pop();
    }
    return sum;
}
int main(){
    std::string eq;
    std::cin >> eq;
    std::stack<int> st;
    int total = 0;
    int cur_int;
    bool _op = true;
    
    for(auto a = eq.begin() ; a != eq.end() ; a++){
        if(a == eq.end() - 1){
            st.push(*a);
            if(_op) total += st_to_int(st);
            else total -= st_to_int(st);
        }
        if(*a == '-' || *a == '+'){
            if(_op) total += st_to_int(st);
            else total -= st_to_int(st);
            
            if(*a == '-') _op = false;
        }else st.push(*a);
    }
    std::cout << total << "\n";
    
    return 0;
}
