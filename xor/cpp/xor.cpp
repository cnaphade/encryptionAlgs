#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>
#include <cstring>
#include <iterator>
using namespace std;

string xor_cipher(string text, string password) {
	string cipher_text = "";
	for (int i = 0; i < text.length(); i++) {
		cipher_text += text[i] ^ password[i % password.length()];
	}
	return cipher_text;
}

int main(int argc, char *argv[]) {
	string password;
	string in_file;
	string out_file;
	if (argc == 4) {
		password = argv[1];
		in_file = argv[2];
		out_file = argv[3];
	}
	else return 0;

	ifstream ifs(in_file, ios::in | ios::binary);
	string text((istreambuf_iterator<char>(ifs)),
				(istreambuf_iterator<char>()));
	ifs.close();
	string cipher_text = xor_cipher(text, password);
	ofstream encrypted(out_file, ios::out | ios::binary);
	encrypted.write(cipher_text.c_str(), cipher_text.length());
	encrypted.close();
}