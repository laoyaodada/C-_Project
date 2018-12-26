
#include "Object.h"
#include <cstdlib>
#include <iostream>

namespace LYlib {

void* Object::operator new(size_t heap_size) throw() {
    return malloc(heap_size);
}
void Object::operator delete(void* heap_space) {
    free(heap_space);
}
void* Object::operator new[](size_t heap_size) throw() {
    return malloc(heap_size);
}
void Object::operator delete[](void* heap_space) {
    free(heap_space);
}
Object::~Object() {}

}  // namespace LYlib
