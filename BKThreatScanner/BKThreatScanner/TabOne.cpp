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
}


BEGIN_MESSAGE_MAP(CTabOne, CDialogEx)
END_MESSAGE_MAP()


// CTabOne message handlers
