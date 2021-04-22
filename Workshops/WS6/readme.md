 # Workshop #6: Classes and resources, IO operators
* Version 0.91 (reviewed, minor modifications to the text) 
* Version 1.0 (DIY output corrected)

In this workshop, you will implement classes with resources that follow [the rule of 3](https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)) to be safely copied and assigned.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define and create copy constructors
- define and create copy assignment 
- Prevent copying and assignment in a class
- Overload insertion operator so the class can be printed using ostream
- Overload extraction operator so the class can be read using istream
- Do simple file IO using ifstream and ofstream
- use the C++ string class to extract an unknown number of characters from the input.

## Submission Policy

The workshop is divided into two coding parts; part 1, **LAB** and part 2, **DIY**  and one non-coding part:

- ***LAB*** (part 1): worth 50% of the workshop's total price, is due on **Thursday, March 11th at 23:59:59**.

> Please note that the LAB (part 1) section is **not to be started in your lab session**. You should start it on your own before the day of your lab and join the lab session to ask for help and correct your mistakes.

- ***DIY*** (part 2): worth 50% of the workshop's total price, is due on **Sunday, March 14th at 23:59:59**.  Submissions of *DIY* part that do not contain the *reflection* are not considered valid submissions and are ignored.

- *reflection*: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have prices associated with it but can incur a **penalty of max 40% of the whole workshop's price** if your professor deems it insufficient (you make your prices from the code, but you can lose some on the reflection).

If at the deadline the workshop is not complete, there is an extension of **one day** when you can submit the missing parts.  **The code parts that are submitted late receive 0%.**  After this extra day, the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the price for the entire workshop is 0%**.

Every file that you submit must contain (as a comment) at the top **your name**, **your Seneca email**, **Seneca Employee ID** and the **date** when you completed the work.

If the file contains only your work or work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the price for the parts you got help for, and the person helping you will be clear of any wrongdoing.


## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind ws
```

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace.


# LAB (50%) TextFile module

Your task for this lab is to complete the implementation of the **TextFile** module. This module attaches itself to a text file on the hard drive and loads the content of the text file into an array of **Line**s.

This module is then capable of displaying the text file page by page on the screen or give the user program read-only access to the lines of the text file as an array of C-strings.

A **Textfile** can be safely copied, and the copying will also result in the creation of a copy of the attached file on the hard drive.

A **TextFile** can be safely assigned to another **TextFile**, and the assignment will also overwrite the contents of the target file on the hard drive with the content of the source file.

Unlike all the other modules that you have created till now (containing the implementation of only one class), the **TextFile** module contains two classes; **Line** and **TextFile**.

The **Line** class encapsulates a single line of a text file. The **TextFile** encapsulates a text file on the hard drive and it is a dynamic array of **Lines**. This means an instance of **Line** class should not be able to exist outside of a **TextFile** class.

To enforce this, make the **Line** class fully private and make the **TextFile** class a friend of the **Line** class. Doing so, only within the scope of the **TextFile** class, a **Line** can be instantiated and accessed:

```C++
class TextFile; // forward declaration
class Line{  // fully private, no public member
    ........
    friend class TextFile;
};
class TextFile{
    public:
    .......
};
```

## The Line Class
The **Line** class is fully private and should only be accessible by the **TextFile** class.
```C++
   class Line {
      char* m_value;
      Line();
      ~Line();
      operator const char* ()const;
      Line& operator=(const char* lineContent);
      // incomplete...

   };
```
### Attributes (Member variables)
#### char* m_value
holds the address of the dynamically allocated Cstring (to hold a line of the text file)
### Methods (Member functions)
#### operator const char* ()const;
Returns the address held in the **m_value** attribute.
#### Operator=(const char*) overload
Dynamically allocates memory in **m_value** and copies the Cstring pointed by **lineContent** into it.
### default constructor 
Initializes the **m_value** attribute to **nullptr**.
### destructor
Makes sure all the allocated memory is freed. 

> Make sure **Line** can not be copied or assigned to another **Line**.

## The TextFile Class
```C++
class TextFile {
      Line* m_textLines;
      char* m_filename;
      unsigned m_noOfLines;
      unsigned m_pageSize;
      void setFilename(const char* fname, bool isCopy = false);
      void setNoOfLines();
      void loadText();
      void saveAs(const char *fileName)const;
      void setEmpty();
   public:
      TextFile(unsigned pageSize = 15);
      TextFile(const char* filename, unsigned pageSize = 15);
      TextFile(const TextFile&);
      TextFile& operator=(const TextFile&);
      ~TextFile();
      std::ostream& view(std::ostream& ostr)const;
      std::istream& getFile(std::istream& istr);
      operator bool()const;
      unsigned lines()const;
      const char* name()const;
      const char* operator[](unsigned index)const;
   };
