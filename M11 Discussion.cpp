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

    void test() {
        try {
            if (value == 0)
                throw runtime_error("Zero!!!!");
        }
        catch (runtime_error& e) {
            cout << e.what() << endl;
            tuesdayfunctioncall();
        }
    }
};

// Class with overloaded operator
class Num {
public:
    int x;
    Num(int a) : x(a) {}

    Num operator+(const Num& other) {
        return Num(x + other.x);
    }
};

int main() {
    Box<int> x(0);
    x.test();

    Num a(5), b(10);
    Num c = a + ;

//Print to screen
    cout << c.x << endl;
    return 0;
}