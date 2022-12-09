#! /bin/bash
if cmp -s "OGtext.txt" "decrypted.txt"
then
echo Algorithm Works!
else
echo Files Differ!
fi