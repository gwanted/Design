
// DesignDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Design.h"
#include "DesignDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CDesignDlg 对话框




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


// CDesignDlg 消息处理程序

BOOL CDesignDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDesignDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDesignDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDesignDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_show == '0'){
		m_show = '1';
	}else {
		m_show += '1';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_show == '0'){
		m_show = '2';
	}else {
		m_show += '2';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_show == '0'){
		m_show = '3';
	}else {
		m_show += '3';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_show == '0'){
		m_show = '4';
	}else {
		m_show += '4';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_show == '0'){
		m_show = '5';
	}else {
		m_show += '5';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_show == '0'){
		m_show = '6';
	}else {
		m_show += '6';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_show == '0'){
		m_show = '7';
	}else {
		m_show += '7';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_show == '0'){
		m_show = '8';
	}else {
		m_show += '8';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_show == '0'){
		m_show = '9';
	}else {
		m_show += '9';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_show == '0'){
		m_show = '0';
	}else {
		m_show += '0';
	}
	UpdateData(false);
}


void CDesignDlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	m_num2 = m_show;
	Calculate(c_operator);
}
