#pragma once
#include <wx/wx.h>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
extern int flag;
class MainFrame:public wxFrame{
public:
	MainFrame(const wxString& title, const wxPoint& pos, const wxSize& Size);
	
private:
	//Pointer variables of Control Elemet of UI
	wxTextCtrl* firstnamectrl;
	wxTextCtrl* lastnamectrl;
	wxTextCtrl* ctzctrl;
	wxTextCtrl* usernamectrl;
	wxTextCtrl* passwordctrl;
	wxTextCtrl* loginusername;
	wxTextCtrl* loginpassword;
	
private:
	//Event handler 
	void OnLogIn(wxCommandEvent & );
	void OnSignUp(wxCommandEvent &);
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
	string GetPassWord(){
		return password; 
	}
	void write_data() {
		ofstream WritingVoterData("Data.dat", ios::binary | ios::app |ios::out);
		WritingVoterData.write(reinterpret_cast<char*>(this), sizeof(*this));
		
	}
	
	/*void read_data() {
		int counter;
		ifstream ReadingVoterData("Data.dat", ios::binary);
		if (!ReadingVoterData) {
			cout << "File can't be opened"<<endl;
		}
		ReadingVoterData.seekg(0, ios::end);
		counter = ReadingVoterData.tellg()/sizeof(*this);	
	}*/
};




