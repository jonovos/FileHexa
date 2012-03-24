// fileHexaView.h : interface of the CfileHexaView class
//


#pragma once


class CfileHexaView : public CView
{
protected: // create from serialization only
	CfileHexaView();
	DECLARE_DYNCREATE(CfileHexaView)

// Attributes
public:
	CfileHexaDoc* GetDocument() const;
    CEdit *m_pTheEditBox;
    CFont *m_pFontCourier;

// Operations
private:
    void file_input_to_edit( void );

public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CfileHexaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnDestroy();
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnDropFiles(HDROP hDropInfo);
    afx_msg void OnReload();
};

#ifndef _DEBUG  // debug version in fileHexaView.cpp
inline CfileHexaDoc* CfileHexaView::GetDocument() const
   { return reinterpret_cast<CfileHexaDoc*>(m_pDocument); }
#endif

