stop=0
while [ $stop -eq 0 ]
do
echo 1 to print date
echo 2 or 4 to print directory
echo 3 to stop
echo WHats your chwaisce
read ye
case $ye in 
1)
date
;;
2|4)
pwd
;;
3)
stop=1
;;
esac
done
echo Ihope i get the correct answer
