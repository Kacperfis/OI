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
                                                              
struct segtree{
	int size = 1;
	vector<LL>tree;
	
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		tree.assign(2*size, 0);
	}
	
	void set(int i, int v){
		return set(i, v, 0, 0, size);
	}
	
	void set(int i, int v, int x, int lx, int rx){
		if(rx - lx == 1){
			tree[x] = v;
			return;
		}
		int mid = (lx + rx) / 2;
		if(i < mid){
			set(i, v, x*2+1, lx, mid);
		}
		else{
			set(i, v, x*2+2, mid, rx);
		}
		tree[x] = min(tree[x*2+1], tree[x*2+2]);
	}
	
	LL query(int l, int r, int x, int lx, int rx){
		if(lx >= r || rx <= l) return INF;
		else if(lx >= l && rx <= r) return tree[x];
		int mid = (lx + rx) / 2;
		return min(query(l, r, x*2+1, lx, mid), query(l, r, x*2+2, mid, rx));
	}
	
	LL query(int l, int r){
		return query(l, r, 0, 0, size);
	}
	
};

/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])																					 
{ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                  												       
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	int n, m;
	cin >> n >> m;
	segtree st;
	st.init(n);
    for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		st.set(i, x);
	}
	while(m--){
		int op;
		cin >> op;
		if(op == 1){
			int i, v;
			cin >> i >> v;
			st.set(i, v);
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << st.query(l, r) << endl;
		}
	}
	
	
	
	return 0;
}
