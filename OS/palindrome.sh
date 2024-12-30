
echo "enter a number"
read n
rev=0
org=$n
 while [ $n -ne  0 ]
 do
 i=$(($n%10))
 rev=$((i+ $rev * 10))
 n=$(($n/10))
 done 
 if [ $org -eq $rev ] 
 then
 echo "$org is palindrome"
 else 
 echo "$org is not palindrome"
 fi
 

