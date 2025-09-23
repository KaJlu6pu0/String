#include <iostream>
#include <cstring>

using namespace std;

class String {
    char* string;
    int length;

public:
    String() {
        length = 80;
        string = new char[length + 1];
        string[0] = '\0';
    }

    String(int size) {
        length = size;
        string = new char[length + 1];
        string[0] = '\0';
    }

    String(const char* s) {
        length = static_cast<int>(strlen(s));
        string = new char[length + 1];
        strcpy_s(string, length + 1, s);
    }

    String(const String& other) {
        length = other.length;
        string = new char[length + 1];
        strcpy_s(string, length + 1, other.string);
    }

    void input() {
        char buffer[248];
        cout << "Enter string: ";
        cin.getline(buffer, 248);

        delete[] string;
        length = static_cast<int>(strlen(buffer));
        string = new char[length + 1];
        strcpy_s(string, length + 1, buffer);
    }

    void output() const {
        cout << string << endl;
    }

    ~String() {
        delete[] string;
    }
};

int main() {
    String s1;
    String s2;
    String s3;

    s1.input();
    std::cout << "s1: ";
    s1.output();

    s2.input();
    std::cout << "s2: ";
    s2.output();

    s3.input();
    std::cout << "s3: ";
    s3.output();

    String s4(s3);
    std::cout << "(copy of): ";
    s4.output();
}
