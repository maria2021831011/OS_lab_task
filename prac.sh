month=$(date +%B)

if [ "$month" = "October" ]; then
    echo "Yes, it's October!"
else
    echo "No,it's not Octobe. It's $month."
fi
