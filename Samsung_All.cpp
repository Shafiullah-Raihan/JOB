# Travelling Salesman --------->


int adj[20][20];
int vis[20];
int solve(int cnt , int last)
{
    if (cnt == n)
    {
        return adj[last][0];
    }
    int ret = inf;
    for (int i = 1; i < n; i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            ret = min(ret , solve(cnt + 1 , i) + adj[last][i] );
            vis[i] = 0;
        }
    }
    return ret;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            for (int j = 0; j < n; j++)
            {
                cin >> adj[i][j];
            }
        }

        ans = solve(1, 0);
        cout << ans << endl;
    }

}


# Flip Column ----------------->


int arr[16][16];

void flip(int i) {
    for (int j = 0; j < n; j++)
        if (arr[j][i])
            arr[j][i] = 0;
        else
            arr[j][i] = 1;
}


void solve(int cnt)
{
    if (cnt == k)
    {
        int counT = 0 , row = 0;
        for (int i = 0; i < n; i++)
        {
            counT = 0 ;
            for (int j = 0; j < m; j++)
            {
                if ( arr[i][j] == 1 )
                    counT++;
            }
            if (counT == m)
                row++;
        }

        ans = max(ans , row);
        return ;
    }

    for (int jj = 0; jj < m; jj++)
    {
        flip(jj);
        solve(cnt + 1);
        flip(jj);
    }
    return;
}

int main()
{
    int t = 1;
    //cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        ans = 0;
        solve(0);
        cout << ans << endl;
    }

}


# Endoscope ------------------->

int a[50][50],n,m;
int vis[50][50]={0};

void DFS(int xpos,int ypos,int rem_len){
    if(xpos<0 || xpos>=n || ypos<0 || ypos>=m || rem_len==0)
        return;
    vis[xpos][ypos]=1;
    if(a[xpos][ypos] == 1){

        if((xpos!=0) && (a[xpos-1][ypos] ==2 || a[xpos-1][ypos] ==5 || a[xpos-1][ypos] ==6 || a[xpos-1][ypos] ==1))  //up
            DFS(xpos-1, ypos, rem_len-1);

        if((xpos!=n-1) && (a[xpos+1][ypos] ==2 || a[xpos+1][ypos] ==4 || a[xpos+1][ypos] ==7 || a[xpos+1][ypos] ==1)) //down
            DFS(xpos+1, ypos, rem_len-1);

        if((ypos!=0)&& (a[xpos][ypos-1] ==3 || a[xpos][ypos-1] ==4 || a[xpos][ypos-1] ==5 || a[xpos][ypos-1] ==1))     //left
            DFS(xpos, ypos-1, rem_len-1);

        if((ypos!=m-1) && (a[xpos][ypos+1] ==3 || a[xpos][ypos+1] ==6 || a[xpos][ypos+1] ==7 || a[xpos][ypos+1] ==1))   //right
            DFS(xpos, ypos+1, rem_len-1);

    }
    else if(a[xpos][ypos] == 2)
    {
        if((xpos!=0) && (a[xpos-1][ypos] ==1 || a[xpos-1][ypos] ==5 || a[xpos-1][ypos] ==6 || a[xpos-1][ypos] ==2))    //up
            DFS(xpos-1, ypos, rem_len-1);

        if((xpos!=n-1) && (a[xpos+1][ypos] ==1 || a[xpos+1][ypos] ==4 || a[xpos+1][ypos] ==7 || a[xpos+1][ypos] ==2))  //down
            DFS(xpos+1, ypos, rem_len-1);
    }
    else if(a[xpos][ypos] == 3)
    {
        if((ypos!=0)&& (a[xpos][ypos-1] ==1 || a[xpos][ypos-1] ==4 || a[xpos][ypos-1] ==5 || a[xpos][ypos-1] ==3))     //left
            DFS(xpos, ypos-1, rem_len-1);

        if((ypos!=m-1) && (a[xpos][ypos+1] ==1 || a[xpos][ypos+1] ==6 || a[xpos][ypos+1] ==7 || a[xpos][ypos+1] ==3))   //right
            DFS(xpos, ypos+1, rem_len-1);
    }
    else if(a[xpos][ypos] == 4)
    {
        if((xpos!=0) && (a[xpos-1][ypos] ==1 || a[xpos-1][ypos] ==2 || a[xpos-1][ypos] ==5 || a[xpos-1][ypos] ==6))    //up
            DFS(xpos-1, ypos, rem_len-1);

        if((ypos!=m-1) && (a[xpos][ypos+1] ==1 || a[xpos][ypos+1] ==3 || a[xpos][ypos+1] ==6 || a[xpos][ypos+1] ==7))   //right
            DFS(xpos, ypos+1, rem_len-1);
    }
    else if(a[xpos][ypos] == 5)
    {
        if((xpos!=n-1) && (a[xpos+1][ypos] =1 || a[xpos+1][ypos] ==2 || a[xpos+1][ypos] ==7 || a[xpos+1][ypos] ==4))  //down
            DFS(xpos+1, ypos, rem_len-1);

        if((ypos!=m-1) && (a[xpos][ypos+1] ==1 || a[xpos][ypos+1] ==3 || a[xpos][ypos+1] ==6 || a[xpos][ypos+1] ==7))   //right
            DFS(xpos, ypos+1, rem_len-1);
    }
    else if(a[xpos][ypos] == 6)
    {
        if((xpos!=n-1) && (a[xpos+1][ypos] ==1 || a[xpos+1][ypos] ==2 || a[xpos+1][ypos] ==7 || a[xpos+1][ypos] ==4))  //down
            DFS(xpos+1, ypos, rem_len-1);

        if((ypos!=0)&& (a[xpos][ypos-1] ==1 || a[xpos][ypos-1] ==3 || a[xpos][ypos-1] ==5 || a[xpos][ypos-1] ==4))     //left
            DFS(xpos, ypos-1, rem_len-1);
    }
    else if(a[xpos][ypos] == 7)
    {
        if((xpos!=0) && (a[xpos-1][ypos] ==1 || a[xpos-1][ypos] ==2 || a[xpos-1][ypos] ==5 || a[xpos-1][ypos] ==6))    //up
            DFS(xpos-1, ypos, rem_len-1);

        if((ypos!=0)&& (a[xpos][ypos-1] ==1 || a[xpos][ypos-1] ==3 || a[xpos][ypos-1] ==4 || a[xpos][ypos-1] ==5))     //left
            DFS(xpos, ypos-1, rem_len-1);
    }
}


int main() {
    int t,i,j,k,x,y,l;
    cin>>t;
    while(t--){

       cin>>n>>m>>x>>y>>l;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++)
                cin>>a[i][j];
        }

        DFS(x,y,l);

        int count=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(vis[i][j]==1){
                     count++;
                    vis[i][j]=0;
                }
            }
        }
        cout<<count<<endl;
    }
}




# Kim Refrigerator


int main()
{
    fastio;
    t = 10;
    //cin >> t;
    while (t--)
    {
        counT = inf;
        cin >> n ;
        vector<pair<int, int>>vc;
        vector<int>per;

        int homea , homeb , offa , offb ;
        cin >> offa >> offb >> homea >> homeb;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            per.push_back(i + 1);
            vc.push_back({a, b});
        }

        do
        {
            sum = 0 ;
            pair<int, int> pp = {offa , offb};
            for (int i = 0; i < per.size(); i++) {
                sum += abs(vc[per[i] - 1].first - pp.first) + abs(vc[per[i] - 1].second - pp.second);
                pp = vc[per[i] - 1];
            }
            sum += abs(homea - pp.first) + abs(homeb - pp.second);

            //    dbg(per);

            counT = min(counT , sum);
        } while ( (next_permutation(per.begin(), per.end())) );

        cout << "# " << ++cs  << ' ' << counT << endl;


    }
}





# Warmholes -------------------->


int mask[10], w[10][5], f = 0;
int distance(int sx, int sy, int dx, int dy) {
    int xd = abs(dx - sx);
    int yd = abs(dy - sy);
    return (xd + yd);
}

void cal(int sx, int sy, int dx, int dy, int dis)
{
    ans = min(ans, distance(sx, sy, dx, dy) + dis);
    for (int i = 0; i < n; i++)
    {
        if (mask[i] == 0)
        {
            mask[i] = 1;

            int temp = distance(sx, sy, w[i][0], w[i][1]) + dis + w[i][4];
            cal(w[i][2], w[i][3] , dx , dy , temp);

            temp = distance(sx, sy, w[i][2], w[i][3]) + dis + w[i][4];
            cal(w[i][0], w[i][1] , dx , dy , temp);

            mask[i] = 0 ;
        }
    }

}

int main()
{
    fastio;
    t = 10;
    cin >> t;
    while (t--)
    {

        cin >> n;
        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;

        for (int i = 0; i < n; i++) {
            mask[i] = 0;
            for (int j = 0; j < 5; j++) {
                cin >> w[i][j];
            }
        }
        ans = 999999;
        cal(sx, sy, dx, dy, 0);
        cout << ans << endl;


    }
}




# Burst Balloons Optimally  ----------------->

ll arr[15] , vis[15] ;

void func(ll cnt , ll sum)
{
    if (cnt == n)
    {
        Max = max(Max , sum);
        return ;
    }

    ll new_ans = sum;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            ll lf = 0 , rf = 0 , lf_val = 1 , rf_val = 1;

            for (j = i - 1; j >= 0; j--)
            {
                if (vis[j] == 0)
                {
                    lf = 1;
                    lf_val = arr[j];
                    break;
                }
            }
            for (j = i + 1; j < n; j++)
            {
                if (vis[j] == 0)
                {
                    rf = 1;
                    rf_val = arr[j];
                    break;
                }
            }


            if (lf == 0 and rf == 0)
                sum += arr[i];
            else sum = sum + (lf_val * rf_val);

            func(cnt + 1 , sum);
            vis[i] = 0;
            sum = new_ans;

        }
    }
    return ;
}

int main()
{
    fastio;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        vis[i] = 0;
    }

    Max = -inf;
    func(0, 0);

    cout << Max << ln;
}




# Fisherman

int gates[3];
int fisherman[3];
int visited[20];

void permut(int visited[] , int l , int r)
{
    if (l == r)
    {

        int i, j, k, dist = 0;
        for (i = 0; i < fisherman[0]; i++) {
            dist = dist + abs(visited[i] - gates[0]) + 1 ;
        }
        for (j = 0; j < fisherman[1]; j++) {
            dist = dist + abs(visited[i] - gates[1]) + 1 ;
            i += 1;
        }
        for (k = 0; k < fisherman[2]; k++) {
            dist = dist + abs(visited[i] - gates[2]) + 1 ;
            i += 1;
        }

        counT = min(counT , dist);

        return ;


    }
    else
    {
        for (int i = l; i <= r; i++) {
            swap(visited[i], visited[l]);
            permut(visited, l + 1, r);
            swap(visited[i], visited[l]);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < 3; i++)
        cin >> gates[i];
    for (int i = 0; i < 3; i++)
        cin >> fisherman[i];

    for (int i = 0; i < n; i++)
        visited[i] = i + 1;

    permut(visited, 0, n - 1);
    cout << counT << endl;

}

# Aeroplane Bombing

ll arr[12][12];

void solve(int row , int col , int temp , int &ans , int bomb , int effect)
{
    if (row < 0)
    {
        ans = max(ans , temp);
        return;
    }

    for (int i = -1 ; i <= 1 ; i++)
    {
        if ( (col + i) < 0 or (col + i) > 4 ) continue;

        if (arr[row][col + i] == 1 or arr[row][col + i] == 0) /// no enemy
        {
            if (bomb == 0)
                solve(row - 1, col + i, temp + arr[row][col + i] , ans , bomb , effect - 1 );
            else
                solve(row - 1, col + i, temp + arr[row][col + i] , ans , bomb , effect );
        }
        else
        {
            if (bomb == 0)
            {
                if (effect > 0)
                {
                    solve(row - 1, col + i, temp, ans , bomb , effect - 1 );
                }
            }
            else
                solve(row - 1, col + i, temp , ans , 0 , 5 );
        }
    }
    return ;

}

int main()
{
    fastio;
    t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n; m = 5;

        f0(i, n)
        {
            f0(j, m)
            {
                cin >> arr[i][j];
            }
        }

        int ans = 0 ;
        solve(n - 1, 2, 0, ans , 1 , 0);
        cout << "#" << ++cs << ' ' << ans << endl;

    }
}



