echo Enter a string
read str
n=`expr length $str`
echo The lengt of the string is $n
i=1
flag=0
j=`expr $n / 2`
while [ $i -le $j ]
do
	if [ `expr substr $str $i 1` -eq `expr substr $str $n-$i+1 1` ]
	then 
		$flag=1
	else 
		$flag=0
	fi
done
if [ $flag -eq 1 ]
then 
	echo String is palindrome
else 
	echo String is not  apalindrome
fi


