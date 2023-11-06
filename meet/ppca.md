## Exp1

### AIM
Student should be able to use different decision making statements and functions in Python


**Decision Statements in Python:**
1. Programming languages offer control structures for complex execution paths.
2. Types of loops in Python:
   - `while` loop: Repeats a statement while a condition is true.
   - `for` loop: Executes statements multiple times with a loop variable.
   - `do...while` loop: Similar to `while`, but tests the condition at the end.
   - Nested loops: You can use one or more loops inside another loop.

**Loop Control Statements:**
1. Loop control statements alter the normal execution sequence.
2. Control statements in Python:
   - `break` statement: Terminates a loop or switch and moves to the next statement.
   - `continue` statement: Skips the rest of the loop body and retests the condition.
   - `goto` statement: Transfers control to a labeled statement (not recommended).

**Functions in Python:**
1. Functions are blocks of organized, reusable code for a specific task.
2. Types of functions:
   - Standard library functions: Built-in functions available in Python.
   - User-defined functions: You can create your own functions.
3. Defining a function in Python:
   - Starts with `def` followed by the function name and parentheses.
   - Input parameters placed within the parentheses.
   - First statement can be a documentation string (docstring).
   - Function code block starts with a colon and is indented.
   - `return` statement exits a function, optionally returning an expression.
   - Function format:
   
```python
def functionname(parameters):
    "function_docstring"
    function_suite
    return [expression]
```


```python

Programs on Functions:


# 1. Write a python function to calculate GCD of two numbers.
def gcd(num1, num2):
    for i in range(1, min(num1, num2) + 1):
        if num1 % i == 0 and num2 % i == 0:
            result = i
    return result

# 2. Write a python function to print first nth terms in Fibonacci series.
def fibo(n):
    if n <= 0:
        return "Invalid input"
    elif n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        return fibo(n - 1) + fibo(n - 2)

# 3. Write a python function to print the factorial of a number.
def fact(n):
    if n <= 0:
        return "Invalid input"
    elif n < 2:
        return 1
    else:
        return n * fact(n - 1)

# 4. Write a function to convert an integer number to its binary equivalent number.
def toBinary(n):
    ans = ""
    while(n != 0):
        rem = n % 2
        ans = ans + str(rem)
        n //= 2
    return ans[::-1]  # reverse the returned string

# 5. Write a function to greet a person with a name and time of day.
def greetUser(name, time):
    time = time.upper()
    if (time == "MORNING" or time == "DIN"):
        return f"Good Morning, {name}"
    elif (time == "AFTERNOON" or time == "DOPHAR"):
        return f"Good Afternoon, {name}"
    elif (time == "NIGHT" or time == "SHAAM"):
        return f"Good Evening, {name}"
    else:
        return f"Good Night, {name}"

```


### R Code

**decimal-to-binary.py**
```python
a = int(input("enter the number: "))

def dec_to_bin(a):
    ans = ""
    while a != 0:
        rem = a % 2
        ans = ans + str(rem)
        a //= 2
    return ans[::-1]

print(dec_to_bin(a))
```

**factorial.py**
```python
a = int(input("enter the number: "))

prod = 1
while a > 1:
    prod = prod * a
    a -= 1

print(prod)
```

**fibonacci.py**
```python
def fibo(n):
    a, b = 0, 1
    # Print the first number
    print(a)

    # Print the second number
    if n >= 2:
        print(b)

    # Print the remaining numbers
    for _ in range(2, n):
        a, b = b, a + b
        print(b)

fibo(5)
```

**gcd.py**
```python
a = int(input("enter the number: "))
b = int(input("enter the number: "))

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)
```

**largest-of-three.py**
```python
a = int(input("enter the number: "))
b = int(input("enter the number: "))
c = int(input("enter the number: "))

if a > b:
    if a > c:
        print(f"largest is {a}")
    else:
        print(f"largest is {c}")
else:
    if b > c:
        print(f"largest is {b}")
    else:
        print(f"largest is {c}")
```

**last-digit.py**
```python
a = int(input("enter the number: "))
ld = a % 10
if ld % 4 == 0:
    print("YES")
else:
    print("NO")
```

**leap-year.py**
```python
a = int(input("enter the year: "))
if (a % 4 == 0 and a % 100 != 0) or a % 400 == 0:
    print(f"Year: {a} is a leap year")
else:
    print(f"Year: {a} is not a leap year")
```

I've fixed the indentation and formatting for each script. Please make sure to use the corrected code.











## Exp2

### AIM
Demonstrate Abstraction and Encapsulation in Python Programming

