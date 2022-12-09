#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
using namespace std;

string rot13(string text, map<char, char> mapping) {
    string cipher_shift = "";
    for (int i = 0; i < text.length(); i++) {
        if (mapping.count(text[i])) cipher_shift += mapping[text[i]];
        else cipher_shift += text[i];
    }
    return cipher_shift;
}

void test_cipher() {
    // check if encryption works
    ifstream file_1("../OGtext.txt");
    string text_1((std::istreambuf_iterator<char>(file_1)),
                (std::istreambuf_iterator<char>()));
    file_1.close();
    ifstream file_2("../decrypted.txt");
    string text_2((std::istreambuf_iterator<char>(file_2)),
                (std::istreambuf_iterator<char>()));
    file_2.close();
    if (text_1 == text_2) cout << true << '\n';
    else cout << false << '\n';

    cout << text_1.length() << '\n';
    cout << text_2.length() << '\n';
}

int main() {
    char choice;
    while (choice != 'e' and choice != 'd') {
        cout << "Want to encrypt or decrypt your cipher? Input e/d: ";
        cin >> choice;
    }

    map<char, char> mapping;
    for (int i = 0; i < 26; i++) {
        mapping.insert(make_pair<char, char> ('a' + i, ((i + 13) % 26) + 'a'));
        mapping.insert(make_pair<char, char> ('A' + i, ((i + 13) % 26) + 'A'));
    }

    if (choice == 'e') {
        ifstream ifs("../OGtext.txt");
        string text((std::istreambuf_iterator<char>(ifs)),
                    (std::istreambuf_iterator<char>()));
        ifs.close();
        ofstream encrypted("../encrypted.txt");
        encrypted << rot13(text, mapping);
        encrypted.close();
    }

    if (choice == 'd') {
        ifstream ifs("../encrypted.txt");
        string text((std::istreambuf_iterator<char>(ifs)),
                    (std::istreambuf_iterator<char>()));
        ifs.close();
        ofstream decrypted("../decrypted.txt");
        decrypted << rot13(text, mapping);
        decrypted.close();
    }
    
    test_cipher();
}