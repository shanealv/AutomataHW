flex hw3.l
gcc hw3.c

echo "===== Valid Cases ====="
while IFS= read -r line
do
	printf '[test case]: %s\n' "$line"
	echo "$line" | ./a.out
	printf "\n"
done < "valid.txt"
printf "\n\n"
echo "==== Invalid Cases ===="
while IFS= read -r line
do 
	printf '[test case]: %s\n' "$line"
	echo "$line" | ./a.out
	printf "\n"
done < "invalid.txt"

