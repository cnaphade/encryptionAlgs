#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>
#include <cstring>
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
		ifstream ifs("../OGtext.txt", ios::in | ios::binary);
		string text((istreambuf_iterator<char>(ifs)),
					(istreambuf_iterator<char>()));
		ifs.close();
		string cipher_text = xor_cipher(text, password);
		ofstream encrypted("../encrypted.txt", ios::out | ios::binary);
		encrypted.write(cipher_text.c_str(), cipher_text.length());
		encrypted.close();
	}

	if (choice == 'd') {
		ifstream ifs("../encrypted.txt", ios::in | ios::binary);
		string text((istreambuf_iterator<char>(ifs)),
					(istreambuf_iterator<char>()));
		ifs.close();
		string cipher_text = xor_cipher(text, password);
		ofstream decrypted("../decrypted.txt", ios::out | ios::binary);
		decrypted.write(cipher_text.c_str(), cipher_text.length());
		decrypted.close();
	}
}