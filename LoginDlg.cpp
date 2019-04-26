// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "template_ocean.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include"InfoFile.h"


// CLoginDlg �Ի���

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DIALOG_LOGIN, pParent)
	, m_user(_T(""))
	, m_pwd(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON4, &CLoginDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CLoginDlg::OnBnClickedButton3)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CLoginDlg ��Ϣ�������


void CLoginDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��¼��ť����¼�
	UpdateData(TRUE);
	if (m_user.IsEmpty() || m_pwd.IsEmpty())
	{
		MessageBox(TEXT("�������ݲ���Ϊ��"));
		return;
	}
	//��ȡ��ȷ��ֵ
	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name,pwd);
	if (name == m_user)//�û���һ��
	{
		if (pwd == m_pwd) //����һ��
		{
			//�رյ�ǰ�Ի���
			CDialog::OnCancel();
		}
		else {
			MessageBox(TEXT("��������"));
		}
	}
	else {
		MessageBox(TEXT("�û�������"));
	}
}


void CLoginDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


void CLoginDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}


void CLoginDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//CDialogEx::OnClose();
	exit(0);
}


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	HICON icon;
	icon = AfxGetApp()->LoadIconW(IDI_ICON_SYSU);
	SetIcon(icon, true);
	SetIcon(icon, false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
