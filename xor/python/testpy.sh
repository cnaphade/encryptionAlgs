#! /bin/bash
arg="random"
pass="password"
if [ "$1" = $arg ]
	then
		file_size=$(( RANDOM * 300 ))
		pass_size=$(( $RANDOM % 50 + 1 ))
		openssl rand -base64 $file_size > ../OGtext.txt
		pass=$(openssl rand -base64 $pass_size)
		echo "file size: " $file_size
fi

echo "password: " $pass
echo "password size: " ${#pass}
python3 xor.py --choice e --password $pass --in_file $2 --out_file $3
python3 xor.py --choice d --password $pass --in_file $3 --out_file $4

if cmp -s $2 $4
	then
		pass_size=$(( $RANDOM % 10 + 1 ))
		echo "test pass size: " $pass_size
		pass=$(openssl rand -base64 $pass_size)
		python3 xor.py --choice d --password $pass --in_file $3 --out_file $4
		if cmp -s $2 $4
			then
				echo Failure!
			else
				echo Algorithm Works!
		fi
	else
		echo Failure!
fi