```
### Attributes (Member variables)
**TextFile** has four private member variables:
```C++
Line* m_textLines;
```
A pointer to hold the dynamic array of **Lines**. This attribute should be initialized to **nullptr**
```C++
char* m_filename;
```
A pointer to hold the dynamic Cstring holding the name of the file. This attribute should be initialized to **nullptr**
```C++
unsigned m_noOfLines;
```
An unsigned integer to be set to the number of lines in the file.
```C++
unsigned m_pageSize;
```
The page size is the number of lines that should be displayed on the screen before the display is paused. After these lines are displayed, the user must hit enter for the next page to appear. 
### Private Methods (Member functions)
#### setEmpty
```C++
void setEmpty();
```
deletes the **m_textLines** dynamic array and sets is to **nullptr**
deletes the **m_filename** dynamic Cstring and sets is to **nullptr**
sets **m_noOfLines** attribute to **zero**.
#### setFilename
```C++
void setFilename(const char* fname, bool isCopy = false);
```
If the isCopy argument is false, dynamically allocates a Cstring in **m_filename** and copies the content of the **fname** argument into it.
If the isCopy argument is true, dynamically allocates a Cstring in **m_filename** and copies the content of the **fname** argument with a prefix of **"C_"** attached to it.
```C++
Example:
setFilename("abc.txt"); // sets the m_filename to "abc.txt"
setFilename("abc.txt", true); // sets the m_filename to "C_abc.txt"
```
#### setNoOfLines
```C++
void setNoOfLines();
```
Counts the number of lines in the file:

Creates a local **ifstream** object to open the file with the name held in **m_filename**. Then it will read the file, character by character, and accumulates the number of newlines in the **m_noOfLines** attribute. 

In the end, it will increase **m_noOfLines** by one, just in case, the last line does not have a new line at the end.

If the number of lines is zero, it will delete the m_filename and set it to nullptr. (Setting the TextFile to a safe empty state)

#### loadText
```C++
void loadText();
```
Loads the text file **m_filename** into the dynamic array of Lines pointed by **m_textLines** :<br />
If the **m_filename** is null, this function does nothing.

If the **m_filename** is not null (**TextFile** is not in a safe empty state ), **loadText()** will dynamically allocate an array of Lines pointed by **m_textLines** with the size kept in m_noOfLines. 
> *Make sure **m_textLine** is deleted before this to prevent memory leak*. 

Create a local instance of **ifstream** using the file name **m_filename** to read the lines of the text file.

Since the length of each line is unknown, read the line using a local C++ string object and the **getline** **helper** function. (note: this is the **HELPER** **getline** function and not a method of istream).

In a loop reads each line into the string object and then sets the **m_textLines** array elements to the values returned by the **c_str()** method of the string object until the reading fails (end of file reached). 

After all the lines are read, make sure to update the value of m_noOfline to the actual number of lines read (This covers the possibility of one extra empty line at the end of the file)

#### saveAs
```C++
void saveAs(const char *fileName)const;
```
Saves the content of the TextFile under a new name. 

Use a local ofstream object to open a new file using the name kept in the argument filename. Then loop through the elements of the m_textLines array and write them in the opened file adding a new line to the end of each line. 

### Constructors
```C++
     TextFile(unsigned pageSize = 15);
```
Creates an empty TextFile and initializes the m_pageSize attribute using the pageSize argument.
```C++
     TextFile(const char* filename, unsigned pageSize = 15);
