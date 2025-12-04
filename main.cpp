#include <iostream>
#include "Library.h"
using namespace std;

int main() {
    Library lib;

    Author author1{"James Clear", 1986};
    Author author2{"Robert Greene", 1959};

    Book book1{"Atomic Habits", author1, 2018, 29.90, "id-001"};
    Book book2{"The 48 Laws of Power", author2, 1998, 34.50, "id-002"};

    string id1 = book1.getid();
    string id2 = book2.getid();

    Member member{"Petar Petrov", "M001", 2023};
    string memberId = member.getId();

    lib.addBook(book1);
    lib.addBook(book2);
    lib.addMember(member);


    cout << lib.to_string() << "\n";


    if (lib.loanBook(id1, memberId, "2025-11-03", "2025-11-17")) {
        cout << "Loan created for " << id1 << ".\n";
    }

    lib.returnBook(id1, memberId);


    cout << "Available " << id1 << "? " 
         << boolalpha << lib.isBookAvailable(id1) << "\n";

    for (const auto& bk : lib.findByAuthor("Clear")) 
    {
        cout << bk.to_string() << "\n";
    }

    return 0;

}
