#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <stdexcept>

class Member {
private:
    std::string name;
    std::string memberId;
    int yearJoined;

public:
    Member() : name("Unknown"), memberId("NONE"), yearJoined(2000) {}

    Member(const std::string& n, const std::string& id, int y)
        : name(n), memberId(id), yearJoined(y) {
        if (id.empty()) throw std::invalid_argument("Empty member ID");
    }

    const std::string& getName() const { return name; }
    const std::string& getId() const { return memberId; }
    int getYearJoined() const { return yearJoined; }

    std::string to_string() const {
        return name + " | " + memberId + " | " + std::to_string(yearJoined);
    }
};

#endif