**Abstraction:**
1. Abstraction is a fundamental concept in object-oriented programming.
2. It hides unnecessary details and focuses on essential object or system features.
3. Achieved through abstract classes and interfaces.
4. In Python, use abstract classes with abstract methods defined using the `@abstractmethod` decorator.
5. Abstract classes cannot be instantiated; they establish a contract with subclasses.

**Encapsulation:**
1. Encapsulation bundles data and methods within a single unit (e.g., a class).
2. It hides an object's internal representation from the outside (information hiding).
3. Data members and methods can be declared as private or protected in Python using single or double underscores.
4. Python provides three access modifiers: public, private, and protected.
5. Public members are accessible anywhere, private members are accessible within the class, and protected members are accessible within the class and its sub-classes.


Here's the corrected and properly indented Python code for the scripts you provided:



**Abstraction:**
```python
from abc import ABC, abstractmethod

class Shape(ABC):
    @abstractmethod
    def area(self):
        pass

class Rectangle(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height

class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return 3.14 * self.radius * self.radius

r = Rectangle(5, 10)
print("Rectangle area:", r.area())

c = Circle(7)
print("Circle area:", c.area())
```

**Encapsulation:**
```python
class Person:
    def __init__(self, name, age, gender):
        self.name = name  # public member
        self._age = age  # protected member
        self.__gender = gender  # private member

    # Getter methods
    def get_age(self):
        return self._age

    def get_gender(self):
        return self.__gender

    # Setter methods
    def set_age(self, age):
        self._age = age

    def set_gender(self, gender):
        self.__gender = gender

class Employee(Person):
    def __init__(self, name, age, gender, emp_id):
        super().__init__(name, age, gender)
        self.emp_id = emp_id

    def display_info(self):
        print(f"Name: {self.name}")
        print(f"Age: {self._age}")
        print(f"Gender: {self.get_gender()}")
        print(f"Employee ID: {self.emp_id}")

# Creating objects and testing the program
emp = Employee("John Doe", 30, "Male", "12345")
emp.display_info()

# Try accessing protected and private members from outside the class
print(emp.name)  # Accessing public member
print(emp._age)  # Accessing protected member

# Try setting protected and private members from outside the class
emp.set_age(35)  # Setting protected member
print(emp.get_age())  # Prints 35

# Test if the getters and setters are working as expected
print(emp.get_gender())  # Prints "Male"
emp.set_gender("Female")
print(emp.get_gender())  # Prints "Female"
```




### R CODE


**abstraction.py:**
```python
from abc import ABC, abstractmethod
import math

class Shape(ABC):
    """
    Shape is an abstract class that only contains an abstract method.
    """
    @abstractmethod
    def area(self):
        pass

class Rectangle(Shape):
    def __init__(self, length, breadth):
        self.length = length
        self.breadth = breadth

    def area(self):
        return self.length * self.breadth

class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return math.pi * (self.radius ** 2)

rect = Rectangle(4, 2)
print(rect.area())

ci = Circle(10)
print(ci.area())
```

**encapsulation.py:**
```python
class Person:
    def __init__(self, name, age, ssn):
        self.name = name  # public
        self._age = age  # protected
        self.__ssn = ssn  # private

    def get_name(self):
        return self.name

    def get_age(self):
        return self._age

    def get_ssn(self):
        return self.__ssn

per = Person("rj", 21, 1212)
print(per.get_ssn())
```













## Exp3

### AIM
Demonstrate Inheritance and Polymorphism in Python 


**Inheritance:**
1. Inheritance allows creating a new class (child class) based on an existing class (parent class).
2. The child class inherits properties from the parent class.
3. Types of inheritance in Python:
   - Single inheritance
   - Multiple inheritances
   - Multilevel inheritance
   - Hierarchical inheritance
   - Hybrid inheritance

**Polymorphism:**
1. Polymorphism means "many forms."
2. In Python, polymorphism involves the ability of different classes to provide their own implementations for methods inherited from a common interface or base class.
3. In some cases, methods inherited from a parent class can be modified or overridden in a child class, allowing for different behaviors.
4. Types of polymorphism in Python include:
   - Operator Overloading
   - Method Overriding in Inheritance (user-defined)
   - Method Overriding (in-built)
   - Method Overloading



**Inheritance:**
```python
class Vehicle:
    def __init__(self, color='white'):
        self.color = color
        self.sitting_capacity = 4

    def get_fare(self):
        return self.sitting_capacity * 100

class Bus(Vehicle):
    def __init__(self, color='red'):
        super().__init__(color)
        self.sitting_capacity = 50

    def get_fare(self):
        base_fare = super().get_fare()
        return base_fare + (base_fare * 0.1)

# Create instances of Vehicle and Bus
vehicle = Vehicle()
bus = Bus()

print("Vehicle fare:", vehicle.get_fare())
print("Bus fare:", bus.get_fare())
```

