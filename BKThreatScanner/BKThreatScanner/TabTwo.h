#pragma once


// CTabTwo dialog

class CTabTwo : public CDialogEx
{
	DECLARE_DYNAMIC(CTabTwo)

public:
	CTabTwo(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTabTwo();

// Dialog Data
	enum { IDD = IDD_TAB_TWO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
