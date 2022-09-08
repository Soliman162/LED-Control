# LED-Control
Led Control using TM4C123GH6PM


# Control blinking of an LED for a user-defined ON and OFF periods
Create a function in the App layer that takes as an input from the user a specific ON time and OFF time in seconds, 
lights a LED for the given ON time, and dim it for the given OFF time. 
It’s prohibited to use predefined delay functions, only timer driver functions can be used. 
This function implements implicitly the PWM module using Timer Overflow.

# For GPIO Driver
1. Create the GPIO driver from scratch using the sufficient interface,configure,private and program files
2. Create functions in GPIO driver that are needed to perform the required project functionality

# For Timer Driver
1. Create the Timer driver from scratch using the sufficient interface,configure,private and program files
2. Create functions in Timer driver that are needed to perform the required project functionality
3. Creating a Timer Overflow ISR that performs the required functionality
4. Passing the ISR as a callback function from App Layer to Timer driver in MCAL layer

# For NVIC Driver
1. Creating the Interrupt driver from scratch using the sufficient interface, configure, private and program files
2. Create functions in Interrupt driver that are needed to perform the required project functionality
