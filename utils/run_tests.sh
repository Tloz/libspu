#!/bin/bash
echo -e "Running all tests for libspu."
for progTest in bin/test_*
do
    echo -ne "\nRunning "
    SHORTNAME=$(echo $progTest | cut -d'/' -f2) #| cut -d'_' -f2-
    #echo "$progTest" | cut -d'/' -f2 #| cut -d'_' -f2-
    echo "$SHORTNAME"
    ./"$progTest"
    if [ $? != 0 ]
    then
        echo -e "\n$SHORTNAME failed. Aborting"
        exit 127
    else
        echo -e "\n$SHORTNAME passed !"
    fi
done

echo -e "\nAll tests passed succesfully, ready to build."
