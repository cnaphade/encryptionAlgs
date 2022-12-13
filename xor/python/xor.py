import argparse

def xor(text, password):
	cipher_text = ""
	for i in range(len(text)):
		cipher_text += chr(ord(text[i]) ^ ord(password[i % len(password)]))
	return cipher_text

def main():
	parser = argparse.ArgumentParser()
	parser.add_argument("--password")
	parser.add_argument("--in_file")
	parser.add_argument("--out_file")
	args = parser.parse_args()

	file = open(args.in_file, "rb")
	text = file.read()
	file.close()

	e_text = open(args.out_file, 'wb')
	e_text.write(xor(text.decode(), args.password).encode())
	e_text.close()

main()
