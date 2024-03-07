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
    Book(const Book &ref)
        : price(ref.price) {
        title = new char[strlen(ref.title) + 1];
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(title, ref.title);
        strcpy(isbn, ref.isbn);
    }

    void ShowBookInfo() {
        cout << "[ " << title << " ]" << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Price: $" << price << endl;
    }

    Book& operator=(const Book &ref) {
        delete []title;
        delete []isbn;
        title = new char[strlen(ref.title) + 1];
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(title, ref.title);
        strcpy(isbn, ref.isbn);
        price = ref.price;

        return *this;
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
    EBook(const EBook &ref) 
        : Book(ref) {
        DRMKey = new char[strlen(ref.DRMKey) + 1];
        strcpy(DRMKey, ref.DRMKey);
    }

    void ShowEBookInfo() {
        ShowBookInfo();
        cout << "DRM Key: " << DRMKey << endl;
    }

    EBook& operator=(const EBook &ref) {
        Book::operator=(ref);
        delete []DRMKey;
        DRMKey = new char[strlen(ref.DRMKey) + 1];
        strcpy(DRMKey, ref.DRMKey);

        return *this;
    }
};

int main(void) {
    Book book1("Good C++", "555-12345-890-0", 20);
    Book book2(book1);
    book2.ShowBookInfo();
    Book book3 = book1;
    book3.ShowBookInfo();
    cout << endl;

    EBook ebook1("Good C++ ebook", "555-12345-890-1", 10, "fdx9w0i8kiw");
    EBook ebook2(ebook1);
    ebook2.ShowEBookInfo();
    EBook ebook3 = ebook1;
    ebook3.ShowEBookInfo();

    return 0;
}