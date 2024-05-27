

# Text Editor Program

This is a simple text editor program implemented in C++. It allows users to enter and manipulate text, read from and write to files, and search for specific text within the buffer.

## Features
- Enter and edit text
- Create new lines
- Read from files
- Save text to files
- Search for text within the buffer

## Installation

1. Clone the repository or download the source code.
2. Ensure you have a C++ compiler installed (e.g., GCC).
3. Compile the program using the following command:

```sh
g++ main.cpp -o text_editor
```

## Usage

Run the compiled program:

```sh
./text_editor
```

You will be prompted to enter commands to interact with the program.

## Commands

The program supports the following commands:

1. **Enter Text**
   - **Command:** `1`
   - **Description:** Allows you to enter text. Input ends when you press `Enter`.

2. **Create New Line**
   - **Command:** `2`
   - **Description:** Creates a new line in the buffer.

3. **Read from File**
   - **Command:** `3`
   - **Description:** Reads text from a specified file.
   - **Input:** Enter the name of the file.

4. **Save to File**
   - **Command:** `4`
   - **Description:** Saves the current buffer content to a specified file.
   - **Input:** Enter the name of the file.

5. **Search Text**
   - **Command:** `5`
   - **Description:** Searches for specified text within the buffer.
   - **Input:** Enter the text to search for.

6. **Exit Program**
   - **Command:** `6`
   - **Description:** Exits the program.

## Example Session

```
Enter your command:
1
Enter the text:
Hello, World!
2
New line was created
4
Enter the name of the file:
output.txt
Text saved to output.txt
6
Exiting the program...
```

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.


You can save this content to a file named `README.md`. Here is the code to do so:


