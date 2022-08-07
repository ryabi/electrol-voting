#include"MainFrame.h"
#include"VotingArea.h"
//Function for event handling of LogIn and registration frame

void MainFrame::OnSignUp(wxCommandEvent& evt) {
	wxLogStatus("Sign Up Clicked");
	string Buffer[5];
	Buffer[0] = firstnamectrl->GetValue().ToStdString();
	Buffer[1] = lastnamectrl->GetValue().ToStdString();
	Buffer[2] = ctzctrl->GetValue().ToStdString();
	Buffer[3] = usernamectrl->GetValue().ToStdString();
	Buffer[4] = passwordctrl->GetValue().ToStdString();
	
	if (!Buffer[4].compare(confirmpasswordctrl->GetValue().ToStdString())) {
		VoterData voterID(Buffer);
		wxMessageDialog* confirm = new wxMessageDialog(NULL, "Are you sure provided data are right ?", "Signing Up", wxYES_DEFAULT | wxYES_NO | wxICON_QUESTION);
		confirm->ShowModal();
		//Writing Data on File
		voterID.write_data();
	}
	else //if(Buffer[4].compare(confirmpasswordctrl->GetValue().ToStdString())!=0) 
	{
		wxMessageDialog* retry = new wxMessageDialog(NULL, "Recheck password and Confirm password");
		retry->ShowModal();
	}
}

void MainFrame::OnLogIn(wxCommandEvent& e) {
	string Buffer[4];
	Buffer[0] = loginusername->GetValue().ToStdString();
	Buffer[1] = loginpassword->GetValue().ToStdString();
	/*VoterData voterID;
	ifstream ReadingVoterData("Data.dat",ios::binary |ios::in);
	if (!ReadingVoterData) {
		cout << "File can't be opened" << endl;
			return ;
	}
	ReadingVoterData.seekg(0, ios::beg);
	ReadingVoterData.seekg(0, ios::end);
	int counter = ReadingVoterData.tellg() / sizeof(*this);
	do {
		ReadingVoterData.read(reinterpret_cast<char*>(&voterID), sizeof(voterID));
	ReadingVoterData.seekg(sizeof(voterID), ios::cur);
	} while (!ReadingVoterData.eof());*/
	VotingArea* voting = new VotingArea("Electrol Voting System", wxDefaultPosition, wxSize(800, 800));
	voting->Show(true);
	delete this;
}