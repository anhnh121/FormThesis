
// BKThreatScannerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BKThreatScanner.h"
#include "BKThreatScannerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CBKThreatScannerDlg dialog



CBKThreatScannerDlg::CBKThreatScannerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBKThreatScannerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBKThreatScannerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_ScanTabCtrl);
	//DDX_Control(pDX, IDC_LIST1, m_listCtrl);
}

BEGIN_MESSAGE_MAP(CBKThreatScannerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CBKThreatScannerDlg::OnSelchangeTab1)
END_MESSAGE_MAP()


// CBKThreatScannerDlg message handlers

BOOL CBKThreatScannerDlg::OnInitDialog()
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_ScanTabOne.Create(IDD_TAB_ONE, &m_ScanTabCtrl);
	m_ScanTabTwo.Create(IDD_TAB_TWO, &m_ScanTabCtrl);

	m_ScanTabCtrl.InsertItem(0,_T("AnhNH1"));
	m_ScanTabCtrl.InsertItem(1, _T("AnhNH2"));
	m_ScanTabCtrl.InsertItem(2, _T("AnhNH3"));
	m_ScanTabCtrl.InsertItem(3, _T("AnhNH4"));
	m_ScanTabCtrl.InsertItem(4, _T("AnhNH5"));
	m_ScanTabCtrl.InsertItem(5, _T("AnhNH6"));
	m_ScanTabCtrl.InsertItem(6, _T("AnhNH7"));
	m_ScanTabCtrl.InsertItem(7, _T("AnhNH8"));
	m_ScanTabCtrl.InsertItem(8, _T("AnhNH9"));

	CRect TabRect;
	m_ScanTabCtrl.GetClientRect(&TabRect);
	m_ScanTabCtrl.AdjustRect(FALSE, &TabRect);
	m_ScanTabOne.MoveWindow(TabRect);
	m_ScanTabTwo.MoveWindow(TabRect);
	m_ScanTabOne.ShowWindow(SW_SHOW);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBKThreatScannerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBKThreatScannerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBKThreatScannerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBKThreatScannerDlg::OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	//int iSel = m_ScanTabCtrl.GetCurSel();
	switch (this->m_ScanTabCtrl.GetCurSel())
	{
	case 0:
		this->m_ScanTabOne.ShowWindow(SW_SHOW);
		this->m_ScanTabTwo.ShowWindow(SW_HIDE);
		break;
	case 1:
		this->m_ScanTabTwo.ShowWindow(SW_SHOW);
		this->m_ScanTabOne.ShowWindow(SW_HIDE);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	default:
		this->m_ScanTabOne.ShowWindow(SW_SHOW);
		this->m_ScanTabTwo.ShowWindow(SW_HIDE);
		break;

	}
	*pResult = 0;
}
