g++ -c treenode/treenode.cpp -o treenode.o
g++ main.cpp -o main -I . ./treenode.o
./main

# remove some alternvtive file

if [ -f ./treenode.o ] 
then 
  rm ./treenode.o
fi

if [ -f ./main ] 
then 
  rm ./main
fi
