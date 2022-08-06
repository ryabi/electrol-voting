#include "VotingArea.h"
#include <wx/wx.h>
VotingArea::VotingArea(const wxString& title,const wxPoint &pos,const wxSize &size) :wxFrame(NULL, wxID_ANY, title,pos,size) {
	CreateStatusBar(1);
	//Making menu Bar
	wxMenu* filemenu = new wxMenu;
	filemenu->Append(wxID_ABOUT);
	filemenu->Append(wxID_CUT);
	wxMenu* helpmenu = new wxMenu;
	helpmenu->Append(wxID_HELP);

	wxMenuBar* menubar = new wxMenuBar;
	menubar->Append(filemenu, "&File");
	menubar->Append(helpmenu, "&Help");
	SetMenuBar(menubar);


	//array to hold candident name
	wxArrayString Name;
	Name.Add("Hari");
	Name.Add("Biraj");
	Name.Add("Nitesh");

	//Main body 
	wxPanel* HeaderPanel = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(800, 100));
	wxStaticText* Header = new wxStaticText(HeaderPanel, wxID_ANY, "Welcome to the Digital Voting System", wxPoint(50, 20));
	wxFont font = Header->GetFont();
	font.SetPointSize(18);
	Header->SetFont(font);
	//voting section 
	wxPanel* Bodypanel = new wxPanel(this, wxID_ANY, wxPoint(0, 101), wxSize(1000, 699));
	wxStaticText* persident = new wxStaticText(Bodypanel, wxID_ANY, "Vote for Persident", wxPoint(85, 50), wxSize(100, 50));
	wxChoice* persidentList = new wxChoice(Bodypanel, wxID_ANY, wxPoint(85, 100), wxSize(100, -1), Name);
	wxStaticText* vicepersident = new wxStaticText(Bodypanel, wxID_ANY, "Vote for Vice Persident", wxPoint(300, 50));
	wxChoice* vicpPersidentList = new wxChoice(Bodypanel, wxID_ANY, wxPoint(300, 100), wxSize(100, -1));


}