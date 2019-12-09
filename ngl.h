/**************************************************************************
File Name		: NGL.H					    | Author		    : JOHN EDWARDS
Library version	: 2.61					| Modifications	:
----------------------------------------+----------------------------------
Compiler  : Independent					| Start Date	  : 29/12/01
Options	  :								      | Latest Update : 20/06/15
---------------------------------------------------------------------------
This file may be modified, in any way, providing that this header remains
within the file and none of the header contents are removed or modified.

This software is provided as user supported software and with no warranty.

DELETION OF ANY INFORMATION IN THIS HEADER IS IN VIOLATION OF YOUR LICENSE.

Copyright (C) 2001 to 2015 Numerix Ltd.
---------------------------------------------------------------------------
Description : Graph display functions. Supports line and pole-zero graphs.

****************************************************************************/

#ifndef		_NGL_H
#define		_NGL_H

#define	NGL_VERSION				2.61		/* Indicates NGL version being used */

/* Math constants */
#define TWO_PI					6.283185307179586476925286766559
#define TWO_PI_OVER_THREE_SIXTY	0.017453292519943295769236907684886

/* Graphics constants */
#define GRAPH_SCALE				0		/* Scale graph to screen */
#define GRAPH_NO_SCALE			1		/* No graph scaling (default 1) */

#define MAXIMUM_GRAPH_WIDTH		512		/* Maximum graph width */
#define MAXIMUM_PZ_SIZE			512		/* Maximum number of poles and zeros to plot */

enum pz_type				/* Pole zero types */
{
	PZ_COMPLEX_POLE_ZERO,
	PZ_CONJUGATE_POLE_ZERO,
	PZ_COMPLEX_ZERO,
	PZ_CONJUGATE_ZERO,
	PZ_COMPLEX_POLE,
	PZ_CONJUGATE_POLE
};


class LineGraphCanvas;
class PoleZeroPlotCanvas;


#if !defined (SIGLIB)
				/* Complex Cartesian (Rectangular) numbers */
typedef struct
{
	double	real;
	double	imag;
} SLComplexRect_s;
#endif


enum
{
//	UPDATE_LINE_GRAPH = wxID_HIGHEST + 1,
	UPDATE_LINE_GRAPH = 1001,
	UPDATE_POLE_ZERO_PLOT = 1002,
};

class LineGraph : public wxPanel
{
public:
	LineGraph (wxWindow* parent, wxWindowID id, wxSize GraphSize);
	~LineGraph ();
    void   		AddDataSet (const double *pSrc, const double scaleFlag, const wxColour colour, const int size);

	void		SetTopLabel (wxString String);
	void		SetMiddleLabel (wxString String);
	void		SetBottomLabel (wxString String);
	void		SetLeftLabel (wxString String);
	void		SetCenterLabel (wxString String);
	void		SetRightLabel (wxString String);
	void		SetStatusBarValueText (wxString);
	wxString	GetStatusBarValueText (void);
	void		SetQuantizeXAxisFlag (bool);
	bool		GetQuantizeXAxisFlag (void);
	void		SetStatusBarIndexMultiplier (double);
	double		GetStatusBarIndexMultiplier (void);

	LineGraphCanvas	*GraphCanvas;

    void		Draw (wxDC& dc, bool draw_bitmaps = TRUE);
	double		GetValue (int Location);

private:
	double		AbsMax (const double *pSrc, const long SampleLength);

	wxStaticText	*LeftLabel, *CenterLabel, *RightLabel;
	wxStaticText	*TopLabel, *MiddleLabel, *BottomLabel;

	wxString	pStatusBarValueText;		// String used for title on status line
	double		StatusBarIndexMultiplier;

	wxColour	LineColour;

	wxSize		GraphSize;
	bool		QuantizeXAxisFlag;

	double		*pDataSet;
	double		Max;					// Peak value in data graph
	int			DataSetSize;			// Data set size
	int			PreviousX, PreviousY;

    DECLARE_EVENT_TABLE()
};



// Define a new canvas for the line graph
class LineGraphCanvas: public wxWindow
{
public:
    LineGraphCanvas (LineGraph *pLineGraph, wxPanel *parent, wxPoint GraphPoint, wxSize GraphSize);
//    LineGraphCanvas (wxPanel *parent, wxPoint GraphPoint, wxSize GraphSize);
    ~LineGraphCanvas ();
    void OnPaint (wxPaintEvent & event);

private:
	void OnMouseMove (wxMouseEvent & event);

	wxSize		GraphSize;
	wxPanel		*m_owner;
	LineGraph	*m_LineGraph;
//	wxPanel		*m_LineGraph;
//	wxString	pStatusBarValueText;		// String used for title on status line

    DECLARE_EVENT_TABLE()
};




class PoleZeroPlot : public wxPanel
{
public:
	PoleZeroPlot (wxWindow* parent, wxWindowID id, wxSize plotSize);
	~PoleZeroPlot ();
    void   		AddDataSet (const SLComplexRect_s *pSrc, int plotSize, const int plotType);

	PoleZeroPlotCanvas	*PlotCanvas;

    void		Draw (wxDC& dc, bool draw_bitmaps = TRUE);

private:
	SLComplexRect_s	*pDataSet;

	int			DataSetSize;			// Size of data set - may be different from the plot size

	int			PlotType;				// Type of plot data
	wxSize		PlotSize;				// Size of plot

    DECLARE_EVENT_TABLE()
};



// Define a new canvas for the pole zero plot
class PoleZeroPlotCanvas: public wxWindow
{
public:
    PoleZeroPlotCanvas (PoleZeroPlot *pPoleZeroPlot, wxPanel *parent, wxPoint plotPoint, wxSize plotSize);
    ~PoleZeroPlotCanvas ();
    void OnPaint (wxPaintEvent& event);

private:
	wxSize			PlotSize;
	wxPanel			*m_owner;
	PoleZeroPlot	*m_PoleZeroPlot;

	double			*pDataSet;

    DECLARE_EVENT_TABLE()
};



#endif			// End of #ifndef _NGL_H