```
Initializes the m_pageSize attribute using the pageSize argument and all the other attributes to nullptr and zero. Then if the filename is not null, it will set the filename, set the number of Lines and load the Text (using the corresponding private methods.)
### Rule of three implementations for classes with resource
Implement The Copy Constructor, Copy assignment and destructor.
#### Copy Constructor

Initializes the m_pageSize attribute using the m_pageSize of the incoming TextFile object and all the other attributes to nullptr and zero.
If the incoming Text object is in a valid State, performs the following tasks to copy the textfile and the content safely:

- Sets the file-name to the name of the incoming TextFile object (isCopy set to true) [See setFilename()](#setfilename)
- Saves the content of the incoming TextFile under the file name of the current TextFile
- set the number of lines
- loads the Text 

#### Copy Assignment
If the current and the incoming TextFiles are valid it will first delete the current text and then overwrites the current file and data by the content of the incoming TextFile.

- deallocate the dynamic array of Text and sets the pointer to null
- Saves the content of the incoming TextFile under the current filename
- Sets the number of lines
- loads the Text

#### destructor
Deletes all the dynamic data.
### public Methods
#### lines()
```C++
unsigned lines()const;
```
returns m_noOfLines;
#### view()
```C++
std::ostream& view(std::ostream& ostr)const;
```
Prints the filename and then the content of the file "m_pageSize" lines at a time.

- print the file name
- underline the file name with '=' character
- loops through the lines and print them one by line
- pauses after printing "m_pageSize" lines and prompts the user ```Hit ENTER to continue...``` and waits for the user to press enter and repeats until all lines are printed.

The function performs no action if the **TextFile** is in an empty state.

This function receives and returns an instance of istream and uses the instance for printouts.

#### getFile()
```C++
std::istream& getFile(std::istream& istr);
```
Receives a filename from istr to set the file name of the TextFile. Then sets the number of lines and loads the Text.
When done it will return the istr;

#### index Operator Overload
```C++
const char* operator[](unsigned index)const;
```
Returns the element in the m_textLine array corresponding to the index argument. If the TextFile is in an empty state, it will return null.
If the index exceeds the size of the array it should loop back to the beginning.

For example, if the number of lines is 10, the last index should be 9 and index 10 should return the first element and index 11 should return the second element. 

### Type conversion overloads:
#### boolean cast
```C++
operator bool()const;
```
Returns true if the TextFile is not in an empty state and returns false if it is.
#### constant character pointer cast
```C++
const char* name()const;
```
Returns the filename.

### Insertion and extraction helper operator overloads
To print and read on and from istream and ostream overload operator<< and operator>>:
#### operator<< 
```C++
   ostream& operator<<(ostream& ostr, const TextFile& text);
```
uses the view() method to print the TextFile
#### operator>> 
```C++
   istream& operator>>(istream& istr, TextFile& text);
```
uses the getFile() method to get the file name from console and load the content from the file
### Tester program
```C++
// Workshop 6-lab:
// Version: 0.9
// Date: 2021/02/20
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop
/////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
using namespace sdds;
using namespace std;

