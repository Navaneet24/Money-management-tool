# Social Money Management System

The **Social Money Management System** is a program written in C that allows users to manage expenses and split bills among a group of members for various events. It provides functionality to calculate expenditure, split bills equally or based on a percentage share, and display member details.

## Code Structure

The code consists of several functions to perform different tasks. Here's an overview of the functions and their purpose:

1. `struct data`: This structure defines the data fields for each member, including their name, email, phone, and mode of payment.

2. `displayDetails()`: This function takes a pointer to an array of member data and the number of members as input. It prompts the user to enter a name and displays the details of the member with the matching name.

3. `billcalc()`: This function calculates the bill splitting among members based on the chosen option: equal splitting, unequal splitting, or percentage share. It takes the group name, total amount, number of members, and an array of amounts paid as input.

4. `check()`: This function is used to calculate unequal splitting of bills. It prompts the user to enter the amount paid by each member and ensures that the total amount paid does not exceed the total bill amount.

5. `ptgcheck()`: This function is used to calculate bill splitting based on a percentage share. It prompts the user to enter the percentage share of each member and calculates the share amount accordingly.

6. `split()`: This function is responsible for splitting the bill among members after the payment has been made. It takes the total amount, arrays of indices for positive and negative differences, the difference amounts, member names, and the event name as input.

7. `main()`: This is the main function of the program. It prompts the user to enter the number of members and their details. Then it asks for the event name and total amount. Based on the user's choice, it either calculates the expenditure before paying the bill or splits the bill among members after payment. It also provides an option to fetch member details and allows the user to continue for another event or exit the program.

## Usage

To use the program, compile the code and run the executable. Follow the prompts to enter the required information such as member details, event name, and total amount. Choose the desired options to calculate expenditure or split the bill. The program will display the calculated amounts and suggestions for bill splitting. You can also choose to fetch member details or continue for another event.