#  Rock Climbing


ll arr[12][12];

void solve(int row , int col , int temp , int &ans , int bomb , int effect)
{
    if (row < 0)
    {
        ans = max(ans , temp);
        return;
    }

    for (int i = -1 ; i <= 1 ; i++)
    {
        if ( (col + i) < 0 or (col + i) > 4 ) continue;

        if (arr[row][col + i] == 1 or arr[row][col + i] == 0) /// no enemy
        {
            if (bomb == 0)
                solve(row - 1, col + i, temp + arr[row][col + i] , ans , bomb , effect - 1 );
            else
                solve(row - 1, col + i, temp + arr[row][col + i] , ans , bomb , effect );
        }
        else
        {
            if (bomb == 0)
            {
                if (effect > 0)
                {
                    solve(row - 1, col + i, temp, ans , bomb , effect - 1 );
                }
            }
            else
                solve(row - 1, col + i, temp , ans , 0 , 5 );
        }
    }
    return ;

}

int main()
{
    fastio;
    t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n; m = 5;

        f0(i, n)
        {
            f0(j, m)
            {
                cin >> arr[i][j];
            }
        }

        int ans = 0 ;
        solve(n - 1, 2, 0, ans , 1 , 0);
        cout << "#" << ++cs << ' ' << ans << endl;

    }
}





# Sum of Nodes at Kth Level


int main()
{
    string s;
    cin >> n >> s;
    sum = 0 , counT = 0 ;
    stack<pair<char , ll>>st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ')')
        {
            if (s[i] == '(')
            {
                st.push({s[i], counT});
                counT++;
            }
            else
            {
                st.push({s[i], inf});
            }
        }
        else
        {
            string num = "";
            // dbg( i , st.size());
            while (st.top().F != '(')
            {
                if ( (st.top().F - '0') >= 0  and (st.top().F - '0') <= 9 )
                {
                    num += st.top().F;
                }
                st.pop();
            }
            reverse(all(num));

            int jog = 0;
            f0(j, num.size())
            jog = jog * 10 + (num[j] - '0');

            //    dbg(num , jog);

            counT = st.top().S;
            st.pop();
            if (counT == n)
                sum += jog;

        }

    }

    cout << sum << endl;



}





# Detect CYcle and print minimum sum

vector<pll>vc;
vector<ll>graph[100];

vector<int>parent , color ;
int start_cycle , end_cycle ;

bool dfs(int node)
{
    color[node] = 1;
    for (auto it : graph[node])
    {
        if (color[it] == 0)
        {
            parent[it] = node;
            if ( dfs(it) ) return true;
        }
        else if (color[it] == 1)
        {
            start_cycle = it;
            end_cycle = node;
            return true;
        }

    }
    color[node] = 2;
    return false;
}

int main()
{
    fastio;
    cin >> n >> m;
    f0(i, 2 * m)
    {
        cin >> a >> b ;
        vc.pb({a, b});
    }
    Max = (1 << n) - 1;
    counT = inf;
    vector<ll>res;

    i = Max;
    for (i = 0; i <= Max; i++)
    {

        map<ll, ll>mp;
        vector<ll>new_node;

        for (j = 0; j < n; j++)
        {
            if (checkBit(i, j))
            {
                int node = j + 1;
                mp[node]++;
            }
        }

        f1(j, n)
        {
            graph[j].clear();
        }
        for (auto it : vc)
        {
            if (mp[it.F] and mp[it.S])
            {
                graph[it.F].pb(it.S);
                new_node.pb(it.F);
                new_node.pb(it.S);
            }
        }



        /// Find Cycle
        color.assign(n + 1 , 0);
        parent.assign(n + 1 , -1);
        start_cycle = -1;

        for (auto it : new_node)
        {
            if (color[it] == 0 and dfs(it))
                break;
        }


        if (start_cycle != -1)
        {

            vector<int>cycle;
            ll cost = 0;
            for (int v = end_cycle ; v != start_cycle ; v = parent[v])
            {
                cycle.pb(v);
                cost += v;
            }
            cycle.push_back(start_cycle);


            if (counT > cost)
            {
                sort(all(cycle));
                for (auto it : cycle)
                    res.pb(it);
                counT = cost;
            }

        }
    }


    for (auto it : res)
        cout << it << ' ';
    cout << endl;
}





# cycle undirected graph

int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v, int par) { // passing vertex and its parent vertex
    visited[v] = true;
    for (int u : adj[v]) {
        if(u == par) continue; // skipping edge to parent vertex
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}

void find_cycle() {
    visited.assign(n, false);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dfs(v, parent[v]))
            break;
    }

    if (cycle_start == -1) {
        cout << "Acyclic" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}






# bipartite

