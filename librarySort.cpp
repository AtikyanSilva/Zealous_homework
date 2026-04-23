#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
struct bookName {
    string name;
    bool isTaken = false;
};
struct book {
    vector<bookName> books;
    string author;
};
void fillBookList(vector<book>& allBooks){
   string listString = R"(The Great Gatsby - F. Scott Fitzgerald
To Kill a Mockingbird - Harper Lee
1984 - George Orwell
Pride and Prejudice - Jane Austen
Moby-Dick - Herman Melville
War and Peace - Leo Tolstoy
The Catcher in the Rye - J.D. Salinger
The Hobbit - J.R.R. Tolkien
Brave New World - Aldous Huxley
Crime and Punishment - Fyodor Dostoevsky
Jane Eyre - Charlotte Brontë
The Lord of the Rings - J.R.R. Tolkien
Animal Farm - George Orwell
Wuthering Heights - Emily Brontë
The Odyssey - Homer
The Brothers Karamazov - Fyodor Dostoevsky
One Hundred Years of Solitude - Gabriel García Márquez
The Picture of Dorian Gray - Oscar Wilde
Fahrenheit 451 - Ray Bradbury
Dracula - Bram Stoker
The Iliad - Homer
Les Misérables - Victor Hugo
A Tale of Two Cities - Charles Dickens
Don Quixote - Miguel de Cervantes
Ulysses - James Joyce
The Divine Comedy - Dante Alighieri
Hamlet - William Shakespeare
Macbeth - William Shakespeare
The Alchemist - Paulo Coelho
The Little Prince - Antoine de Saint-Exupéry
Slaughterhouse-Five - Kurt Vonnegut
Catch-22 - Joseph Heller
The Sun Also Rises - Ernest Hemingway
The Old Man and the Sea - Ernest Hemingway
Anna Karenina - Leo Tolstoy
Madame Bovary - Gustave Flaubert
The Stranger - Albert Camus
The Metamorphosis - Franz Kafka
Siddhartha - Hermann Hesse
Heart of Darkness - Joseph Conrad
The Sound and the Fury - William Faulkner
Lolita - Vladimir Nabokov
Beloved - Toni Morrison
Invisible Man - Ralph Ellison
The Road - Cormac McCarthy
Life of Pi - Yann Martel
The Kite Runner - Khaled Hosseini
A Thousand Splendid Suns - Khaled Hosseini
The Book Thief - Markus Zusak
The Fault in Our Stars - John Green
Gone with the Wind - Margaret Mitchell
The Hunger Games - Suzanne Collins
Harry Potter and the Sorcerer’s Stone - J.K. Rowling
The Da Vinci Code - Dan Brown
Angels & Demons - Dan Brown
The Girl with the Dragon Tattoo - Stieg Larsson
The Shining - Stephen King
It - Stephen King
Misery - Stephen King
Dune - Frank Herbert
Ender’s Game - Orson Scott Card
Neuromancer - William Gibson
Snow Crash - Neal Stephenson
Foundation - Isaac Asimov
I, Robot - Isaac Asimov
The Martian - Andy Weir
Ready Player One - Ernest Cline
Jurassic Park - Michael Crichton
The Time Machine - H.G. Wells
The War of the Worlds - H.G. Wells
Frankenstein - Mary Shelley
Handmaid’s Tale - Margaret Atwood
Oryx and Crake - Margaret Atwood
The Giver - Lois Lowry
The Maze Runner - James Dashner
Divergent - Veronica Roth
Twilight - Stephenie Meyer
The Chronicles of Narnia - C.S. Lewis
Alice’s Adventures in Wonderland - Lewis Carroll
Through the Looking-Glass - Lewis Carroll
Peter Pan - J.M. Barrie
Treasure Island - Robert Louis Stevenson
Robinson Crusoe - Daniel Defoe
Gulliver’s Travels - Jonathan Swift
The Secret Garden - Frances Hodgson Burnett
Little Women - Louisa May Alcott
Anne of Green Gables - L.M. Montgomery
Heidi - Johanna Spyri
Black Beauty - Anna Sewell
Charlotte’s Web - E.B. White
Matilda - Roald Dahl
The BFG - Roald Dahl
Charlie and the Chocolate Factory - Roald Dahl
The Wind in the Willows - Kenneth Grahame
Watership Down - Richard Adams
The Call of the Wild - Jack London
White Fang - Jack London
Of Mice and Men - John Steinbeck
East of Eden - John Steinbeck
The Grapes of Wrath - John Steinbeck)";
    stringstream lineStream(listString);
    string line;
    while(getline(lineStream, line)){
        stringstream newStream(line);
        string name;
        string author;
        getline(newStream, name, '-');
        name.erase(name.find_last_not_of(" ") + 1);
        getline(newStream, author);
        author.erase(author.find_last_not_of(" ") + 1);
        author.erase(0, author.find_first_not_of(" "));
        bool theSameAuthor = false;
        bookName bookN;
        bookN.name = name;
        for(int i = 0; i < allBooks.size(); i++){
            if(allBooks[i].author == author){
                allBooks[i].books.push_back(bookN);
                theSameAuthor = true;
                break;
            }
        }
        if(!theSameAuthor){
            book newBook;
            newBook.author = author;
            newBook.books.push_back(bookN);
            allBooks.push_back(newBook);
        }
    }
       
}
void sortBooks(vector<book>& allBooks){
    for(int i = 0; i < allBooks.size(); i++){
        for(int j = 0; j < allBooks.size() - i - 1; j++){
            if(allBooks[j].author > allBooks[j + 1].author){
                book temp = allBooks[j];
                allBooks[j] = allBooks[j + 1];
                allBooks[j + 1] = temp;
            }
        }
}
}
int quickFindAuthor(vector<book>& allBooks, string nameInput, int start, int end){
    if(start > end){
        return -1;
    }
    if(allBooks[(start + end) / 2].author == nameInput){
        return (start + end) / 2;
    }
    else if(allBooks[(start + end) / 2].author > nameInput){
        return quickFindAuthor(allBooks, nameInput, start, (start + end) / 2 - 1);
    }
    else{
        return quickFindAuthor(allBooks, nameInput, (start + end) / 2 + 1, end);
    }
}
void findName(vector<book>& allBooks, string nameInput){
   for(int i = 0; i < allBooks.size(); i++){
       for(int j = 0; j < allBooks[i].books.size(); j++){
           if(allBooks[i].books[j].name == nameInput){
               if(allBooks[i].books[j].isTaken == true){
                   cout << "Sorry the book is already taken." << endl;
                   return;
               }
               else{
                   allBooks[i].books[j].isTaken = true;
                   cout << "You take " + nameInput << endl;
                   return;
               }
           }
       }
   }
   cout << "Sorry we don't have such a book or author." << endl;
}
void findNameReturn(vector<book>& allBooks, string nameInput){
   for(int i = 0; i < allBooks.size(); i++){
       for(int j = 0; j < allBooks[i].books.size(); j++){
           if(allBooks[i].books[j].name == nameInput){
               if(allBooks[i].books[j].isTaken == false){
                   cout << "Sorry, this book isn't taken. Are you sure you take it?" << endl;
                   return;
               }
               else{
                   allBooks[i].books[j].isTaken = false;
                   cout << "You return " + nameInput + ", thank you" << endl;
                   return;
               }
           }
       }
   }
   cout << "Sorry we don't have such a book or author." << endl;
}
void borrowBook(vector<book>& allBooks, string nameInput){
    int end = allBooks.size() - 1;
    int bookIndex = quickFindAuthor(allBooks, nameInput, 0, end);
    if(bookIndex == -1){
        findName(allBooks, nameInput);
    }
    else{
        cout << "Please enter the name of book from: " + nameInput << endl;
        for(int i = 0; i < allBooks[bookIndex].books.size(); i++){
            if(allBooks[bookIndex].books[i].isTaken != true){
                cout << allBooks[bookIndex].books[i].name << endl;}
        }
        getline(cin, nameInput);
        findName(allBooks, nameInput);
    }
}
void returnBook(vector<book>& allBooks, string nameInput){
    int end = allBooks.size() - 1;
    int bookIndex = quickFindAuthor(allBooks, nameInput, 0, end);
    if(bookIndex == -1){
        findNameReturn(allBooks, nameInput);
    }
    else{
        cout << "Please enter the name of book from: " + nameInput << endl;;
        for(int i = 0; i < allBooks[bookIndex].books.size(); i++){
            if(allBooks[bookIndex].books[i].isTaken != false){
                cout << allBooks[bookIndex].books[i].name << endl;}
        }
        getline(cin, nameInput);
        findNameReturn(allBooks, nameInput);
    }
}
void bookReport(vector<book>& allBooks){
    cout << endl;
    cout << "Taken books: " << endl;
    for(int i = 0; i < allBooks.size(); i++){
        for(int j = 0; j < allBooks[i].books.size(); i++){
            if(allBooks[i].books[j].isTaken == true){
                cout << allBooks[i].books[j].name << endl;
            }
        }
    }
    cout << endl;
    cout << "Avaliable books: " << endl;
    for(int i = 0; i < allBooks.size(); i++){
        for(int j = 0; j < allBooks[i].books.size(); i++){
            if(allBooks[i].books[j].isTaken == false){
                cout << allBooks[i].books[j].name << endl;
            }
        }
    }
}
int main()
{
    vector<book> booksList;
    fillBookList(booksList);
    sortBooks(booksList);
    string command;
    string name;
    cout << "Please enter what do you want to do (avaliable commands ` 'Take', 'Return', 'Book report', 'End'): ";
    getline(cin, command);
    command[0] = toupper(command[0]);
    while(command != "Take" and command != "Return" and command != "Book report" and command != "End"){
        cout << "Please enter avaliable command! ";
        getline(cin, command);
        command[0] = toupper(command[0]);
    }
    while(command != "End"){
        if(command == "Take"){
            cout << "Please enter name of author or book you want to borrow: ";
            getline(cin, name);
            name[0] = toupper(name[0]);
            borrowBook(booksList, name);
        }
        else if(command == "Return"){
            cout << "Please enter name of author or book you want to return: ";
            getline(cin, name);
            name[0] = toupper(name[0]);
            returnBook(booksList, name);
        }
        else{
            bookReport(booksList);
        }
        cout << "Please enter what do you want to do (avaliable commands ` 'Take', 'Return', 'Book report', 'End'): ";
        getline(cin, command);
        command[0] = toupper(command[0]);
        while(command != "Take" and command != "Return" and command != "Book report" and command != "End"){
            cout << "Please enter avaliable command! ";
            getline(cin, command);
            command[0] = toupper(command[0]);
    }
    }

    return 0;
}