**Polymorphism:**
```python
class Employee:
    def __init__(self, name, base_pay):
        self.name = name
        self.base_pay = base_pay

    def get_pay(self):
        return self.base_pay

class SalesEmployee(Employee):
    def __init__(self, name, base_pay, sales_incentive):
        super().__init__(name, base_pay)
        self.sales_incentive = sales_incentive

    def get_pay(self):
        return self.base_pay + self.sales_incentive

# Creating object of subclass
john = SalesEmployee('John', 5000, 1500)
print('Salary is', john.get_pay())

# Creating object of superclass
jane = Employee('Jane', 5000)
print('Salary is', jane.get_pay())
```





### R CODE:

```python

Nahi banaya
```











## Exp4

### AIM
Demonstrate Exception Handling (Inbuilt Exception)



**Exceptions:**
1. An exception is a Python object that represents an error in the program's execution.
2. Exceptions are raised when errors occur, and they need to be handled to prevent abnormal program termination.
3. Python provides a collection of built-in exceptions to handle commonly occurring errors.
4. Common built-in exceptions include StopIteration, SystemExit, StandardError, ArithmeticError, OverflowError, FloatingPointError, ZeroDivisionError, AssertionError, AttributeError, EOFError, ImportError, KeyboardInterrupt, LookupError, and IndexError.
5. Each exception has a base class, and programmers can create custom exceptions by inheriting from these base classes.


LEARN ANY 5

Exception
All exceptions of Python have a base class.

StopIteration
If the next() method returns null for an iterator, this exception is raised.

SystemExit
The sys.exit() procedure raises this value.

StandardError
Excluding the StopIteration and SystemExit, this is the base class for all Python built-in exceptions.

ArithmeticError
All mathematical computation errors belong to this base class.

OverflowError
This exception is raised when a computation surpasses the numeric data type's maximum limit.

FloatingPointError
If a floating-point operation fails, this exception is raised.

ZeroDivisionError
For all numeric data types, its value is raised whenever a number is attempted to be divided by zero.

AssertionError
If the Assert statement fails, this exception is raised.

AttributeError
This exception is raised if a variable reference or assigning a value fails.

EOFError
When the endpoint of the file is approached, and the interpreter doesn't get any input value by raw_input() or input() functions, this exception is raised.

ImportError
This exception is raised if using the import keyword to import a module fails.

KeyboardInterrupt
If the user interrupts the execution of a program, generally by hitting Ctrl+C, this exception is raised.

LookupError
LookupErrorBase is the base class for all search errors.

IndexError
This exception is raised when the index attempted to be accessed is not found.



Write a function division() that accepts two arguments. The function should be able to catch an exception such as ZeroDivisionError, ValueError, or any unknown error you might come across when you are doing a division operation.


**First Code (division):**
```python
def division(x, y):
    try:
        return x / y
    except ZeroDivisionError as e:
        print("Zero Division Error:", e)
    except ValueError as e:
        print("Value Error:", e)
    except Exception as e:
        print("Unknown error:", e)

def main():
    test_cases = [
        (10, 0),      # Division by zero (ZeroDivisionError)
        ('a', 2),     # Value error (ValueError)
        (10, 'b'),    # Unknown error (Exception)
    ]
    for idx, (x, y) in enumerate(test_cases):
        print(f"Test Case {idx+1}:")
        division_result = division(x, y)
        print("Result:", division_result)
        print("="*20)

if __name__ == "__main__":
    main()
```




 program to print the reciprocal of even numbers. The function should be able to catch an exception such as ZeroDivisionError, ValueError, or any unknown error you might come across when you are doing an operation.




**Second Code (reciprocal):**
```python
def reciprocal(number):
    try:
        if number % 2 == 0:
            return 1 / number
        else:
            raise ValueError("number is not even")
    except ZeroDivisionError as e:
        print("Zero Division Error:", e)
    except ValueError as e:
        print("Value Error:", e)
    except Exception as e:
        print("Unknown error:", e)

def main():
    test_cases = [
        2,     # Regular division (ZeroDivisionError)
        3,     # Value error (ValueError)
        'a',   # Unknown error (Exception)
    ]

    for idx, num in enumerate(test_cases):
        print(f"Test Case {idx+1}:")
        reciprocal_result = reciprocal(num)
        print("Result:", reciprocal_result)
        print("="*20)

if __name__ == "__main__":
    main()
```