bool isBipartite(int G[][V], int src)
{

    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;

    // Assign first color to source
    colorArr[src] = 1;

    queue <int> q;
    q.push(src);

    // Run while there are vertices
    // in queue (Similar to BFS)
    while (!q.empty())
    {
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
        int u = q.front();
        q.pop();

        // Return false if there is a self-loop
        if (G[u][u] == 1)
        return false;

        for (int v = 0; v < V; ++v)
        {

            if (G[u][v] && colorArr[v] == -1)
            {
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }

            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }

    return true;
}




# Men's Restroom

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct s
{
    int distance;
    int start;
    int ending;
};
struct fn
{
    bool operator()(s const&a,s const &b)
    {
        if(a.distance!=b.distance)
        {
            return a.distance<b.distance;
        }
        return a.start<b.start;
    }
};
int main()
{
    int n;
    cin >> n;
    int mat[n] = {0};
    priority_queue<s,vector<s>,fn> q;
    struct s temp;
    int l=1,r=n,coun=1;
    q.push({n,l,r});
    while(!q.empty())
    {
        temp = q.top();
        q.pop();
        int left = temp.start;
        int right = temp.ending;
        int mid = (left+right)/2;
        if(temp.distance>0)
        {
            if(right>mid)
            {
                q.push({right-mid,mid+1,right}); // first push right child then left
            }
            if(left<mid)
            {
                q.push({mid-left,left,mid-1});
            }
        }
        mat[mid-1] = coun;
        coun++;
        for(int i=0; i<n; i++)
        {
            if(mat[i]==0)
            {
                cout << "_" << " ";
            }
            else
            {
                cout << "X" << " ";
            }

        }
        cout << endl;
    }

}



# Rare elements

#include<iostream>
using namespace std;

struct node {
    int x;
    int y;
    int level;
};

node q[1000];
int front = 0, back = 0;

void init() {
    front = back = 0;
}

void push(int x, int y, int level) {
    q[back].x = x;
    q[back].y = y;
    q[back].level = level;
    back++;
}
node pop() {
    return q[front++];
}
bool empty() {
    return (front == back);
}


int a[100][100];
int rare[4][2];
int c;
int n;

bool valid(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

int vis[100][100];

int xx[] = { -1, 0, 1, 0};
int yy[] = {0, 1, 0, -1};

int bfs(int sx, int sy, int dx, int dy) {

    push(sx, sy, 0);
    vis[sx][sy] = 1;

    while (!empty()) {

        node temp = pop();
        if (temp.x == dx && temp.y == dy) return temp.level;

        for (int i = 0; i < 4; i++) {

            int valx = temp.x + xx[i];
            int valy = temp.y + yy[i];
            int lvl = temp.level + 1;

            if (valid(valx, valy)) {
                if (a[valx][valy] == 1 && vis[valx][valy] == 0) {
                    push(valx, valy, lvl);
                    vis[valx][valy] = 1;
                }
            }
        }
    }

}


int main() {


    int t; cin >> t;
    while (t--) {
        cin >> n;
        cin >> c;

        init();

        for (int i = 0; i < c; i++) {
            int x, y; cin >> x >> y;

            x--; y--;
            rare[i][0] = x;
            rare[i][1] = y;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        int ans = 10000;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int temp;

                if (a[i][j] == 1) {
                    temp = 0;

                    for (int k = 0; k < c; k++) {

                        init();
                        for (int l = 0; l < 100; l++)
                            for (int m = 0; m < 100; m++)
                                vis[l][m] = 0;

                        int res = bfs(i, j, rare[k][0], rare[k][1]);
                        temp = max(res, temp);
                    }

                    ans = min(ans, temp);
                }

            }
        }
        cout << ans << endl;
    }

    return 0;
}



# Sum binary tree

class Node
{
public:
	int data;
	Node *left , *right;
};

Node *newNode(int data)
{
	Node *temp = new Node;
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;

	return temp;
}

int toSumTree(Node *root)
{
	if (root == NULL) return 0;

	int old_val = root->data;
	root->data = toSumTree(root->left) + toSumTree(root->right);

	return root->data + old_val;

}

void printInorder(Node *root)
{
	if (root == NULL) return ;
	printInorder(root->left);
	cout << " " << root->data;
	printInorder(root->right);
}


int main()
{
	Node *root;
	root = newNode(10);
	root->left = newNode(-2);
	root->right = newNode(6);
	root->left->left = newNode(8);
	root->left->right = newNode(-4);
	root->right->left = newNode(7);
	root->right->right = newNode(5);

	toSumTree(root);

	cout << "Inorder Traversal of the resultant tree is: \n";
	printInorder(root);
	return 0;

}




# Day from a week

const string str[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int dayofweek(int d, int m, int y)
{
    int t[] = {11, 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 12; i++)
    {
        double dd =   (2.6 * t[i] - 0.2) ;
        cout << dd << ' ';
    }

    for (int i = 0; i < 12; i++)
        cout << t[i] << ' ';
    cout << endl;

    //int t[] = {0, 3, 2, 5, 0, 5, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y / 4 + y / 400 - y / 100 + t[m - 1] + d) % 7;
}
int main()
{
    while (1) {
        int d, m, y;
        cin >> d >> m >> y;
        int num = dayofweek(d, m, y);
        cout << str[num] << endl;
        break;
    }
    return 0;
}

/*

So consider this as an array : int t[] = {11,12,1,2,3,4,5,6,7,8,9,10};

Now for all elements in array just do : (2.6*m - 0.2) mod 7 parse
the result as integer and you will get this: 0 3 2 5 0 3 5 1 4 6 2 4

*/



# Largest bst

/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' is the total number of nodes in the binary tree.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

struct info
{
	bool isValid;
	int size, min, max;
};

info maxSize(Node* currNode, int &maxBST)
{
	if (currNode == NULL)
	{
		// isValid, size, min, max.
		return {true, 0, INT_MAX, INT_MIN};
	}


	// Information of left and right subtrees.
	info left = maxSize(currNode -> left, maxBST);
	info right = maxSize(currNode -> right, maxBST);


	info currInfo;

	currInfo.size = left.size + right.size + 1;


	currInfo.isValid = left.isValid & right.isValid;

	// Current subtree must form a BST.
	currInfo.isValid &= (currNode -> data > left.max);
	currInfo.isValid &= (currNode -> data < right.min);

	// Updating min and max for current subtree.
	currInfo.min = min(min(left.min, right.min), currNode -> data);
	currInfo.max = max(max(left.max, right.max), currNode -> data);


	if (currInfo.isValid == true)
	{
		maxBST = max(maxBST, currInfo.size);
	}

	return currInfo;
}



int main()
{
	Node *root = new Node(60);
	root->left = new Node(65);
	root->right = new Node(70);
	root->left->left = new Node(50);

	int ans = 0;
	maxSize(root , ans);
	printf(" Size of the largest BST is %d\n", ans);
	return 0;

}




# Closest leaf


class BinaryTreeNode {
public :
	T data;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;

	BinaryTreeNode(T data) {
		this -> data = data;
		left = NULL;
		right = NULL;
	}

};

const int INF = 1e6;

// Function that returns the distance of the closest leaf in the sub tree.
int closestLeafNodeInSubtree(BinaryTreeNode<int> *root) {
	if (root == NULL) {
		return INF;
	}
	if (root->left == NULL && root->right == NULL) {
		// Node is a leaf node.
		return 0;
	}

	int distLeft = closestLeafNodeInSubtree(root->left);
	int distRight = closestLeafNodeInSubtree(root->right);

	return 1 + min(distLeft, distRight);
}

// Helper function to calculate the closest leaf distance of the node.
int findClosestLeafNodeDistanceHelper(vector<BinaryTreeNode<int> *> &ancestors,
                                      BinaryTreeNode<int> *root, int x) {

	if (root == NULL) {
		return INF;
	}

	// If the required node is found, calculate the distance of the closest leaf node.
	if (root->data == x) {
		int result = closestLeafNodeInSubtree(root);
		int n = ancestors.size();
		for (int i = n - 1; i >= 0; --i) {
			int dist = n - i + closestLeafNodeInSubtree(ancestors[i]);
			result = min(result, dist);
		}
		return result;
	}
	// Else check for other nodes by adding and removing the nodes as ancestor and recur further.
	ancestors.push_back(root);

	int distLeft = findClosestLeafNodeDistanceHelper(ancestors, root->left, x);
	int distRight = findClosestLeafNodeDistanceHelper(ancestors, root->right, x);

	ancestors.pop_back();

	return min(distLeft, distRight);
}

int findClosestLeafNodeDistance(BinaryTreeNode<int> *root, int x) {
	// Vector to store the ancestors of the node in the tree.
	vector<BinaryTreeNode<int> *> ancestors;

	return findClosestLeafNodeDistanceHelper(ancestors, root, x);
}





# All posible BST

// For 0th ans = 1;
void catalan(int n)
{
    cpp_int cat_ = 1;
    cout << cat_ << " "; // C(0)
    for (cpp_int i = 1; i <=n; i++)
    {
        cat_ *= (4 * i - 2);
        cat_ /= (i + 1);
        cout << cat_ << " ";
    }
}



# Crow Pot

int minCrowPotStone()
{
    int tot_stone = 0;
    int temp[n + 9];
    temp[0] = a[0];
    for (int i = 1; i < n ; i++)
        temp[i] = a[i] - a[i - 1];
    for (int i = 0; i < m; i++)
        tot_stone += (temp[i] * (n - i) );
    return tot_stone;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort();
    cout << minCrowPotStone() << endl;
}



# oil mine

int n , m , ans = INT_MAX ;
void calculateTotal(int i, int curr, int oil[], int visited[], int minV, int maxV, int comNum)
{
	if (visited[i]) {
		int newMin = min(curr, minV);
		int newMax = max(curr, maxV);

		if (comNum == n - 1) {
			ans = min(ans, newMax - newMin);
		}
		return;
	}
	visited[i] = 1;
	int j = (i + 1) % m;

	calculateTotal(j, curr + oil[i] , oil, visited, minV, maxV, comNum);

	int newMin = min(curr, minV);
	int newMax = max(curr, maxV);

	calculateTotal(j , oil[i], oil, visited, newMin, newMax, comNum + 1 );

	visited[i] = 0;
	return;

}
int main()
{
	cin >> n >> m;
	int oil[m] , visited[m];
	for (int i = 0; i < m; i++)
		cin >> oil[i] , visited[i] = 0;

	if (n > m)
	{
		cout << -1 << endl;
		return 0;
	}


	for (int i = 0; i < m; i++)
		calculateTotal(i , 0 , oil , visited , INT_MAX , INT_MIN , 0);
	cout << ans << endl;

}



# Jewel Maze



/*
There is a maze that has one entrance and one exit. Jewels are placed in passages of the maze. You want to pick up the jewels after getting into the maze through the entrance and before getting out of it through the exit. You want to get as many jewels as possible, but you don’t want to take the same passage you used once.

When locations of a maze and jewels are given, find out the greatest number of jewels you can get without taking the same passage twice, and the path taken in this case.

Input
There can be more than one test case in the input file. The first line has T, the number of test cases. Then the totally T test cases are provided in the following lines (T ≤ 10 ).

In each test case, In the first line, the size of the maze N (1 ≤ N ≤ 10) is given. The maze is N×N square-shaped. From the second line through N lines, information of the maze is given. “0” means a passage, “1” means a wall, and “2” means a location of a jewel. The entrance is located on the upper-most left passage and the exit is located on the lower-most right passage. There is no case where the path from the entrance to the exit doesn’t exist.

Output
From the first line through N lines, mark the path with 3 and output it. In N+1 line, output the greatest number of jewels that can be picked up. Each test case must be output separately as a empty.

MAX DIAMONDS COLLECTED AND ITS PATH IS THE OUTPUT.

*/

#include<iostream>
using namespace std;

int n;
int a[100][100];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

bool valid(int x, int y){
    return ((a[x][y] == 0 || a[x][y] == 2) && x>=0 && x<n && y>=0 && y<n);
}

int ans[50][50];
//int paths;
int value = -100;

void print(){
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void solve(int r, int c, int diamonds){

    if(r == n-1 && c == n-1){
        if(diamonds>value){
          value = diamonds;
          for(int i = 0; i<n; i++){
             for(int j = 0; j<n; j++){
                ans[i][j] = a[i][j];
                //print();
             }
          }
        }
    }

    for(int i=0; i<4; i++){

        int x = r + dx[i];
        int y = c + dy[i];

        if(valid(x,y)){

            int check = (a[x][y] == 2) ? 1:0;
            a[x][y] = 3;
            solve(x,y,diamonds + check);
            a[x][y] = (check == 1) ? 2:0;
        }
    }
}


int main(){

    cin>>n;
    for(int i =0; i<n; i++)
    for(int j =0; j<n; j++)
    cin>>a[i][j];

    /* here 2 is diamond
       0 means a passage
       1 means a wall
      */
    //paths = 0;
    value = -100;
    a[0][0] = 3;
    solve(0,0,0);
    cout<<value<<endl;
    print();

    return 0;
}










# Lanching Bomb


int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


void solve() {

	if (a[sx][sy] == 0)return;

	vis[sx][sy] = true;
	push(sx, sy, 1);


	while (!empty()) {

		node temp = pop();

		int x, y, l;
		x = temp.x;
		y = temp.y;
		l = temp.l;


		ans = max(ans, l);


		for (int i = 0; i < 4; i++) {

			int xx = x + dx[i];
			int yy = y + dy[i];

			if (valid(xx, yy) && a[xx][yy] == 1) {
				vis[xx][yy] = true;
				push(xx, yy, l + 1);
			}

		}

	}

}

int main() {

	int t; cin >> t;
	while (t--) {

		/* FIRST COLUMN IS TAKEN AS INPUT AND THEN ROW ACC.
		TO TEST CASES */
		cin >> m >> n;


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vis[i][j] = false;
				cin >> a[i][j];
			}
		}
		/* acc to the test cases first col is taken as input and then row
		   I have taken the input as row and then col so write it down as
		   cin>>sy>>sx
		*/
		cin >> sx >> sy;
		sx--; sy--;  /* zero based indexing */
		init();
		ans = -1;
		solve();
		cout << ans << endl;
	}


	return 0;
}



# Count BSt and BS

#include<iostream>
using namespace std;
#define ll long long

const ll MOD = 1e9 + 7;
const ll N = 500;
ll fact[1005] , n = 1000 ;


ll normal(ll &a)
{
	a %= MOD;
	if (a < 0) a += MOD;
}
ll ModMul(ll a, ll b)
{
	normal(a), normal(b);
	return (a * b) % MOD;
}
ll ModPow(ll b, ll p)
{
	ll r = 1;
	while (p)
	{
		if (p & 1) r = ModMul(r , b);
		b = ModMul(b, b);
		p >>= 1;
	}
	return r;
}
ll modInverse(ll a) {
	return ModPow(a, MOD - 2);
}

ll ModDiv(ll a, ll b)
{
	return ModMul(a , ModPow(b , MOD - 2));
}

void func()
{
	fact[0] = 1;
	for (int i = 1; i <= n; i++)
		fact[i] = ModMul(fact[i - 1] , i );
}

ll NcR(ll n, ll r)
{
	if (n < r)
		return 0;
	if (r == 0)
		return 1;


	return (fact[n] * modInverse(fact[r]) % MOD
	        * modInverse(fact[n - r]) % MOD)
	       % MOD;
}

long long NCR(ll n, ll r) { /// O(r)
	if (r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
	long long ans = 1;
	for (int i = 1; i <= r; i++) {
		ans *= n - r + i; /// or ans *= n-i+1
		ans /= i;
	}
	return ans;
}

unsigned long int catalan(unsigned long int n)
{
	// Calculate value of 2nCn
	unsigned long int _2nCn = NCR(2 * n, n);

	// return 2nCn/(n+1)
	return _2nCn / (n + 1);
}

unsigned long int countBST(unsigned int n)
{
	unsigned long int count = catalan(n);
	// return nth catalan number
	return count;
}

unsigned long int countBT(unsigned int n)
{
	unsigned long int count = catalan(n);
	// return count * n!
	return count * fact[n];
}


int main()
{
	ll n , r , t;

	func();


	int count1, count2, nn = 5;

	// find count of BST and binary trees with n nodes
	count1 = countBST(nn);
	count2 = countBT(nn);

	// print count of BST and binary trees with n nodes
	cout << "Count of BST with " << nn << " nodes is " << count1 << endl;
	cout << "Count of binary trees with " << nn << " nodes is " << count2;
}





# Frog Jump

#include<iostream>
using namespace std;

int n, m;
int a[100][100];

int r[] = {0, -1, 0, 1};
int c[] = { -1, 0, 1, 0};

int dp[100][100];

bool valid(int x, int y) {
	return (x > 0 && x <= n && y > 0 && y <= m && a[x][y] == 1);
}

void solve(int sx, int sy, int dx, int dy, int ans) {

	if (dp[sx][sy] > ans) {
		dp[sx][sy] = ans;

		for (int i = 0; i < 4; i++) {

			int x = sx + r[i];
			int y = sy + c[i];

			if (valid(x, y)) {
				int temp;
				if (y == sy)temp = 1;
				if (x == sx)temp = 0;
				solve(x, y, dx, dy, ans + temp);
			}
		}
	}

}

int main() {

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = 1000000;
			cin >> a[i][j];
		}
	}

	int sx, sy, dx, dy;
	cin >> sx >> sy >> dx >> dy;

	solve(sx, sy, dx, dy, 0);

	cout << dp[dx][dy] << endl;

	return 0;
}