void FirstTen(TextFile T);
void Copy(const string& dest, const string& source);
void Dump(const string& filename);
int main() {
   TextFile Empty;
   TextFile BadFilename("badFilename");
   Copy("echoes.txt", "echoesOriginal.txt");
   Copy("seamus.txt", "seamusOriginal.txt");
   TextFile E;
   TextFile S("seamus.txt");
   cout << "Enter the text file name: ";
   cin >> E;
   cout << E << endl;
   cout << S << endl;
   FirstTen(E);
   FirstTen(S);
   E = S;
   cout << E << endl;
   cout << "============================================================" << endl;
   Dump("echoes.txt");
   Dump("seamus.txt");
   Dump("C_echoes.txt");
   Dump("C_seamus.txt");
   cout << "*" << Empty << BadFilename << "*" << endl;
   return 0;
}
void FirstTen(TextFile T) {
   if (T) {
      cout << ">>> First ten lines of : " << T.name() << endl;
      for (unsigned i = 0; i < 10; i++) {
         cout << (i + 1) << ": " << T[i] << endl;
      }
   }
   else {
      cout << "Nothing to print!" << endl;
   }
   cout << endl << "-------------------------------------------------------------" << endl;
}
void Dump(const string& filename) {
   cout << "DUMP---------------------------------------------------------" << endl;
   cout << ">>>" << filename << "<<<" << endl ;
   ifstream fin(filename.c_str());
   char ch;
   while (fin.get(ch)) cout << ch;
   cout << endl << "-------------------------------------------------------------" << endl;
}
void Copy(const string& dest, const string& source) {
   ifstream fin(source.c_str());
   ofstream fout(dest.c_str());
   char ch;
   while (fin.get(ch)) fout << ch;
}
```
### Execution sample

[Output Sample](lab/ExecutionOutputSample.txt)

## LAB Submission (part 1)
Files to submit:  
```Text
TextFile.h
TextFile.cpp
cstring.h
cstring.cpp
w6p1_tester.cpp
```

Upload your source code and data file to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca user-id
- replace **#** with the workshop number
- replace **??** with your subject code (2**00** or 2**44**)
```text
~profname.proflastname/submit 2??/w#/p1
```

and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.


# DIY (50%) Stats Module

Create a module called **Stats** that can represent a file on the hard disk containing comma-separated numbers. 

This module should be able to load the numbers and perform the following tasks.

- A **Stats** object should be able to display the numbers in a tabular format on ostream in a specified number of columns, column width and precision. 
- A **Stats** object should be able to display the numbers that fall within a specific range and the number of their occurrence.
- A **Stats** object should be able to sort the numbers in an ascending or descending order.
- Copying a **Stats** object should be done safely and doing so it should also copy the data file on the hard disk. The new file name should be the same as the original file with an added **"C_"** prefix. 
- Assigning a **Stats** object to another should be done safely and the content of the target file should also be overwritten by the source file.
- A **Stats** object should also make the numbers available to the user program by indexing like an array. 
- A **Stats** object should be able to receive the data file name from the istream and load the data from the file on the hard drive.

## Required public functionalities

### construction
#### 3 Argument Constructor
```C++
Stats(unsigned columnWidth = 15, 
      unsigned noOfColumns = 4, 
      unsigned precision = 2);
```
- columnWidth: width of each column in characters
- noOfColumns: number of columns to display the numbers in
- precision: number of digits after the decimal point for each number

In this case, the "**Stats**" object is not tied to any file on the hard drive and is empty.

#### 4 Argument Constructor

```C++
Stats(const char* filename, 
      unsigned columnWidth = 15, 
      unsigned noOfColumns = 4, 
      unsigned precision = 2);
```
Same as the previous constructor, but in this case, if the filename argument is not null and is successfully opened, the numbers in the file will be loaded into the **Stats** object.

#### Copy Constructor
Copying a **Stats** object should be done safely and doing so it should also copy the data file on the hard disk. The new file name should be the same as the original file with an added **"C_"** prefix. 

### Operator overloads
#### Copy assignment
Assigning a **Stats** object to another should be done safely and the content of the target file should also be overwritten by the content of the source file.

#### Index operator overloads  
```C++
double& operator[](unsigned idx);
```
Returns the reference of the number at idx index. If the index exceeds the size of the array, it should loop back to the beginning. For example, if the array size is 10, index 10 will be the reference of the element at index 0 and index 11 will be the reference of the element at index 1.

If the **Stats** object is empty, it should return the reference of a dummy double member variable.
```C++
double operator[](unsigned idx)const;
```
Returns the value of the number at idx index. If the index exceeds the size of the array, it should loop back to the beginning. For example, if the array size is 10, index 10 will be the value of the element at index 0 and index 11 will be the value of the element at index 1.

If the **Stats** object is empty, it should return zero.

### Boolean type conversion overload
If **Stats** is casted to boolean, it should return true only if it is not empty. Otherwise, it should return false.

### Methods (Member variables)
#### sort()
```C++
void sort(bool ascending);
```
Sorts the numbers in ascending or descending order.
#### size()
```C++
unsigned size()const;
```
returns the number of numbers in the **Stats** object.
#### name()
```C++
const char* name()const;
```
returns the name of the file tied to the **Stats** object.
#### occurrence()
```C++
unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);
```
displays the numbers that fall within a specific range and the number of their occurrence on ostream. 

The format of the printout should be the same as printing all the numbers.

## helper implementations 
### ostream insertion operator<<

**Stats** should be printable by ostream (cout) using the ```operator<<```. 

A Stats object should be able to display the numbers in a tabular format on ostream in a specified number of columns, column width and precision. See the execution sample file.

### istream extraction operator>>

**Stats** object should be able to receive the data file name from ostream (cin) using operator>>. After receiving the name, if the data file is open successfully, the numbers should be loaded into the **Stats** object.

## The tester program:

> Modify the tester program to test all the different circumstances/cases of the application if desired and note that the professor's tester may have many more samples than the tester program here.

```C++
// Workshop 6-diy:
// Version: 0.9
// Date: 2021/02/20
// Author: Fardad Soleimanloo
// Description:
// This file tests the diy section of your workshop
/////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include "Stats.h"
using namespace sdds;
using namespace std;

