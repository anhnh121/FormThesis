// TabOne.cpp : implementation file
//

#include "stdafx.h"
#include "BKThreatScanner.h"
#include "TabOne.h"
#include "afxdialogex.h"


// CTabOne dialog

IMPLEMENT_DYNAMIC(CTabOne, CDialogEx)

CTabOne::CTabOne(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabOne::IDD, pParent)
{

}

CTabOne::~CTabOne()
{
}

void CTabOne::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
}


BEGIN_MESSAGE_MAP(CTabOne, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CTabOne::OnLvnItemchangedList1)
END_MESSAGE_MAP()

BOOL CTabOne::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	//Initial colum for List Ctrl
	m_listCtrl.InsertColumn(0, _T("PID"), LVCFMT_LEFT, 200);
	m_listCtrl.InsertColumn(1, _T("Image Path"), LVCFMT_LEFT, 200);
	m_listCtrl.InsertColumn(2, _T("Signature"), LVCFMT_LEFT, 200);

	int temp = m_listCtrl.InsertItem(0, L"1");
	m_listCtrl.SetItemText(temp, 1, L"anhnh.exe");
	m_listCtrl.SetItemText(temp, 2, L"Viettel");
	m_listCtrl.InsertItem(1, L"2");
	

	return TRUE;
}
// CTabOne message handlers


void CTabOne::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
