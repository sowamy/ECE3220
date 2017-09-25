// L10_Ex3_const.cpp
#include <iostream>
#define EXAMPLE 1	// 1, 2, 3, 4, 5
using namespace std;

int main(){
	const int i = 10;	// const int
	const int &ri = i;	// reference to const int
	const int *k = &i;	// pointer to const int

	cout << "1) i: " << i << " ri: " << ri << " *k: " << *k << " k: " << k << endl;

#if EXAMPLE >= 2
	int j = ri;
	cout << "2) i: " << i << " ri: " << ri << " j: " << j << " *k: " <<  *k << " k: " << k << endl;

	j = 50;
	cout << "3) i: " << i << " ri: " << ri << " j: " << j << " *k: " <<  *k << " k: " << k << endl;
#endif

#if EXAMPLE == 3
	i = 15;
	ri = 10;
	cout << "4) i: " << i << " ri: " << ri << " j: " << j << " *k: " <<  *k << " k: " << k << endl;

	const int &rj = j;	// reference to const
	cout <<  "5) rj: " << rj << " j: " << j <<  endl;

	j = 20;
	cout <<  "6) rj: " << rj << " j: " << j <<  endl;

	rj = 30;
	cout <<  "7) rj: " << rj << " j: " << j <<  endl;
#endif

#if EXAMPLE >= 4
	int *const pj = &j;	// const pointer
	cout <<  "8) pj: " << pj << " j: " << *pj <<  endl;
	*pj = 100;
	cout <<  "9) pj: " << pj << " j: " << *pj <<  endl;
	
#if EXAMPLE == 5	
	pj++;
	cout <<  "10) pj: " << pj << " j: " << *pj <<  endl;
#endif
	
	const int *qj = &j;	// pointer to const
	cout <<  "11) qj: " << qj << " j: " << *qj <<  endl;
	
#if EXAMPLE == 5
	*qj = 40;
	cout <<  "12) qj: " << qj << " j: " << *qj <<  endl;
	qj++;
	cout <<  "13) qj: " << qj << " j: " << *qj <<  endl;
#endif
#endif

	return 0;	
}