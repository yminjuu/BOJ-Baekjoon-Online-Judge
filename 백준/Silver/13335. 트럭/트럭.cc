#include <iostream>
#include <vector>

using namespace std; 

int n, w, L;
vector<int> truck_weights;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> w >> L;
    truck_weights.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> truck_weights[i];
    }

    vector<pair<int, int>> bridge;
    int sum = 0;
    int time = 0;
    int i = 0;

    while (i < n || !bridge.empty()) {
        time++;

        if (!bridge.empty()) {
            for (auto& truck : bridge) {
                truck.second--;
            }
            if (bridge.front().second == 0) {
                sum -= bridge.front().first;
                bridge.erase(bridge.begin());
            }
        }

        if (i < n && sum + truck_weights[i] <= L && bridge.size() < w) {
            bridge.push_back({truck_weights[i], w});
            sum += truck_weights[i];
            i++;
        }
    }

    cout << time << '\n';
    return 0;
}