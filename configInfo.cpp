#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include "configInfo.h"
using namespace std;

/* Default constructor for ConfigInfo */
ConfigInfo::ConfigInfo()
{
}

/* Constructor for ConfigInfo */
ConfigInfo::ConfigInfo(bool setEach[], unsigned int newCount, unsigned int newInterval):count(newCount), interval(newInterval)
{
	isBlkRead = setEach[0];
	isBlkReadS = setEach[1];
	isBlkWrtn = setEach[2];
	isBlkWrtnS = setEach[3];
	isKbReadS = setEach[4];
	isKbWrtnS = setEach[5];
}

/* 
 * Reads configuration file and stores settings
 * for reading later.
 * Parameters: None
 * Return: None
 */
void ConfigInfo::readConfigFile()
{
	ifstream infile;
	infile.open("audisktool.conf");
	int data;
	if(infile.is_open())
	{
		infile >> data;
		interval = data;

		infile >> data;
		count = data;

		infile >> data;
		isBlkRead = data;

		infile >> data;
		isBlkReadS = data;

		infile >> data;
		isBlkWrtn = data;

		infile >> data;
		isBlkWrtnS = data;

		infile >> data;
		isKbReadS = data;

		infile >> data;
		isKbWrtnS = data;

		infile.close();
	}
	else
	{
		cout << "Error opening file." << endl;
	}
	
}

/*
 * Saves user's new configuration options
 * to config file.
 * Parameter: none
 * Return: none
 */
void ConfigInfo::saveConfig()
{
	if(changeFlag)
	{
		ofstream outstream;
		outstream.open("audisktool.conf");
	
		outstream << interval << " ";
		outstream << count << " ";
		outstream << isBlkRead << " ";
		outstream << isBlkReadS << " ";
		outstream << isBlkWrtn << " ";
		outstream << isBlkWrtnS << " ";
		outstream << isKbReadS << " ";
		outstream << isKbWrtnS << " ";

		outstream.close();
	}
	else
	{
		cout << "Audisktool.conf has not been updated. There is no need to save the file." << endl;
	}
	changeFlag = false;
}

/*
 * Prints configuration info the the screen
 * with user friendly labels.
 */
void ConfigInfo::printFile()
{
	cout << "Monitoring time = " << interval << ", Number of records = " << count 
	<< ", print_blk_read = " << isBlkRead << ", print_blk_read/s = " << isBlkReadS
	<< ", print_kb_read/s = " << isKbReadS << ", print_blk_write = " << isBlkWrtn
	<< ", print_blk_write/s = " << isBlkWrtnS << ", print_kb_write/s = " << isKbWrtnS
	<< endl;
}

/* Accessor for isBlkRead */
bool ConfigInfo::getIsBlkRead()
{
	return isBlkRead;
}

/* Mutator for isBlkRead */
void ConfigInfo::setIsBlkRead(bool isSet)
{
	isBlkRead = isSet;
}

/* Accessor for isBlkReadS */
bool ConfigInfo::getIsBlkReadS()
{
	return isBlkReadS;
}

/* Mutator for isBlkReadS */
void ConfigInfo::setIsBlkReadS(bool isSet)
{
	isBlkReadS = isSet;
}

/* Accessor for isBlkWrtn */
bool ConfigInfo::getIsBlkWrtn()
{
	return isBlkWrtn;
}

/* Mutator for isBlkWrtn */
void ConfigInfo::setIsBlkWrtn(bool isSet)
{
	isBlkWrtn = isSet;
}

/* Accessor for isBlkWrtnS */
bool ConfigInfo::getIsBlkWrtnS()
{
	return isBlkWrtnS;
}

/* Mutator for isBlkWrtnS */
void ConfigInfo::setIsBlkWrtnS(bool isSet)
{
	isBlkWrtnS = isSet;
}

/* Accessor for isKbReadS */
bool ConfigInfo::getIsKbReadS()
{
	return isKbReadS;
}

/* Mutator for isKbReadS */
void ConfigInfo::setIsKbReadS(bool isSet)
{
	isKbReadS = isSet;
}

/* Accessor for isKbWrtnS */
bool ConfigInfo::getIsKbWrtnS()
{
	return isKbWrtnS;
}

/* Mutator for isKbWrtnS */
void ConfigInfo::setIsKbWrtnS(bool isSet)
{
	isKbWrtnS = isSet;
}

/* Accessor for count */
unsigned int ConfigInfo::getCount()
{
	return count;
}

/* Mutator for count */
void ConfigInfo::setCount(unsigned int newCount)
{
	count = newCount;
}

/* Accessor for interval */
unsigned int ConfigInfo::getInterval()
{
	return interval;
}

/* Mutator for interval */
void ConfigInfo::setInterval(unsigned int newInterval)
{
	interval = newInterval;
}

/* Accessor for changeFlag */
bool ConfigInfo::getChangeFlag()
{
	return changeFlag;
}

/* Mutator for change flag */
void ConfigInfo::setChangeFlag(bool newFlag)
{
	changeFlag = newFlag;
}

