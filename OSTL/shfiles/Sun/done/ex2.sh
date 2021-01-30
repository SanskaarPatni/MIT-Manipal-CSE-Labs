echo Enter n:
read n
x=1
c=1
while [ $c -le $n ]
do 
echo $x
x=`expr $x + 2`
c=`expr $c + 1`
done
