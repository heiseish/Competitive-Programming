#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#define INFILE "F.inp"
#define OUTFILE "F.out"

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(INFILE, "r"))
    {
        freopen(INFILE, "r", stdin);
        freopen(OUTFILE, "w", stdout);
    }

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N, vector<int>(N, -100));

    for (int i = 0; i < M; ++i)
    {
        int A, B, C;
        cin >> A >> B >> C;
        A -= 1;
        B -= 1;
        graph[A][B] = C;
        graph[B][A] = -C;
    }

    for (int k = 0; k < N; ++k)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (graph[i][k] == -100 or graph[k][j] == -100)
                    continue;
                graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    vector<int> visited(N);

    vector<vector<int>> components, nxt;
    components.emplace_back();
    nxt.emplace_back();
    vector<int> degree(N);

    auto BFS = [&](int source) -> int
    {
        vector<int> current;
        queue<int> q;
        q.push(source);

        visited[source] = true;
        while (not q.empty())
        {
            int u = q.front();
            q.pop();

            current.push_back(u);
            for (int v = 0; v < N; ++v)
            {
                if (not visited[v] and graph[u][v] != -100)
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        components.emplace_back(current);

        for (int u : components.back())
        {
            for (int v : components.back())
            {
                if (graph[v][u] > 0)
                {
                    degree[v] += 1;
                }
            }
        }

        int root = -1;

        vector<int> temp_value(N, -1);
        for (int x : components.back())
        {
            visited[x] = false;
            if (degree[x] == 0)
            {
                root = x;
                visited[x] = true;
                q.push(x);
                temp_value[x] = 0;
            }
        }

        while (not q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : components.back())
            {
                if (graph[v][u] > 0 and visited[v] == false)
                {
                    visited[v] = true;

                    temp_value[v] = temp_value[u] + graph[v][u];
                    q.push(v);
                }
            }
        }

        sort(current.begin(), current.end(), [&](int u, int v)
             { return temp_value[u] < temp_value[v]; });

        int mask = 0;
        components.back() = move(current);

        for (int x : components.back())
        {
            mask |= 1 << temp_value[x];
        }

        return mask;
    };
    for (int i = 0; i < N; ++i)
    {
        if (visited[i])
            continue;

        int mask = BFS(i);
        nxt.emplace_back();

        while (mask < (1 << N))
        {
            nxt.back().push_back(mask);
            mask <<= 1;
        }
    }

    int len = (int)components.size();

    vector<vector<int>> dp_left(len + 1, vector<int>(1 << N)), dp_right(len + 1, vector<int>(1 << N));

    dp_left[0][0] = 1;
    for (int i = 1; i < len; ++i)
    {
        for (int mask = 0; mask < (1 << N); ++mask)
        {
            if (dp_left[i - 1][mask] == 0)
                continue;

            for (int x : nxt[i])
            {
                if ((mask & x) == 0)
                {
                    dp_left[i][mask | x] = true;
                }
            }
        }
    }

    dp_right[len][0] = 1;
    for (int i = len - 1; i; --i)
    {
        for (int mask = 0; mask < (1 << N); ++mask)
        {
            if (dp_right[i + 1][mask] == 0)
                continue;

            for (int x : nxt[i])
            {
                if ((mask & x) == 0)
                {
                    dp_right[i][mask | x] = true;
                }
            }
        }
    }

    vector<int> F(N, -1);

    for (int i = 1; i < len; ++i)
    {
        vector<int> &v = components[i];

        for (int chosen : nxt[i])
        {
            for (int left_mask = 0; left_mask < (1 << N); ++left_mask)
            {
                if ((left_mask & chosen))
                    continue;

                if (dp_left[i - 1][left_mask] and dp_right[i + 1][((1 << N) - 1) ^ left_mask ^ chosen])
                {
                    int p = 0;

                    for (int x = chosen; x; x -= x & -x)
                    {
                        int d = __builtin_ctz(x);

                        if (F[v[p]] == -100)
                        {
                            p += 1;
                            continue;
                        }

                        if (F[v[p]] >= 0)
                        {
                            F[v[p]] = -100;
                        }
                        else
                        {
                            F[v[p]] = d;
                        }

                        p += 1;
                    }

                    break;
                }
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        if (F[i] < 0)
            cout << "-1 ";
        else
            cout << F[i] + 1 << ' ';
    }
    return 0;
}