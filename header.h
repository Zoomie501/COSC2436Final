#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Record {
    string name;
    string genre;
    string artist;
    int year;

    Record() :name(""), genre(""), artist(""), year(0) {}

    Record(const string& _name, const string& _genre, const string& _artist, const int _year)
        : name(_name), genre(_genre), artist(_artist), year(_year) {}
};

class MyArray {
private:
    Record* arr;
    int size;
    int capacity;
    void quickSortHelper(int left, int right);
    string recordToString(const Record& record) const;

public:
    MyArray() : arr(nullptr), size(0), capacity(1) {
        resize();
    } // constructor

    ~MyArray() {
        delete[] arr;
    } // destructor

    void addRecord(const string& name, const string& genre, const string& artist, const int year);
    inline void removeRecord(const string& name);
    vector<Record>findArtist(const string& searchArtist) const;
    vector<Record>findGenre(const string& searchGenre) const; 
    void displayRecords() const;
    void resize();
    void addRecordFromInput();
    void quickSort(int left, int right);
    void sortByYear();
    void loadFromFile(const string& filename);
    void saveToFile(const std::string& filename) const {
      std::ofstream file(filename);

      if (!file.is_open()) {
          std::cerr << "Error: Unable to open file for writing." << std::endl;
          return;
      }

      for (int i = 0; i < size; ++i) {
          file << recordToString(arr[i]) << std::endl;
      }

      file.close();
    }
};


void MyArray::resize() {
    int newCapacity = (capacity == 0) ? 1 : capacity * 2;
    Record* newArr = new Record[newCapacity];

    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}
vector<Record> MyArray::findGenre(const string& searchGenre) const {
    vector<Record> matchingRecords;

    for (int i = 0; i < size; ++i) {
        if (arr[i].genre == searchGenre) {
            matchingRecords.push_back(arr[i]);
        }
    }
    return matchingRecords;
    if (!matchingRecords.empty()) {
        cout << "Records in genre " << searchGenre << ":" << endl;
        for (const auto& record : matchingRecords) {
            cout << "Album: " << record.name << ", Artist: " << record.artist
                 << ", Genre: " << record.genre << ", Year: " << record.year << endl;
        }
    } else {
        cout << "No records found for genre: " << searchGenre << endl;
    }
  return matchingRecords;
}
void MyArray::addRecord(const string& name, const string& artist, const string& genre, const int year) {
    if (size == capacity) {
        resize();
    }
    arr[size++] = Record(name, genre, artist, year);
}

void MyArray::removeRecord(const string& name) {
    for (int i = 0; i < size; ++i) {
        if (arr[i].name == name) {
            for (int j = i; j < size - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            size--;
            return;
        }
    }
    cout << "Record with Name " << name << " not found." << endl;
}

vector<Record> MyArray::findArtist(const string& artist) const {
    vector<Record> matchingRecords;

    for (int i = 0; i < size; ++i) {
        if (arr[i].artist == artist) {
            matchingRecords.push_back(arr[i]);
        }
    }

    return matchingRecords;
}

void MyArray::displayRecords() const {
    for (int i = 0; i < size; ++i) {
        cout << "Album: " << arr[i].name << ", Artist: " << arr[i].artist
             << ", Genre: " << arr[i].genre << ", Year: " << arr[i].year << endl;
    }
}
void MyArray::addRecordFromInput(){
  string name, genre, artist;
  int year;

  cout << "Enter Album Name ";
    getline(cin, name);

  cout << "Enter Artist Name ";
    getline(cin,artist);

  cout << "Enter Genre ";
    getline(cin,genre);

  cout << "Enter Year ";
    cin >> year;

  addRecord(name, artist, genre, year);
}
void MyArray::quickSortHelper(int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2].year; // Change the pivot to the "year" field

    // Partition
    while (i <= j) {
        while (arr[i].year < pivot)
            i++;
        while (arr[j].year > pivot)
            j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Recursion
    if (left < j)
        quickSortHelper(left, j);
    if (i < right)
        quickSortHelper(i, right);
}

void MyArray::quickSort(int left, int right) {
    if (size == 0 || left >= right)
        return;

    quickSortHelper(left, right);
}

void MyArray::sortByYear() {
    quickSort(0, size - 1);

}

void MyArray::loadFromFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    // Clear existing records
    size = 0;

    while (!file.eof()) {
        string line;
        getline(file, line);

        if (!line.empty()) {
            // Parse the line and add a record
            // Assuming the format is: AlbumName,ArtistName,Genre,Year
            istringstream iss(line);
            string name, artist, genre;
            int year;

            getline(iss, name, ',');
            getline(iss, artist, ',');
            getline(iss, genre, ',');
            iss >> year;

            addRecord(name, artist, genre, year);
        }
    } file.close();
      cout << "File loaded successfully." << endl;
}


string MyArray::recordToString(const Record& record) const {
    ostringstream oss;
    oss << record.name << ',' << record.artist << ',' << record.genre << ',' << record.year;
    return oss.str();
}
