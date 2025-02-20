# CDatabase - A Simple Key-Value Store with Memory Caching and File Persistence

## File Structure
```
cdatabase/
│── src/
│   ├── main.c          # Entry point of the application
│   ├── db.c            # Implementation of key-value database logic
│   ├── cache.c         # Memory caching (hash table) logic
│── include/
│   ├── db.h            # Function prototypes for db.c
│   ├── cache.h         # Function prototypes for cache.c
│── database.txt        # Persistent storage file
│── Makefile            # For building the project
│── README.md           # Project documentation
```

## README.md (GitHub Documentation)
```markdown
# CDatabase

CDatabase is a simple key-value store written in C with memory caching and file persistence. It allows fast key-value lookups using an in-memory hash table while persisting data to disk.

## Features
✅ **In-Memory Caching** - Fast lookups using a hash table.
✅ **File Persistence** - Stores data in `database.txt` to survive restarts.
✅ **Thread-Safety** - Uses `pthread_mutex_t` to handle concurrent access.
✅ **Modular Design** - Separated concerns for better maintainability.

## Installation & Usage
```sh
# Clone the repository
git clone https://github.com/yourusername/cdatabase.git
cd cdatabase

# Build the project
make

# Run the database application
./cdatabase
```

## Example Usage
```
1. Set Key-Value
2. Get Value
3. Delete Key
4. Exit
Enter choice: 1
Enter key: name
Enter value: Michael
Stored: name = Michael

Enter choice: 2
Enter key: name
Value: Michael

Enter choice: 3
Enter key to delete: name
Deleted key: name

Enter choice: 4
Exiting...
```

## Future Improvements
- Add expiration policies for cache entries.
- Improve file storage efficiency with structured formats (JSON, binary).
- Introduce a CLI or API for interaction.
```
