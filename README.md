# embedded c code for I2C PROTOCOL  and hardware design in proteus software.
#
Inter Intergrated communication protocol( i2c)Inter Intergrated communication protocol( i2c)

Associated with National Institute of Technology WarangalAssociated with National Institute of Technology Warangal
The I2C (Inter-Integrated Circuit) protocol project involves the development of a communication system that enables data exchange between integrated circuits (ICs) using a synchronous, serial communication protocol. 
Developed Embedded C code and made the hardware connection on Proteus software . In which used 
24C04A EEPROM to store permanent data. It is a non-volatile memory. I2C debugger for debugging I2C communication between devices, AT89C51 microcontroller (8051-family) and 16x2 LCD display.
Master-Slave Communication: The project implements the master-slave communication model, where one device acts as the master and initiates communication, while the other devices act as slaves and respond to commands from the master.

Data Transmission: Data is transmitted serially over the I2C bus. It involves sending packets of information, typically comprising a start condition, device address, data bytes, and stop condition.

Addressing: The master initiates communication by sending the address of the target slave device along with the desired read or write operation. Each slave device on the bus has a unique address, allowing the master to address specific devices.