# JOb Scheduling


struct node
{
	int start , finish , profit;
};

bool cmp(node a, node b)
{
	return a.finish < b.finish;
}

int latestconflict(node arr[], int idx, int n)
{
	int low = 0 , high = idx - 1 , j = -1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid].finish <= arr[idx].start)
		{
			j = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	return j;
}

void solve(node arr[], int n)
{
	int table[n + 9];
	for (int i = 0; i < n + 9; i++)
		table[i] = 0;

	int ans = 0 ;
	table[0] = arr[0].profit;
	for (int i = 1; i < n; i++)
	{
		int l = latestconflict(arr, i, n);
		int res = 0 ;
		if (l != -1) res = table[l] + arr[i].profit;

		table[i] = max(table[i - 1] , res);
	}

	cout << table[n - 1] << endl;
}


int main()
{
	int n;
	cin >> n ;
	node arr[n + 9];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].start >> arr[i].finish >> arr[i].profit;
	}
	sort(arr , arr + n , cmp );

	solve(arr , n);

}




# Max pipe


int dp[1000][1000];
int arr[1000];

int solve(int pos , int curr)
{
	if (pos == n)
	{
		int tmp = abs( tot - curr - curr);
		if (tmp < ans)
		{
			ans = tmp;
			counT =  max(curr , tot - curr);
		}
		return 1;
	}

	if (dp[pos][curr] != -1)
		return dp[pos][curr];

	dp[pos][curr] = solve(pos + 1 , curr + arr[pos]) + solve(pos + 1 , curr);
	return dp[pos][curr];
}

