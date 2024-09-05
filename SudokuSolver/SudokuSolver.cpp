#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e4, MaxV = 1e6;

int n, m;
int start, endd;
vector<int> res(MaxN, MaxV);
vector<vector<int>> a;
vector<vector<int>> ke (MaxN);

int ShortestDistance() {
    res[start] = 0;

    for(int i = 1; i < n; i++) {
        bool check = false;

        for(int j = 0; j < m; j++) {
            int u, v, x;
            u = a[j][0];
            v = a[j][1];
            x = a[j][2];

            if(res[u] > res[v] + x) {
                res[u] = res[v] + x;
                check = true;
            }

            if(res[v] > res[u] + x) {
                res[v] = res[u] + x;
                check = true;
            }
        }

        if(!check)
            break;
    }

    if(res[endd] == MaxV)
        res[endd] = -1;

    return res[endd];
}

int main() {
    cout << "Input n, m: ";
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        
        a.push_back(vector<int> ({u, v, x}));

        ke[u].push_back(v);
        ke[v].push_back(u);
    }

    cout << "Start, End: ";
    cin >> start >> endd;

    cout << "----------" << endl << "ShortestDistance: " << ShortestDistance();
}