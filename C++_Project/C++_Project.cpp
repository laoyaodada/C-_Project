#include "Headers.h"

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
    SeqList<int>* l;
    return 0;
}
