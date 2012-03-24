// fileHexaDoc.cpp : implementation of the CfileHexaDoc class
//

#include "stdafx.h"
#include "fileHexa.h"

#include "fileHexaDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfileHexaDoc

IMPLEMENT_DYNCREATE(CfileHexaDoc, CDocument)

BEGIN_MESSAGE_MAP(CfileHexaDoc, CDocument)
END_MESSAGE_MAP()


// CfileHexaDoc construction/destruction

CfileHexaDoc::CfileHexaDoc()
{
	// TODO: add one-time construction code here

    //// designate ram size as 8-megabytes
    m_nMemSize = (1024*1024 *8);

    //// allocate the memory
    m_pMem = (unsigned char *)HeapAlloc(
            GetProcessHeap(),
            HEAP_NO_SERIALIZE,
            m_nMemSize );
}

CfileHexaDoc::~CfileHexaDoc()
{
    if( NULL != m_pMem )  {
        HeapFree( GetProcessHeap(), 0, (LPVOID)m_pMem );
        m_pMem = NULL;
    }
}

BOOL CfileHexaDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CfileHexaDoc serialization

void CfileHexaDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CfileHexaDoc diagnostics

#ifdef _DEBUG
void CfileHexaDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CfileHexaDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CfileHexaDoc commands

void CfileHexaDoc::m_SetDropFile( char* fname )
{
    //// store the new dropped-file name
    strcpy( m_szDropFileName, fname );
}

