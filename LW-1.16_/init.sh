clang++ main.cpp -o main
./main < 01-example.input.txt > 01-example.actual.txt 2
diff -w 01-example.expected.txt 01-example.actual.txt
