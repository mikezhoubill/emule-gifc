#pragma once


// CSearchWaitDialog dialog

class CSearchWaitDialog : public CDialog
{
	DECLARE_DYNAMIC(CSearchWaitDialog)

public:
	CSearchWaitDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSearchWaitDialog();

// Dialog Data
	enum { IDD = IDD_SEARCHWAIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual void OnCancel();

	DECLARE_MESSAGE_MAP()
};
