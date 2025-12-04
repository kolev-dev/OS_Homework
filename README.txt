Library System

##Compile with:
g++ -std=gnu++17 -Wall -Wextra -O2 -o library main.cpp

##Run with:
library.exe

(Всички .h файлове се включват автоматично от main.cpp)

##Files
- Author.h – автори
- Book.h – книги (Rule of 5, статичен член)
- Member.h – читатели
- Loan.h – заеми
- Library.h – управление на книги/читатели/заеми
- main.cpp – инициализация
- README.md – Тези инструкции


##Example run ->

Books: 2, Members: 1, Active loans: 0
Loan created for id-001.
Available id-001? true
Atomic Habits | James Clear1986 | 2018 | 29.900000 | id-001
