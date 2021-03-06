#ifndef CONFIG_INFO_H
#define CONFIG_INFO_H

#include<iostream>
using namespace std;

/* 
 * ConfigInfo handles all information retreived 
 * from config file. Tool uses to that it can access
 * file information and make decisions based on 
 * data provided.
 */
class ConfigInfo
{
	bool isBlkRead;
	bool isBlkReadS;
	bool isBlkWrtn;
	bool isBlkWrtnS;
	bool isKbReadS;
	bool isKbWrtnS;
	unsigned int count;
	unsigned int interval;
	bool changeFlag;
	static unsigned int const NUM_ATTRIBUTES = 6;
	public:
	ConfigInfo();
	ConfigInfo(bool setEach[], unsigned int newCount, unsigned int newInterval);
	void readConfigFile();
	void saveConfig();
	void printFile();
	bool getIsBlkRead();
	void setIsBlkRead(bool isSet);
	bool getIsBlkReadS();
	void setIsBlkReadS(bool isSet);
	bool getIsBlkWrtn();
	void setIsBlkWrtn(bool isSet);
	bool getIsBlkWrtnS();
	void setIsBlkWrtnS(bool isSet);
	bool getIsKbReadS();
	void setIsKbReadS(bool isSet);
	bool getIsKbWrtnS();
	void setIsKbWrtnS(bool isSet);
	unsigned int getCount();
	void setCount(unsigned int newCount);
	unsigned int getInterval();
	void setInterval(unsigned int newInterval);
	bool getChangeFlag();
	void setChangeFlag(bool newFlag);
};

#endif
