# Workshop #7: Derived Classes & Custom I/O Operators

In this workshop, you will work with classes that make up the hierarchical structure. The base or parent class will be a `MotorVehicle` that holds common attributes of a vehicle with an engine then the child class `Truck` will be derived from the parent class. In addition to this hierarchy, we will define custom input/output operators for these classes.


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- inherit a derived class from a base class
- shadow a base class member function with a derived class member function
- access a shadowed member function that is defined in a base class
- utilize custom input/output operators with these classes
- describe to your instructor what you have learned in completing this workshop



> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace.


# lab (part 1) (100%)


## `MotorVehicle` Module

Design and code a class named `MotorVehicle` that holds information about a vehicle with an engine. Place your class definition in a header file named `MotorVehicle.h` and your function definitions in an implementation file named `MotorVehicle.cpp`.

Include in your solution all of the statements necessary for your code to compile under a standard C++ compiler and within the `sdds` namespace.

### `MotorVehicle` Class

Design and code a class named `MotorVehicle` that holds information about a vehicle with an engine.


#### `MotorVehicle` Private Members

The class should be able to store the following data:

- a license plate number as a statically allocated array of characters of size 9.
- the address where the vehicle is at a given moment as a statically allocated array of characters of size 64.
- the year when the vehicle was built.

You can add any other private members in the class, as required by your design.



#### `MotorVehicle` Public Members

- a custom constructor that receives as parameters the license plate number and the year when the vehicle was built.  Set the location of the vehicle at `Factory`. Assume all data is valid.
- `void moveTo(const char* address)`: moves the vehicle to the new address if the new address is different from the current address. Prints to the screen the message
  ```txt
  |[LICENSE_PLATE]| |[CURRENT_ADDRESS] ---> [NEW_ADDRESS]|<ENDL>
  ```
  where
  - the license plate is a field of 8 characters aligned to the right
  - current address is a field of 20 characters aligned to the right
  - new address is a field of 20 characters aligned to left

- `ostream& write(ostream& os)`: a query that inserts into `os` the content of the object in the format
  ```txt
  | [YEAR] | [PLATE] | [ADDRESS]
  ```
- `istream& read(istream& in)`: a mutator that reads from the stream `in` the data for the current object
  ```txt
  Built year: [USER TYPES HERE]
  License plate: [USER TYPES HERE]
  Current location: [USER TYPES HERE]
  ```


#### Helper Functions

- overload the insertion and extraction operators to insert a `MotorVehicle` into a stream and extract a `MotorVehicle` from a stream. These operators should call the `write`/`read` member functions in the class `MotorVehicle`.

## `Truck` Module

Design and code a class named `Truck` that holds information about a motor vehicle that can carry cargo. Place your class definition in a header file named `Truck.h` and your function definitions in an implementation file named `Truck.cpp`.

Include in your solution all of the statements necessary for your code to compile under a standard C++ compiler and within the `sdds` namespace.

### `Truck` Class

Design and code a class named `Truck` that holds information about a motor vehicle that can carry cargo.  **This class should inherit from `MotorVehicle` class.**


#### `Truck` Private Members

The class should be able to store the following data (on top of data coming from the parent class):

- a capacity in kilograms as a floating-point number in double precision; this is the maximum weight of the cargo the truck can carry.
- the current cargo load (in kilograms) is a floating-point number in double precision; the load cannot exceed the capacity.

You can add any other private members in the class, as required by your design.  **Do not duplicate members from the base class!**



#### `Truck` Public Members

- a custom constructor that receives as parameters the license plate number, the year when the truck was built, the capacity of the truck and the current address.  Call the constructor from the base class and pass the license number and year to it.  Set the current cargo to 0 and move the truck to the address specified in the last parameter.
- `bool addCargo(double cargo)`: a mutator that adds to the attribute that stores the current cargo load the weight specified as a parameter. **Do not exceed the capacity!**  If the current load has been changed, return `true`, otherwise return `false`.
- `bool unloadCargo()`: a mutator that unloads current cargo (sets the attribute to 0).  If the current load has been changed, return `true`, otherwise, return `false`.
- `ostream& write(ostream& os)`: a query that inserts into `os` the content of the object in the format
  ```txt
  | [YEAR] | [PLATE] | [ADDRESS] | [CURRENT_CARGO]/[CAPACITY]
  ```
- `istream& read(istream& in)`: a mutator that reads from the stream `in` the data for the current object
  ```txt
  Built year: [USER TYPES HERE]
  License plate: [USER TYPES HERE]
  Current location: [USER TYPES HERE]
  Capacity: [USER TYPES HERE]
  Cargo: [USER TYPES HERE]
  ```


#### Helper Functions

- overload the insertion and extraction operators to insert a `Truck` into a stream and extract a `Truck` from a stream. These operators should call the `write`/`read` member functions in the class `Truck`.

## `main` Module (supplied)

**Do not modify this module!**  Look at the code and make sure you understand it.



### Sample Output

```Text
----------------------------------------
|> T1: Vehicle
----------------------------------------
| 2010 | VVV-111 | Factory

| VVV-111| |             Factory ---> Downtown Toronto    |
| VVV-111| |    Downtown Toronto ---> Mississauga         |
| VVV-111| |         Mississauga ---> North York          |

| 2010 | VVV-111 | North York

----------------------------------------
|> T2: Read/Write
----------------------------------------
Built year: 2020
License plate: abc-111
Current location: Toronto

| 2020 | abc-111 | Toronto

----------------------------------------
|> T3: Truck
----------------------------------------
|  T-1111| |             Factory ---> Toronto HQ          |

|  T-1111| |          Toronto HQ ---> Toronto Deposit     |
Cargo loaded!
| 2015 | T-1111 | Toronto Deposit | 2345/5432

|  T-1111| |     Toronto Deposit ---> Montreal            |
Cargo loaded!
| 2015 | T-1111 | Montreal | 5432/5432

|  T-1111| |            Montreal ---> New York            |
Adding cargo failed!
| 2015 | T-1111 | New York | 5432/5432

|  T-1111| |            New York ---> New Jersey          |
Cargo unloaded!
| 2015 | T-1111 | New Jersey | 0/5432

|  T-1111| |          New Jersey ---> Toronto             |
Unloading cargo failed!
| 2015 | T-1111 | Toronto | 0/5432

----------------------------------------
|> T4: Read/Write
----------------------------------------
Built year: 2019
License plate: def-222
Current location: Montreal
Capacity: 2345
Cargo: 1234

| 2019 | def-222 | Montreal
| 2019 | def-222 | Montreal | 1234/2345

```



# Part 2: Reflection

Study your final solutions for each deliverable of the workshop **and the most recent milestones of the project**, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and **the project milestones** and mention any issues that caused you difficulty.
