#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <map>
#include <vector>

enum class DateFormat {
    DD_MM_YYYY = 1,
    MM_DD_YYYY,
    MM_YYYY_DD,
    DD_YYYY_MM,
    YYYY_DD_MM,
    YYYY_MM_DD
};

struct Day {
    std::string m_day;
    Day(const std::string&);
};

struct Month {
    std::string m_month;
    Month(const std::string&);
};

struct Year {
    std::string m_year;
    Year(const std::string&);
};


class Date {
public:
    Date(int, const std::vector<std::string>&);

private:
    void init();

private:
    std::map<int, DateFormat> mp;
};
#endif // DATE_H