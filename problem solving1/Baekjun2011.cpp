#include<iostream>
#include<string>
std::string password;
long long int dp[5001];
int main(){
    std::cin >> password;
    dp[0] = 1;
    dp[1] = 1;
    bool flag = true;
    int leng = password.length();
    if(password[0] == '0') flag = false;
    for(int i = 1 ; i <= leng ; i++){
        int num = (password[i-2] - '0') * 10 + (password[i-1] - '0');
        
        if(password[i-1] == '0'){
            if(num >= 1 && num <= 26){
                dp[i] = dp[i-2] % 1000000;
            }
            else{
                flag = false;
                break;
            }
        }
        else{
            if(num >= 1 && num <= 26 && password[i-2] != '0'){
                dp[i] = (dp[i-2] + dp[i-1]) % 1000000;
            }
            else{
                dp[i] = dp[i-1] % 1000000;
            }
        }
    }
    if(!flag) std::cout << 0 << "\n";
    else std::cout << dp[leng] << "\n";
    return 0;
}
