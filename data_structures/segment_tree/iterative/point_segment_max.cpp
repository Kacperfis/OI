/*																													   
 Templatka c++ Kacper Fis																							   																											   //
*/																													  
																								   
#include <bits/stdc++.h>																							   
																													   
using namespace std; 																								   
																													   
const int INF = 1000000001;																						   
const float PI = 3.14;																								   
typedef long long LL;																								   
																													   
typedef vector<int> vi;																								   
typedef list<int> li;																								   
typedef queue<int> qi; 																								   
typedef pair<int,int> ii; 																							   
typedef map<string,int> msi; //np msi['nazwa'] = 'liczba'															   
typedef vector<ii> vii; //vector par<int>, do tworzenia tablicy dla grafów wagowych #dijkstra #Bellman_Ford			   
typedef priority_queue< ii, vector<ii>, greater<ii> > pq; //kolejka priorytetowa vectorów par(top()=min) #dijkstra	   
																													   																				   																												   
list<int>::iterator it;																								   
list<int>::iterator it1;																							   
vector<int>::iterator it2;																							   
vector<int>::iterator it3;																							   
set<int>::iterator it4;																								   
map<string, int>::iterator it5; 																					   
vector<ii>::iterator iter;																						   
																													   																				   
#define print_list(x) for(it = (x).begin(); it != (x).end(); it++) {cout << *it << " ";}							   
#define print_vector(x) for(it2 = (x).begin(); it2 != (x).end(); it2++) {cout << *it2 << " ";}						   
#define search_list(x) for(it = (x).begin(); it != (x).end(); it++)													   
#define search_vector(x) for(it2 = (x).begin(); it2 != (x).end(); it2++);											   
#define pb(x) push_back(x) 																							   
#define pf(x) push_front(x)																							   
#define mp(x, y) make_pair(x, y)                                                                                       
///////////////////////////////////////////////GLOBAL DEFINITIONS////////////////////////////////////////////////////////

const int m = 1 << 20;
const int leaf = 1 << 20;

int tree[2000005];

///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////

void add(int a, int x){
	a += leaf;
	while(a){
		tree[a] += max(tree[a], x);
		a /= 2;
	}
}

int query(int l, int r){
	l += leaf;
	r += leaf;
	int ans = max(tree[l], tree[r]);
	while(l / 2 != r / 2){
		if(l % 2 == 0) ans = max(ans, tree[l + 1]);
		if(r % 2 == 1) ans = max(ans, tree[r - 1]);
		l /= 2;
		r /= 2;
	}
	return ans;
}

/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])																					 
{ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                  												       
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	int q;
	cin >> q;\
	fill(tree, tree+2000003, -INF);
	for(int i = 1; i <= q; i++){
		int x, a, b, v; //x == 1 -->dodawanie elementu b na pozycję a; x == 2 --> max na przedziale [a, b]
		cin >> x;
		if(x == 1){
			cin >> a >> v;
			add(a, v);
		}
		else if(x == 2){
			cin >> a >> b;
			cout << query(a, b) << endl;
		}
	}
	
	return 0;
}
