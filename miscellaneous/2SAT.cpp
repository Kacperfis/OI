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
vector<vi> tab;
vector<vi> tab2;
vi order; //postorder
vi comp; //graf silnie spójnych - components
vector<bool> assignment; //assignment 2SAT values;
vector<bool> visited;


///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////

void vectors_initialize(){
	order.resize(n);
	comp.resize(n);
	assignment.resize(n);
	visited.resize(n);
}

void dfs1(int v){
	visited[v] = true;
	for(auto it : tab[v]) if(!visited[it]){
		dfs1(it);
	}
	order.pb(v);
}

void dfs2(int v, int licznik){
	comp[v] = licznik;
	for(auto it : tab[v]) if(comp[it] == -1){
		dfs2(it, licznik);
	}
}

bool solve_2SAT(){
	visited.assign(n, false);
	for(int i = 0; i < n; i++){
		if(!visited[i]) dfs1(i);
	}
	comp.assign(n, -1);
	int j = 0;
	for(int i = n-1; i >= 0; i--){
		if(comp[order[i]] == -1) dfs2(order[i], j++);
	} 
	assignment.assign(n / 2, false);
	for(int i = 0; i < n; i+= 2){
		if(comp[i] == comp[i+1]) return false;
		assignment[i / 2] = comp[i] > comp[i+1];
	}
	return true;
}

/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main()
{ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //READ INPUT AND CREATE IMPLICATION GRAPH
    
    //vectors_initialize();
    //solve_2SAT();
    
    
    
    
    
	
    return 0;
}
