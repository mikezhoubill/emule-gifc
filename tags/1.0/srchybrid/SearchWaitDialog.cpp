// SearchWaitDialog.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "otherfunctions.h"
#include "SearchWaitDialog.h"


// CSearchWaitDialog dialog

IMPLEMENT_DYNAMIC(CSearchWaitDialog, CDialog)

CSearchWaitDialog::CSearchWaitDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchWaitDialog::IDD, pParent)
{

}

CSearchWaitDialog::~CSearchWaitDialog()
{
}

void CSearchWaitDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSearchWaitDialog, CDialog)
END_MESSAGE_MAP()


// CSearchWaitDialog message handlers

BOOL CSearchWaitDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	InitWindowStyles(this);
	CenterWindow();
	
	SetWindowText(L"");
	SetDlgItemText(IDC_SEARCHWAIT, GetResString(IDS_SEARCHWAIT));
	return TRUE;
}

void CSearchWaitDialog::OnCancel()
{
}