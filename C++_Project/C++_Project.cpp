#include "Headers.h"

using namespace std;
using namespace LYlib;

int main(int argc, const char* argv[]) {
    // StaticList<int, 5> l;
    // for (int i = 0; i < l.capacity(); i++) {
    //     l.insert_node(0, i);
    // }
    // for (int i = 0; i < l.length_list(); i++) {
    //     cout << l[i] << endl;
    // }
    // l[0] *= l[0];
    // for (int i = 0; i < l.length_list(); i++) {
    //     cout << l[i] << endl;
    // }
    // try {
    //     l[5] = 5;
    // } catch (const Exception& e) {
    //     cout << e.get_message() << endl;
    //     cout << e.get_location() << endl;
    // }
    DynamicList<int> l(5);
    for (int i = 0; i < l.capacity(); i++) { l.insert_node(0, i); }
    for (int i = 0; i < l.length_list(); i++) { cout << l[i] << endl; }
    l[0] *= l[0];
    for (int i = 0; i < l.length_list(); i++) { cout << l[i] << endl; }
    try {
        l[5] = 5;
    } catch (const Exception& e) {
        cout << e.get_message() << endl;
        cout << e.get_location() << endl;
        l.resize(10);
        l.insert_node(5, 50);
    }
    l[5] = 5;
    for (int i = 0; i < l.length_list(); i++) { cout << l[i] << endl; }

    return 0;
}
