#pragma once


// CTabOne dialog

class CTabOne : public CDialogEx
{
	DECLARE_DYNAMIC(CTabOne)

public:
	CTabOne(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTabOne();

// Dialog Data
	enum { IDD = IDD_TAB_ONE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
