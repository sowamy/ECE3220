// L20_Ex1_FunctionT.cpp
// By Luis Rivera

#include <iostream>
using namespace std;

// Find the max among three elements.
// The operations (comparisons, assignments etc.) should make sense for all intented types.
template <typename Type>
Type FindMax(Type v1, Type v2, Type v3) {
   Type maxVal = v1;
   
   if(v2 > maxVal) {
      maxVal = v2;
   }
   if(v3 > maxVal) {
      maxVal = v3;
   }
   
   return maxVal;
}

int main() {
   int num1 = 55, num2 = 99, num3 = 66;
   double dbl1 = 12.5, dbl2 = 7.9, dbl3 = -10.3;
   
   cout << "Items: " << num1 << " " << num2 << " " << num3 << endl;
   cout << "Max: " << FindMax(num1, num2, num3) << endl << endl;
   
   cout << "Items: " << dbl1 << " " << dbl2 << " " << dbl3 << endl;
   cout << "Max: " << FindMax(dbl1, dbl2, dbl3) << endl << endl;
      
   return 0;
}