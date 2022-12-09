#include <iostream>
#include <ctype.h>
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

int main(int argc, char *argv[]) {
    char choice;
    if (argc == 2 && isalpha(*argv[1])) choice = *argv[1];
    else return 0;

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
}