#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

#include "diskStat.h"
using namespace std;

/*
 * Parses diskstats file and stores relevant
 * information. Discards the rest.
 * Parameter: none
 * Return: none
 */
void DiskStat::getDiskInfo()
{
	ifstream infile;
	infile.open("/proc/diskstats");
	string allStats;
	while(!infile.eof())
	{
		allStats += infile.get();
	}
	diskName = "sda";
	unsigned int diskPosition = allStats.find(diskName);
	unsigned int endDiskPos = allStats.find("\n", diskPosition);
	unsigned int diskDataLength = endDiskPos - diskPosition;
	string diskData = allStats.substr(diskPosition, diskDataLength); 
	
	unsigned int startPosition = 0;
	unsigned int endPosition = 0;	
	unsigned int readLength = 0;

	//blkRead - field 1
	blkRead = getBlockData(diskData, startPosition, endPosition);

	//discard - field 2
	getBlockData(diskData, startPosition, endPosition);

	//blkReadS - field 3
	blkReadS = getBlockData(diskData, startPosition, endPosition);

	//discard - field 4
	getBlockData(diskData, startPosition, endPosition);

	//blkWrtn - field 5
	blkWrtn = getBlockData(diskData, startPosition, endPosition);
	
	//discard - field 6
	getBlockData(diskData, startPosition, endPosition);
	
	//blkWrtnS - field 7
	blkWrtnS = getBlockData(diskData, startPosition, endPosition);
}

/* 
 * Takes a string with start and end position and retreives 
 * next block of data (seperated by " ") from string. Data will
 * be converted into a number.
 * Parameters: diskData - string to parse
 *		startPosition - where substring starts
 *		endPosition - where substring ends
 * Return: unsigned long - number held in diskstat
 */
unsigned long DiskStat::getBlockData(string diskData, unsigned int& startPosition, unsigned int& endPosition)
{

	startPosition = endPosition;
	unsigned int readLength;

	startPosition = diskData.find(" ", startPosition);
	endPosition = diskData.find(" ", startPosition + 1);
	readLength = endPosition - startPosition;
	string blkInfo = diskData.substr(startPosition, readLength);
	unsigned long blkData = atoi(blkInfo.c_str());
	return blkData;
}

/* Accessor for diskName */
string DiskStat::getDiskName()
{
	return diskName;
}

/* Mutator for diskName */
void DiskStat::setDiskName(string newDiskName)
{
	diskName = newDiskName;
}

/* Accessor for blkRead */
unsigned long DiskStat::getBlkRead()
{
	return blkRead;
}

/* Mutator for blkRead */
void DiskStat::setBlkRead(unsigned long newBlkRead)
{
	blkRead = newBlkRead;
}

/* Accessor for blkReadS */
unsigned long DiskStat::getBlkReadS()
{
	return blkReadS;
}

/* Mutator for blkReadS */
void DiskStat::setBlkReadS(unsigned long newBlkReadS)
{
	blkReadS = newBlkReadS;
}

/* Accessor for blkWrtn */
unsigned long DiskStat::getBlkWrtn()
{
	return blkWrtn;
}

/* Mutator for blkWrtn */
void DiskStat::setBlkWrtn(unsigned long newBlkWrtn)
{
	blkWrtn = newBlkWrtn;
}

/* Accessor for blkWrtnS */
unsigned long DiskStat::getBlkWrtnS()
{
	return blkWrtnS;
}

/* Mutator for blkWrtnS */
void DiskStat::setBlkWrtnS(unsigned long newBlkWrtnS)
{
	blkWrtnS = newBlkWrtnS;
}

/* Accessor for kbReadS */
unsigned long DiskStat::getKbReadS()
{
	return kbReadS;
}

/* Mutator for kbReadS */
void DiskStat::setKbReadS(unsigned long newKbReadS)
{
	kbReadS = newKbReadS;
}

/* Accessor for kbWrtnS */
unsigned long DiskStat::getKbWrtnS()
{
	return kbWrtnS;
}

/* Mutator for kbWrtnS */
void DiskStat::setKbWrtnS(unsigned long newKbWrtnS)
{
	kbWrtnS = newKbWrtnS;
}
