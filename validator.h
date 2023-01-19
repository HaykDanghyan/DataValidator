#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <iostream>
#include <algorithm>
#include <vector>

#include "date.h"

class Validator {
public:
    static void run();

private:
    static void validate_email();
    static void validate_url();
    static void validate_date();
    static void validate_number();

private:
    static bool is_letter(char);
    static int count(const std::string&, char);
    static bool is_number(char);
    static std::vector<std::string> split(const std::string&, const std::string&);
private:
    Validator() = delete;
    Validator(const Validator&) = delete;
    Validator(Validator&&) = delete;
    ~Validator() = delete;
};

#endif // VALIDATOR_H
