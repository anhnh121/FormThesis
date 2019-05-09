#pragma once
#include "afxcmn.h"


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
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listCtrl;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnEditCopy();
};
