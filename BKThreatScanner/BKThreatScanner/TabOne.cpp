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
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(CTabOne, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CTabOne::OnLvnItemchangedList1)
//	ON_COMMAND(ID_EDIT_COPY, &CTabOne::OnEditCopy)
ON_NOTIFY(HDN_ITEMCLICK, 0, &CTabOne::OnHdnItemclickList1)
ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CTabOne::OnDblclkList1)
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

void CTabOne::OnHdnItemclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	// TODO: Add your control notification handler code here
	//MessageBoxA(0,"OK", "OK", MB_OK);
	*pResult = 0;
}


void CTabOne::OnDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	int row = m_listCtrl.GetSelectionMark();
	if (row < 0)
		return;
	CString s1 = m_listCtrl.GetItemText(row, 0);
	CString s2 = m_listCtrl.GetItemText(row, 1);
	CString s3 = m_listCtrl.GetItemText(row, 2);

	CString dll_ret = L"PID = " + s1 + L"\nPath = " + s2 + L"\nSigned = " + s3 + "\n";
	CT2A output(dll_ret);
	const size_t len = strlen(output) + 1;
	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
	memcpy(GlobalLock(hMem), output, len);
	GlobalUnlock(hMem);
	OpenClipboard();
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hMem);
	CloseClipboard();
	MessageBoxW(L"Copied to Clipboard",L"OK", 0);
	//m_edit.SetWindowTextW(dll_ret.GetBuffer());
	//MessageBoxW(s2.GetBuffer(),L"OK", 0);
	*pResult = 0;
}
