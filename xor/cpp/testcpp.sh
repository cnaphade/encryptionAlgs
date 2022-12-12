#! /bin/bash
arg="random"
pass="password"
if [ "$1" = $arg ]
	then
		openssl rand -base64 32 > ../OGtext.txt
		pass=$(openssl rand -base64 12)
fi

echo $pass
./xor e $pass
./xor d $pass

if cmp -s "../OGtext.txt" "../decrypted.txt"
	then
		echo Algorithm Works!
	else
		echo Files Differ!
fi