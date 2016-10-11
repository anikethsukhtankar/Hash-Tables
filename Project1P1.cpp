//**************************************************************
//  main.cpp
//  HashTable
//
//  Created by Shailee Desai on October 11, 2016.
//  Demonstrate a simple Hash Table in C++.
//  Implements a Linked List class.
//**************************************************************

#include "HashTable.h"
#include "HashTable.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include <iostream> //to use cout
#include <iomanip> //to format output
#include <sstream>
#include <string>
#include <deque>
#include <vector>

using namespace std;

void printMenu();

int main()
{
    // local variables, can be accessed anywhere from the main method
       char input1 = 'Z';
       string inputInfo;

       string discipline, gender, isTeam, event, venue, medal, athlete, country, itemKey;
       Item * found;
       int tablesize,count=0,numofcommands;
       string line="";
       bool success = false;

       cout << "Please Enter The Table Size:\n";
       cin >> tablesize;

       // Create a Hash Table of 13 Linked List elements.
       HashTable table(tablesize);

       cout << "Please Enter Athlete Data:\n";

       while(line!="InsertionEnd"){
            getline(cin, line);
            std::istringstream ss(line);
            std::string token;
            std::string athleteData[7];
            int i =0;
            if(line!="InsertionEnd" && line!=""){
                while(std::getline(ss, token, ',')) {
                    //std::cout << token << '\n'; Debug
                    athleteData[i] = token;
                    //std::cout << athleteData[i] << '\n'; Debug
                    i=i+1;
                }
                Item * A = new Item {athleteData[0]+athleteData[1]+athleteData[3]+athleteData[6],athleteData[0],athleteData[1],athleteData[2],athleteData[3],athleteData[4],athleteData[5],athleteData[6],athleteData[7], NULL};
                table.insertItem(A);
            }
       };

       cout << "Please Enter The Number Of Commands To Follow:\n";
       cin >> numofcommands;
       cin.ignore();

       while(line!="quit"){
            printMenu();
            cout << "Please Enter A Command:\n";
            getline(cin, line);
            std::istringstream ss(line);
            std::string token;
            std::string commandLine[4];
            int i =0;
            while(std::getline(ss, token, ',')) {
                    //std::cout << token << '\n'; Debug
                    commandLine[i] = token;
                    //std::cout << athleteData[i] << '\n'; Debug
                    i=i+1;
                }

            itemKey = commandLine[1]+commandLine[2]+commandLine[3]+commandLine[4];

            if(commandLine[0]=="hash_display"){

                table.printTable();

            }
            if(commandLine[0]=="hash_search"){
                //cout << itemKey; Debug
                found = table.getItemByKey( itemKey );
                if (found != NULL )
                cout << "The medal recipient "<< commandLine[4] << " has the medal of "<< found -> medal <<"\n";
                else
                cout << commandLine[4] <<" for "<< commandLine[1] <<" with event "<<commandLine[3]<<" not found\n";

            }
            if(commandLine[0]=="hash_delete"){
                //cout << itemKey; Debug
                success = table.removeItem( itemKey );
                if (success == true)
                cout << "The medal recipient "<< commandLine[4] <<" for " << commandLine[1] <<" with event "<<commandLine[3] <<" deleted\n";
                else
                cout << commandLine[4] <<" for "<<commandLine[1]<<" with event "<<commandLine[3]<<" not found\n";

            }
            if(count >= numofcommands){
                break;
            }
            count=count+1;
       }

    return 0;

}

  /** The method printMenu displays the menu to a user**/
  void printMenu()
   {
     cout << "\n\nCommand\n";
     cout << "------\t\t------\n";
     //cout << "A\t\tAdd Athlete Data\n";
     cout << "hash_display\n";
     cout << "hash_search\n";
     cout << "hash_delete\n";
     cout << "quit\n\n";
     //cout << "?\t\tDisplay Help\n\n";
  }

