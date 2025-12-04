#ifndef LOAN_H
#define LOAN_H

#include <string>
#include <stdexcept>

class Loan {
private:
    std::string isbn;
    std::string memberId;
    std::string startDate;
    std::string dueDate;
    bool returned;

public:
    Loan(const std::string& i, const std::string& m,
         const std::string& start, const std::string& due) : isbn(i), memberId(m), startDate(start), dueDate(due), returned(false)
    {
        if (due < start)
            throw std::invalid_argument("due < start");
    }

    void markReturned() { returned = true; }
    bool isReturned() const { return returned; }

    bool isOverdue(const std::string& today) const
    {
        return !returned && today > dueDate;
    }

    const std::string& getISBN() const { return isbn; }
    const std::string& getMemberId() const { return memberId; }

    
    std::string to_string() const {
        return isbn + " | " + memberId + " | " + startDate + " -> " + dueDate +
               (returned ? " | returned" : " | active");
    }
};

#endif
