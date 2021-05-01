@echo off

chcp 1251

@javac -encoding utf8 stackarray\Main.java

java -classpath . stackarray.Main

pause
