
#include<wx/wx.h>
#include "Myapp.h"
#include"MainFrame.h"
#include "VotingArea.h"

wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit() {
	MainFrame* frame = new MainFrame("Electrol Voting System", wxDefaultPosition, wxSize(800, 800));
	frame->Show(true);
	return true;
}
