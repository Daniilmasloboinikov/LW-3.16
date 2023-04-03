clang++ main.cpp -o main
./main < 03-example.input.txt > 03-example.actual.txt
diff -w 03-example.expected.txt 03-example.actual.txt

