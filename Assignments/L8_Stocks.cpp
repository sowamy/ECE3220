// L8_Stocks.cpp

#include <iostream>
#include <cstring>

class Stock{
	private:
		char company[30];
		int shares;
		double share_val;
		double total_val;
		void set_tot(){total_val = shares * share_val; }
		
	public:
		void acquire(const char * co, int n, double pr);
		void buy(int num, double price);
		void sell(int num, double price);
		void update(double price);

		
		
		char* getName( void );
		int getNumberOfShares( void );
		double getShareValue( void );
		double getTotalValue( void );
};

void Stock::acquire(const char * co, int n, double pr){
	std::strncpy(company, co, 29);
	company[29] = '\0';
	
	if(n < 0){
		//std::cerr << "Number of shares can't be negative; "
		//		  << company << " shares set to 0.\n";
		shares = 0;
	}
	else{
		shares = n;
		// std::cout << "Updated shares." << std::endl;
	}
	
	share_val = pr;
	set_tot();
}

// Get Methods
char* Stock::getName( void ) { return company; }
int Stock::getNumberOfShares( void ) { return shares; }
double Stock::getShareValue( void ) { return share_val; }
double Stock::getTotalValue( void ) { return total_val; }

int main(){
	using std::cout;
	using std::endl;
	using std::cin;
	
	char comp[ 30 ];
	int numberOfShares = 0;
	double shareValue = 0;

	short doneFlag = 0;

	Stock stock1, stock2;
	
	cout << "Name of Stock: ";
	cin >> &comp[ 0 ];
	cout << "Number of Shares: ";
	cin >> numberOfShares;
	cout << "Value of Shares: ";
	cin >> shareValue;

	stock1.acquire( comp, numberOfShares, shareValue );

	cout << "Stock Info: " << endl << endl;
	cout << "Name:\t" << stock1.getName() << endl;
	cout << "Number of Shares:\t" << stock1.getNumberOfShares() << endl;
	cout << "Value of Shares:\t" << stock1.getShareValue() << endl;
	cout << "Total Value of Stock:\t" << stock1.getTotalValue() << endl;

	while( doneFlag == 0 ) {
		cout << endl << endl << "Menu: " << endl;
	}

	return 0;
}
