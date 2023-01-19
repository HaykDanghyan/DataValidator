#include "validator.h"

void Validator::run() {
    std::cout << "\t=========================\n";
    std::cout << "\t\tMain Menu\t\t\n";
    std::cout << "\t[1] Validate email\n\t[2] Validate URL\n\t[3] Validate date\n\t[4] Validate number\n\t[5] Exit\n\n\t";
    int choice = 0;
    do {
        std::cout << "Enter your choice [ ]\b\b";
        std::cin >> choice;
        switch (choice) {
            case 1:
                validate_email();
                break;
            case 2:
                validate_url();
                break;
            case 3:
                validate_date();
                break;
            case 4:
                validate_number();
                break;
            case 5:
                std::cout << "Bye\n";
                exit(0);
            default:
                std::cout << "Wrong input\n";
        }
    } while (choice != 5);
}

void Validator::validate_number() {
    std::string str{};
    std::cout << "Enter a number : ";
    std::cin >> str;
    auto it = std::find_if(str.begin(), str.end(), is_letter);
    if (it != str.end()) {
        std::cout << "The entered number is wrong\n";
        return;
    } 
    try {
        double d = std::stod(str);
        if (count(str, '.') > 1) {
            std::cout << "The entered number is wrong\n";
            return;
        }
        if (count(str, '-') > 1) {
            std::cout << "The entered number is wrong\n";
            return;    
        }
    } catch (const std::exception& e) {
        std::cout << "The entered number is wrong\n";
        return;
    }
    std::cout << "The entered number is correct\n";    
}

void Validator::validate_url() {
    std::string str{};
    std::cout << "Enter the URL : ";
    std::cin >> str;
    if (count(str, '/') != 2) {
        std::cout << "The entered URL is wrong\n";
        return;    
    }
    if (str.find(':') == std::string::npos) {
        std::cout << "The entered URL is wrong\n";
        return;    
    }
    if (str.find('.') == std::string::npos) {
        std::cout << "The entered URL is wrong\n";
        return;    
    }
    if (str.find(' ') != std::string::npos) {
        std::cout << "The entered URL is wrong\n";
        return;    
    }
    std::cout << "The entered URL is correct\n";
}

bool Validator::is_letter(char ch) {
    return (ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z');
}

bool Validator::is_number(char ch) {
    return ch >= '0' and ch <= '9';
}

int Validator::count(const std::string& str, char ch) {
    int c = 0;
    for (const auto& el : str) {
        if (ch == el) {
            c++;
        }
    }
    return c;
}

void Validator::validate_email() {
    std::string str{};
    std::cout << "Enter an email : ";
    std::cin >> str;
    if (count(str, '@') > 1 || count(str, '.') > 1) {
        std::cout << "The entered email is wrong\n";
        return;
    }
    std::cout << "The entered email is correct\n";
}

std::vector<std::string> Validator::split(const std::string& str, const std::string& del) {
    std::string word{};
    std::vector<std::string> res;
    for (const auto& el : str) {
        if (del.find(el) == std::string::npos) {
            word += el;
        }
        else if (!word.empty()) {
            res.push_back(word);
            word.clear();
        }
    }
    if (!word.empty()) {
        res.push_back(word);
        word.clear();
    }
    return res;
}

void Validator::validate_date() {
    std::string str{};
    std::cout << "Select the date format\n";
    std::cout << "1. dd/mm/yyyy\n";
    std::cout << "2. mm/dd/yyyy\n";
    std::cout << "3. mm/yyyy/dd\n";
    std::cout << "4. dd/yyyy/mm\n";
    std::cout << "5. yyyy/dd/mm\n";
    std::cout << "6. yyyy/mm/dd\n";
    int format = 0;
    do {
        std::cout << "Enter the format : ";
        std::cin >> format;
    } while (format < 0 || format > 6);
    std::cout << "Enter the date : ";
    std::string date;
    std::cin >> date;
    auto vec = split(date, "/");
    Date d(format, vec);
}