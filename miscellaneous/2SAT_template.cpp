#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;
const int INF = 1e9;
const long long INFL = 1e18;
const double PI = 3.14;
const int mod = 1e9 + 7;
typedef long long LL;

typedef vector<int> vi;
typedef list<int> li;
typedef queue<int> qi;
typedef pair<int,int> ii;
typedef pair<LL, LL> ll;
typedef map<string,int> msi;
typedef set<int> sett;
typedef vector<ii> vii;
typedef priority_queue< ii, vector<ii>, greater<ii> > pq;
vector<ii>::iterator iter;

#define pb push_back
#define pf push_front
#define mp(x, y) make_pair(x, y)
#define size(x) (int)x.size()
#define endl '\n'

int _X[] = {0, 1, 1, 1, 0, -1, -1, -1};
int _Y[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int _X2[] = {1, 0, -1, 0};
int _Y2[] = {0, 1, 0, -1};

//FILE I/O
void FILE_OI(){
    fstream plik;
    plik.open("plik.txt"); //create plik.txt!
    plik << "_put here your input_";
    plik.close();
}

//DEBUG
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

///////////////////////////////////////////////GLOBAL DEFINITIONS////////////////////////////////////////////////////////

int n, m;

///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////

///////
Author: Olaf Surgut © 
//////

struct SAT {
    int n;
    vector<vector<int>> adj;
    vector<int> ans;

    SAT(int _n) : n(_n), adj(2 * n) { }

    void either(int a, int b) { 
        a = max(2 * a, -1 - 2 * a);
        b = max(2 * b, -1 - 2 * b);
        assert(0 <= a && a < 2 * n && 0 <= b && b < 2 * n);
        adj[a].push_back(b ^ 1);
        adj[b].push_back(a ^ 1);
    }
    
    void add_edge1(int a, int b){
		either(a, b);
	}
	void add_edge2(int a, int b){
		either(~a, ~b);
	}
	
    void set_value(int x) { either(x, x); }

    vector<int> val, comp, z; int time = 0;
    int dfs(int u) {
        int low = val[u] = ++time, x; z.push_back(u);
        for(int v : adj[u]) if(!comp[v])
            low = min(low, val[v] ?: dfs(v));
        if(low == val[u]) do {
            x = z.back(); z.pop_back();
            comp[x] = low;
            if(ans[x >> 1] == -1) ans[x >> 1] = x & 1;
        } while(x != u);
        return val[u] = low;
    }

    bool solve(){
        ans.assign(n, -1);
        val.assign(2 * n, 0); comp = val;
        for(int i = 0; i < 2 * n; i++) if(!comp[i]) dfs(i);
        for(int i = 0; i < n; i++)  if(comp[2 * i] == comp[2 * i + 1])  return false;
        return true;
    }
    
    void print_ans(){
		for(int i = 0; i < size(ans); i++){
			if(ans[i]) cout << i + 1 << endl;
		}
	}
};

/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main()
{ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	cin >> n >> m;
	SAT sat(2 * n);
	for(int i = 0; i < n; i++){
		sat.add_edge1(2*i, 2*i+1);
	}
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		sat.add_edge2(a, b);
	}
	
	if(!sat.solve()) cout << "NIE" << endl;
	else{
		sat.print_ans();
	}
	
	
    
    
    
    
	
    return 0;
}
