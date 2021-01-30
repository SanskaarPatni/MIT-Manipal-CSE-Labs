echo Enter a mf number
read num
rev=0
dig=0
while [ $num -gt 0 ]
do
	dig=$((num%10))
	num=$((num/10))
	rev=`expr $rev \* 10 + $dig`
done
echo $rev
