import os.path
import argparse

def generate_full_key(text, password):
	key = ""
	for i in range(len(text)):
		key += password[i % len(password)]
	return key

def xor(text, password):
	key = generate_full_key(text, password)
	cipher_text = ""
	for i in range(len(text)):
		cipher_text += chr(ord(text[i]) ^ ord(key[i]))
	return cipher_text

def main():
	text_path = os.path.dirname(os.getcwd())
	parser = argparse.ArgumentParser()
	parser.add_argument("--choice")
	parser.add_argument("--password")
	args = parser.parse_args()

	if args.choice == 'e':
		file = open(text_path + '/OGtext.txt', "rb")
		text = file.read()
		file.close()

		e_text = open(text_path + '/encrypted.txt', 'wb')
		e_text.write(xor(text.decode(), args.password).encode())
		e_text.close()

	if args.choice == 'd':
		file = open(text_path + '/encrypted.txt', "rb")
		text = file.read()
		file.close()

		d_text = open(text_path + '/decrypted.txt', 'wb')
		d_text.write(xor(text.decode(), args.password).encode())
		d_text.close()

main()
