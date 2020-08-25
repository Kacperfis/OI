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
																													   																				   										   
#define pb(x) push_back(x) 																							   
#define pf(x) push_front(x)																							   
#define mp(x, y) make_pair(x, y)
 
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
 
LL n, m;
LL leaf = (1 << 18);
pair<LL, LL> tree[1000005];
//{min, counter}
 
///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////

pair<LL, LL> combine(pair<LL,LL> a, pair<LL,LL> b){
	if(a.first < b.first) return a;
	if(b.first < a.first) return b;
	return mp(a.first, a.second + b.second);
}

void add(int pos, int v){
	pos += leaf;
	tree[pos] = mp(v, 1);
	pos /= 2;
	while(pos){
		tree[pos] = combine(tree[pos*2], tree[pos*2+1]);
		pos /= 2;
	}
}

void check(int pos){
	pos += leaf;
	while(pos){
		cout << "tree: " << tree[pos].first << " " << tree[pos].second << endl;
		pos /= 2;
	}
}

pair<LL,LL> query(int l, int r){
	l += leaf;
	r += leaf;
	
	pair<LL,LL> ans = mp(INFL, 0);
	ans = combine(ans, tree[l]);
	if(l != r) ans = combine(ans, tree[r]);
	
	while(l / 2 != r / 2){
		if(l % 2 == 0) ans = combine(ans, tree[l+1]);
		if(r % 2 == 1) ans = combine(ans, tree[r-1]);
		l /= 2;
		r /= 2;
	}
	return ans;
}

/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])																					 
{//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                  												       
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    for(int i = 0; i < 1000003; i++){tree[i].first = INFL; tree[i].second = 0;}
	cin >> n >> m;
	for(LL i = 0; i < n; i++){
		LL x; cin >> x;
		add(i, x);
	}
	while(m--){
		LL x;
		cin >> x;
		if(x == 1){ //add
			LL pos, v;
			cin >> pos >> v;
			add(pos, v);
		}
		else if(x == 2){ //query
			LL l, r;
			cin >> l >> r;
			pair<LL, LL> res = query(l, r-1);
			cout << res.first << " " << res.second << endl;
		}
	}
	
	return 0;
}
