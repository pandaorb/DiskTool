CC = g++
CFLAGS = -c

project2: command.o commandLine.o configInfo.o diskStat.o report.o tool.o project2_demo.cpp
	$(CC) command.o commandLine.o configInfo.o diskStat.o report.o tool.o project2_demo.cpp -o project2
command.o: command.cpp command.h
	$(CC) $(CFLAGS) command.cpp
commandLine.o: commandLine.cpp commandLine.h command.h
	$(CC) $(CFLAGS) commandLine.cpp
configInfo.o: configInfo.cpp configInfo.h
	$(CC) $(CFLAGS) configInfo.cpp
diskStat.o: diskStat.cpp diskStat.h 
	$(CC) $(CFLAGS) diskStat.cpp
report.o: report.cpp report.h diskStat.h
	$(CC) $(CFLAGS) report.cpp
tool.o: tool.cpp tool.h diskStat.h commandLine.h configInfo.h
	$(CC) $(CFLAGS) tool.cpp
