// L17_Ex2.h

#include <iostream>
using namespace std;

#ifndef L19_EX2_H_
#define L19_EX2_H_

class bad_hmean{
private:
	double v1;
	double v2;
public:
	// Notice how members v1 and v2 can be initialized.
	bad_hmean(double a = 0, double b = 0) : v1(a), v2(b){}
	void mesg();
};

// Notice the "inline" keyword. It's not needed.
// The Compiler replaces the definition of inline functions at compile time,
// instead of referring function definition at runtime. If the function has
// many instructions, the compiler may ignore the inline request.
// Inline functions may increase efficiency if they are small (small execution
// time compared to overhead of making the function call).
inline void bad_hmean::mesg()
{
	cout << "hmean(" << v1 << " , " << v2 << ") : " << "invalid arguments: a = -b\n";
}

class bad_gmean{
public:
	double v1;
	double v2;
	// Notice how members v1 and v2 can be initialized.
	bad_gmean(double a = 0, double b = 0): v1(a), v2(b){}
	const char * mesg();
};

inline const char * bad_gmean::mesg()
{
	return "gmean() argumens should be >= 0\n";
}

#endif /* L19_EX2_H_ */
