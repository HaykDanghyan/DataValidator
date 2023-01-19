#include "date.h"

Day::Day(const std::string& d) : m_day{d} {
    try {
        int day = std::stoi(d);
        if (day < 0 || day > 31) {
            throw std::invalid_argument("Day cannot be less than 0 or bigger than 31");
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
} 

Month::Month(const std::string& m) : m_month{m} {
    try {
        int month = std::stoi(m);
        if (month < 0 || month > 12) {
            throw std::invalid_argument("Month cannot be less than 0 or bigger than 12");
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
} 

Year::Year(const std::string& y) : m_year{y} {
    try {
        int year = std::stoi(y);
        if (year < 0 || year > 9999) {
            throw std::invalid_argument("Year cannot be less than 0 or bigger than 9999");
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
} 

void Date::init() {
    mp[1] = DateFormat::DD_MM_YYYY;
    mp[2] = DateFormat::MM_DD_YYYY;
    mp[3] = DateFormat::MM_YYYY_DD;
    mp[4] = DateFormat::DD_YYYY_MM;
    mp[5] = DateFormat::YYYY_DD_MM;
    mp[6] = DateFormat::YYYY_MM_DD;
}

Date::Date(int format, const std::vector<std::string>& input) {
    init();
    auto x = mp[format];
    Day* d;
    Month* m;
    Year* y;
    switch ((int)x) {
        case 1:
            d = new Day(*input.begin());
            m = new Month(*++input.begin());
            y = new Year(*++input.begin());   
        break;     
        case 2:
            m = new Month(*input.begin());
            d = new Day(*++input.begin());
            y = new Year(*++input.begin());   
        break;     
        case 3:
            m = new Month(*input.begin());
            y = new Year(*++input.begin());   
            d = new Day(*++input.begin());
        break;     
        case 4:
            d = new Day(*input.begin());
            y = new Year(*++input.begin());   
            m = new Month(*++input.begin());
        break;     
        case 5:
            y = new Year(*input.begin());   
            d = new Day(*++input.begin());
            m = new Month(*++input.begin());
        break;     
        case 6:
            y = new Year(*input.begin());   
            m = new Month(*++input.begin());
            d = new Day(*++input.begin());
        break;     
        default: 
            std::cout << "Wrong date format\n";
            break;    
    }   
}