# Final Design Document

**Title:** Record Collection Catalog System  
**Student:** Enrique Morell 
**Course:** COSC 2436 Fall 23  

## Object:

Our object in this project is a Record. Each record is defined with four attributes:

- **Album Name:** The name of the record
- **Artist Name:** The name of the artist or band
- **Genre:** The genre that the record falls into
- **Year:** The year the record was released

## Data Structures:

For managing the collection, we use two data structures:

1. **Array List:** A Dynamic Array is used to store the entire collection, allowing for efficient addition and removal of records from the collection, as well as the ability to access any record in the collection directly by its name.
2. **Linear Search:** The key for the linear search is the genre, and the value is the record itself.

## Algorithms:

We implemented two different search algorithms:

- **Linear Search:** Used in conjunction with the Array List for searching records by any genre.
- **Array List** Used for searching records by artist, providing a constant time complexity.

For sorting the collection, the Quick Sort algorithm is used due to its average time complexity of O(n log n), and it's not difficult to implement and is used to sort the records by year of release.

## User Interface:

The user interface is a simple command-line interface, with prompts for various options to interact with the collection, including options to add a new record to the collection, remove a record from the collection, display all records in the collection, search for a specific record, and sort the collection.

## Persistent Storage:

File input/output operations are used to read and write the record collection data to a file, ensuring that the data is not lost when the program ends and can be retrieved when the program is started again.

## Exception Handling:

The program handles exceptions appropriately by catching them, displaying a meaningful error message to the user, and then continuing with the next operation.
