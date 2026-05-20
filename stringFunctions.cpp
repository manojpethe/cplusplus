#include<iostream>
#include<vector>
using namespace std;

struct Contact{
    short int id;
    string name;
    string phonenumber;
};

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
    cout << "\n index "<< startIndex << " " << endIndex << endl;
    contactEntry.phonenumber = record.substr(startIndex,endIndex-startIndex);
    // cout << id << "\n" << name << "\n" << phonenumber << endl;
    
}

int main (){
vector <string> records;
string data = "1|manoj|9823282613|\n2|neel|9823282614|\n";
string record;
short endIndex = 0;
short startIndex = 0;
// const short int lastidx = data.size();

    // endIndex = data.find("\n",startIndex);
    // record = data.substr(startIndex,endIndex);
    // records.push_back(record);
    // startIndex = endIndex+1;
    // cout << "startIndex:" << startIndex << " EndIndex:"<< endIndex << " Record: " << record << endl;

    // endIndex = data.find("\n",startIndex);
    // record = data.substr(startIndex,endIndex);
    // records.push_back(record);
    // startIndex = endIndex+1;
    // cout << "startIndex:" << startIndex << " EndIndex:"<< endIndex << " Record: " << record << endl;

    while(true){
        endIndex = data.find("\n",startIndex);
        if(endIndex < 0){
            break;
        }
        record = data.substr(startIndex,endIndex);
        records.push_back(record);
        startIndex = endIndex+1;
    }
    cout << records.size() << endl;

    for(int i = 0; i < records.size(); i++){
        composeContact(records[i]);
    }

}