### R CODE:

```python

4.exception-built-in-and-user-defined.py


class StupidityError(Exception):
    pass

try:
    a = int(input("enter the number: "))
    b = int(input("enter the number: "))
    if a == 0 and b == 0:
        raise StupidityError("learn your math, stupid")

    c = a / b

except ZeroDivisionError as e:
    print(f"Error: {e} occurred")
except StupidityError as err:
    print(f"Error: {err}")
except Exception as e:
    print(f"Error: {e} occurred")

```











## Exp5

### AIM
Demonstrate Exception Handling (User-defined Exception)

**Exceptions:**
1. An exception is a Python object representing an error during program execution.
2. It's raised when an error occurs, and it should be handled to prevent abnormal program termination.
3. Programmers should anticipate error situations and include code to handle exceptions.

**User-Defined Exceptions:**
1. In Python, user-defined exceptions are created by programmers when built-in exceptions do not meet program requirements.
2. These are custom exceptions designed to handle specific errors or situations in the code.
3. Programmers can create their own exception classes with custom attributes and methods.
4. User-defined exceptions provide better control over handling specific errors in the code.



Q. Write a program used to enroll students in a particular course. To decide which students can enroll, there is a cut-off and maximum score. If a student's percentage is in the acceptable range, they are enrolled, or else an exception is raised. In this case, no student enrolling should have a percentage less than the cut-off as well as their score cannot be higher than the maximum score.
Create following Exception classes and use the same in the program.
1. PercentageError class is a base class that implements the Python Exception class. This class can be implemented by the other Exception classes.
2. InvalidPercentageError Exception is raised if the percentage value is greater than 100. LessPercentageError Exception is raised if the percentage value is less than the cut-off range. Both these classes have Initializers that send respective messages to the superclass.
3. checkPercentage class has an Initializer (Constructor) function that takes the percentage argument as per. It raises an exception incase if the percentage  is not in desired range i.e InvalidPercentageError if greater than 100 or LessPercentageError if less than 80.



```python

# Base class
class PercentageError(Exception):
    pass

# Exception class for percentage > 100
class InvalidPercentageError(PercentageError):
    def __init__(self):
        super().__init__("Percentage is invalid")

# Exception class for percentage < 80
class LessPercentageError(PercentageError):
    def __init__(self):
        super().__init__("The Percentage is lesser than the Cut-off, Please try again!")

# class to check percentage range
class checkPercentage(PercentageError):
    def __init__(self, per):
        if per < 80:
            raise LessPercentageError
        if per > 100:
            raise InvalidPercentageError
        print("Congrats you're Enrolled")

# different cases and output
try:
    print("For Percentage: 93")
    checkPercentage(93)
except Exception as e:
    print(e)

try:
    print("\nFor Percentage: 102")
    checkPercentage(102)
except Exception as e:
    print(e)

try:
    print("\nFor Percentage: 58")
    checkPercentage(58)
except Exception as e:
    print(e)

```



### R CODE:

```python

5.percentage-error.py

class PercentageError(Exception):
    pass

class InvalidPercentageError(PercentageError):
    def __init__(self):
        super().__init__("Invalid percentage")

class LessPercentageError(PercentageError):
    def __init__(self):
        super().__init__("Percentage is less than the required")

class CheckPercentage(PercentageError):
    def __init__(self, percent):
        if percent < 80:
            raise LessPercentageError
        elif percent > 100:
            raise InvalidPercentageError
        print("Congratulations")

try:
    a = int(input("Enter the percentage: "))
    check = CheckPercentage(a)
except Exception as e:
    print(e)

```








## Exp6

### AIM
Demonstrate File Handling Operations


**File Handling in Python:**
1. File handling is essential in web applications for various activities with files.
2. Access modes control the operations that can be performed on an opened file.
3. Access modes specify where the file handle is located within the file.
4. In Python, there are six access modes:
   - Read Only ('r'): Opens the file for reading only.
   - Read and Write ('r+'): Opens the file for both reading and writing.
   - Write Only ('w'): Opens the file for writing only, and it can create a new file.
   - Write and Read ('w+'): Opens the file for both reading and writing, overwriting existing data.
   - Append Only ('a'): Opens the file for writing, creating a new file if it doesn't exist, and appends data to the end.
   - Append and Read ('a+'): Allows reading and writing, sets the handle at the end, and appends data.



Q.1] Write a program to write Name and Roll Nos into a binary file.

