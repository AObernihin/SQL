#include <iostream>
#include <string>
#include <algorithm>



using namespace std;
//книги
struct Book {
    string title;
    string author;
    string publisher;
    string genre;
};


void editBook(Book& book, const string& title, const string& author, const string& publisher, const string& genre) {
    book.title = title;
    book.author = author;
    book.publisher = publisher;
    book.genre = genre;
}


void printBooks(const Book books[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Title: " << books[i].title << ", Author: " << books[i].author
            << ", Publisher: " << books[i].publisher << ", Genre: " << books[i].genre << endl;
    }
}


void searchByAuthor(const Book books[], int size, const string& author) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (books[i].author == author) {
            cout << "Found book by " << author << ": " << books[i].title << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No books found by author " << author << endl;
    }
}


void searchByTitle(const Book books[], int size, const string& title) {
    for (int i = 0; i < size; i++) {
        if (books[i].title == title) {
            cout << "Found book with title " << title << ": " << books[i].author << ", " << books[i].publisher << endl;
            return;
        }
    }
    cout << "No book found with title " << title << endl;
}


void sortByTitle(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.title < b.title;
        });
}


void sortByAuthor(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.author < b.author;
        });
}


void sortByPublisher(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.publisher < b.publisher;
        });
}
//==================================машина
struct car {
    string color;
    string model;
    union {
        int intnum;
        char strnum[8];
    } number;
};

void InitCar(car* car) 
{
    int type;
    cout << "enter color:";
    cin >> car->color;
    cout << "enter model:";
    cin >> car->model;
    cout << "enter type of number:";
    cin >> type;
    cout << "enter num:";
    if (type == 0) 
    {
        cin >> car->number.strnum;
    }
    else if (type == 1) 
    {
        cin >> car->number.intnum;
    }
    else {
        cout << "incorrect input" << endl;
    }
}
void PrintCar(car car,int type) 
{
    if (type == 0)
    {
        cout << car.color << ";" << car.model << ";" << car.number.strnum << endl;
    }
    else if (type == 1)
    {
        cout << car.color << ";" << car.model << ";" << car.number.intnum << endl;
    }
    else {
        cout << "incorrect input" << endl;
    }   
}

void EditCar(car& car, const string& color , const string& model , const int number) {
    car.color = color;
    car.model = model;
    car.number.intnum = number;
}
void EditCar(car& car, const string& color, const string& model, const char number[]) {
    car.color = color;
    car.model = model;
    size_t length = strlen(number); 
    if (length >= sizeof(car.number.strnum)) 
    { length = sizeof(car.number.strnum) - 1; } 
    for (size_t i = 0; i < length; ++i) 
    { car.number.strnum[i] = number[i]; } 
    car.number.strnum[length] = '\0';
}
void PrintCars(car car[], int SIZE)
{
    for (int i = 0; i < SIZE; i++) 
    {
        cout << car[i].color << endl;
        cout << car[i].model << endl;
        cout << car[i].number.intnum << endl;
        cout << "=====" << endl;
    }
}
void SearchByNum(car cars[], int SIZE, int num) 
{
    bool found = false;
    for (int i = 0; i < SIZE; i++)
    {
        if (cars[i].number.intnum == num)
        {
            cout << "car with this num was found in " << i + 1 << " element" << endl;
            found = true ;
        }
    }
    if (!found) 
    {
    cout << "there`s no car with this number in massive" << endl;   
    }
}
//==================================================жива тварь
enum Type {
    Bird,
    Cattle,
    Human
};

struct LivingEntity {
    double speed;      
    Type type;         
    string color;      

    
    union Characteristic {
        double flightSpeed;     
        bool isEvenToed;        
        int iq;                 
    } characteristic;

    
    void input() {
        cout << "Enter movement speed: ";
        cin >> speed;

        int typeChoice;
        cout << "Enter type (0 = Bird, 1 = Cattle, 2 = Human): ";
        cin >> typeChoice;
        type = static_cast<Type>(typeChoice);

        cout << "Enter color: ";
        cin >> color;

       
        switch (type) {
        case Bird:
            cout << "Enter flight speed for Bird: ";
            cin >> characteristic.flightSpeed;
            break;
        case Cattle:
            cout << "Is it even-toed? (1 = Yes, 0 = No): ";
            cin >> characteristic.isEvenToed;
            break;
        case Human:
            cout << "Enter IQ level for Human: ";
            cin >> characteristic.iq;
            break;
        }
    }

    void print() const {
        cout << "Movement speed: " << speed << endl;
        cout << "Type: " << (type == Bird ? "Bird" : type == Cattle ? "Cattle" : "Human") << endl;
        cout << "Color: " << color << endl;

      
        switch (type) {
        case Bird:
            cout << "Flight speed: " << characteristic.flightSpeed << endl;
            break;
        case Cattle:
            cout << "Is even-toed: " << (characteristic.isEvenToed ? "Yes" : "No") << endl;
            break;
        case Human:
            cout << "IQ level: " << characteristic.iq << endl;
            break;
        }
    }
};


    void editEntity(LivingEntity& entity) {
       
        entity.input();
    }


    void printAllEntities(LivingEntity entities[], int size) {
        for (int i = 0; i < size; ++i) {
            cout << "Entity #" << (i + 1) << ":" << endl;
            entities[i].print();
            cout << "============="  << endl;
        }
    }

    void searchByCharacteristic(LivingEntity entities[], int size, int iqLevel) {
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (entities[i].type == Human && entities[i].characteristic.iq == iqLevel) {
                cout << "Entity found with IQ level " << iqLevel << ":" << endl;
                entities[i].print();
                found = true;
            }
        }
        if (!found) {
            cout << "No entity found" << endl;
        }
    }


int main() {
    /*const int SIZE = 10;
    Book library[SIZE] = {
        {"Book1", "AuthorA", "PublisherX", "Genre1"},
        {"Book2", "AuthorB", "PublisherY", "Genre2"},
        {"Book3", "AuthorA", "PublisherX", "Genre1"},
        {"Book4", "AuthorC", "PublisherZ", "Genre3"},
        {"Book5", "AuthorB", "PublisherY", "Genre2"},
        {"Book6", "AuthorD", "PublisherX", "Genre1"},
        {"Book7", "AuthorE", "PublisherW", "Genre4"},
        {"Book8", "AuthorA", "PublisherZ", "Genre3"},
        {"Book9", "AuthorC", "PublisherX", "Genre1"},
        {"Book10", "AuthorF", "PublisherY", "Genre5"}
    };


    printBooks(library, SIZE);


    searchByAuthor(library, SIZE, "AuthorA");


    searchByTitle(library, SIZE, "Book5");


    sortByTitle(library, SIZE);
    printBooks(library, SIZE);


    sortByAuthor(library, SIZE);
    printBooks(library, SIZE);


    sortByPublisher(library, SIZE);
    printBooks(library, SIZE);*/
    //=====================================
    //car cars[5]
        // я не зміг вручну ініціалізувати номера стрінгові, видає помилку(, не зміг зрозуміти до кінця як працювати з стрінгою в юніон
    /*{
        {"white", "miata1", 1},
        {"pink", "miata2", 2347},
        {"black", "miata3", 3},
        {"purple", "miata4", 4},
        {"purple", "miata5", 5}
    };
    PrintCars(cars, 5);
    SearchByNum(cars, 5, 2347);*/
    //============================
    const int SIZE = 10;
    LivingEntity entities[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        cout << "Enter data for entity #" << (i + 1) << ":" << endl;
        entities[i].input();
        
    }
    
    
    //2347


}