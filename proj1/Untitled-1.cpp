#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int maxRewardPoints(int A, int B, vector<vector<int>>& C) {
    vector<int> dist(A + 1, -INF);
    dist[B] = 0;

    for (int i = 0; i < A; i++) {
        for (int j = 0; j < C.size(); j++) {
            int u = C[j][0];
            int v = C[j][1];
            int w = C[j][2];

            if (dist[u] != -INF && dist[u] + w - (i * (i - 1) / 2) > dist[v]) {
                dist[v] = max(dist[v], dist[u] + w - (i * (i - 1) / 2));
            }
        }
    }

    int maxReward = 0;
    for (int i = 1; i <= A; i++) {
        maxReward = max(maxReward, dist[i]);
    }

    return maxReward;
}

int main() {
    int A, B, M;
    cin >> A >> B >> M;

    vector<vector<int>> C(M, vector<int>(3));
    for (int i = 0; i < M; i++) {
        cin >> C[i][0] >> C[i][1] >> C[i][2];
    }

    cout << maxRewardPoints(A, B, C) << endl;

    return 0;
}