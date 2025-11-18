// Charles Edge
// CS310-T301
// M11: Discussion

#include <iostream>
#include <stdexcept>
using namespace std;

// This is the template class
template <class T>
class Box {
public:
    T value;

    Box(T v) : value(v) {}

    // Member function with Exception Handling
    void test() {
        try {
            if (value == 0)
                throw runtime_error("Value is Zero!");
        }
        catch (runtime_error& e) {
            // FIX 1: Removed the call to the undefined function 'tuesdayfunctioncall()'.
            cout << "\n--- Exception Caught ---" << endl;
            cout << "Error in Box::test(): " << e.what() << endl;
            cout << "------------------------" << endl;
        }
    }
};

// Class with overloaded operator
class Num {
public:
    int x;
    Num(int a) : x(a) {}

    // Overloaded addition operator (allows Num a + Num b)
    Num operator+(const Num& other) {
        return Num(x + other.x);
    }
};

int main() {
    // 1. Test the Template Class (Box) and Exception Handling
    cout << "Testing Box Class and Exception Handling..." << endl;

    // This will trigger the exception because the value is 0.
    Box<int> x(0);
    x.test();

    // This will NOT trigger the exception.
    Box<double> y(1.5);
    y.test();

    // 2. Test the Overloaded Operator (Num)
    cout << "\nTesting Num Class and Overloaded Operator..." << endl;

    Num a(5);
    Num b(10);

    // FIX 2: Added the missing right-hand operand 'b' to the addition operation.
    Num c = a + b;

    // Print the result to screen
    cout << "Num a = " << a.x << ", Num b = " << b.x << endl;
    cout << "Result of 'a + b' (c.x): " << c.x << endl;

    return 0;
}