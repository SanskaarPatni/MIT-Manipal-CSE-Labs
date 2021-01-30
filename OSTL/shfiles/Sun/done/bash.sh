echo Enter a number 
read num
if [ $num -lt 0 ]
then
	k=0
else
	k=1
fi

case $k in
	0)
echo Negative Number
;;
1)
root=$(bc<<<"scale=2 ; sqrt($num)")
echo root is $root
;;
esac
