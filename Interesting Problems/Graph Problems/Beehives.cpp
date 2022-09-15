#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define ll long long int

using namespace std;

vector<int> graph[505];
int dis[505];
bool visited[505];
int parent[505];
int shortest_cycle_length(int x)
{
    queue<int> q;
    q.push(x);
    dis[x] = 0;
    visited[x] = true;
    int minimum_cycle_length = INT_MAX;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto u : graph[v])
        {
            if (!visited[u])
            {
                dis[u] = dis[v] + 1;
                visited[u] = true;
                q.push(u);
                parent[u] = v;
            }
            else
            {
                if (parent[v] != u && parent[u] != v)
                    minimum_cycle_length = min(minimum_cycle_length, dis[u] + dis[v] + 1);
            }
        }
    }
    if (minimum_cycle_length == INT_MAX)
    {
        return -1;
    }
    else
    {
        return minimum_cycle_length;
    }
}

int main()
{
    fastio;
    int t;
    cin >> t;
    int kase=1;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        cout<<"Case "<<kase++<<": ";
        for (int i = 0; i < n; i++)
        {
            graph[i].clear();
            dis[i] = 0;
            visited[i] = false;
        }
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int ans=INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dis[j] = 0;
                visited[j] = false;
            }
            ans= min(ans,shortest_cycle_length(i));
        }
        if(ans!=-1)
        cout<<ans<<endl;
        else
        cout<<"impossible"<<endl;
    }
    return 0;
}
