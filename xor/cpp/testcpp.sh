#! /bin/bash
random="true"
pass="password"
og_file=../OGtext.txt
en_file=../encrypted.txt
de_file=../decrypted.txt

for i in {0..40}
do
	if [ "$1" = $random ]
		then
			file_size=$(( $RANDOM * 300 ))
			pass_size=$(( $RANDOM % 50 + 1 ))
			openssl rand $file_size > $og_file
			pass=$(openssl rand $pass_size | base64)
	fi

	./xor $pass $og_file $en_file
	./xor $pass $en_file $de_file

	if cmp -s $og_file $de_file
		then
			pass_size=$(( $RANDOM % 10 + 1 ))
			pass=$(openssl rand $pass_size | base64 )
			./xor $pass $en_file $de_file
			if cmp -s $og_file $de_file
				then
					echo "password: " $pass
					echo "password size: " ${#pass}
					echo "test pass: " $pass
					echo "test pass size: " $pass_size
					echo $i Failure!
				else
					echo $i Algorithm Works!
			fi
		else
			echo "password: " $pass
			echo "password size: " ${#pass}
			echo $i Failure!
	fi
done