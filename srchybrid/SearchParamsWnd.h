#pragma once

#include "EditX.h"
#include "ComboBoxEx2.h"
#include "ListCtrlEditable.h"
class CCustomAutoComplete;
// >> add by Ken
class CSearchWaitDialog;
// << add by Ken

typedef enum EOptsRows
{
	orMinSize,
	orMaxSize,
	orAvailability,
	orCompleteSources,
	orExtension,
	orCodec,
	orBitrate,
	orLength,
	orTitle,
	orAlbum,
	orArtist
};

class CSearchParamsWnd : public CDialogBar
{
	DECLARE_DYNAMIC(CSearchParamsWnd);

// Construction
public:
	CSearchParamsWnd();
	virtual ~CSearchParamsWnd();

// Dialog Data
	enum { IDD = IDD_SEARCH_PARAMS };

	CEditX m_ctlName;
	CButton m_ctlStart;
	CButton m_ctlCancel;
	CButton m_ctlMore;
	CSearchResultsWnd* m_searchdlg;
	// >> add by Ken
	CSearchWaitDialog* m_searchWaitDlg;
	// << add by Ken

	void Localize();
	void ResetHistory();
	void SaveSettings();

	SSearchParams* GetParameters();
	void SetParameters(const SSearchParams* pParams);
	void ProcessEd2kSearchLinkRequest(CString strSearchTerm);

	virtual CSize CalcDynamicLayout(int, DWORD nMode);
	virtual void OnUpdateCmdUI(CFrameWnd* pTarget, BOOL bDisableIfNoHndler);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	// >> add by Ken
	bool m_bAutoDownload;
	// << add by Ken

protected:
	HCURSOR m_hcurMove;
	CComboBoxEx2 m_ctlMethod;
// >> modified by Ken -- change attribute from protected to public
public:
	CComboBoxEx2 m_ctlFileType;
protected:
// << modified by Ken
	CEditableListCtrl m_ctlOpts;
	CRect m_rcNameLbl;
	CRect m_rcName;
	CRect m_rcDropDownArrow;
	CRect m_rcFileTypeLbl;
	CRect m_rcFileType;
	CRect m_rcReset;
	CRect m_rcMethodLbl;
	CRect m_rcMethod;
	CRect m_rcOpts;
	CRect m_rcStart;
	CRect m_rcMore;
	CRect m_rcCancel;
	CImageList m_imlSearchMethods;
	CImageList m_imlFileType;
	CSize m_szMRU;
	CSize m_szFloat;
	CCustomAutoComplete* m_pacSearchString;

	void UpdateControls();
	BOOL SaveSearchStrings();
	void SetAllIcons();
	void InitMethodsCtrl();
	void InitFileTypesCtrl();
	uint64 GetSearchAttrSize(const CString& rstrExpr);
	ULONG GetSearchAttrNumber(const CString& rstrExpr);
	ULONG GetSearchAttrLength(const CString& rstrExpr);

	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
	afx_msg LRESULT OnInitDialog(WPARAM, LPARAM);
	afx_msg void OnSize(UINT nType, int cx, int cy);
// >> modified by Ken -- change attribute from protected to public
public:
	afx_msg void OnBnClickedStart();
protected:
// << modified by Ken
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedMore();
	afx_msg void OnCbnSelChangeMethod();
	afx_msg void OnCbnSelEndOkMethod();
	afx_msg void OnDDClicked();
	afx_msg void OnBnClickedSearchReset();
	afx_msg void OnEnChangeName();
	afx_msg void OnDestroy();
	afx_msg void OnSysColorChange();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);

	// ==> Design Settings [eWombat/Stulle] - Max
protected:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CBrush m_brMyBrush;
public:
	void OnBackcolor();
	// <== Design Settings [eWombat/Stulle] - Max
};
