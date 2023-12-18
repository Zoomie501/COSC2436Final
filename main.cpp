#include <iostream>
#include <string>
#include <fstream>
#include "Arrayy.h"

using namespace std;


int main() {
    MyArray myArray;
   
    int option;
  
    do {
        cout << "Menu:" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. Search Records by Artist" << endl;
        cout << "3. Search Records by Genre" << endl;
        cout << "4. Display Records" << endl;
        cout << "5. Sort Records by Year" << endl;
        cout << "6. Save to File" << endl;
        cout << "7. Load from File" << endl;
        cout << "8. Remove Record" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> option;
        cin.ignore(); // to clear the newline

        switch (option) {
            case 1: { // Add a record through user input
                cout << "Adding a new record:" << endl;
                myArray.addRecordFromInput();
                break;
            }
            case 2: { // Search for records by artist
                cout << "Enter the artist name to search: ";
                string input;
                getline(cin, input);

                vector<Record> matchingRecords = myArray.findArtist(input);

                if (!matchingRecords.empty()) {
                    cout << "Records by " << input << ":" << endl;
                    for (const auto &record : matchingRecords) {
                        cout << "Album: " << record.name << ", Artist: " << record.artist
                             << ", Genre: " << record.genre << ", Year: " << record.year << endl;
                    }
                } else {
                    cout << "No records found for artist: " << input << endl;
                }
                break;
            }
          case 3: { // Search for records by genre
              cout << "Enter the genre to search: ";
              string input;
              getline(cin, input);

              vector<Record> matchingRecords = myArray.findGenre(input);

              if (!matchingRecords.empty()) {
                  cout << "Records in genre " << input << ":" << endl;
                  for (const auto &record : matchingRecords) {
                      cout << "Album: " << record.name << ", Artist: " << record.artist
                           << ", Genre: " << record.genre << ", Year: " << record.year << endl;
                  }
              } else {
                  cout << "No records found for genre: " << input << endl;
              }
              break;
          }
            case 4: { // Display all records
                myArray.displayRecords();
                break;
            }
              case 5: { // Sort records by year
                myArray.sortByYear();
                cout << "Records sorted by year." << endl;
                break;
            }
              case 6: {
                myArray.saveToFile("records.txt");
                break;
              }
              case 7:{
                myArray.loadFromFile("records.txt");
                break;
              }
          case 8: { // Remove a record by name
              cout << "Enter the name of the record to remove: ";
              string name;
              getline(cin, name);
              myArray.removeRecord(name); // Pass the input 'name' to the removeRecord function
              break;
          }
            case 0:
                cout << "Exiting program." << endl;
                break;

          
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 0);

    return 0;
}
