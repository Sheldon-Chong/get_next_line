## get_next_line
The aim of get_next_line is to create a function that reads a file, line by line, with efficient memory handling. Whenever the function is called, the next line should be retreived, until it reaches the end of the file.

## 📖 Concepts
Fds, opening files, reading, static variables

## ⬇️ Clone this repository
```zsh
git clone git@github.com:Sheldon-Chong/get_next_line.git
```

## My experience with this project
At first glance, get_next_line seems fairly straightforward. However, the project comes with strict constraints, such as requiring a fixed number of bytes to be read per call to `read()` and prohibiting backtracking or re-reading from a previous point in the file. Once I figured out the algorithm, I was impressed by how resourceful and efficient it was at handling file reading while adhering to these limitations.
