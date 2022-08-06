#include "MainFrame.h"
extern int flag;
void FontChanger(wxStaticText* Name, int a) {
	wxFont font = Name->GetFont();
	font.SetPointSize(a);
	Name->SetFont(font);
}
MainFrame::MainFrame(const wxString& title,const wxPoint &pos,const wxSize &size) : wxFrame(NULL, wxID_ANY, title,pos,size) {

	CreateStatusBar(2);

	//Creating the outter window
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	//Creating the inner window
	wxPanel* HeaderPanel = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(750, 50));
	wxPanel* registerPanel = new wxPanel(this,wxID_ANY,wxPoint(0,60),wxSize(750,350));
	wxPanel* loginPanel = new wxPanel(this);

	//Element for Header Panel
	wxStaticText* Header = new wxStaticText(HeaderPanel, wxID_STATIC,"Welcome to Digital Voting System",wxPoint(170,20),wxDefaultSize);
	FontChanger(Header, 18);
	

	//Element for the register panel is added
	
	wxStaticText* signUpText = new wxStaticText(registerPanel, wxID_ANY, "Register to Digital Voting System", wxPoint(50, 5));
	wxFont font = signUpText->GetFont();
	font.SetPointSize(12);
	font.SetWeight(wxFONTWEIGHT_BOLD);
	signUpText->SetFont(font);

	wxStaticText* firstname = new wxStaticText(registerPanel, wxID_ANY, "First Name :", wxPoint(15, 40), wxSize(85, -1));
	FontChanger(firstname, 12);
	firstnamectrl = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(140, 35), wxSize(200, -1));
	wxStaticText* lastname = new wxStaticText(registerPanel, wxID_ANY, "Last Name :", wxPoint(360, 40), wxSize(75, -1));
	FontChanger(lastname, 12);
	lastnamectrl = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(460, 35), wxSize(200, -1));
	string  provinceName[] = { "Provience 1" ,"Provience 2","Bagmati","Gandaki","Lumbini","Karnali","Sudur Paschim" };
	wxStaticText* Province = new wxStaticText(registerPanel, wxID_ANY, "Province:", wxPoint(15, 60), wxDefaultSize);
	wxChoice* ProvinceList = new wxChoice(registerPanel, wxID_ANY,wxPoint(140,65),wxSize(200,-1));



	wxStaticText* ctz = new wxStaticText(registerPanel, wxID_ANY, "Citizenship Number :", wxPoint(15, 110), wxSize(120, -1));
	ctzctrl = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(140, 105), wxSize(200, -1));
	wxStaticText* username = new wxStaticText(registerPanel, wxID_ANY, "UserName :", wxPoint(15, 140), wxSize(80, -1));
	usernamectrl = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(140,135), wxSize(200, -1));
	wxStaticText* passWord = new wxStaticText(registerPanel, wxID_ANY, "Password :", wxPoint(15, 170), wxSize(80, -1));
	passwordctrl = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(140, 165), wxSize(200, -1), wxTE_PASSWORD);
	wxButton* signup = new wxButton(registerPanel, wxID_ANY, "Sign Up", wxPoint(80, 200), wxSize(140, -1));
	signup->Bind(wxEVT_BUTTON, &MainFrame::OnSignUp,this);

	//Element of login is added;
	wxStaticText* loginText = new wxStaticText(loginPanel, wxID_ANY, wxT("Login to Digital Voting System"), wxPoint(50, 5));
	wxFont font2 = loginText->GetFont();
	font2.SetPointSize(12);
	font2.SetWeight(wxFONTWEIGHT_BOLD);
	loginText->SetFont(font2);
	wxStaticText* userName2 = new wxStaticText(loginPanel, wxID_ANY, "UserName :", wxPoint(15, 30), wxSize(100, -1));
	loginusername = new wxTextCtrl(loginPanel, wxID_ANY, "", wxPoint(140, 25), wxSize(200, -1));
	wxStaticText* passWord2 = new wxStaticText(loginPanel, wxID_ANY, "Password :", wxPoint(15, 60), wxSize(80, -1));
	loginpassword = new wxTextCtrl(loginPanel, wxID_ANY, "", wxPoint(140, 55), wxSize(200, -1),wxTE_PASSWORD);
	wxButton* login = new wxButton(loginPanel, wxID_ANY, "Login", wxPoint(80, 100), wxSize(140, -1));
	login->Bind(wxEVT_BUTTON, &MainFrame::OnLogIn, this);

	//Panels were added to the sizer

	sizer->Add(HeaderPanel, 1, wxEXPAND |wxTOP |wxRIGHT |wxLEFT, 10);
	sizer->Add(registerPanel, 3, wxEXPAND | wxTOP | wxRIGHT | wxLEFT, 10);
	sizer->Add(loginPanel, 2, wxEXPAND | wxALL, 10);
	this->SetSizerAndFit(sizer);

}
//Function for event handling

void MainFrame::OnSignUp(wxCommandEvent& evt) {
	wxLogStatus("Sign Up Clicked");
	string Buffer[5];
	Buffer[0] = firstnamectrl->GetValue().ToStdString();
	Buffer[1] = lastnamectrl->GetValue().ToStdString();
	Buffer[2] = ctzctrl->GetValue().ToStdString();
	Buffer[3] = usernamectrl->GetValue().ToStdString();
	Buffer[4] = passwordctrl->GetValue().ToStdString();
	VoterData voterID(Buffer);
	wxMessageDialog* confirm = new wxMessageDialog(NULL, "Are you sure provided data are right ?", "Signing Up", wxYES_DEFAULT | wxYES_NO | wxICON_QUESTION);
	confirm->ShowModal();
	//Writing Data on File
	voterID.write_data();
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
	flag++;
	delete this;
}