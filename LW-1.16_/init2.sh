clang++ main.cpp -o main
./main < 02-example.input.txt > 02-example.actual.txt 
diff -w 02-example.expected.txt 02-example.actual.txt

