

#include "Object.h"
#include <cstdlib>

namespace LYlib {

void* Object::operator new(size_t size) throw() {
    cout << "new object" << endl;
    return malloc(size);
}
void Object::operator delete(void* p) {
    cout << "delete object" << endl;
    free(p);
}
void* Object::operator new[](size_t size) throw() { return malloc(size); }
void Object::operator delete[](void* p) { free(p); }
Object::~Object() {}

}  // namespace LYlib