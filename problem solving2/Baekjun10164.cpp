#include <iostream>
#include <cstring>
using namespace std;
int n, m, k;
int field[16][16];
int dp[16][16];



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    int ky, kx;
    int num = 1;
    //1~n*m 초기화
    dp[0][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            if(num++ == k){
                ky = i;
                kx = j;
            }
        }
    }
    if(k == 0)
    {
        cout << dp[n][m];
        return 0;
    }
    int my = n - ky + 1;
    int mx = m - kx + 1;
    cout << dp[ky][kx] * dp[my][mx];
    return 0;
}

