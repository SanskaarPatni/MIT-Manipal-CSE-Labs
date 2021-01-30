sum=0
echo enter number
read n
echo when user will type -819 it will show the sum
while [ n != -819 ]
do
	sum=`expr $sum + $n`
	read n
	if [ $n -eq -819 ]
	then 
		break
	fi

done
echo Sum is $sum
