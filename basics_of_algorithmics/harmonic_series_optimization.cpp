/*																													   
 Templatka c++ Kacper Fis																							   																											   //
*/																													  
																								   
#include <bits/stdc++.h>																							   
																													   
using namespace std; 																								   
		
const double eps = 1e-9;																							   
const int INF = 1000000001;																						   
const double PI = 3.14;																								   
typedef long long LL;																								   
																													   
typedef vector<int> vi;																								   
typedef list<int> li;																								   
typedef queue<int> qi; 																								   
typedef pair<int,int> ii; 																							   
typedef map<string,int> msi; //np msi['nazwa'] = 'liczba'															   
typedef vector<ii> vii; //vector par<int>, do tworzenia tablicy dla grafów wagowych #dijkstra #Bellman_Ford			   
typedef priority_queue< ii, vector<ii>, greater<ii> > pq; //kolejka priorytetowa vectorów par(top()=min) #dijkstra	   
																													   																				   
vector<ii>::iterator iter;																							   
																													   																				   
#define print_list(x) for(it = (x).begin(); it != (x).end(); it++) {cout << *it << " ";}							   
#define print_vector(x) for(it2 = (x).begin(); it2 != (x).end(); it2++) {cout << *it2 << " ";}						   
#define search_list(x) for(it = (x).begin(); it != (x).end(); it++)													   
#define search_vector(x) for(it2 = (x).begin(); it2 != (x).end(); it2++);											   
#define pb(x) push_back(x) 																							   
#define pf(x) push_front(x)																							   
#define mp(x, y) make_pair(x, y)                                                                                       
///////////////////////////////////////////////GLOBAL DEFINITIONS////////////////////////////////////////////////////////



///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])																					 
{ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                  												       
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    /*  "Optymalizacja szeregiem harmonicznym"
     * 
     * 	zastanów się jaką złożoność ma poniższy kod:
     * 
	 * 	for(int i = 1; i <= n; i++){
	 * 		for(int j = 1; i j <= n; j += i){
     * 			//rób coś...
     * 		}
     * 	}
     * 	
     * 	Na pierwszy rzut oka może to wyglądać na O(n^2), lecz złożoność
     *  jest jednak znacznie lepsza, bo rzędu O(n logn)
     * 
     * 	Gdzie to ma zastosowanie?, oto przykładowe zadanie:
     * 	Dla danych liczb n i k znajdź ile liczb naturalnych ze zbioru [1, n]
     * 	ma co najmniej k dzielników.
     * 	
     * 	Dla danych n = 10, k = 4, mamy odpowiedź 3, ponieważ tylko liczby
     * 	6, 8, 10 mają przynajmniej k dzielników.
     * 
     * 	Poniżej kod rozwiązania
     * */
     
     int n, k;
     int ans = 0;
     int divisors[100005];
     fill(divisors, divisors + 100003, 0);
     
     cin >> n >> k;
     
     for(int i = 1; i <= n; i++){ //iterujemy się po dzielnikach
		 for(int j = i; j <= n; j += i){ // przechodzimy po wielokrotnosciach
			 divisors[j]++;
		 }
	 }
		
	 for(int i = 1; i <= n; i++){
		 if(divisors[i] >= k){
			 ans++; //obliczamy ile liczb ma co najmniej k dzielników
		 }
	 }
	 
	 cout << ans << '\n';
	 
	 
	 /* Przykładowe zadanie z Olimpiady informatycznej: OI19 Zad Bony 
	  * */
	
	 return 0;
}
