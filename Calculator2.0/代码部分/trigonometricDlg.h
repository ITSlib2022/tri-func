
// trigonometricDlg.h: 头文件
//

#pragma once


// CtrigonometricDlg 对话框
class CtrigonometricDlg : public CDialogEx
{
// 构造
public:
	CtrigonometricDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRIGONOMETRIC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAngleRaddio();
	afx_msg void OnBnClickedRadianRaddio();
	double m_editinput;
	double m_editoutput;
	CComboBox m_combotype;
	afx_msg void OnCbnSelchangeTypeCombo();
	afx_msg void OnEnChangeOutputEdit();
	afx_msg void OnBnClickedButton1();
};
