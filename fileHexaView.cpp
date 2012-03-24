// fileHexaView.cpp : implementation of the CfileHexaView class
//

#include "stdafx.h"
#include "fileHexa.h"

#include "fileHexaDoc.h"
#include "fileHexaView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfileHexaView

IMPLEMENT_DYNCREATE(CfileHexaView, CView)

BEGIN_MESSAGE_MAP(CfileHexaView, CView)
    ON_WM_CREATE()
    ON_WM_DESTROY()
    ON_WM_SIZE()
    ON_WM_DROPFILES()
    ON_COMMAND(IDM_RELOAD, &CfileHexaView::OnReload)
END_MESSAGE_MAP()

// CfileHexaView construction/destruction

CfileHexaView::CfileHexaView()
{
	// TODO: add construction code here

    //// get a font MFC-object
    m_pFontCourier = new CFont();

    //// create the courier font for use
    m_pFontCourier->CreateFont( 16,
                                0,0,0,
                                FW_NORMAL,
                                0,0,0,
                                0,0,0,
                                DEFAULT_QUALITY,
                                FIXED_PITCH|FF_MODERN,
                                "Courier New" );
}

CfileHexaView::~CfileHexaView()
{
    //// remove the courier font from use
    m_pFontCourier->DeleteObject();

    //// delete the font MFC-object
    delete m_pFontCourier;
    m_pFontCourier = NULL;
}

BOOL CfileHexaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CfileHexaView drawing

void CfileHexaView::OnDraw(CDC* /*pDC*/)
{
	CfileHexaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CfileHexaView diagnostics

#ifdef _DEBUG
void CfileHexaView::AssertValid() const
{
	CView::AssertValid();
}

void CfileHexaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CfileHexaDoc* CfileHexaView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CfileHexaDoc)));
	return (CfileHexaDoc*)m_pDocument;
}
#endif //_DEBUG


// CfileHexaView message handlers

int CfileHexaView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CView::OnCreate(lpCreateStruct) == -1)
        return -1;

    // TODO:  Add your specialized creation code here

    //// get the window's dimensions
    RECT rect;
    GetClientRect( &rect );

    //// create an Edit control MFC-object
    m_pTheEditBox = new CEdit();

    //// Create the edit control's Window
    m_pTheEditBox->Create( WS_VISIBLE | WS_CHILD | WS_VSCROLL
                         | ES_AUTOVSCROLL
                         | ES_AUTOHSCROLL
                         | ES_LEFT
                         | ES_READONLY
                         | ES_MULTILINE,
                         rect,
                         this,
                         1001 );

    //// set the edit-control's font
    m_pTheEditBox->SetFont( m_pFontCourier );

    CfileHexaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if( pDoc )
        m_pTheEditBox->SetWindowText( "Ready." );

    //// allow drag and drop files into this window
    this->DragAcceptFiles();

    return 0;
}

void CfileHexaView::OnDestroy()
{
    CView::OnDestroy();

    // TODO: Add your message handler code here

    //// destory the child window
    m_pTheEditBox->DestroyWindow();

    //// delete the control MFC-object, created above with "new"
    delete m_pTheEditBox;
    m_pTheEditBox = NULL;
}

void CfileHexaView::OnSize(UINT nType, int cx, int cy)
{
    CView::OnSize(nType, cx, cy);

    // TODO: Add your message handler code here

    //// track the app-window's size
    m_pTheEditBox->MoveWindow( 0,0, cx, cy, FALSE );
}





void CfileHexaView::OnDropFiles(HDROP hDropInfo)
{
    // TODO: Add your message handler code here and/or call default

////////CView::OnDropFiles(hDropInfo);
    //// get the dropped file name
    char  szTemp[260];
    DragQueryFile( hDropInfo, 0, szTemp, (260-1) );
    DragFinish( hDropInfo );

    //// tell the DOCUMENT the new dropped file name
    CfileHexaDoc *pDoc = (CfileHexaDoc *)GetDocument();
    pDoc->m_SetDropFile( szTemp );

    PostMessage( WM_COMMAND, IDM_RELOAD, 0 );
}

void CfileHexaView::OnReload()
{
    // TODO: Add your command handler code here
    file_input_to_edit();
}


void CfileHexaView::file_input_to_edit( void )
{
    //// get PTR to the DOCUMENT
    CfileHexaDoc *pDoc = (CfileHexaDoc *)GetDocument();
    char *pDest = (char *)(pDoc->m_pMem);

    //// BUILD STRING FOR EDIT-CONTROL
    ////
    //// First, comes the subject file-name
    strcpy( pDest, "===> \"" );
    strcat( pDest, pDoc->m_szDropFileName );
    strcat( pDest, "\"\r\n" );

    //// open the file
    FILE *fp = fopen( pDoc->m_szDropFileName, "rb" );
    if( NULL == fp )  {
        strcat( pDest, "****Error-Open." );
        m_pTheEditBox->SetWindowText( pDest );
        return;
    }

    fseek( fp, 0L, SEEK_END );
    int nFileLength = ftell( fp );
    fseek( fp, 0L, SEEK_SET );
    sprintf( pDest + strlen(pDest),
             "===> Size: %d-bytes\r\n",
             nFileLength );


    int nread, nOffs, nAddr, nByte, nPosHexaByte, nPosAsciiByte, i;
    unsigned char fbuff[1024];
    char szLine[256];
    char szHexa[256];
    char szAscii[32];
    char szX[32];
    BOOL bPassedEnd;

    nread = (0);
    nOffs = (0);

    nAddr = 0x00000000;
    bPassedEnd = FALSE;
    while( ! bPassedEnd )
    {
        sprintf( szLine,  "%08x: ", nAddr );
        sprintf( szHexa,  "                                                      " );
        sprintf( szAscii, "                       " );
        nPosHexaByte = (0);
        nPosAsciiByte = (0);
        //
        for( i=0; i<16; i++ )
        {
            if( nOffs >= nread )  {
                nread = fread( fbuff, 1, 1024,  fp );
                nOffs = (0);
                if( nread <= 0 )  {
                    bPassedEnd = TRUE;
                    break;
                }
            }
            nByte = ((int)fbuff[ nOffs++ ]  & 0x000ff);

            sprintf( szX, "%02x", nByte );
            szHexa[ nPosHexaByte++ ] = szX[0];
            szHexa[ nPosHexaByte++ ] = szX[1];
            szHexa[ nPosHexaByte++ ] = (' ');
            if( nPosHexaByte == 24 )  {
                szHexa[ 24 ] = '-';
                nPosHexaByte = 26;
            }

            if( nByte >= (' ') && nByte <='~' )
                szAscii[nPosAsciiByte++] = (nByte);
            else  szAscii[nPosAsciiByte++] = ('.');
            if( nPosAsciiByte == 8 )
                szAscii[nPosAsciiByte++] = ('|');
        }

        if( (nAddr & 0x7f) == 0 )
            strcat( pDest, "\r\n" );

        sprintf( szLine, "%08x: %-50.50s [ %-17.17s ]\r\n",
                 nAddr,  szHexa,  szAscii );

        strcat( pDest, szLine );
        nAddr += 16;

        if( strlen(pDest) >= (pDoc->m_nMemSize - 128) )  {
            sprintf( szLine, "\r\n******* TRUNCATED ****" );
            strcat( pDest, szLine );
            break;
        }
    }
    //fread( pDest + strlen(pDest), 1, nFileLength,  fp );
    fclose( fp );


    m_pTheEditBox->SetWindowText( pDest );
}