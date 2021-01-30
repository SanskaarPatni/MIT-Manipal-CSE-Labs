echo Enter values for a,b and c
read a
read b
read c
d=`expr $b \* $b - 4 \* $a \* $c`
echo $d
