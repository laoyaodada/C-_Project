#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <cstddef>

namespace LYlib {
#define throw_exception(exception, message) \
    (throw exception(message, __FILE__, __LINE__))
class Exception {
protected:
    char *m_message;
    char *m_location;
    void init(const char *message, const char *file, int line);

public:
    Exception(const char *message);
    Exception(const char *file, int line);
    Exception(const char *message, const char *file, int line);
    Exception(const Exception &e);
    Exception &operator=(const Exception &e);
    virtual const char *get_message() const;
    virtual const char *get_location() const;
    virtual ~Exception() = 0;
};

class ArithmeticException : public Exception {
public:
    ArithmeticException() : Exception(NULL) {}
    ArithmeticException(const char *message) : Exception(message) {}
    ArithmeticException(const char *file, int line) : Exception(file, line) {}
    ArithmeticException(const char *message, const char *file, int line)
        : Exception(message, file, line) {}
    ArithmeticException(const ArithmeticException &e) : Exception(e) {}
    ArithmeticException &operator=(const ArithmeticException &e) {
        Exception::operator=(e);
        return *this;
    }
};
}  // namespace LYlib

#endif
