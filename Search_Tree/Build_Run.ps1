# Generate lib
g++ -c .\src\i.cxx -o .\bin\Tree.o
g++ -shared -fPIC -o .\bin\libTree.dll .\bin\Tree.o

# Compile
g++ .\Demo.cpp -g -O0 -o .\bin\Demo.exe -I .\include -L.\bin -lTree -Wall -std=c++17 

# run
.\bin\Demo