```python
import pickle

with open("file.dat", "wb") as F1:
    while True:
        op = int(input("Enter 1 to add data, 0 to quit"))
        if op == 1:
            name = input("Enter name: ")
            rollno = int(input("Roll no: ")
            pickle.dump([name, rollno], F1)
        elif op == 0:
            break
```

Q.2] Write a program to read name and roll no from a binary file. The file has data as a list [name, rollno].

```python
import pickle

F1 = open("file.dat", "rb")
while True:
    try:
        l = pickle.load(F1)
        print(l)
    except EOFError:
        break

F1.close()
```

Q.3] Write a code to show how a dictionary is stored as a binary file.

```python
import pickle

# Sample dictionary
student_data = {
    "Name": "Satish Gupta",
    "Roll_no": 11,
    "Marks": [85, 90, 78, 92]
}

# Define the filename for the binary file
file_name = "student_data.pkl"

# Write the dictionary to a binary file using pickle
try:
    with open(file_name, 'wb') as file:
        pickle.dump(student_data, file)
        print("Dictionary has been stored as a binary file.")
except Exception as e:
    print(f"An error occurred: {str(e)}")

# Read the dictionary from the binary file
try:
    with open(file_name, 'rb') as file:
        loaded_data = pickle.load(file)
        print("Loaded data from the binary file:")
        print(loaded_data)
except Exception as e:
    print(f"An error occurred while loading the data: {str(e)}")
```

Q.4] Write a code that reads from a file "sales.dat" which has the following information [itemcode, amount]. Read from the file and find the sum of the amount.

```python
# Initialize a variable to hold the total sum
total_amount = 0

# Try to open the "sales.dat" file for reading
try:
    with open("sales.dat", "r") as file:
        # Iterate through each line in the file
        for line in file:
            # Split the line into item code and amount (assuming they are separated by a comma)
            item_code, amount_str = line.strip().split(',')

            # Convert the amount string to a float and add it to the total amount
            amount = float(amount_str)
            total_amount += amount

        # Print the total sum
        print(f"Total Amount: {total_amount}")
except FileNotFoundError:
    print("File 'sales.dat' not found.")
except Exception as e:
    print(f"An error occurred: {str(e)}")
```






### R CODE:


6.file-handling-bin.py

```python
import pickle

data_dict = {"name": "Rishabh", "Roll no.": 15}

# To save data_dict to a binary file "a.dat"
with open("a.dat", "wb") as data:
    pickle.dump(data_dict, data)

# Read and calculate the sum of float values in "a.dat"
sum_of_floats = 0
with open("a.dat", "rb") as data:
    data_dict = pickle.load(data)
    for key, value in data_dict.items():
        if isinstance(value, float):
            sum_of_floats += value

print("Sum of float values:", sum_of_floats)
```

6.file-handling.py

```python
sum = 1
try:
    with open("hello.txt", "r+") as first_file:
        file_cont = first_file.read()
        new_cont = file_cont.replace("hello", "first")
        first_file.seek(0)
        first_file.write(new_cont)
        first_file.truncate()
except Exception as e:
    print(f"Error {e} occurred")
```








## Exp7

### AIM
Implement GUI Programming using Python

**GUI (Graphical User Interface):**
1. GUIs provide a visual way to interact with computers and perform various tasks.
2. They are used on desktop computers, laptops, and mobile devices.
3. GUI applications can create, read, download, and delete files.
4. GUIs include various widgets like buttons, canvases, checkbuttons, text fields, and more.

**Tkinter Library:**
1. Tkinter is a widely used method for creating GUIs in Python.
2. It's a standard interface to the Tk GUI toolkit bundled with Python.
3. Creating GUI applications with tkinter is fast and straightforward.
4. The process of creating a tkinter app involves importing the module, creating the main window, adding widgets, and applying event triggers.

**Common Widgets:**
1. Button: Displays buttons in the application.
2. Canvas: Used for drawing shapes like lines, ovals, polygons, and rectangles.
3. Checkbutton: Displays multiple checkboxes for selecting options.
4. Entry: Provides a single-line text field for user input.
5. Frame: Serves as a container widget to organize other widgets.



1) Creating a button (Code and Output):

```python
from tkinter import *

root = Tk()
button = Button(root, text="Click Me")
button.pack()

root.mainloop()
```

2) Creating a Label (Code and Output):

```python
from tkinter import *

root = Tk()
var = StringVar()
label = Label(root, textvariable=var, relief=RAISED)
var.set("Hey!? How are you doing?")
label.pack()

root.mainloop()
```

3) Creating Radio Buttons (Code and Output):

