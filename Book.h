#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <stdexcept>
#include "Author.h"

class Book {
private:
    std::string title;
    Author author;
    int year;
    double price;
    std::string isbn;

public:
    static int totalBooks;

    Book()
        : title("Unknown"), author(), year(1900), price(0.0), isbn("NONE") {
        totalBooks++;
    }

    Book(const std::string& t, const Author& a, int y, double p, const std::string& i) : title(t), author(a), year(y), price(p), isbn(i) {
        
        if (p < 0) throw std::invalid_argument("Price < 0");
        if (y < 1500 || y > 2025) throw std::invalid_argument("Invalid year");
        totalBooks++;
        
    }

    Book(const Book& other) = default;
    Book(Book&& other) noexcept = default;
    Book& operator=(const Book& other) = default;
    Book& operator=(Book&& other) noexcept = default;
    ~Book() = default;

    const std::string& getTitle() const { return title; }
    const Author& getAuthor() const { return author; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    const std::string& getISBN() const { return isbn; }

    std::string to_string() const {
        return title + " | " + author.to_string() + " | " +
               std::to_string(year) + " | " +
               std::to_string(price) + " | " + isbn;
    }

    static int getTotalBooks() { return totalBooks; }
};

int Book::totalBooks = 0;

#endif
