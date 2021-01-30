echo loop index
read index
i=0
while [ $i -lt $index ]
do
	echo $i
	i=`expr $i + 1`
done