void twentyNumbers(Stats T);
void badIndex(const Stats& T);
void Copy(const string& dest, const string& source);
void Dump(const string& filename);
int main() {
   Copy("numLtl.csv", "numbersLtlOriginal.csv");
   Copy("numbers.csv", "numbersOriginal.csv");
   Stats L(10, 7, 0);
   Stats S("numLtl.csv"), Empty, BadFilename("badFilename");
   cout << "Enter the data file name: ";
   cin >> L;
   cout << L << endl;
   cout << S << endl;
   twentyNumbers(L);
   twentyNumbers(S);
   cout << "Total of " << L.size() << " numbers in " << L.name() << endl; 
   L[1000] = 11111.11;
   L.occurrence(-12345.0, 31342.55);
   L.sort(true);

   cout << "Sorted Ascending: " << endl;
   L.occurrence(-12345.0, 31342.55);
   L.sort(false);
   cout << "Sorted Descending: " << endl;
   L.occurrence(-12345.0, 31342.55);
   L = S;
   cout << L << endl;
   cout << "============================================================" << endl;
   Dump("numbers.csv");
   Dump("numLtl.csv");
   Dump("C_numbers.csv");
   Dump("C_numLtl.csv");
   cout << "Empty object tests: " << endl;
   cout << "*" << Empty << BadFilename << "*" << endl;
   cout << Empty[10] << endl;
   badIndex(Empty);
   Empty.sort(true);
   Empty.occurrence(1, 2);
   cout << Empty.size() << endl;
   return 0;
}
void twentyNumbers(Stats T) {
   if (T) {
      cout << ">>> 20 numbers of : " << T.name() << endl;
      cout.setf(ios::fixed);
      cout.precision(1);
      for (unsigned i = 0; i < 200;i+=10) {
         cout << "T[" << i << "]: " << T[i] << endl;
      }
      cout.unsetf(ios::fixed);
   }
   else {
      cout << "Nothing to print!" << endl;
   }
   cout << endl << "-------------------------------------------------------------" << endl;
}
void Dump(const string& filename) {
   cout << "DUMP---------------------------------------------------------" << endl;
   cout << ">>>" << filename << "<<<" << endl ;
   ifstream fin(filename.c_str());
   int i = 0;
   char ch;
   while (fin.get(ch)) {
      if (i++ % 80 == 0) cout << endl;
      cout << ch;
   }
   cout << endl << "-------------------------------------------------------------" << endl;
}
void Copy(const string& dest, const string& source) {
   ifstream fin(source.c_str());
   ofstream fout(dest.c_str());
   char ch;
   while (fin.get(ch)) fout << ch;
}
void badIndex(const Stats& T) {
   cout << T[10] << endl;
}

```

## Execution output sample

[Output Sample](DIY/ExecutionOutputSample.txt)

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)
Files to submit:  
```Text
cstirng.cpp
cstring.h
Stats.cpp
Stats.h
w6p2_tester.cpp
```

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca user-id
- replace **#** with the workshop number
- replace **??** with your subject code (2**00** or 2**44**)
```text
~profname.proflastname/submit 2??/w#/p2
```
and follow the instructions.

> **:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.