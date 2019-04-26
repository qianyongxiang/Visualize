#pragma once

#include <list>
#include <fstream>
#include <iostream>
#include <string>

#define _F_LOGIN "./login.ini"
#define _F_INFO "./noise10_info.txt"


using namespace std;

struct msg
{
	float lon;
	float lat;
	float deep;
	float temp;
	float salt;
	float stream;
	float temp_n;
	float salt_n;
	float stream_n;

	
};

class CInfoFile
{
public:
	CInfoFile();
	~CInfoFile();

	//��ȡ��¼��Ϣ
	void ReadLogin(CString &name, CString &pwd);

	/*void ReadDocline();

	list<msg> ls;
	int num;
*/

	

	
};

