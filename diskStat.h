#ifndef DISKSTAT_H
#define DISKSTAT_H

#include<iostream>
#include<string>
using namespace std;

/*
 * DiskStat handles all information regarding
 * data from diskstat file. 
 */
class DiskStat
{
	string diskName;
	unsigned long blkRead;
	unsigned long blkReadS;
	unsigned long blkWrtn;
	unsigned long blkWrtnS;
	unsigned long kbReadS;
	unsigned long kbWrtnS;
	public:
	void getDiskInfo();
	unsigned long getBlockData(string diskData, unsigned int& originalPosition, unsigned int& endPosition);
	string getDiskName();
	void setDiskName(string newName);
	unsigned long getBlkRead();
	void setBlkRead(unsigned long newBlkRead);
	unsigned long getBlkReadS();
	void setBlkReadS(unsigned long newBlkReadS);
	unsigned long getBlkWrtn();
	void setBlkWrtn(unsigned long newBlkWrtn);
	unsigned long getBlkWrtnS();
	void setBlkWrtnS(unsigned long newBlkWrtnS);
	unsigned long getKbReadS();
	void setKbReadS(unsigned long newKbReadS);
	unsigned long getKbWrtnS();
	void setKbWrtnS(unsigned long newKbWrtnS);
};

#endif
