
// trigonometricDlg.cpp: 实现文件
//

#include "pch.h"
#include "CTipDlg.h"
#include "framework.h"
#include "trigonometric.h"
#include "trigonometricDlg.h"
#include "afxdialogex.h"
#include "trifuncs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int nSel = 0;
int selection = 0;


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CtrigonometricDlg 对话框



CtrigonometricDlg::CtrigonometricDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TRIGONOMETRIC_DIALOG, pParent)
	, m_editinput(0)
	, m_editoutput(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtrigonometricDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INPUT_EDIT, m_editinput);
	DDX_Text(pDX, IDC_OUTPUT_EDIT, m_editoutput);
	DDX_Control(pDX, IDC_TYPE_COMBO, m_combotype);
}

BEGIN_MESSAGE_MAP(CtrigonometricDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ANGLE_RADDIO, &CtrigonometricDlg::OnBnClickedAngleRaddio)
	ON_BN_CLICKED(IDC_RADIAN_RADDIO, &CtrigonometricDlg::OnBnClickedRadianRaddio)
	ON_CBN_SELCHANGE(IDC_TYPE_COMBO, &CtrigonometricDlg::OnCbnSelchangeTypeCombo)
	ON_EN_CHANGE(IDC_OUTPUT_EDIT, &CtrigonometricDlg::OnEnChangeOutputEdit)
	ON_BN_CLICKED(IDC_BUTTON1, &CtrigonometricDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CtrigonometricDlg 消息处理程序

BOOL CtrigonometricDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	// 默认选中“角度”单选按钮   
	CheckDlgButton(IDC_RADIAN_RADDIO, 1);
	OnBnClickedAngleRaddio();

	// 为组合框控件的列表框添加列表项“余弦”   
	m_combotype.AddString(_T("余弦"));
	// 为组合框控件的列表框添加列表项“反正弦”   
	m_combotype.AddString(_T("反正弦"));
	// 为组合框控件的列表框添加列表项“反正切”   
	m_combotype.AddString(_T("反正切"));
	// 在组合框控件的列表框中索引为1的位置插入列表项“正弦”   
	m_combotype.InsertString(1, _T("正弦"));
	// 默认选择第一项   
	m_combotype.SetCurSel(0);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CtrigonometricDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CtrigonometricDlg::OnPaint()
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
HCURSOR CtrigonometricDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtrigonometricDlg::OnBnClickedAngleRaddio()
{
	// TODO: 在此添加控件通知处理程序代码
	// 如果选择了“角度”单选按钮，则选择角度函数进行计算此处加入角度函数
	selection = 1;
}


void CtrigonometricDlg::OnBnClickedRadianRaddio()
{
	// TODO: 在此添加控件通知处理程序代码
	// 如果选择了“弧度”单选按钮，则选择弧度函数进行计算此处加入角度函数
	selection = 2;
}


void CtrigonometricDlg::OnCbnSelchangeTypeCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strFunctionSel;
	// 获取组合框控件的列表框中选中项的索引   
	nSel = m_combotype.GetCurSel();
}

void CtrigonometricDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	float input;
	input = m_editinput;

	// 若选中“余弦”则将其加入结果字符串   
	if (0 == nSel)
	{
		//if (selection == 1)
		//{
		//	//调用正余弦计算函数，因为返回值有正弦值和余弦值两项，因此用结构体变量接受返回值
		//	struct Result r = Trigonometric(input);
		//	//将结构体变量中的余弦值赋值给输出变量
		//	m_editoutput = r.cosine;
		//}
		////如果选择弧度，则输出弧度
		//if (selection == 2)
		//{
		//	input = input * 180 / pi;
		//	struct Result r = Trigonometric(input);
		//	m_editoutput = r.cosine;
		//}
		float result = cos(selection, input);
		m_editoutput = result;
	}

	// 若选中“正弦”则将其加入结果字符串
	if (1 == nSel)
	{
		//if (selection == 1)
		//{
		//	//调用正余弦计算函数，因为返回值有正弦值和余弦值两项，因此用结构体变量接受返回值
		//	struct Result r = Trigonometric(input);
		//	//将结构体变量中的正弦值赋值给输出变量
		//	m_editoutput = r.sine;
		//}
		////如果选择弧度，则输出弧度
		//if (selection == 2)
		//{
		//	input = input * 180 / pi;
		//	struct Result r = Trigonometric(input);
		//	m_editoutput = r.sine;
		//}
		float result = Sin(selection, input);
		m_editoutput = result;
	}

	// 若选中“反正弦”则将其加入结果字符串
	if (2 == nSel)
	{
		//如果输入值在反正弦的定义域内，则正常计算
		if (input >= -1 && input <= 1)
		{
			//double angle = arcsin(input);
			////如果选择角度，则输出角度
			//if (selection == 1)
			//{
			//	m_editoutput = angle;
			//}
			////如果选择弧度，则输出弧度
			//if (selection == 2)
			//{
			//	angle = angle / 180 * pi;
			//	m_editoutput = angle;
			//}
			float result = arcsin(input);
			m_editoutput = result;
		}
		//如果输入值超出定义域，则输出“404”
		if (input < -1 || input > 1)
		{
			// 编辑框中默认显示第一项的文字“您的输入有误，请重新输入。”   
			INT_PTR nRes;             // 用于保存DoModal函数的返回值   
			CTipDlg tipDlg;           // 构造对话框类CTipDlg的实例   
			nRes = tipDlg.DoModal();  // 弹出对话框  

			//m_editoutput = 404;
		}
	}

	// 若选中“反正切”则将其加入结果字符串
	if (3 == nSel)
	{
		//double angle = arctan(input);
		////如果选择角度，则输出角度
		//if (selection == 1)
		//{
		//	m_editoutput = angle;
		//}
		////如果选择弧度，则输出弧度
		//if (selection == 2)
		//{
		//	angle = angle / 180 * pi;
		//	m_editoutput = angle;
		//}
		float result = arctan(input);
		m_editoutput = result;
	}

	m_editoutput = m_editoutput;
	// 根据各变量的值更新相应的控件。和的编辑框会显示m_editSum的值   
	UpdateData(FALSE);

}


void CtrigonometricDlg::OnEnChangeOutputEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	

}


