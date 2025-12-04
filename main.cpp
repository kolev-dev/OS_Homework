#include <iostream>
#include "Library.h"
using namespace std;

int main() {
    Library lib;

    Author a1{"James Clear", 1986};
    Author a2{"Robert Greene", 1959};

    Book b1{"Atomic Habits", a1, 2018, 29.90, "ISBN-001"};
    Book b2{"The 48 Laws of Power", a2, 1998, 34.50, "ISBN-002"};

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addMember(Member{"Pepi Petrov", "M001", 2023});

    cout << lib.to_string() << "\n";

    if (lib.loanBook("ISBN-001", "M001", "2025-11-03", "2025-11-17"))
        cout << "Loan created.\n";


    cout << "Available ISBN-001? " << boolalpha << lib.isBookAvailable("ISBN-001") << "\n";
    lib.returnBook("ISBN-001", "M001");
    cout << "Available ISBN-001? " << boolalpha << lib.isBookAvailable("ISBN-001") << "\n";
    
    
    for (const auto& bk : lib.findByAuthor("Clear")) {
        cout << bk.to_string() << "\n";
    }

    return 0;
    
}
