// C++_Project.cpp: 定义应用程序的入口点。

#include "C++_Project.h"

using namespace std;
using namespace LYlib;

class Test {
public:
    Test() { cout << "Test()" << endl; }
    ~Test() { cout << "~Test()" << endl; }
};

int main(int argc, const char *argv[]) {
    try {
        // throw Exception("test", __FILE__, __LINE__);
        throw_exception(ArithmeticException, "test");
    } catch (const Exception &e) {
        cout << "catch(const Exception&1)" << endl;
        cout << e.get_message() << endl;
        cout << e.get_location() << endl;
    }
    // catch (const ArithmeticException &e) {
    //     cout << "catch(const Exception&)2" << endl;
    //     cout << e.get_message() << endl;
    //     cout << e.get_location() << endl;
    // }

    SmartPointer<Test> sp = new Test();
    SmartPointer<Test> nsp;
    nsp = sp;
    cout << sp.pointer_is_null() << endl;
    cout << nsp.pointer_is_null() << endl;
    return 0;
}
