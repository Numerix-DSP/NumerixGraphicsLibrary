/**************************************************************************
File Name		: DFGRAPH.CPP			| Author		: JOHN EDWARDS
Library version	: 1.20					| Modifications	:
----------------------------------------+----------------------------------
Compiler  : Independent					| Start Date	: 29/12/01
Options	  :								| Latest Update : 08/08/03
---------------------------------------------------------------------------
This file may be modified, in any way, providing that this header remains
within the file and none of the header contents are removed or modified.

You are free to use this software for any purpose you see fit.
This software is provided as user supported software and with no warranty.
If you do make changes then please feel free to send them back to us and
we will incorporate them into future versions.

DELETION OF ANY INFORMATION IN THIS HEADER IS IN VIOLATION OF YOUR LICENSE.

Copyright (C) 2001 to 2003 Numerix Ltd.
---------------------------------------------------------------------------
Description : Top level graph functions
	
****************************************************************************/
/*
	wxWindows program main functions
*/

/* Include files */
// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#if wxUSE_TOOLTIPS
    #include "wx/tooltip.h"
#endif

#include "mainframe.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};


mainFrame	  *AppMainFrame = (mainFrame *) NULL;

IMPLEMENT_APP(MyApp)


/*
	Function Name : main
	Description : Top level function
	Notes : 
*/

// `Main program' equivalent: the program execution "starts" here
bool MyApp::OnInit()
{

	AppMainFrame = new mainFrame (_T("Main Window"), wxDefaultPosition, wxDefaultSize);

	SetTopWindow (AppMainFrame);		// Tell the application that it's our main window
	AppMainFrame->Show (TRUE);			// Show it

	return TRUE;
}


