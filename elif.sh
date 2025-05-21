if [ -f  $1 ]
then
     echo "ffile  exist"
elif [ -d $1 ]
then
     echo " dir have"
else
     echo "none"
fi
