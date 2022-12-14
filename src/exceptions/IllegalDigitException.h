/**
 * Header file that describes IllegalDigitException.
 *  @author sanyavertolet
 */

#ifndef COUNTING_STARS_ILLEGALDIGITEXCEPTION_H
#define COUNTING_STARS_ILLEGALDIGITEXCEPTION_H

#include <exception>

/**
 * Exception thrown on illegal character inside digit-string.
 *
 * @inherit std::exception
 */
class IllegalDigitException : std::exception
{
private:
    const char *message;

public:
    explicit IllegalDigitException(const char *msg) : message(msg) {}
    explicit IllegalDigitException(const std::string &msg) : message(msg.c_str()) {}
    const char *what()
    {
        return message;
    }
};

#endif // COUNTING_STARS_ILLEGALDIGITEXCEPTION_H
