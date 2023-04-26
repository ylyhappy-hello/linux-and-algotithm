#!/bin/bash

read -p "Enter The Users Password : " PASSWD
for UNAME in `cat users.txt`
do 
  id $UNAME &> /dev/null
  if [ $? -eq 0 ]
  then
    echo "$UNAME , Already exists"
  else
    useradd $UNAME &> /dev/null
    echo "$PASSWD" | passwd --stdin $UNAME &> /dev/null
    echo "$UNAME , Create success"
  fi 
done
