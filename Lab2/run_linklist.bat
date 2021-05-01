@echo off

chcp 1251

@javac -encoding utf8 linklist\Main.java

java -classpath . linklist.Main

pause
