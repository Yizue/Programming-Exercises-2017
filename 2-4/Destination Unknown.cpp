#include <bits/stdc++.h>
using namespace std;

const int INF = 1.0e9;

#define MEM(arr,val)memset(arr,val, sizeof arr)
#define PI acos(0)*2.0
#define eps 1.0e-9
#define are_equal(a,b)fabs(a-b)<eps
#define LS(b)(b& (-b)) // Least significant bit
#define DEG_to_RAD(a)((a*PI)/180.0) // convert to radians

#define forn(i,n) for(int (i) = 0; (i) < (n); (i)++)
#define fornm(i,n,m) for(int (i) = (n); (i) < (m); (i)++)
#define formn(i,m,n) for(int (i) = (m); (i) > (n); (i)--)
#define DEBUG if(debugging)

#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<int,char> ic;
typedef pair<long,char> lc;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<dd> vdd;


int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}
int cmp(const void *a, const void *b) {return *(int*)a - *(int*)b;}

const int debugging = 1;

/*
	__builtin_popcount(int d) // count bits
	__builtin_popcountll(long long d)
	strtol(s, &end, base); // convert base number
*/
//----------------------------------------------------------------------//

vector<vii> G;
set<int> D;
vi dist;
vector<vi> P;
int V,E,t,s,g,h;

void dijk() { // Dijkstra's Algorithm
    dist.assign(V, INF); dist[s] = 0;
    P.assign(V, vi());
    priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
    while (!pq.empty()) {
        ii fr = pq.top(); pq.pop();
        int d = fr.first, u = fr.second;
        if (d > dist[u]) continue;
        forn (j, (int)G[u].size()) {
            ii v = G[u][j];
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                P[v.first].clear();
                P[v.first].push_back(u);
                pq.push(ii(dist[v.first], v.first));
            }
            else if (dist[u] + v.second == dist[v.first])
                P[v.first].push_back(u);
} } }

vi vis;
bool found;

void dfs(int u) {
    vis[u] = 1;
    forn(j, (int)P[u].size()) {
        int v = P[u][j];
        if (u == g && v == h) found = true;
        if (u == h && v == g) found = true;
        if (vis[v] == 0)
            dfs(v);
} }

int main() {
	FASTER;
	int N; cin >> N;
	forn(a, N)
	{
        cin >> V >> E >> t >> s >> g >> h;
        s--; g--; h--;
        G.assign(V, vii());
        forn(i, E)
        {
            int a,b,d;
            cin >> a >> b >> d;
            G[a-1].push_back(ii(b-1, d));
            G[b-1].push_back(ii(a-1, d));
        }
        dijk();

        /*forn(i, P.size())
        {
            cout << i << ": ";
            forn(j, P[i].size())
                cout << P[i][j] << " ";
            cout << endl;
        }*/
        forn(j, t)
        {
            int in; cin >> in;
            found = false;
            vis.assign(V, 0);
            dfs(in-1);
            if(found) D.insert(in);
        }
        set<int>::iterator it;
        for(it = D.begin(); it!=D.end(); ++it)
        {
           cout << *it << " ";
        }
        cout << endl;
        D.clear();

	}

	return 0;
}