int main()
{
	cin >> n ;
	for (int i = 0; i < n; i++)
		cin >> arr[i] , tot += arr[i];

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= tot; j++)
		{
			dp[i][j]  = -1;
		}
	}
	ans = 100000;
	solve(0, 0) ;
	cout << counT << endl;
}





# Max Grid Sum


int main()
{
    int grid[N][M] = { { 10, 10, 2, 0, 20, 4 },
        { 1, 0, 0, 30, 2, 5 },
        { 0, 10, 4, 0, 2, 0 },
        { 1, 0, 2, 20, 0, 4 }
    };

    int n = N , m = M;

    for (int i = 1; i < n; i++) {
        grid[0][i] += grid[0][i - 1];
    }

    for (int i = 1; i < m; i++) {
        grid[i][0] += grid[i - 1][0];

        for (int j = 1; j < n; j++) {
            grid[i][j] += max(grid[i][j - 1], grid[i - 1][j]);
        }
    }

    cout <<  grid[M - 1][N - 1];

}




# Rotate Image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reflect(matrix);
    }

    void transpose(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
    }

    void reflect(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                swap(matrix[i][j] , matrix[i][n - j - 1]);
            }
        }
    }
};





# DOctor Probability

/*
https://www.geeksforgeeks.org/samsung-interview-experience-set-39-campus-r-d-noida/
https://www.careercup.com/page?pid=samsung-interview-questions
A Doctor travels from a division to other division where divisions are connected like a graph(directed graph) and
the edge weights are the probabilities of the doctor going from that division to other connected division but the
doctor stays 10mins at each division now there will be given time and had to find the division in which he will be
staying by that time and is determined by finding division which has high probability.
Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division
in which he will be there, the edges starting point, end point, probability.
Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling
time is not considered and during that 10min at 10th min he will be in next division, so be careful
2
6 10 40
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
6 10 10
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
6 0.774000
3 0.700000
*/

