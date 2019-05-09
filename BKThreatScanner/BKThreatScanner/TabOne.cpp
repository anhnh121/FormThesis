// TabOne.cpp : implementation file
//

#include "stdafx.h"
#include "BKThreatScanner.h"
#include "TabOne.h"
#include "afxdialogex.h"
#include "UsingSQLite.h"


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
//	ON_COMMAND(ID_EDIT_COPY, &CTabOne::OnEditCopy)
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

	CRect rect;
	m_listCtrl.GetClientRect(&rect);
	int nColInterval = rect.Width() / 10;

	//Initial colum for List Ctrl
	m_listCtrl.InsertColumn(0, _T("PID"), LVCFMT_LEFT, 1*nColInterval);
	m_listCtrl.InsertColumn(1, _T("Image Path"), LVCFMT_LEFT, 7 * nColInterval);
	m_listCtrl.InsertColumn(2, _T("Signature"), LVCFMT_LEFT, 2 * nColInterval);

	list<USGN_INFO> dll_list;
	CUsingSQLite sqlite;
	dll_list = sqlite.QueryDllUnsigned(DATABASE_PATH);
	int iSTT = 0;
	int temp = 0;
	CStringW cs;
	list<USGN_INFO>::iterator it_dll;
	for (it_dll = dll_list.begin(); it_dll != dll_list.end(); it_dll++)
	{
		//printf("%ld\n", it_dll->dwPID);
		//printf("%ls\n", it_dll->szPath);
		//printf("%ls\n", it_dll->szSigner);
		cs.Format(L"%ld", it_dll->dwPID);
		temp = m_listCtrl.InsertItem(iSTT, cs);
		m_listCtrl.SetItemText(temp, 1, it_dll->szPath);
		m_listCtrl.SetItemText(temp, 2, it_dll->szSigner);
		iSTT++;
	}
	/*int temp = m_listCtrl.InsertItem(0, L"1");
	m_listCtrl.SetItemText(temp, 1, L"anhnh.exe");
	m_listCtrl.SetItemText(temp, 2, L"Viettel");*/
	
	return TRUE;
}
// CTabOne message handlers


void CTabOne::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}