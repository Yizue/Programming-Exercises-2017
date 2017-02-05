#include <bits/stdc++.h>
using namespace std;

#define MEM(arr,val)memset((arr),(val), sizeof (arr))
#define PI (acos(0)*2.0)
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll gcd(ll a,ll b){return b == 0 ? a : gcd(b,a%b);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}

/**
 * __builtin_popcount(int d) // count bits
 * strtol(s, &end, base); // convert base number
 */
//----------------------------------------------------------------------//


class Vertex
{
    public:
        class Edge
        {
        public:
            Vertex* adj;
            double perc;
            bool isSup;

            Edge(Vertex* v, double p, bool isS)
            {
                adj = v;
                perc = p;
                isSup = isS;
            }
        };

        vector<Edge*> child;
        int id;
        int chSize;
        bool visited;
        double liq;

        Vertex(int n)
        {
            id=n;
            chSize=0;
            liq = -1.0;
            visited = false;
        }

        void addEdge(Vertex* v, double p, bool isS)
        {
            Edge* e = new Edge(v, p, isS);
            child.push_back(e);
            chSize++;
        }
        void setLiq(int num)
        {
            liq = num;
        }
        void print()
        {
            cout << "childSize: " << child.size() << " setLiq: " << liq << endl;
        }
};

double postOrder(Vertex* v, double per, bool isS)
{
     double maxLiq=0.0;
     if (v->chSize == 0)
     {
         double liqNeeded;
         if(isS)
         {
             liqNeeded = sqrt(v->liq)/per;
         }
         else
         {
             liqNeeded = (v->liq)/per;
         }
         v->liq = liqNeeded;
         //cout << v->id << ": " << endl;
         //cout << v->liq << endl;
         return v->liq;
     }
     else
     {
         for(int i=0;i<v->chSize;i++)
         {
             double liqNeeded = postOrder(v->child.at(i)->adj, v->child.at(i)->perc, v->child.at(i)->isSup);
             //cout << "liqN: " << liqNeeded << endl;
             if(liqNeeded >= maxLiq)
                maxLiq = liqNeeded;
         }
     }
     // now deal with the node
     //cout << v->id << "*" << endl;
     if(isS && v->id!=0)
     {
        maxLiq = sqrt(maclass Vertex
{
    public:
        class Edge
        {
        public:
            Vertex* adj;
            double perc;
            bool isSup;

            Edge(Vertex* v, double p, bool isS)
            {
                adj = v;
                perc = p;
                isSup = isS;
            }
        };

        vector<Edge*> child;
        int id;
        int chSize;
        bool visited;
        double liq;

        Vertex(int n)
        {
            id=n;
            chSize=0;
            liq = -1.0;
            visited = false;
        }

        void addEdge(Vertex* v, double p, bool isS)
        {
            Edge* e = new Edge(v, p, isS);
            child.push_back(e);
            chSize++;
        }
        void setLiq(int num)
        {
            liq = num;
        }
        void print()
        {
            cout << "childSize: " << child.size() << " setLiq: " << liq << endl;
        }
};

double postOrder(Vertex* v, double per, bool isS)
{
     double maxLiq=0.0;
     if (v->chSize == 0)
     {
         double liqNeeded;
         if(isS)
         {
             liqNeeded = sqrt(v->liq)/per;
         }
         else
         {
             liqNeeded = (v->liq)/per;
         }
         v->liq = liqNeeded;
         //cout << v->id << ": " << endl;
         //cout << v->liq << endl;
         return v->liq;
     }
     else
     {
         for(int i=0;i<v->chSize;i++)
         {
             double liqNeeded = postOrder(v->child.at(i)->adj, v->child.at(i)->perc, v->child.at(i)->isSup);
             //cout << "liqN: " << liqNeeded << endl;
             if(liqNeeded >= maxLiq)
                maxLiq = liqNeeded;
         }xLiq)/per;
     }
     else if(!isS && v->id!=0)
     {
        maxLiq = (maxLiq)/per;
     }

     //printf("MaxLiq: %f\n", maxLiq);
     v->liq = maxLiq;
     return v->liq;
}

int main(){
	FASTER;
    int n;
    scanf("%d", &n);
    vector<Vertex*> G;
    for(int j=0; j<n; j++)
    {
        Vertex* v = new Vertex(j);
        G.push_back(v);
    }
    int a, b, x, t;

    for(int i=0; i<n-1; i++)
    {
        scanf(" %d %d %d %d", &a, &b, &x, &t);
        bool isS;
        if(t==1)isS=true;
        else isS =false;
        G.at(a-1)->addEdge(G.at(b-1), x/100.0, isS);
    }

    for(int k=0; k<n; k++)
    {
        int liq;
        scanf(" %d", &liq);
        G.at(k)->setLiq(liq*1.0);
    }
    /*
    for(int l=0; l<n; l++)
    {
        cout << l << ": ";
        G.at(l)->print();
    }
    cout << endl;*/
    postOrder(G.at(0), 0.0, false);
    printf("%f", G.at(0)->liq);

	return 0;
}
