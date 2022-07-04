#!/bin/sh
#java -jar /mnt/c/Javalib/antlr-4.10.1-complete.jar -Dlanguage=Cpp -no-listener -visitor -o libs ObjectPascalLexer.g4
#java -jar /mnt/c/Javalib/antlr-4.10.1-complete.jar -Dlanguage=Cpp -no-listener -visitor -o libs ObjectPascalParser.g4

java -jar /usr/local/lib/antlr-4.10.1-complete.jar -Dlanguage=Cpp -no-listener -visitor -o libs ObjectPascalLexer.g4
java -jar /usr/local/lib/antlr-4.10.1-complete.jar -Dlanguage=Cpp -no-listener -visitor -o libs ObjectPascalParser.g4

gcc -Wall -pedantic -g -c -o build/inc.o inc.c

cd build
bash build.sh
