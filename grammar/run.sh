#!/bin/sh
java -jar /usr/local/lib/antlr-4.10.1-complete.jar -Dlanguage=Cpp -no-listener -visitor -o libs ObjectPascalLexer.g4
java -jar /usr/local/lib/antlr-4.10.1-complete.jar -Dlanguage=Cpp -no-listener -visitor -o libs ObjectPascalParser.g4

cd build
bash build.sh
