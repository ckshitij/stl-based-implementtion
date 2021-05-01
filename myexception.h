#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H
#include <exception>

namespace myexception {
    class my_exception : public std::exception {
        const char* message;
        public:
        my_exception(const char* message) {
            this->message = message;
        }
        my_exception() {
            this->message = "stackException thrown";
        }
        const char* what() const throw() {
            return message;
        }
    };
}

#endif //MY_EXCEPTION_H
