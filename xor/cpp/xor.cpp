#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>
#include <iterator>
using namespace std;

string generate_full_key(string text, string password) {
	string key = "";
	for (int i = 0; i < text.length(); i++) {
		key += password[i % password.length()];
	}
	return key;
}

string xor_cipher(string text, string password) {
	string key = generate_full_key(text, password);
	string cipher_text = "";
	for (int i = 0; i < text.length(); i++) {
		cipher_text += text[i] ^ key[i];
	}
	return cipher_text;
}

int main(int argc, char *argv[]) {
	char choice;
	string password;
	if (argc == 3 && isalpha(*argv[1])) {
		choice = *argv[1];
		password = argv[2];
	}
	else return 0;

	if (choice == 'e') {
		ifstream ifs("../OGtext.txt");
		string text((istreambuf_iterator<char>(ifs)),
					(istreambuf_iterator<char>()));
		ifs.close();
		ofstream encrypted("../encrypted.txt");
		encrypted << xor_cipher(text, password);
		encrypted.close();
	}

	if (choice == 'd') {
		ifstream ifs("../encrypted.txt");
		string text((istreambuf_iterator<char>(ifs)),
					(istreambuf_iterator<char>()));
		ifs.close();
		ofstream decrypted("../decrypted.txt");
		decrypted << xor_cipher(text, password);
		decrypted.close();
	}
}