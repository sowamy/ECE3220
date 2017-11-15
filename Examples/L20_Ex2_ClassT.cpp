// L20_Ex2_ClassT.cpp
// By Luis Rivera

#include <iostream>
#include <string>
using namespace std;

template <typename Type>
class Items {
public:
   Items(Type val1, Type val2, Type val3);
   void display() const; // Print all data member values
   Type FindMax() const; // Return max data member value
private:
   Type item1;
   Type item2;
   Type item3;
};

// Constructor
template <typename Type>
Items<Type>::Items(Type i1, Type i2, Type i3) {
   item1 = i1;
   item2 = i2;
   item3 = i3;
}

// Print all data member values
template <typename Type>
void Items<Type>::display() const {
   cout << "(" << item1 << "," << item2
        << "," << item3 << ")" << endl;
   return;
}

// Return max data member value
// The operations (comparisons, assignments etc.) should make sense for all intented types.
template <typename Type>
Type Items<Type>::FindMax() const {
   Type maxVal = item1;
   
   if(item2 > maxVal) {
      maxVal = item2;
   }
   if(item3 > maxVal) {
      maxVal = item3;
   }
   
   return maxVal;
}

int main()
{
   Items<int> IntItems(10, 65, 33);		// Items class with ints
   Items<short> ShortItems(9, 5, 6);	// Items class with shorts
   Items<string> StringItems("abcd", "3bd", "ef");   // Items class with strings
   
   IntItems.display();
   cout << "Max: " << IntItems.FindMax() << endl << endl;
   
   ShortItems.display();
   cout << "Max: " << ShortItems.FindMax() << endl << endl;
   
   StringItems.display();
   cout << "Max: " << StringItems.FindMax() << endl << endl;
   
   return 0;
}