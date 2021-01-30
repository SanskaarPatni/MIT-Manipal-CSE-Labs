echo Enter number of elements of the array
read n
declare -a array
i=0
j=0
while [ $i -lt $n ]
do
	echo enter element
	read ele
    array[$i]=$ele
    i=`expr $i + 1`
done
echo Array elements are ${array[*]}
lar=${array[0]}
seclar=${array[0]}
#for j in ${!array[*]}
while [ $j -lt $n ]
do 
	if [ ${array[$j]} -gt $lar ]
	then 
	seclar=`expr $lar`		
	lar=`expr ${array[$j]}`
	j=`expr $j + 1`	
    elif [ ${array[$j]} -lt $lar ] && [ ${array[$j]} -gt $seclar ]
    	then
    		seclar=`expr ${array[$j]}`
    		j=`expr $j + 1`	
    else
    j=`expr $j + 1`	
fi
done
echo $seclar