```python
from tkinter import *

def sel():
    selection = "You selected the option " + str(var.get())
    label.config(text=selection)

root = Tk()
var = IntVar()

R1 = Radiobutton(root, text="Option 1", variable=var, value=1, command=sel)
R1.pack(anchor=W)

R2 = Radiobutton(root, text="Option 2", variable=var, value=2, command=sel)
R2.pack(anchor=W)

R3 = Radiobutton(root, text="Option 3", variable=var, value=3, command=sel)
R3.pack(anchor=W)

label = Label(root)
label.pack()

root.mainloop()
```





### R CODE:



7.gui-implementation.py:
```python
import tkinter as tk
from tkinter import messagebox

window = tk.Tk()

# All code should be between these two lines
label = tk.Label(window, text="Hello world")
label.pack()

def on_click():
    print("Hello world")

button = tk.Button(window, text="I am a button", command=on_click)
button.pack()

def msg():
    messagebox.showinfo("Information", "I am a messagebox")

msg_box = tk.Button(window, text="Message Box", command=msg)
msg_box.pack()

window.mainloop()
```

7.radiobutton.py:
```python
from tkinter import *

def sel():
    selection = "You selected the option " + str(var.get())
    label.config(text=selection)

root = Tk()
var = IntVar()

R1 = Radiobutton(root, text="Option 1", variable=var, value=1, command=sel)
R1.pack(anchor=W)

R2 = Radiobutton(root, text="Option 2", variable=var, value=2, command=sel)
R2.pack(anchor=W)

R3 = Radiobutton(root, text="Option 3", variable=var, value=3, command=sel)
R3.pack(anchor=W)

label = Label(root)
label.pack()

root.mainloop()
```









## Exp8

### AIM

Implement Databases Connectivity using python


Here are the important points about Databases, MySQL, and Database Operations:

**Databases:**
1. A database is a structured collection of data that can be easily managed and accessed in various ways.
2. Relational databases are popular and include MySQL, Oracle Database, SQL Server, and more.
3. MySQL is one of the easiest databases to work with.
4. MySQLdb is an open-source relational database management system that uses Structured Query Language (SQL).

**Python Database Connection:**
1. Connecting Python to a database is simple, using modules like MySQL connector Python.
2. A connection request is sent to the database, accepted, and a cursor is executed for result data.

**MySQL Installation:**
1. Before connecting to the MySQL database, ensure you have MySQL installed with components like MySQL server, connectors, tools, and documentation.

**Database Operations (CRUD):**
1. CRUD operations are essential in database programming:
   - Create: Used to create records in a table or create a table itself.
   - Read: Fetches information from the database.
   - Update: Modifies records or tables.
   - Delete: Removes tables or records from the database.




```python
import mysql.connector

try:
    # Create a MySQL connection
    mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        password="tcet"
    )

    print(mydb)

    mycursor = mydb.cursor()

    # Create a database named 'myPython'
    mycursor.execute("CREATE DATABASE IF NOT EXISTS myPython")
    print("Database 'myPython' is created successfully")

except mysql.connector.Error as error:
    print("Failed to create database in MySQL: {}".format(error))

finally:
    if mydb.is_connected():
        mycursor.close()
        mydb.close()
        print("MySQL connection is closed")

try:
    # Connect to the 'myPython' database
    mydb = mysql.connector.connect(
        host="localhost",
        database="myPython",
        user="root",
        password="tcet"
    )

    print(mydb)

    mycursor = mydb.cursor()

    # Create the 'Employee' table
    mycursor.execute("CREATE TABLE IF NOT EXISTS Employee ("
                    "NAME varchar(20) not null, "
                    "ID int(20) not null primary key, "
                    "SALARY float not null, "
                    "DEPT_ID int not null)"
                    )
    print("Table 'Employee' is created successfully")

except mysql.connector.Error as error:
    print("Failed to create table in MySQL: {}".format(error))

finally:
    if mydb.is_connected():
        mycursor.close()
        mydb.close()
        print("MySQL connection is closed")
```






### R CODE:
I've formatted and corrected the code for creating a MySQL database and table. Here's the revised version:

8.python-database-create-db.py

```python
import mysql.connector

mydb = mysql.connector.connect(host="localhost", user="root", password="tcet")

mycursor = mydb.cursor()
try:
    mydb = mysql.connector.connect(host="localhost", user="root", password="tcet")
    print(mydb)
    mycursor = mydb.cursor()
    mycursor.execute("CREATE DATABASE myPython")
    print("Database 'myPython' is created successfully")
except mysql.connector.Error as error:
    print("Failed to create database in MySQL: {}".format(error))
finally:
    if mydb.is_connected():
        mycursor.close()
        mydb.close()
        print("MySQL connection is closed")
```

