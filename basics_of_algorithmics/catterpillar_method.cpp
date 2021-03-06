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
																													   																				   
vector<ii>::iterator iter;																							   
																							   																				   
#define print_list(x) for(it = (x).begin(); it != (x).end(); it++) {cout << *it << " ";}							   
#define print_vector(x) for(it2 = (x).begin(); it2 != (x).end(); it2++) {cout << *it2 << " ";}						   
#define search_list(x) for(it = (x).begin(); it != (x).end(); it++)													   
#define search_vector(x) for(it2 = (x).begin(); it2 != (x).end(); it2++);											   
#define pb(x) push_back(x) 																							   
#define pf(x) push_front(x)																							   
#define mp(x, y) make_pair(x, y)                                                                                       
///////////////////////////////////////GLOBAL DEFINITIONS////////////////////////////////////////////////////////
	
	
///////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////


/////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])																					 
{ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                  												       
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int A[10005] = {1, 2, 3, 7, 6, 5}; // tablica A
	int n = 6; // rozmiar tablicy
	int K = 4; // suma K
	int licznik = 0; // tu będziemy zliczać fragmenty o sumie K
    int suma = A[0];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while ((j < n - 1) && (suma < K))    
        {
            j++;   // zwiększaj j, doliczając A[j] do sumy
            suma += A[j]; // dopóki nie przekroczysz K, albo j nie osiągnie maksymalnej wartości n-1
        }
        if (suma == K) //jesli osiagnelo k to zwiekszamy licznik
            licznik++;
        suma -= A[i];  // za chwilę przejdziemy od i do i+1, trzeba odliczyć A[i] od sumy
    }
	
	return 0;
}
