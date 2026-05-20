#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<iostream>
#include<sstream>
#include<cstring>

const string DATAFILE = "datafile.dat";


using namespace std;
short int generateid(){
    static short int id = 1;
    return id++;
}

struct Contact{
    short int id;
    string name;
    string phonenumber;
};

class Phonebook{
private:
    vector<Contact> contacts;
public:
    ~Phonebook(){
        cout << "info: triggered deconstructor...." << endl;
    };

    void addContact(Contact &newContact){
        contacts.push_back(newContact);
    };

    void listContacts(){
        ruler
        cout << "Records #" << contacts.size() << endl;
        for(short int i = 0; i< contacts.size(); ++i){
            cout << contacts[i].id << " " << contacts[i].name<< " " << contacts[i].phonenumber << endl;
        }
    };

    Contact inputContact(){
        Contact newContact;
        ruler
        cout << "Please enter name:";
        getline(cin >> ws, newContact.name);
        ruler
        cout << "Please enter phone number:";
        getline(cin >> ws, newContact.phonenumber);
        newContact.id = generateid();
        return newContact;
    }

    void saveData(){
        cout << "Saving data to file.." << endl;
    
        // Create and open a text file
        ofstream outFile(DATAFILE);

        if (outFile.is_open()) {
            for (const Contact& val : contacts) {
                outFile << val.id << "|" << val.name << "|"<< val.phonenumber << "|\n";
            }
            outFile.close();
        }
    }
    

    string loadFile(){
        cout << "Loading data to file.." << endl;
        ifstream inFile;
        inFile.open(DATAFILE); //open the input file

        stringstream strStream;
        strStream << inFile.rdbuf(); //read the file
        string datafileStream = strStream.str(); //str holds the content of the file

        // cout << datafileStream << "\n"; //you can do anything with the string!!!
        // bool eof = false;
        // while(!eof){
        //     strstr(datafileStream, "\n")
        // }
        return datafileStream;
        // cout << datafileStream << endl;

    }

    void loadData(string data){
        string record;
        short endIndex = 0;
        short startIndex = 0;
        short int recordCounter = 0;
        while(true){
            endIndex = data.find("\n",startIndex);
            if(endIndex < 0){
                break;
            }
            record = data.substr(startIndex,endIndex);
            composeContact(record);
            startIndex = endIndex+1;
            recordCounter++;
        }
        cout << "Number of Records loaded: " << recordCounter << endl;
    }

    void composeContact(string record){
        Contact contactEntry ;
        int startIndex = 0;
        int endIndex = 0;
        endIndex = record.find("|",startIndex);
        contactEntry.id = stoi(record.substr(startIndex,endIndex));
        startIndex = endIndex+1;
        endIndex = record.find("|",startIndex);
        contactEntry.name = record.substr(startIndex,endIndex-startIndex);
        startIndex = endIndex+1;
        endIndex = record.find("|",startIndex);
        // cout << "\n index "<< startIndex << " " << endIndex << endl;
        contactEntry.phonenumber = record.substr(startIndex,endIndex-startIndex);
        contacts.push_back(contactEntry);
    }

    void clearEntries(){
        contacts.clear();
    }

};


void phonebookApp(){
    string command = "";

    map<string, int> commandMap;
    commandMap["add"] = 1;
    commandMap["list"] = 2;
    commandMap["quit"] = 3;
    commandMap["save"] = 4;
    commandMap["load"] = 5;
    commandMap["delete"] = 6;
    commandMap["clear"] = 7;

    cout << "Starting phonebook App" << endl;
    Phonebook phonebook;
    Contact newContact;
    do {
        ruler
        cout << "Enter a command: ";
        cin >> command;

        int switchValue = commandMap[command];

        switch (switchValue) {
        case 1:
            cout << "adding contact" << endl;
            newContact = phonebook.inputContact();
            phonebook.addContact(newContact);
            break;

        case 2:
            cout << "list contacts" << endl;
            phonebook.listContacts();
            break;
        
        case 3:
            cout << "Exiting...." << endl;
            break;

        case 4:
            phonebook.saveData();
            break;

        case 5:
            phonebook.loadData(phonebook.loadFile());
            break;
        
        case 6:
            cout << "Delete...." << endl;
            break;
            
        case 7:
            phonebook.clearEntries();
            cout << "Truncating all entries...." << endl;
            break;
        
        default:
            cout << "commands: add, list, save, load, quit."<< endl;
            break;
        }

    }
    while(command != "quit");
    
}