import argparse

def xor(text, password):
	cipher_text = bytearray()
	for i in range(len(text)):
		cipher_text.extend((int.from_bytes(text[i:i+1], byteorder='big') ^ password[i % len(password)]).to_bytes(1, byteorder='big'))
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
	e_text.write(xor(text, args.password.encode()))
	e_text.close()

main()
