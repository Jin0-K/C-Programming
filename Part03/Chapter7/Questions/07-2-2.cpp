#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Book {
private :
    char *title;    // Title of the book
    char *isbn;     // International Standard Book Number
    int price;      // Regular price of the book
public:
    Book(char *title, char *isbn, int price)
        : price(price) {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
        this->isbn = new char[strlen(isbn) + 1];
        strcpy(this->isbn, isbn);
    }

    void ShowBookInfo() {
        cout << "[ " << title << " ]" << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Price: $" << price << endl;
    }
};

class EBook : protected Book {
private :
    char *DRMKey;    // Security key
public :
    EBook(char *title, char *isbn, int price, char *DRMKey)
        : Book(title, isbn, price) {
        this->DRMKey = new char[strlen(DRMKey) + 1];
        strcpy(this->DRMKey, DRMKey);
    }

    void ShowEBookInfo() {
        ShowBookInfo();
        cout << "DRM Key: " << DRMKey << endl;
    }
};

int main(void) {
    Book book("Good C++", "555-12345-890-0", 20);
    book.ShowBookInfo();
    cout << endl;

    EBook ebook("Good C++ ebook", "555-12345-890-1", 10, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();

    return 0;
}