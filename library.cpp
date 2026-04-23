#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
using namespace std;
void fillBookList(unordered_map<string, vector<string>>& booksList, unordered_map<string, bool>& nameList){
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
        nameList[name] = false;
        booksList[author].push_back(name);
    }
}
void borrowBook(unordered_map<string, vector<string>> booksList, unordered_map<string, bool>& nameList, string nameOfBook){
    if(nameList.find(nameOfBook) != nameList.end()){
        if(nameList[nameOfBook] == false){
            nameList[nameOfBook] = true;
            cout << "You take " + nameOfBook + "." << endl; 
        }
        else{
            cout << "Sorry, this book is already taken." << endl;
        }
    }
    else if(booksList.find(nameOfBook) != booksList.end()){
        string name;
        cout << "Please input name of book from this author, the avaliable book is:" << endl;
            for(int i = 0; i < (booksList[nameOfBook]).size(); i++){
                if(nameList[booksList[nameOfBook][i]] == false){
                    cout << booksList[nameOfBook][i] << endl;
        }}
        getline(cin, name);
        borrowBook(booksList, nameList, name);
    }
    else{
        cout << "Sorry not such a book or author." << endl;
    }}
void returnBook(unordered_map<string, vector<string>> booksList, unordered_map<string, bool>& nameList, string nameOfBook){
    if(nameList.find(nameOfBook) != nameList.end()){ // if the book's name is not found in this list (list of book names), then we have to check if it exist in the list of author
        if(nameList[nameOfBook] == true){
            nameList[nameOfBook] = false;
            cout << "You return " + nameOfBook + ", thank you." << endl; 
        }
        else{
            cout << "Sorry, this book isn't taken. Are you sure you take it?" << endl;
        }
    }
    else if(booksList.find(nameOfBook) != booksList.end()){ // if user input exist in the list of author, the system will suggest name of the book from this author
        string name;
        cout << "Please enter wich book do you want to return:" << endl;
        for(int i = 0; i < (booksList[nameOfBook]).size(); i++){
            if(nameList[booksList[nameOfBook][i]] == true){
                cout << booksList[nameOfBook][i] << endl;
        }}
        getline(cin, name);
        returnBook(booksList, nameList, name);
    }
    else{
        cout << "Sorry not such a book or author." << endl;
    }
}
void bookReport(unordered_map<string, bool> nameList){
    cout << endl;
    cout << "Taken books is: ";
    for(auto x : nameList){
        if(x.second == true){
            cout << x.first << endl;
        }
    }
    cout << endl;
    cout << "Avaliable books is: ";
    for(auto x : nameList){
        if(x.second == false){
            cout << x.first << endl;
        }
    }
}
int main()
{
    unordered_map<string, vector<string>> booksList; //dictionary of author(string) : nameBook(vector<int>) (we have books more then one from each author, so if user input name of author, the system will suggest name of book of that author to input)
    unordered_map<string, bool> nameList; //dictonary of nameBook(string) : isTaken(bool) (each book as value has bool(taken or not))
    fillBookList(booksList, nameList);
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
            borrowBook(booksList, nameList, name);
        }
        else if(command == "Return"){
            cout << "Please enter name of author or book you want to return: ";
            getline(cin, name);
            name[0] = toupper(name[0]);
            returnBook(booksList, nameList, name);
        }
        else{
            bookReport(nameList);
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
