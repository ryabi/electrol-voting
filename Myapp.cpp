#include<wx/wx.h>
#include "Myapp.h"
#include"MainFrame.h"
#include "VotingArea.h"
extern int flag;
bool MyApp::OnInit() {
	MainFrame* frame = new MainFrame("Electrol Voting System", wxDefaultPosition, wxSize(800, 800));
	frame->Show();
	if (flag) {
		VotingArea* voting = new VotingArea("Electrol Voting System", wxDefaultPosition, wxSize(800, 800));
		voting->Show();
	}
	return true;
}
wxIMPLEMENT_APP(MyApp);