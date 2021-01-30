echo Enter number of elements of the array
read n
declare -a array
i=0;
j=0;
while [ $i -lt $n ]
do
	echo enter element
	read ele
    array[i]=`expr $ele`
    i=`expr $i + 1`
done
lar=${array[0]}
seclar=${array[0]}
while [ $j -lt $n ]
do 
	if [ ${array[j]} -gt $lar ]
	then 
		lar=${array[j]}
		seclar=$lar
		j=`expr $j + 1`
    elif [ ${array[j]} -gt $seclar ] || [ ${array[$j]} -lt $lar ]
    	then
    		seclar=${array[$j]}
    		j=`expr $j + 1`
	else 
		j=`expr $j +1`
fi
done
echo $seclar





