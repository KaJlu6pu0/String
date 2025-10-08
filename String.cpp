#include <iostream>
#include <cstring>

using namespace std;

class String {
    char* str;
    int length;
    static int count;

public:
    String() : String(80) {}

    String(int size)
        : length(size), str(new char[size + 1]) {
        str[0] = '\0';
        ++count;
    }

    String(const char* s)
        : length(static_cast<int>(strlen(s))), str(new char[length + 1]) {
        strcpy_s(str, length + 1, s);
        ++count;
    }

    String(const String& other)
        : length(other.length), str(new char[other.length + 1]) {
        strcpy_s(str, length + 1, other.str);
        ++count;
    }

    String(String&& other) noexcept
        : str(other.str), length(other.length) {
        other.str = nullptr;
        other.length = 0;
        ++count;
        cout << "[Move constructor called]" << endl;
    }

    void input() {
        char buffer[248];
        cout << "Enter string: ";
        cin.getline(buffer, 248);

        delete[] str;
        length = static_cast<int>(strlen(buffer));
        str = new char[length + 1];
        strcpy_s(str, length + 1, buffer);
    }

    void output() const {
        cout << str << endl;
    }

    static int getCount() {
        return count;
    }

    ~String() {
        delete[] str;
        --count;
    }
};

int String::count = 0;

int main() {
    String s1;
    String s2(20);
    String s3("Hello, world!");

    cout << "s1: "; s1.output();
    cout << "s2: "; s2.output();
    cout << "s3: "; s3.output();

    cout << "Objects created: " << String::getCount() << endl;

    s1.input();
    cout << "s1 (new): "; s1.output();

    String s4(s3);
    cout << "s4 (copy of s3): "; s4.output();

    cout << "Objects created: " << String::getCount() << endl;

    String s5(std::move(s3));
    cout << "s5 (moved from s3): "; s5.output();
    cout << "s3 (after move): "; s3.output();

    cout << "Objects created: " << String::getCount() << endl;
}
