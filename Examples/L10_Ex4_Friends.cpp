// L10_Ex4_Friends.cpp
// This example includes the methods and constructors asked for In-Class Assignment #3
// Some slight changes w.r.t L8 and L9 examples.

#include <iostream>
#include <cstring>
using namespace std;

class Stock{
	friend class Broker;	// entire class is a friend
	friend void printStock2(Stock& stock);	// single function is a friend
	
	private:
		char company[30];
		int shares;
		double share_val;
		double total_val;
		void set_tot(){total_val = shares * share_val; }
		Stock& acquire(const char * co, int n, double pr);
		Stock& acquire(const char * co);
	public:
		void buy(int num, double price);
		void sell(int num, double price);
		void update(double price);
		void display();
		// Constructors: same name as the class
		Stock();	// default, no arguments.
		Stock(const char*, int, double);
		Stock(const char*);
};

// Friend class
class Broker{
	private:
		char name[30];
	public:
		void printStock(Stock s);
};

void Broker::printStock(Stock stock){
	cout << endl << "Company: " << stock.company << endl
		 << "Shares: " << stock.shares << endl
		 << "Share value: " << stock.share_val << endl
		 << "Total value: " << stock.total_val << endl;
}

// Friend function (argument doesn't have to be a reference)
void printStock2(Stock& stock){
	cout << endl << "Company: " << stock.company << endl
		 << "Shares: " << stock.shares << endl
		 << "Share value: " << stock.share_val << endl
		 << "Total value: " << stock.total_val << endl;
}

// Default constructor
Stock::Stock(){
	company[0] = '\n';
	shares = 0;
	share_val = 0.0;
	set_tot();
}

// Parametric constructor
Stock::Stock(const char* co, int n, double pr){
	acquire(co, n, pr);
}

// Parametric constructor
Stock::Stock(const char* co){
	acquire(co, 0, 0.0);
}

// default values could be used: (const char *co, int n = 0, double pr = 0.0)
Stock& Stock::acquire(const char *co, int n, double pr){
	strncpy(company, co, 29);
	company[29] = '\0';
	if(n < 0){
		cerr << "Number of shares can't be negative; "
			 << company << " shares set to 0.\n";
		shares = 0;
	}
	else{
		shares = n;
		cout << "\nUpdated shares." << endl;
	}
	share_val = pr;
	set_tot();
	return *this; // 
}

// wouldn't be needed if default values were used in the constructor above.
Stock& Stock::acquire(const char * co){
	strncpy(company, co, 29);
	company[29] = '\0';
	shares = 0;
	share_val = 0.0;
	cout << shares << " Updated shares." << endl;
	set_tot();
	return *this;
}

// num and price supposed to be non-negative.
// adjusts number of shares and share value according to inputs,
// then just re-calculates total value
void Stock::buy(int num, double price){
	if(num < 0){
		cerr << "Number of bought shares can't be negative\n";
	}
	else if(price <= 0.0) {
		cerr << "Share value must be non-negative\n";
	}
	else{
		shares += num;
		share_val = price;	// all shares supposed to have the same price
		set_tot();
		cout << "\nUpdated shares after buying." << endl;
	}
}

// num and price supposed to be non-negative.
// adjusts number of shares and share value according to inputs,
// then just re-calculates total value
void Stock::sell(int num, double price){
	if(num < 0){
		cerr << "Number of sold shares can't be negative\n";
	}
	else if(price <= 0.0) {
		cerr << "Share value must be non-negative\n";
	}
	else{
		shares -= num;
		share_val = price;	// all shares supposed to have the same price
		set_tot();
		cout << "\nUpdated shares after selling." << endl;
	}
}

// After updating the price, the total value needs to be re-calculated.
void Stock::update(double price){
	share_val = price;
	set_tot();
}

// Print all data members.
void Stock::display(){
	cout << endl << "Company: " << company << endl
		 << "Shares: " << shares << endl
		 << "Share value: " << share_val << endl
		 << "Total value: " << total_val << endl;
}

// Purpose here: to show the use of friends.
int main(){
	Stock stock1("Nanosmart", 20, 12.50);
	stock1.display();	// display through object's own method
	
	Broker broker1;
	broker1.printStock(stock1);	// through friend class' display method
		
	Stock &stock2 = stock1;
	printStock2(stock2);		// through friend function
		
	return 0;
}