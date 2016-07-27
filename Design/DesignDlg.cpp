
// DesignDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Design.h"
#include "DesignDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDesignDlg �Ի���




CDesignDlg::CDesignDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDesignDlg::IDD, pParent)
	, m_show(_T("0"))
	, c_operator(0)
	, m_num1(_T("0"))
	, m_num2(_T("0"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDesignDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  D//  DX_Text(p//  DX, I//  DC_E//  DIT3, sum);
	DDX_Text(pDX, IDC_EDIT3, m_show);
}

BEGIN_MESSAGE_MAP(CDesignDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDesignDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDesignDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDesignDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDesignDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDesignDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CDesignDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CDesignDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CDesignDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CDesignDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CDesignDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CDesignDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CDesignDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CDesignDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CDesignDlg::OnBnClickedButton14)
	ON_EN_CHANGE(IDC_EDIT3, &CDesignDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON16, &CDesignDlg::OnBnClickedButton16)
END_MESSAGE_MAP()


// CDesignDlg ��Ϣ�������

BOOL CDesignDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDesignDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDesignDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDesignDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDesignDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_show == '0'){
		m_show = '1';
	}else {
		m_show += '1';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_show == '0'){
		m_show = '2';
	}else {
		m_show += '2';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_show == '0'){
		m_show = '3';
	}else {
		m_show += '3';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_show == '0'){
		m_show = '4';
	}else {
		m_show += '4';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_show == '0'){
		m_show = '5';
	}else {
		m_show += '5';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_show == '0'){
		m_show = '6';
	}else {
		m_show += '6';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_show == '0'){
		m_show = '7';
	}else {
		m_show += '7';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_show == '0'){
		m_show = '8';
	}else {
		m_show += '8';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_show == '0'){
		m_show = '9';
	}else {
		m_show += '9';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_show == '0'){
		m_show = '0';
	}else {
		m_show += '0';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (c_operator){
		m_num2 = m_show;
		Calculate(c_operator);
	}
	c_operator = 1;
	m_num1 = m_show;
	m_show='0';
}


void CDesignDlg::OnBnClickedButton12()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (c_operator){
		m_num2 = m_show;
		Calculate(c_operator);
	}
	c_operator = 2;
	m_num1 = m_show;
	m_show='0';
}


void CDesignDlg::OnBnClickedButton13()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (c_operator){
		m_num2 = m_show;
		Calculate(c_operator);
	}
	c_operator = 3;
	m_num1 = m_show;
	m_show='0';
}


void CDesignDlg::OnBnClickedButton14()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (c_operator){
		m_num2 = m_show;
		Calculate(c_operator);
	}
	c_operator = 4;
	m_num1 = m_show;
	m_show='0';
}


void CDesignDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CDesignDlg::Calculate(int option)
{
	double num1,num2;
	double tmp = 0;
	num1 = _tstof(m_num1);
	num2 = _tstof(m_num2);
	switch(option)
	{
	case 1:
		tmp=num1+num2;
		break;
	case 2:
		tmp = num1-num2;
		break;
	case 3:
		tmp = num1*num2;
		break;
	case 4:
		tmp = num1/num2;
		break;
	}
	if (tmp-(int)tmp == 0) 
		m_show.Format(_T("%.0f"),tmp);
	else m_show.Format(_T("%.6f"),tmp);
	UpdateData(false);
	c_operator=0;
}









void CDesignDlg::OnBnClickedButton16()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_num2 = m_show;
	Calculate(c_operator);
}
