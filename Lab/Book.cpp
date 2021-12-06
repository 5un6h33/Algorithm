#include"Book.h"

Book::Book(): title(""), author(""), year(2016), genre("") {}
void Book::displayBook(std::ofstream& out) const
{
    out << "Title: " << Book::title << std::endl;
    out << "Author: " << Book::author << std::endl;
    out << "Year: " << Book::year << std::endl;
    out << "Genre: " << Book::genre << std::endl;
}
std::string Book::getAuthor() const
{
    return Book::author;
}
std::string Book::getGenre () const
{
    return Book::genre;
}
std::string Book::getTitle () const
{
    return Book::title;
}
int Book::getYear () const
{
    return Book::year;
}
void Book::setAuthor (std::string newAuthor)
{
    Book::author = newAuthor;
}
void Book::setGenre (std::string newGenre)
{
    Book::genre = newGenre;
}
void Book::setTitle (std::string newTitle)
{
    Book::title = newTitle;
}
void Book::setYear (int newYear)
{
    Book::year = newYear;
}