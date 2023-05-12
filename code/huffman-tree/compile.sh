g++ -c treenode/treenode.cpp -o treenode.o
g++ main.cpp -o main -I . ./treenode.o
./main
