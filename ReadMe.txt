================================================================================
Readme.txt
==========

This is a simple file HEXadecimal viewer. You can drag and drop any file
into the window and see its contents and it will display its contents in
the manner of:

00000000: 2f 2f 20 66 69 6c 65 48 - 65 78 61 2e 63 70 70 20  [ // fileH|exa.cpp  ]
00000010: 3a 20 44 65 66 69 6e 65 - 73 20 74 68 65 20 63 6c  [ : Define|s the cl ]
00000020: 61 73 73 20 62 65 68 61 - 76 69 6f 72 73 20 66 6f  [ ass beha|viors fo ]
00000030: 72 20 74 68 65 20 61 70 - 70 6c 69 63 61 74 69 6f  [ r the ap|plicatio ]
00000040: 6e 2e 0d 0a 2f 2f 0d 0a - 0d 0a 23 69 6e 63 6c 75  [ n...//..|..#inclu ]
00000050: 64 65 20 22 73 74 64 61 - 66 78 2e 68 22 0d 0a 23  [ de "stda|fx.h"..# ]
00000060: 69 6e 63 6c 75 64 65 20 - 22 66 69 6c 65 48 65 78  [ include |"fileHex ]
00000070: 61 2e 68 22 0d 0a 23 69 - 6e 63 6c 75 64 65 20 22  [ a.h"..#i|nclude " ]


This project can be dropped into MS Visual-Studio 2008.


Implements Concepts:

- simple file Drag and drop
- simple edit-box control in main window
- simple vertical scroll bar
- simple menu function
- simple Document storage
- simple memory heap-allocation

**** I wrote this SIMPLE application in 1998, and resurected it for MSVS2008.

================================================================================










================================================================================
    MICROSOFT FOUNDATION CLASS LIBRARY : fileHexa Project Overview
===============================================================================

The application wizard has created this fileHexa application for
you.  This application not only demonstrates the basics of using the Microsoft
Foundation Classes but is also a starting point for writing your application.

This file contains a summary of what you will find in each of the files that
make up your fileHexa application.

fileHexa.vcproj
    This is the main project file for VC++ projects generated using an application wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    application wizard.

fileHexa.h
    This is the main header file for the application.  It includes other
    project specific headers (including Resource.h) and declares the
    CfileHexaApp application class.

fileHexa.cpp
    This is the main application source file that contains the application
    class CfileHexaApp.

fileHexa.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited in Microsoft
    Visual C++. Your project resources are in 1033.

res\fileHexa.ico
    This is an icon file, which is used as the application's icon.  This
    icon is included by the main resource file fileHexa.rc.

res\fileHexa.rc2
    This file contains resources that are not edited by Microsoft
    Visual C++. You should place all resources not editable by
    the resource editor in this file.

/////////////////////////////////////////////////////////////////////////////

For the main frame window:
    The project includes a standard MFC interface.

MainFrm.h, MainFrm.cpp
    These files contain the frame class CMainFrame, which is derived from
    CFrameWnd and controls all SDI frame features.

/////////////////////////////////////////////////////////////////////////////

The application wizard creates one document type and one view:

fileHexaDoc.h, fileHexaDoc.cpp - the document
    These files contain your CfileHexaDoc class.  Edit these files to
    add your special document data and to implement file saving and loading
    (via CfileHexaDoc::Serialize).

fileHexaView.h, fileHexaView.cpp - the view of the document
    These files contain your CfileHexaView class.
    CfileHexaView objects are used to view CfileHexaDoc objects.





/////////////////////////////////////////////////////////////////////////////

Other Features:

ActiveX Controls
    The application includes support to use ActiveX controls.

/////////////////////////////////////////////////////////////////////////////

Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named fileHexa.pch and a precompiled types file named StdAfx.obj.

Resource.h
    This is the standard header file, which defines new resource IDs.
    Microsoft Visual C++ reads and updates this file.

fileHexa.manifest
	Application manifest files are used by Windows XP to describe an applications
	dependency on specific versions of Side-by-Side assemblies. The loader uses this
	information to load the appropriate assembly from the assembly cache or private
	from the application. The Application manifest  maybe included for redistribution
	as an external .manifest file that is installed in the same folder as the application
	executable or it may be included in the executable in the form of a resource.
/////////////////////////////////////////////////////////////////////////////

Other notes:

The application wizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

If your application uses MFC in a shared DLL, you will need
to redistribute the MFC DLLs. If your application is in a language
other than the operating system's locale, you will also have to
redistribute the corresponding localized resources MFC90XXX.DLL.
For more information on both of these topics, please see the section on
redistributing Visual C++ applications in MSDN documentation.

/////////////////////////////////////////////////////////////////////////////
