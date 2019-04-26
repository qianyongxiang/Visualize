#include "stdafx.h"
#include "InfoFile.h"


CInfoFile::CInfoFile()
{
}


CInfoFile::~CInfoFile()
{
}

//读取登录信息
void CInfoFile::ReadLogin( CString &name, CString &pwd )
{
	ifstream ifs;	//创建文件输入对象
	ifs.open(_F_LOGIN);

	char buf[1024] ={0};

	ifs.getline(buf, sizeof(buf));	//读取一行内容
	name = CString(buf);	//将char* 转换为CString

	ifs.getline(buf, sizeof(buf));	//读取一行内容
	pwd = CString(buf);	//将char* 转换为CString

	ifs.close();	//关闭文件
}

//void CInfoFile::ReadDocline()
//{
//	ifstream ifs(_F_INFO);
//	char buf[1024] = { 0 };
//	 num = 0;
//	 ls.clear();
//	ifs.getline(buf, sizeof(buf));
//
//	while (!ifs.eof())
//	{
//		msg tmp;
//		ifs.getline(buf, sizeof(buf));
//		num++;
//		char *sst = strtok(buf, "            ");
//		if (sst != NULL)
//		{
//			tmp.lon = atof(sst);//经度
//		}
//		else
//		{
//			break;
//		}
//		sst = strtok(NULL, "            ");
//		tmp.lat = atof(sst);//纬度
//		sst = strtok(NULL, "            ");
//		tmp.deep = atof(sst);//深度
//		sst = strtok(NULL, "            ");
//		tmp.temp = atof(sst);//温度
//		sst = strtok(NULL, "            ");
//		tmp.temp_n = atof(sst);//温度带噪声
//		sst = strtok(NULL, "            ");
//		tmp.salt = atof(sst);//盐度
//		sst = strtok(NULL, "            ");
//		tmp.salt_n = atof(sst);//盐度带噪声
//		sst = strtok(NULL, "            ");
//		tmp.stream = atof(sst);//流速
//		sst = strtok(NULL, "            ");
//		tmp.stream_n = atof(sst);//流速带噪声
//		ls.push_back(tmp);
//		ifs.close();
//	}
	
	
	


	