#include<iostream>
using namespace std;

void docProb(double **graph, int nodes, int time, int curNode, double p, double *answer){
	if(time <= 0){
		answer[curNode] += p;
		return;
	}

	for(int i=1; i<=nodes; i++){
		if(graph[curNode][i] != 0){
			p *= graph[curNode][i];
			docProb(graph, nodes, time - 10, i, p, answer);
			p /= graph[curNode][i];
		}
	}

}

int main(){
	int t;
	cin >> t;
	while(t--){
		int nodes, edges, time;
		cin >> nodes >> edges >> time;

		double **arr = new double*[nodes];
		for(int i=1; i<=nodes; i++){
			arr[i] = new double[nodes];
			for(int j=1; j<=nodes; j++){
				arr[i][j] = 0;
			}
		}

		int from, to;
		double prob;
		for(int i=0; i<edges; i++){
			cin >> from >> to >> prob;
			arr[from][to] = prob;
		}

		/* Initalise answer and function call */
		double answer[nodes] = {0.0};
		docProb(arr, nodes, time, 1, 1.0, answer);

		/* Select max Probability node */
		double finalProb = 0.0;
		int finalDivison = 0;

		for(int i=1; i<=nodes; i++){
			if(answer[i] > finalProb){
				finalProb = answer[i];
				finalDivison = i;
			}
		}
		cout << finalDivison << " " << finalProb << "\n";
	}
	return 0;
}






/// Floyd Warshall
            for(int k=0;k<nodes;k++){
                for(int i=0;i<nodes;i++){
                    for(int j=0;j<nodes;j++){
                        if(i==k||j==k)
                            continue;
                        cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                    }
                }
            }




# Convex Hull

/*
Given random points in a 2-D plane, construct a convex polygon with minimum area of covering and
which encompasses all the given points.
*/
#include<bits/stdc++.h>
int cou = 0;

struct Point{
    int x, y;
};

int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

bool cmp(Point &a, Point &b){
    if(a.x==b.x&&a.y==b.y)
        cou++;

    if(a.x == b.x)
        return a.y < b.y;
    else
        return a.x < b.x;
}

bool myFunc(Point &a, Point &b){
    return (a.x==b.x && a.y==b.y);
}

void convexHull(Point *points, int n){
    cou = 0;
    if (n < 3){
        cout << "-1";
        return;
    }

    vector<Point> hull;

    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    int p = l, q;
    do{
        hull.push_back(points[p]);

        q = (p+1)%n;

        for (int i = 0; i < n; i++)
        {
           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }
        p = q;

    } while (p != l);

    sort(hull.begin(), hull.end(), cmp);

    auto ip = unique(hull.begin(), hull.end(), myFunc);

    hull.resize(std::distance(hull.begin(), ip));

    if(n < 4 && cou > 0 || hull.size() < 3){
        cout << "-1";
        return;
    }
    else{
        for (int i = 0; i < hull.size(); i++){
            if(i != hull.size() - 1)
                cout << hull[i].x << " " << hull[i].y << ", ";
            else
                cout << hull[i].x << " " << hull[i].y;
        }
    }
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        Point *points = new Point[n];

        for(int i=0; i<n; i++){
            cin >> points[i].x >> points[i].y;
        }

        convexHull(points, n);
        cout << "\n";
    }
    return 0;
}


### Two Problem Mixed


Given below are the raw materials quantities and their respective selling price(if sold as raw).

D --> No of CPUs
E --> No of memory chips
F --> No of boards
d --> Selling price of CPU
e --> Selling price of Memory chips

We are given N Computer configurations like below :
Di, Ei, Fi, SPi, which are the CPU, Chips, Boards and one unit selling price for ith computer respectively.
Our task is to maximize the final cost.
Constraints:
1. Can use at Max 3 different Configurations
2. We can use 1 configuration multiple times
3. Remaining Inventories can be sold on its selling price

Input:
T --> Number of test cases.
D E F d e --> Inventories
N --> Total Configuration Count
Di Ei Fi SPi
...
Dn En Fn SPn

1<=T<=10
1<= D, E, F <= 100
1<= d, e <=100000
1<=N<=8