8.python-db-create-table.py

```python
import mysql.connector

try:
    mydb = mysql.connector.connect(
        host="localhost",
        database="myPython",
        user="root",
        password="tcet"
    )
    print(mydb)
    mycursor = mydb.cursor()
    mycursor.execute("CREATE TABLE Employee (NAME varchar(20) not null, ID int(20) not null primary key, SALARY float not null, DEPT_ID int not null)")
    print("Table 'Employee' is created successfully")
except mysql.connector.Error as error:
    print("Failed to create table in MySQL: {}".format(error))
finally:
    if mydb.is_connected():
        mycursor.close()
        mydb.close()
        print("MySQL connection is closed")
```

These revised codes should work as expected to create a MySQL database and an "Employee" table.











## Exp9

### AIM

GUI with Database Connectivity using Python


**GUI and Database Connectivity:**
1. Python offers libraries and frameworks for creating GUIs and connecting to databases.
2. Libraries for different databases include SQLite3, MySQL (using MySQL Connector), PostgreSQL (using psycopg2), and MongoDB (using pymongo).
3. You need to install the appropriate database driver library using pip to connect to a database.
4. Connection objects are used to execute SQL queries and retrieve data from the database.
5. Combining GUI and database connectivity in Python allows the creation of powerful software applications.

**Algorithm for Connecting GUI to a Database:**
1. Choose a GUI toolkit like Tkinter, PyQt, PySide, wxPython, or Kivy.
2. Install necessary libraries, such as tk for Tkinter, according to your chosen GUI toolkit.
3. Create the GUI by designing windows, buttons, text fields, and other interface components.
4. Connect to a database system, create a database, and design tables to store data.
5. Write Python code to connect to the database using Python's built-in DB-API, including creating connection and cursor objects.
6. Code the interaction between the GUI and the database, such as inserting data into the database when a button is clicked.
7. Thoroughly test and debug your application to ensure it works as expected.





```python
from tkinter import *
import tkinter.messagebox as MessageBox
import mysql.connector as mysql

def Insert():
    roll = roll_entry.get()
    name = name_entry.get()
    className = className_entry.get()

    if roll == "" or name == "" or className == "":
        MessageBox.showinfo("ALERT", "Please enter all fields")
    else:
        con = mysql.connect(host="localhost", user="root", password="tcet", database="college")
        cursor = con.cursor()
        cursor.execute("insert into students values('" + name + "', '" + roll + "', '" + className + "')")
        cursor.execute("commit")
        MessageBox.showinfo("Status", "Successfully Inserted")
        con.close()

def Update():
    roll = roll_entry.get()
    name = name_entry.get()
    className = className_entry.get()

    if name == "" or className == "":
        MessageBox.showinfo("ALERT", "Please enter fields you want to update!")
    else:
        con = mysql.connect(host="localhost", user="root", password="tcet", database="college")
        cursor = con.cursor()
        cursor.execute("update students set StudentName = '" + name + "', class='" + className + "' where RollNum ='" + roll + "'")
        cursor.execute("commit")
        MessageBox.showinfo("Status", "Successfully Updated")
        con.close()

def Del():
    if roll_entry.get() == "":
        MessageBox.showinfo("ALERT", "Please enter Roll Number to delete row")
    else:
        con = mysql.connect(host="localhost", user="root", password="tcet", database="college")
        cursor = con.cursor()
        cursor.execute("delete from students where RollNum='" + roll_entry.get() + "'")
        cursor.execute("commit")
        roll_entry.delete(0, 'end')
        name_entry.delete(0, 'end')
        className_entry.delete(0, 'end')
        MessageBox.showinfo("Status", "Successfully Deleted")

def Select():
    if roll_entry.get() == "":
        MessageBox.showinfo("ALERT", "Roll number is required to select row!")
    else:
        con = mysql.connect(host="localhost", user="root", password="tcet", database="college")
        cursor = con.cursor()
        cursor.execute("select * from students where RollNum= '" + roll_entry.get() + "'")
        rows = cursor.fetchall()

        for row in rows:
            name_entry.insert(0, row[0])
            className_entry.insert(0, row[2])

        con.close()

root = Tk()
root.geometry("500x300")
root.title("MySQL CRUD Operations")

roll = Label(root, text="Enter Roll Number:", font=("verdana 15"))
roll.place(x=50, y=30)
roll_entry = Entry(root, font=("verdana 15"))
roll_entry.place(x=150, y=30)

name = Label(root, text="Name:", font=("verdana 15"))
name.place(x=50, y=80)
name_entry = Entry(root, font=("verdana 15"))
name_entry.place(x=150, y=80)

className = Label(root, text="Class", font=("verdana 15"))
className.place(x=50, y=130)
className_entry = Entry(root, font=("verdana 15"))
className_entry.place(x=150, y=130)

btnInsert = Button(root, text="Insert", command=Insert, font=("verdana 15"))
btnInsert.place(x=100, y=190)
btnDelete = Button(root, text="Delete", command=Del, font=("verdana 15"))
btnDelete.place(x=200, y=190)
btnUpdate = Button(root, text="Update", command=Update, font=("verdana 15"))
btnUpdate.place(x=320, y=190)
btnSelect = Button(root, text="Select", command=Select, font=("verdana 15"))
btnSelect.place(x=200, y=240)

root.mainloop()
```





