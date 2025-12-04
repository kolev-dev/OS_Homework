#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include <algorithm>
#include "Book.h"
#include "Member.h"
#include "Loan.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Loan> loans;

public:
    void addBook(const Book& b) {
        books.push_back(b);
    }

    void addMember(const Member& m) {
        members.push_back(m);
    }

    bool hasBook(const std::string& id) const {
        return std::any_of(books.begin(), books.end(),
                           [&](const Book& b){ return b.getid() == id; });
    }

    bool isBookAvailable(const std::string& id) const {
        for (const auto& loan : loans)
            if (loan.getid() == id && !loan.isReturned())
                return false;
        return true;
    }

    bool loanBook(const std::string& id, const std::string& memberId,
                  const std::string& start, const std::string& due)
    {
        if (!hasBook(id)) return false;
        if (!isBookAvailable(id)) return false;

        loans.emplace_back(id, memberId, start, due);
        return true;
    }

    bool returnBook(const std::string& id, const std::string& memberId) {
        for (auto& l : loans) {
            if (l.getid() == id && l.getMemberId() == memberId && !l.isReturned()) {
                l.markReturned();
                return true;
            }
        }
        return false;
    }

    std::vector<Book> findByAuthor(const std::string& authorName) const 
    {
        std::vector<Book> res;
        for (const auto& b : books)
            if (b.getAuthor().getName().find(authorName) != std::string::npos)
                res.push_back(b);
        return res;
    }

    std::string to_string() const {
        int active = 0;
        for (const auto& l : loans)
            if (!l.isReturned()) active++;

        return "Books: " + std::to_string(books.size()) +
               ", Members: " + std::to_string(members.size()) +
               ", Active loans: " + std::to_string(active);
    }

};

#endif
