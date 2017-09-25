// L8_Stocks.cpp

#include <iostream>
#include <cstring>

class Stock{
	private:
		char company[30];					// Name of the company
		int shares;						// Number of shares of the company stock
		double share_val;					// Value of each share of stock
		double total_val;					// Total value of the stocks at the current price
		// Sets the total value of all the shares of stock at the current price		
		void set_tot(){total_val = shares * share_val; }	
		void acquire(const char * co, int n, double pr);	// Edits a stock's attributes
		void acquire( const char *co );				// Edits the stock's name, sets all attributes to 0
	public:
		// Change number of shares, and updates the price of each share
		void buy(int num, double price);
		void sell(int num, double price);
		// Updates the price of each share
		void update(double price);
		// Display information
		void printStockInfo( void );
		// Getter methods
		int getNumberOfShares( void );
		double getSharePrice( void );
		double getTotalValue( void );
		// Constructors		
		Stock( const char *co );
}; // END CLASS Stock

// Constructor: Update name of stock, sets all other attributes to 0
Stock::Stock( const char *co ){
	acquire( co );
	shares = 0;
	share_val = 0;
	total_val = 0;
	set_tot();
}

// Sets object attributes
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

// Set company name, and sets company stock attributes to 0
void Stock::acquire( const char * co ){
	std::strncpy(company, co, 29);
	company[29] = '\0';
	set_tot();
}

// Add <num> to total shares of stock, change <share_val> to <price> and update the total price of the stock
void Stock::buy( int num, double price )
{
	shares += num;
	share_val = price;
	set_tot();
}

// Subtracts <num> from total shares of stock, change <share_val> of stock to <price>, and updates the total price of the stock
void Stock::sell( int num, double price )
{
	shares -= num;
	share_val = price;
	set_tot();
}

// Prints stock attributes to terminal screen
void Stock::printStockInfo( void )
{
	using std::cout;
	using std::endl;

	cout << "Stock Info: " << endl << endl;
	cout << "Name:\t" << company << endl;
	cout << "Number of Shares:\t" << shares << endl;
	cout << "Value of Shares:\t" << share_val << endl;
	cout << "Total Value of Stock:\t" << total_val << endl;

}

// Getter Methods to Acess Stock Attributes 
int Stock::getNumberOfShares( void ) { return shares; }
double Stock::getSharePrice( void ) { return share_val; }
double Stock::getTotalValue( void ) { return total_val; }

// Main function of the program
int main(){
	using std::cout;
	using std::endl;
	using std::cin;
	
	char comp[ 30 ];
	short menuChoice = 0;		// Signifies choice made by user
	short doneFlag = 0;		// Signifies that the program is done - Set to 1 to Exit Program
	int numberOfShares = 0;
	double shareValue = 0;
	
	// Get Stock Attributes
	cout << "Name of Stock: ";
	cin >> &comp[ 0 ];

	// Object Constructor
	Stock stock( comp );

	while( doneFlag == 0 ) {
		// Prints Menu
		cout << endl << endl << "Menu: " << endl;
		cout << "1. Show Stock Information" << endl;
		cout << "2. Buy Stocks" << endl;
		cout << "3. Sell Stocks" << endl;
		cout << "9. Exit" << endl;
		cout << "--> ";
		cin >> menuChoice;

		switch( menuChoice ) {
			case 1: // Print Stock Information
				stock.printStockInfo();
				break;
			case 2: // Buy a number of shares at a given price
				cout << endl << endl << "Number of Shares:\t\t" << stock.getNumberOfShares() << endl;
				cout << "Share Price:\t\t\t" << stock.getSharePrice() << endl;
				cout << "Total Value:\t\t\t" << stock.getTotalValue() << endl << endl;
				cout << "Number of Shares to Buy:\n--> ";
				cin >> numberOfShares;
				cout << endl << "Price of each Share:\n--> ";
				cin >> shareValue;
				stock.buy( numberOfShares, shareValue );
				break;
			case 3: // Sell a number of shares at a given price
				cout << endl << endl << "Number of Shares:\t\t" << stock.getNumberOfShares() << endl;
				cout << "Share Price:\t\t\t" << stock.getSharePrice() << endl;
				cout << "Total Value:\t\t\t" << stock.getTotalValue() << endl << endl;
				cout << "Number of Shares to Sell:\n--> ";
				cin >> numberOfShares;
				cout << endl << "Price of each Share:\n--> ";
				cin >> shareValue;
				stock.sell( numberOfShares, shareValue );
				break;
			case 9: // Exit Program
				doneFlag = 1;
				break;
			default: // Menu Selection Error
				cout << "ERROR: TRY AGAIN";
				break;
		} // END switch - Menu Selection
	} // END while - Main Program

	return 0;
} // END function main
