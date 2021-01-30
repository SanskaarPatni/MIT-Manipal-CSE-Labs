c=0
len=`expr length $1`
i=1
echo $len
while [ $i -le $len ]
do
	p=`expr substr $1 $i 1`
	case $p in
		[aeiouAEIOU])
	c=`expr $c + 1`
	;;
	esac
	i=$((i + 1))
done
echo $c
