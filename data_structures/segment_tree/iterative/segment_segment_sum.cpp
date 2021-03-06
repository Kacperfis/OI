/*																													   
 Templatka c++ Kacper Fis																							   																											   //
*/																													  
																								   
#include <bits/stdc++.h>																							   
																													   
using namespace std; 																								   
																													   
const int INF = 1000000001;																						   
const float PI = 3.14;																								   
typedef long long LL;																								   
																													   
typedef vector<LL> vi;																								   
typedef list<LL> li;																								   
typedef queue<LL> qi; 																								   
typedef pair<LL,LL> ii; 																							   
typedef map<string,LL> msi; //np msi['nazwa'] = 'liczba'															   
typedef vector<ii> vii; //vector par<LL>, do tworzenia tablicy dla grafów wagowych #dijkstra #Bellman_Ford			   
typedef priority_queue< ii, vector<ii>, greater<ii> > pq; //kolejka priorytetowa vectorów par(top()=min) #dijkstra	   
																													   																				   
vector<ii>::iterator iter;																							   
																													   																				   
#define prLL_list(x) for(it = (x).begin(); it != (x).end(); it++) {cout << *it << " ";}							   
#define prLL_vector(x) for(it2 = (x).begin(); it2 != (x).end(); it2++) {cout << *it2 << " ";}						   
#define search_list(x) for(it = (x).begin(); it != (x).end(); it++)													   
#define search_vector(x) for(it2 = (x).begin(); it2 != (x).end(); it2++);											   
#define pb(x) push_back(x) 																							   
#define pf(x) push_front(x)																							   
#define mp(x, y) make_pair(x, y)                                                                                       
///////////////////////////////////////////////GLOBAL DEFINITIONS////////////////////////////////////////////////////////

LL p = 19;
LL leaf = (1 << 19);
LL tree[1000005];
LL lazy[1000005];

///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////

void apply(LL a, LL v, LL sajz){
	tree[a] += v * sajz;
	lazy[a] += v;
}

void build(LL a){
	LL sajz = 1;
	while(a){
		a /= 2;
		sajz *= 2;
		tree[a] = tree[a * 2] + tree[a * 2 + 1] + lazy[a] * sajz;
	}
}

void push(LL a){
	for(LL j = p; j > 0; j--){
		LL i = (a >> j);
		if(lazy[i]){
			LL sajz = (1 << (j - 1));
			apply(i * 2, lazy[i], sajz);
			apply(i * 2 + 1, lazy[i], sajz);
			lazy[i] = 0;
		}
	}
}

void insert(LL l, LL r, LL v){
	l += leaf;
	r += leaf;
	LL L = l;
	LL R = r;
	
	push(l);
	push(r);
	
	LL sajz = 1;
	apply(l, v, sajz);
	if(l != r) apply(r, v, sajz);
	while(l / 2 != r / 2){
		if(l % 2 == 0) apply(l + 1, v, sajz);
		if(r % 2 == 1) apply(r - 1, v, sajz);
		l /= 2;
		r /= 2;
		sajz *= 2;
	}
	build(L);
	build(R);
}

LL query(LL l, LL r){
	l += leaf;
	r += leaf;
	
	push(l);
	push(r);
	
	LL ans = tree[l];
	if(l != r) ans += tree[r];
	while(l / 2 != r / 2){
		if(l % 2 == 0) ans += tree[l + 1];
		if(r % 2 == 1) ans += tree[r - 1];
		l /= 2;
		r /= 2;
	}
	return ans;
}

/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main()																					 
{ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                  												       
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	LL q; cin >> q; //number of operations
	while(q--){
		LL x;
		cin >> x;
		if(x == 1){ //add v on interval [a; b]
			LL a, b, v;
			cin >> a >> b >> v;
			insert(a, b, v);
		}
		else if(x == 2){ //query sum on interval [a; b]
			LL a, b; cin >> a >> b;
			cout << query(a, b) << '\n';
		}
	}
	
	return 0;
}
