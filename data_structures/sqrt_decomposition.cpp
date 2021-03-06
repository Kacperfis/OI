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

const int sq = 3; //z góry zakładamy wartość pierwiastka
int sq_sum[1005]; //tu trzymamy sumy fragmentów
int tab[1000005]; //tablica na nasz ciąg

///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////

void dodaj(int a, int b){
	tab[a] += b;
	sq_sum[a / sq] += b;
}

int sumuj(int l, int r){
	int ans = 0;
	
	//dodajemy fragmenty
	for(int i = l / sq + 1; i < r /sq; i++){
		ans += sq_sum[i];
	}
	
	//dodajemy lewy fragment częściowy
	for(int i = l; i < min(r + 1, (l / sq + 1) * sq); i++){
		ans += tab[i];
	}
	
	//jesli l i r są w różnych fragmentach, dodajemy prawy fragment częściowy
	if(l / sq != r / sq){
		for(int i = r; i >= r / sq * sq; i--){
			ans += tab[i];
		}
	}
	
	return ans;
}

/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])																					 
{ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                  												       
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	int n, q;//n - dlugosc danego ciągu, q - liczba zapytań
	cin >> n >> q;
	for(int i = 1; i <= q; i++){
		int x, a, b; //x=1 --> dodawanie elementu b do elementu na pozycji a; x=2 --> sumowanie elementów od pozycji a do b
		cin >> x >> a >> b;
		if(x == 1){
			dodaj(a, b);
		}
		else if(x == 2){
			cout << sumuj(a, b) << endl;
		}
	}
	
	return 0;
}