Output:
First Line print the Case #testCaseNumber
Second Line Print Maximum Cost per test case in each line.

Sample Input:
1 --> Total Test Case
10 10 10 2 1 --> D E F d e
1 --> PC Configuration Count
1 2 2 3 --> D1 E1 F1 SP1

Sample Output:
Case #1
30


Solution:

#include<iostream>

using namespace std;

#define rep(i,a,n) for(int i =a; i < n; i++)
#define repe(i,a,n) for(int i =a; i <= n; i++)

int D,E,F,d,e;
int config;
int answer = 0;

struct configuration
{
    int D,E,F,SPi;
};
configuration m[9];

void solve(int index, int counta, int D, int E, int F, int cost )
{

    if(index >= config || counta == 3)
    {
        cost += D*d + E*e;
        if(cost > answer)
            answer = cost;
        return;
    }
    solve(index + 1, counta, D,E,F,cost);

    int i = 1;

    while(true)
    {
        if( D - m[index].D*i >= 0 && E - m[index].E*i >=0 && F - m[index].F*i >= 0 )
        {
            solve(index+1,counta+1,D- m[index].D *i,E - m[index].E *i,F- m[index].F*i, cost+ m[index].SPi * i);
            ++i;
        }
        else
        {
            break;
        }
    }
    return;

}

int main()
{
    int t;
    cin >> t;
    repe(_cases,1,t)
    {

        answer = 0;
        cin >> D >> E >> F >> d >> e;

        cin >> config;

        rep(i,0,config)
        {
            cin >> m[i].D >> m[i].E >> m[i].F >> m[i].SPi;
        }
        solve(0,0,D,E,F,0);
        cout << "Case #"<<_cases << "\n" << answer <<"\n";

    }

    return 0;
}
---------------------------------------------------------------------



You want to cut a piece of paper by a certain fixed rule to make some pieces of white or
blue colored square paper with various sizes.

If the size of the entire paper is N×N (N = 2^K; 1 <= K <= 7; K = natural number), the cutting rules
are as below.

‘If the entire piece of paper is not colored the same, cut the middle part horizontally and vertically
to divide it into the same sized four pieces of paper,
(N/2)×(N/2), as with I, II, III, IV in < FIG. 2 >.

For each I, II, III and IV, cut and divide again in the same way if one entire piece of paper
is not colored the same, and make them into the same sized four pieces of paper. Continue until each and
every piece of paper has only one color of white or blue.’

When you finish, < FIG. 3 > shows the first division of < FIG. 1 > and < FIG. 4 >
shows the final version of 9 pieces of white paper and 7 pieces of blue paper of various sizes.

If the length of an edge of the first given piece of paper, N, and
the color information (white or blue) inside each square are given, create a calculation program
 that assesses how many white/blue pieces of paper are.

Time limit: 1 second (java: 2 seconds)

[Input]

Input may include many test cases. The number of test cases, T, is given on the first line of input and then the amount of T of test cases is given in a line. (T <= 30)
The length of an edge of the first given piece of paper, N, is given for the first line of each test case.
From the next line through to the amount of N lines, the color information is given separately as blanks. 0 indicates white and 1 indicates blue.

[Output]

For each test case, you should print "Case #T" in the first line where T means the case number.

For each test case, you should output the number of white pieces of paper and blue pieces of paper separately as blanks on the first line of each test case.

[I/O Example]
Input
2
8
1 1 0 0 0 0 1 1
1 1 0 0 0 0 1 1
0 0 0 0 1 1 0 0
0 0 0 0 1 1 0 0
1 0 0 0 1 1 1 1
0 1 0 0 1 1 1 1
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1


16
1 0 0 1 0 0 0 0 0 0 1 1 0 1 1 1
1 1 0 1 0 1 1 0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 1 1 1 1 0 0 1 0 0 1
1 1 0 0 1 0 0 1 0 0 1 0 1 1 1 0
0 1 1 1 0 0 1 1 0 0 1 0 0 1 1 1
1 0 1 1 0 0 0 1 0 1 0 1 0 0 1 1
1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 0
1 1 0 1 0 1 0 0 1 0 1 1 1 0 0 1
1 1 1 1 1 1 0 0 1 0 1 1 0 1 1 0
1 0 0 1 1 1 0 0 0 0 1 1 1 1 0 0
1 0 0 1 1 1 1 0 0 0 1 1 0 1 0 1
1 1 1 0 1 1 0 0 1 1 1 1 1 1 0 1
1 1 1 1 1 1 0 0 0 0 1 1 1 1 0 0
1 1 1 1 1 1 0 1 1 1 1 1 1 1 0 0
1 1 0 0 0 0 0 0 1 1 0 1 1 0 0 0
1 1 0 0 1 1 0 0 0 1 1 1 1 0 0 0



Output

Case #1
9 7

Case #2
88 99
Solution :
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
const int maxn = 129;
int white = 0, blue = 0;
bool checkSame(bool arr[maxn][maxn], int sti, int stj, int size)
{
	bool color = arr[sti][stj];
	for(int i = sti; i < sti + size; i++){
		for(int j = stj; j < stj + size; j++){
			if(arr[i][j] != color){
				return false;
			}
		}
	}
	return true;
}
void solve(bool arr[maxn][maxn], int size, int sti, int stj)
{
	bool same = checkSame(arr, sti, stj, size);

	if(!same){
		solve(arr, size / 2, sti, stj);
		solve(arr, size / 2, sti + size/2, stj);
		solve(arr, size / 2, sti, stj + size/2);
		solve(arr, size / 2, sti + size/2, stj + size/2);
	}
	else{
		(arr[sti][stj]) ? ++blue : ++white ;
	}
}
int main()
{
	int test ;
	cin >> test ;
	for(int l = 1; l <= test; l++){
		white = 0;
		blue = 0;
		int size ;
		cin >> size;
		bool arr[maxn][maxn];
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				cin >> arr[i][j] ;
			}
		}
		solve(arr, size, 0, 0);
		cout << "Case #" << l << endl;
		cout << white << " " << blue << endl;
	}
	return 0;
}

















