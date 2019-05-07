// TabTwo.cpp : implementation file
//

#include "stdafx.h"
#include "BKThreatScanner.h"
#include "TabTwo.h"
#include "afxdialogex.h"


// CTabTwo dialog

IMPLEMENT_DYNAMIC(CTabTwo, CDialogEx)

CTabTwo::CTabTwo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabTwo::IDD, pParent)
{

}

CTabTwo::~CTabTwo()
{
}

void CTabTwo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabTwo, CDialogEx)
END_MESSAGE_MAP()


// CTabTwo message handlers
