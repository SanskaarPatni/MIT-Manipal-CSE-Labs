echo Enter a string
read str
n=`expr length $str`
echo The length of the string is $n
i=1
flag=0
while [ $i -le $(($n/2)) ]
do
	opp=`expr $n - $i + 1`
	if [ `expr substr $str $i 1` != `expr substr $str $opp 1` ]
	then 
		echo Not a Palindrome
		flag=1
		break
	fi
	i=`expr $i + 1`
done
if [ $flag -eq 0 ]
then 
	echo String is palindrome
fi


