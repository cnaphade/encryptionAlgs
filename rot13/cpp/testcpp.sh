#! /bin/bash
./rot13 e
./rot13 d
if cmp -s "../OGtext.txt" "../decrypted.txt"
then
echo Algorithm Works!
else
echo Files Differ!
fi