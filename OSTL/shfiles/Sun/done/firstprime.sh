echo Enter limit n
read n
echo Finding first $n prime numbers
x=0
i=2
num=2
flag=0
p=0
while [ $p -lt $n ]
do	
	flag=0
	i=2
	while [ $i -le $((num/2)) ]
		do
			if [ `expr $num % $i` -eq 0 ]
			then
				flag=1
				break
			else
				i=`expr $i + 1`
			fi
		done
		if [ $flag -eq 0 ]
		then
			p=`expr $p + 1`
			echo $num
		fi
		num=`expr $num + 1`
done