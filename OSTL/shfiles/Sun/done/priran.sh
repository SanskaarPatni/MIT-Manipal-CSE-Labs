echo Enter lower limit n
read n
echo Enter upper limit f
read f
i=2
p=$n
flag=0
num=$n
while [ $p -lt $f ]
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
			echo $num
		fi
		p=`expr $p + 1`
		num=`expr $num + 1`
done