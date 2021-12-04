#include"BookList.h"

BookList::BookList(): count(0), size(10) {}
void BookList::addBook(Book b)
{
    BookList::books[BookList::count++] = b;
}
void BookList::addBookAt (Book b, int location)
{
    if(location < 0)
    {
        BookList::slideUp(0);
        BookList::books[0] = b;
    }
    else if(location > count)
        BookList::books[BookList::count] = b;
    else
    {
        BookList::slideUp(location);
        BookList::books[location] = b;
    }
    BookList::count++;
}
void BookList::displayBooks (std::ofstream& out) const
{
    out << "Books in my list:" << std::endl;
    for(int i = 0; i < BookList::count; i++)
    {
        out << "Title: " << BookList::books[i].getTitle() << std::endl;
        out << "Author: " << BookList::books[i].getAuthor() << std::endl;
        out << "Year: " << BookList::books[i].getYear() << std::endl;
        out << "Genre: " << BookList::books[i].getGenre() << std::endl;
    }
}
Book BookList::findBook (int location) const
{
    if(location >= 0 && location < count)
        return BookList::books[location];
    else
    {
        Book book;
        return book;
    }
}
Book BookList::removeBook (int location)
{
    if(location >= 0 && location < count)
    {
        Book removedBook = BookList::books[location];
        BookList::slideDown(location);
        BookList::count--;
        return removedBook;
    }
    else
    {
        Book book;
        return book;
    }
}
void BookList::slideDown (int location)
{
    for(int i = location; i < BookList::count - 1; i++)
        BookList::books[i] = BookList::books[i + 1];
}
void BookList::slideUp (int location)
{
    for(int i = BookList::count; i > location; i--)
        BookList::books[i] = BookList::books[i - 1];
}