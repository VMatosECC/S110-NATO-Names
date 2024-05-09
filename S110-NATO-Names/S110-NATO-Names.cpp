// S110-NATO-Names.cpp 
// Goal: Spell the contents of a string using NATO codes
//       NATO symbols, codes, and pronuntiation are available
//       in a disk file. After reading the file, three vectors
//       are created to quickly retrieve symbol, code, and sound.
// --------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//Prototypes


void populateDatabase(vector<string>& vSymb, vector<string>& vNATO, vector<string>& vSound);
void showDatabase(vector<string>& vSymb, vector<string>& vNATO, vector<string>& vSound);
int sequentialSearch(vector<string> vSymb, char key);

int main()
{
    vector<string> vSymb;
    vector<string> vNATO;
    vector<string> vSound;

    populateDatabase(vSymb, vNATO, vSound);
    //showDatabase(vSymb, vNATO, vSound);

    do {
        cout << "\nEnter a string: ";
        string s;
        getline(cin, s);
        for (int i = 0; i < s.size(); i++)
        {
            char key = s[i];
            int dbpos = sequentialSearch(vSymb, key);
            if (dbpos != -1)
            {
                cout << s[i] << "\t" << vNATO[dbpos] << "\t" << vSound[dbpos] << endl;
            }
        }

    } while (true);

    cout << "\nAll done!\n";
}
//-------------------------------------------------------------
int sequentialSearch(vector<string> vSymb, char key)
{
    string skey = string(1, toupper(key));

    for (int i = 0; i < vSymb.size(); i++)
    {
        if (vSymb[i] == skey) return i;
    }
    return -1;
}



//--------------------------------------------------------------
void populateDatabase(vector<string>& vSymb, vector<string>& vNATO, vector<string>& vSound)
{
    string token;
    ifstream myfile("c:/temp/NATO-Letter-Code.csv");
    if (!myfile) {
        cout << "FATAL ERROR - file not found\n";
        exit(1);
    }

    while (getline(myfile, token, ',')) {
        vSymb.push_back(token);

        getline(myfile, token, ',');
        vNATO.push_back(token);

        getline(myfile, token);  
        vSound.push_back(token);
        
        // Mac users -------------------------------------------
        // (Replace the two lines above with the following code)
        
        // getline(myfile,token, '\r');
        // vSound.push_back(token);
        // myfile.ignore()
    }
    myfile.close();
}

void showDatabase(vector<string>& vSymb, vector<string>& vNATO, vector<string>& vSound)
{
    for (int i = 0; i < vSymb.size(); i++)
    {
        cout << "\nDBPos:     " << i << endl;
        cout << "Symbol:    " << vSymb[i] << endl;
        cout << "NATO code: " << vNATO[i] << endl;
        cout << "Sound:     " << vSound[i] << endl;

    }
}