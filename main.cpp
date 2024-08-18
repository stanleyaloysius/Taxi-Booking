#include "Booking.h"

int main() {
    Booking book;
    book.initialize_taxis(4);
    
    book.book_taxi(1, 1, 'A', 'B', 9);
    book.book_taxi(2, 2, 'B', 'D', 9);
    book.book_taxi(3, 3, 'B', 'C', 12);

    book.display();
    return 0;
}