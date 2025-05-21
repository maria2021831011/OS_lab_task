echo "enter file name"
read  name
if [ -f $name ]
then
    echo "exist"
else
      touch $name
fi
