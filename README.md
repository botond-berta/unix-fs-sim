# unix-fs-sim

A UNIX-style filesystem simulator written in C++. Supports a hierarchical directory structure with files, directories, and symbolic links — all in memory, with persistent storage between sessions.

## Features

- Navigate the filesystem with familiar UNIX commands (`cd`, `ls`)
- Create and remove files and directories (`touch`, `mkdir`, `rm`)
- Move and rename entries (`mv`)
- Create symbolic links to directories (`ln`)
- Supports both absolute and relative paths, including `..`
- Persistent state: automatically saved to and loaded from `filesystem.dat`
- Fully redirectable stdin/stdout — works in batch mode

## Usage

```
mkdir <path>        Create a new directory
touch <path>        Create a new empty file
ls [path]           List directory contents
cd <path>           Change current directory
ln <source> <dest>  Create a symbolic link to a directory
rm <path>           Remove a file, link, or directory (recursive)
mv <source> <dest>  Move or rename an entry
exit                Save state and quit
```

### Example session

```
/> mkdir home
/> mkdir home/user
/> touch home/user/notes.txt
/> ln home/user docs_link
/> cd home/user
/home/user> ls
notes.txt
/home/user> cd ../..
/> ls
home/
docs_link -> /home/user
```

## Persistence

The filesystem state is saved automatically to `filesystem.dat` on exit and restored on startup. The file format is plain text:

```
DIR /home
DIR /home/user
FILE /home/user/notes.txt
LINK /docs_link -> /home/user
```

## Build

```bash
g++ -o fs main.cpp
./fs
```

## Implementation

- No STL containers used — all data structures implemented from scratch
- Object-oriented design with a clean inheritance hierarchy
- Modular structure with separate compilation units