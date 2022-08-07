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
	wxArrayString PresidentName;
	PresidentName.Add("Hari" );
	PresidentName.Add("Biraj");
	PresidentName.Add("Nitesh");

	wxArrayString VicePresidentList;
	VicePresidentList.Add("Shyam");
	VicePresidentList.Add("Ram");

	//Main body 
	
	wxPanel* HeaderPanel = new wxPanel(this, wxID_ANY,wxPoint(0,0),wxSize(800,80));
	wxStaticText* Header = new wxStaticText(HeaderPanel, wxID_ANY, "Welcome to the Digital Voting System", wxPoint(50, 20));
	wxFont font = Header->GetFont();
	font.SetPointSize(18);
	Header->SetFont(font);

	//voting section

	
	
	//wxBoxSizer* innersizer = new wxBoxSizer(wxHORIZONTAL);
	wxPanel* VotingPanel = new wxPanel(this, wxID_ANY,wxPoint(0,80),wxSize(400,700));
	//Voting Persident
	wxStaticText* persident = new wxStaticText(VotingPanel, wxID_ANY, "Vote for Persident", wxPoint(50, 75));
	wxChoice* persidentList = new wxChoice(VotingPanel, wxID_ANY, wxPoint(50, 100), wxSize(100, -1), PresidentName);
	//voting Vice persident
	wxStaticText* vicepersident = new wxStaticText(VotingPanel, wxID_ANY, "Vote for Vice Persident", wxPoint(200, 75));
	wxChoice* vicePersidentList = new wxChoice(VotingPanel, wxID_ANY, wxPoint(200, 100), wxSize(100, -1),VicePresidentList);
	//voting secratary
	wxStaticText* secretary = new wxStaticText(VotingPanel, wxID_ANY, "Vote for secratary", wxPoint(50, 200));
	wxChoice* SecrataryList = new wxChoice(VotingPanel, wxID_ANY, wxPoint(50, 220), wxSize(100, -1));
//voting vice secratary
	wxStaticText* joint_secratary = new wxStaticText(VotingPanel, wxID_ANY, "Vote for Joint-Secratary", wxPoint(200, 200));
	wxChoice* joint_secrataryList = new wxChoice(VotingPanel, wxID_ANY, wxPoint(200, 220),wxSize(100,-1));
//voting tresurer
	wxStaticText* tresurar = new wxStaticText(VotingPanel , wxID_ANY,"Vote for tresurar", wxPoint(50, 300));
	wxChoice* treasurarList = new wxChoice(VotingPanel, wxID_ANY, wxPoint(50, 320),wxSize(100,-1));
//voting 






	wxPanel* NoticePanel = new wxPanel(this, wxID_ANY, wxPoint(420,80),wxSize(350,700));
	wxStaticText* notice = new wxStaticText(NoticePanel, wxID_ANY, "Hello",wxPoint(0,50),wxSize(50,50));
/*
	innersizer->Add(VotingPanel, 1, wxEXPAND|wxTOP | wxRIGHT | wxLEFT, 10);
	innersizer->Add(NoticePanel, 1, wxEXPAND|wxALL,10);
	*/
	//BodyPanel->SetSizerAndFit(innersizer);
}