### R CODE:




```python
from tkinter import *
import tkinter.messagebox as MessageBox
import mysql.connector as mysql

# Insert function to insert data into the database
def Insert():
    roll = roll_entry.get()
    name = name_entry.get()
    className = className_entry.get()

    if roll == "" or name == "" or className == "":
        MessageBox.showinfo("ALERT", "Please enter all fields")
    else:
        con = mysql.connect(
            host="localhost", user="root", password="tcet", database="college"
        )
        cursor = con.cursor()
        cursor.execute(
            "insert into students values('"
            + name
            + "', '"
            + roll
            + "', '"
            + className
            + "')"
        )
        cursor.execute("commit")
        MessageBox.showinfo("Status", "Successfully Inserted")
        con.close()

# Update function to update the database
def Update():
    roll = roll_entry.get()
    name = name_entry.get()
    className = className_entry.get()

    if name == "" or className == "":
        MessageBox.showinfo("ALERT", "Please enter fields you want to update!")
    else:
        con = mysql.connect(
            host="localhost", user="root", password="tcet", database="college"
        )
        cursor = con.cursor()
        cursor.execute(
            "update students set StudentName = '"
            + name
            + "', class='"
            + className
            + "' where RollNum ='"
            + roll
            + "'"
        )
        cursor.execute("commit")
        MessageBox.showinfo("Status", "Successfully Updated")
        con.close()

# Delete function to delete a record from the database
def Del():
    if roll_entry.get() == "":
        MessageBox.showinfo("ALERT", "Please enter Roll Number to delete a row")
    else:
        con = mysql.connect(
            host="localhost", user="root", password="tcet", database="college"
        )
        cursor = con.cursor()
        cursor.execute("delete from students where RollNum='" + roll_entry.get() + "'")
        cursor.execute("commit")
        roll_entry.delete(0, "end")
        name_entry.delete(0, "end")
        className_entry.delete(0, "end")
        MessageBox.showinfo("Status", "Successfully Deleted")

# Select specific records of a roll number from the database
def Select():
    if roll_entry.get() == "":
        MessageBox.showinfo("ALERT", "Roll number is required to select a row!")
    else:
        con = mysql.connect(
            host="localhost", user="root", password="tcet", database="college"
        )
        cursor = con.cursor()
        cursor.execute(
            "select * from students where RollNum= '" + roll_entry.get() + "'"
        )
        rows = cursor.fetchall()

        for row in rows:
            name_entry.insert(0, row[0])
            className_entry.insert(0, row[2])

        con close()

# Code for GUI
root = Tk()
root.geometry("500x300")
root.title("MySQL CRUD Operations")

roll = Label(root, text="Enter Roll Number:", font=("verdana 15"))
roll.place(x=50, y=30)
roll_entry = Entry(root, font=("verdana 15"))
roll_entry.place(x=150, y=30)

name = Label(root, text="Name:", font=("verdana 15"))
name.place(x=50, y=80)
name_entry = Entry(root, font=("verdana 15"))
name_entry.place(x=150, y=80)

className = Label(root, text="Class", font=("verdana 15"))
className.place(x=50, y=130)
className_entry = Entry(root, font=("verdana 15"))
className_entry.place(x=150, y=130)

btnInsert = Button(root, text="Insert", command=Insert, font=("verdana 15"))
btnInsert.place(x=100, y=190)
btnDelete = Button(root, text="Delete", command=Del, font=("verdana 15"))
btnDelete.place(x=200, y=190)
btnUpdate = Button(root, text="Update", command=Update, font=("verdana 15"))
btnUpdate.place(x=320, y=190)
btnSelect = Button(root, text="Select", command=Select, font=("verdana 15"))
btnSelect.place(x=200, y=240)

root.mainloop()
```


