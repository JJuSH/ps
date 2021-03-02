#include <bits/stdc++.h>
using namespace std;

int N, M;
// company[x][k] : x 회사에 k원 투자할 때 얻는 가치
int company[22][333];
// dp[x][k] : x 까지 회사에서 k원으로 얻을 수 있는 최대 가치
int dp[22][333];
// 각 기업 투자 액수 추적할 배열
// path[x][k] : dp[x][k]를 최대로 만드는 x에서 투자한 금액
int path[22][333];

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

cin >> N >> M;
for (int i = 1; i <= N; ++i) {
    int invest;
    cin >> invest;
    for (int i = 1; i <= M; ++i) cin >> company[i][invest];
}

for (int i = 1; i <= M; ++i) { // 모든 기업
    for (int cost = 1; cost <= N; ++cost) { // 모든 투자 금액
        // i 기업에서 j만큼 쓴다고 생각.
        for (int j = 0; j <= cost; ++j) {
            // 이전 dp[i-1][cost-j] 에서 얻은 이익 + i기업에서 j금액으로 얻은 이익
            int val = dp[i - 1][cost - j] + company[i][j];
            if (val > dp[i][cost]) { // 이게 더 이득이면
                // dp 값 최신화
                dp[i][cost] = val;
                // dp[i][cost] 값을 최대로 만드는 i번째 회사 투자금액
                path[i][cost] = j;
            }
        }
    }
}

cout << dp[M][N] << '\n';

vector<int> ans;
int curr = M;
int cost = N;
while (curr > 0) {
    // dp[curr][cost] 를 최대로 만드는 현재 기업에서 투자하는 금액
    int now_invest = path[curr][cost];
    ans.push_back(now_invest);

    // 현재 기업에서 투자한 만큼 빼줌
    cost -= now_invest;
    // 이전 기업
    curr--;
}

reverse(ans.begin(), ans.end());
for (auto it : ans) cout << it << ' ';

return 0;
}
