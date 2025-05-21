if [ -d $1 ]
then
     echo " exist"
else
     mkdir $2
     echo " created"
fi
