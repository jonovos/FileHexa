// fileHexaDoc.h : interface of the CfileHexaDoc class
//


#pragma once


class CfileHexaDoc : public CDocument
{
protected: // create from serialization only
	CfileHexaDoc();
	DECLARE_DYNCREATE(CfileHexaDoc)

// Attributes
public:
    unsigned char *m_pMem;
    int            m_nMemSize;
    char           m_szDropFileName[512];

// Operations
public:
    void           m_SetDropFile( char* fname );

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CfileHexaDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


