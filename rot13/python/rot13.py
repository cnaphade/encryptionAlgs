import os.path
import argparse

def rot13(text, mapping):
    cipher_shift = ""
    for i in range(len(text)):
        cipher_shift += mapping.get(text[i], text[i])
    return cipher_shift

def main():
    mapping = {}
    for i in range(26):
        mapping[chr(i + ord('a'))] = chr((i + 13) % 26 + ord('a'))
        mapping[chr(i + ord('A'))] = chr((i + 13) % 26 + ord('A'))
    
    text_path = os.path.dirname(os.getcwd())
    parser = argparse.ArgumentParser()
    parser.add_argument("--choice")
    args = parser.parse_args()

    if args.choice == 'e':
        file = open(text_path + '/OGtext.txt')
        text = file.read()

        e_text = open(text_path + "/encrypted.txt", 'w')
        e_text.write(rot13(text, mapping))
        e_text.close()

    if args.choice == 'd':
        file = open(text_path + '/encrypted.txt')
        text = file.read()

        d_text = open(text_path + "/decrypted.txt", 'w')
        d_text.write(rot13(text, mapping))
        d_text.close()

main()