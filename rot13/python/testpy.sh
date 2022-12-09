#! /bin/bash
python3 rot13.py --choice e
python3 rot13.py --choice d
if cmp -s "../OGtext.txt" "../decrypted.txt"
then
echo Algorithm Works!
else
echo Files Differ!
fi