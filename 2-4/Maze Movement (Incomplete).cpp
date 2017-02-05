#include <bits/stdc++.h>
using namespace std;

const int  INF = std::numeric_limits<int>::max()/3;

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
class Edge{
public:
	int u,v,cap,f;

	Edge(int _u, int _v, int _cap) : u(_u),v(_v),cap(_cap){
		f = 0;
	}
	int other(int vertex){
		if(vertex == u)return v;
		else if(vertex == v)return u;
		return -1;
	}

	int residualTo(int vertex){
		if(vertex == u)return f;
		return cap - f;
	}

	void addFlowTo(int vertex, int ff){
		if(vertex == u){
			f -= ff;
		}else if(vertex == v){
			f += ff;
		}
	}
};


typedef vector<Edge*> edgeList;

map<int, int> M;

#define MAX_V 1000
#define MAX_E 1000
int SRC;
int SINK;
int Flow;
edgeList parent;
vi visited;
vector<edgeList> adj;

void addEdge(int u, int v, int cap){
	Edge* e = new Edge(u,v,cap);
	adj[u].push_back(e);
	adj[v].push_back(e);
}

bool augmentingPath(){
	queue<int> q;
	parent.assign(MAX_V, NULL);
	visited.assign(MAX_V, 0);

	q.push(SRC);
	visited[SRC] = 1;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == SINK)
			break;
		for (int i = 0; i < (int)adj[u].size(); ++i) {
			Edge* e = adj[u][i];
			int v = e->other(u);
			if(!visited[v] && e->residualTo(v) > 0){
				visited[v] = 1;
				parent[v] = e;
				q.push(v);
			}
		}
	}
	return visited[SINK];
}

// Ford Fulkerson
int maxFlow(){
	int mf = 0;
	while(augmentingPath()){
		Flow = 1e9;

		for(int v = SINK; v != SRC ; v = parent[v]->other(v)){
			Flow = min(Flow, parent[v]->residualTo(v));
		}

		for(int v = SINK; v != SRC ; v = parent[v]->other(v)){
			parent[v]->addFlowTo(v,Flow);
		}
		mf += Flow;
	}
	return mf;
}

int main() {
	FASTER;
    int V, SRC = INF, SINK = -1, n;
    cin >> V;
    adj.assign(V, edgeList());

    forn(i, V)
    {
        cin >> n; M[i] = n;
        //cout << i << ": " << M[i] << endl;
        if (n < SRC) SRC = i;
        if (n > SINK) SINK = i;
    }
    //cout << "S: " << s << " T: " << t << endl;
    forn(j, V)
    {
        forn(k, V)
        {
            int cd = gcd(M[j], M[k]);

            if(cd > 1 && j != k)
            {
                //cout << "gcd of " << M[j] << ", " << M[k] << ": " << cd << endl;
                addEdge(j,k,cd);
            }
        }
    }
    /*forn(z, V)
    {
        cout << z << ": ";
        forn(x, G[z].size())
            cout << G[z][x].first << ", " << G[z][x].second << endl;
    }*/
    cout << maxFlow();

	return 0;
}
