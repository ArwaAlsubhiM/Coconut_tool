//
//  File.cpp
//  File_example
//
//  Created by Arwa Alsubhi on 23/11/2021.
//

#include <stdio.h>
#include <iostream>
#include<string.h>
#include <fstream>
#include "TypestateLibrary.h"
using namespace std;

// file class with all methods to handle file objects 
class File{
    string myfileName;
    ifstream file;
    string fileText;
    
public:
    File(){
        
    }
    void OpenFile(){
        file.open(myfileName.c_str());
        
    }
    void read(){
        
       
        if (getline(file, fileText)) cout << fileText;
        
    }
    void ReadNext(){
        
        if (getline(file, fileText)) cout << fileText;
        
    }
    void Close(){
        file.close();
    }
    
  
};

// define states of the protocol 
 enum class FileState{
    INIT,
    OPEN,
    READ,
    CLOSE,
};

// exctract the templates 
using TypestateTool::map_transition;

using TypestateTool::map_protocol;



 // defined the protocol
 
using File_protocol=  map_protocol<map_transition<FileState::INIT, FileState::OPEN, &File::OpenFile>,
map_transition<FileState::OPEN,FileState::READ, &File::read>,
map_transition<FileState::READ, FileState::READ, &File::ReadNext>,
map_transition<FileState::READ, FileState::CLOSE, &File::Close>
>;
// assign it to class


Assign_to_Class(File, File_protocol);


int main(int argc, const char * argv[]) {
    // insert code here...
    File file;
    file.OpenFile();
    file.read();
    file.ReadNext();
    file.Close();
    return 0;
}

