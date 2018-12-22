#include "C++_Project.h"

using namespace std;
using namespace LYlib;

class Test : public Object {
public:
    int i;
    int j;
    Test() { cout << "Test()" << endl; }
    ~Test() { cout << "~Test()" << endl; }
};

class Child : public Test {
public:
    int k;
};

int main(int argc, const char* argv[]) {
    // SmartPointer<int>* sp = new SmartPointer<int>();
    // delete sp;
    // ArithmeticException* e = new ArithmeticException();
    // delete e;
    try {
        // throw Exception("Test", __FILE__, __LINE__);

        throw_exception(InvalidOperationException, "test");
    } catch (const Exception& e) {
        cout << "dd" << endl;
        cout << e.get_message() << endl;
        cout << e.get_location() << endl;
    }
    return 0;
}
