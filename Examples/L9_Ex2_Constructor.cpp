// L9_Ex2_Constructor.cpp

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
		Stock acquire(const char * co, int n, double pr);
		void buy(int num, double price);
		void sell(int num, double price);
		void update(double price);
		void display();
		// Constructors: same name as the class
		Stock();	// default, no arguments.
		Stock(const char*, int, double);	// parametric constructor
};

Stock::Stock(){
	company[0] = '\n';
	shares = 0;
	share_val = 0;
	set_tot();
}

Stock::Stock(const char* co, int n, double pr){
	acquire(co, n, pr);
}

// Notice the return type
Stock Stock::acquire(const char * co, int n, double pr){
	std::strncpy(company, co, 29);
	company[29] = '\0';
	if(n < 0){
		std::cerr << "Number of shares can't be negative; "
				  << company << " shares set to 0.\n";
		shares = 0;
	}
	else{
		shares = n;
		std::cout << "\nUpdated shares." << std::endl;
	}
	share_val = pr;
	set_tot();
	return *this;
}

void Stock::display(){
	std::cout << std::endl << "Company: " << company << std::endl
			  << "Shares: " << shares << std::endl
			  << "Share value: " << share_val << std::endl
			  << "Total value: " << total_val << std::endl;
}

int main(){
	using std::cout;
	using std::endl;
	
	Stock stock1;
	stock1.acquire("Nanosmart", 20, 12.50);
	stock1.display();
		
	Stock stock2("Amazon", 30, 100);
	stock2.display();
		
	return 0;
}