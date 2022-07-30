#pragma once
#include <wx/wx.h>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

class MainFrame:public wxFrame{
public:
	MainFrame(const wxString &title,const wxPoint &pos,const wxSize &Size);
private:
	//Event handler 
	void OnLogIn(wxCommandEvent & );
	void OnSignUp(wxCommandEvent &);

private:
	//Pointer variables of Control Elemet of UI
	wxTextCtrl* firstnamectrl;
	wxTextCtrl* lastnamectrl;
	wxTextCtrl* ctzctrl;
	wxTextCtrl* usernamectrl;
	wxTextCtrl* passwordctrl;
	wxTextCtrl* loginusername;
	wxTextCtrl* loginpassword;

};
class VoterData {
private:
	string firstname;
	string lastname;
	string ctznum;
	string username;
	string password;
public:
	VoterData(){}
	VoterData(string* s) :firstname(s[0]), lastname(s[1]), ctznum(s[2]), username(s[3]),password(s[4]) {}
	string GetUserName() { 
		return username;
	}
	string GetPassWord() {
		return password; 
	}
};
class MyApp:public wxApp {
public:
	bool OnInit();
};
wxIMPLEMENT_APP(MyApp);


//Event handler

void MainFrame::OnSignUp(wxCommandEvent& evt) {
	wxLogStatus("Sign Up Clicked");
	string Buffer[5];
	Buffer[0] = firstnamectrl->GetValue().ToStdString();
	Buffer[1] = lastnamectrl->GetValue().ToStdString();
	Buffer[2] = ctzctrl->GetValue().ToStdString();
	Buffer[3] = usernamectrl->GetValue().ToStdString();
	Buffer[4] = passwordctrl->GetValue().ToStdString();
	VoterData VoterID(Buffer);
	wxMessageDialog* confirm = new wxMessageDialog(NULL, "Are you sure provided data are right ?", "Signing Up",wxYES_DEFAULT|wxNO| wxICON_QUESTION);
	confirm->ShowModal();
	//Writing Data on File
	fstream WritingVoterData("Data.dat",ios::binary| ios::app);
	
	WritingVoterData.write(reinterpret_cast<char*>(&VoterID), sizeof(VoterID));
	WritingVoterData.close();

}

void MainFrame::OnLogIn(wxCommandEvent& e) {
	string Buffer[4];
	VoterData *voterID;
	Buffer[0] = loginusername->GetValue().ToStdString();
	Buffer[1] = loginpassword->GetValue().ToStdString();
	

	fstream ReadingVoterData("Data.txt", ios::in);
	while (!ReadingVoterData.eof()) {
		voterID = new VoterData;
		ReadingVoterData.read(reinterpret_cast<char*>(voterID), sizeof(voterID));
		Buffer[2] = voterID->GetUserName();
		Buffer[3] = voterID->GetPassWord();
		if (!Buffer[0].compare(Buffer[2]) && !Buffer[1].compare(Buffer[3])) {
			wxMessageBox("Log in Sucessful");
		}
		
		delete voterID;
	}

	
}



