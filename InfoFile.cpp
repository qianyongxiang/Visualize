#include "stdafx.h"
#include "InfoFile.h"


CInfoFile::CInfoFile()
{
}


CInfoFile::~CInfoFile()
{
}

//��ȡ��¼��Ϣ
void CInfoFile::ReadLogin( CString &name, CString &pwd )
{
	ifstream ifs;	//�����ļ��������
	ifs.open(_F_LOGIN);

	char buf[1024] ={0};

	ifs.getline(buf, sizeof(buf));	//��ȡһ������
	name = CString(buf);	//��char* ת��ΪCString

	ifs.getline(buf, sizeof(buf));	//��ȡһ������
	pwd = CString(buf);	//��char* ת��ΪCString

	ifs.close();	//�ر��ļ�
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
//			tmp.lon = atof(sst);//����
//		}
//		else
//		{
//			break;
//		}
//		sst = strtok(NULL, "            ");
//		tmp.lat = atof(sst);//γ��
//		sst = strtok(NULL, "            ");
//		tmp.deep = atof(sst);//���
//		sst = strtok(NULL, "            ");
//		tmp.temp = atof(sst);//�¶�
//		sst = strtok(NULL, "            ");
//		tmp.temp_n = atof(sst);//�¶ȴ�����
//		sst = strtok(NULL, "            ");
//		tmp.salt = atof(sst);//�ζ�
//		sst = strtok(NULL, "            ");
//		tmp.salt_n = atof(sst);//�ζȴ�����
//		sst = strtok(NULL, "            ");
//		tmp.stream = atof(sst);//����
//		sst = strtok(NULL, "            ");
//		tmp.stream_n = atof(sst);//���ٴ�����
//		ls.push_back(tmp);
//		ifs.close();
//	}
	
	
	


	





