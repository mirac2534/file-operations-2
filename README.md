

# Project Name: File Operation 2 

Date: 03.08.2024  

In this project, I have used file operations but we will do the operations from the terminal. I used 7 functions in this project. These are openFileForUpdate, addContact, listContact, deleteContact, exportContact, updateContacts, searchContacts.


## Planning

### 1. openFileForUpdate Function
- Firstly, openFileForUpdate function is to open for our listing, writing, updating, deleting, exporting, and searching. 

### 2. addContact Function
- addContact function is for our adding from file. Initially, checks the number of arguments you entered. If the number of arguments you entered is seven, you can add person but the number of arguments you entered is not seven, you cannot add person and returns error message.

### 3. listContact Function
- listContact functions is for our listing from file. Firstly,  checks the number of arguments  you entered. If the number of arguments you entered is two, you can see list  but the number of arguments you entered is not two, you cannot see list.

### 4. deleteContact Function
deleteContact function is for our deleting from file. Foremost, checks the number of arguments  you entered. If the number of arguments you entered is three, you can delete  but the number of arguments you entered is not three, you cannot delete from file. Then also checks inline phone number. If this number matches the number in the file, the deletion process takes place. 

### 5. exportContact Function
- exportContact function is for our exporting. Firstly, opens the file. If don't find the file, doesn't work. After work, reads file and writes all saved persons. 

### 6. updateContacts Function
- updateContacts function is for our updating. Initially, checks the number of arguments you entered. If the number of arguments you entered is not three, doesn't work. After work, Then also checks inline phone number. If this number matches the number in the file, the updation process is starting. You will see old name and you must enter new name. In the last name and depertman it will be like this. Finally, updates information you entered from file. 

### 7. searchContacts
- searchContacts function is for our searching. Foremost, checks the number of arguments you entered. If the number of arguments you entered is not four, doesn't work. 
-- If the letter you entered for the argument is n and the name you entered in terminal is equal to the name where in the file, you can look that phone number, name, last name and department.
-- If the letter you entered for the arguments is l and the last name you entered in terminal is equal to the last name where in file, you can look that phone number name, last name and department.
-- If the letter you entered for arguments is p and the phone number you entered in terminal is equal to the phone number where in the file, you can look that phone number name, last name and department.
-- If the letter you entered for arguments is d and the deparment  you entered in terminal is equal to the department where in the file, you can look that phone number name, last name, and department.
## 
The purpose of this file processing project is to improve the ability to process information from the terminal by receiving it from the terminal
