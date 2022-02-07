# projectEV-3
Project is for developing a battery swapping system for EV's. 
Long way to go. 

> Project contains two Microcontrollers communicating with each other using some suitable protocol 

> Controller 1: (INSIDE THE CAR BATTERY)(This controller is to be swapped along with battery)
> Monitor battery voltage using ADC
> Keeps a Unique ID. 
> Calculate battery power discharged during running. Also monitors battery health based on power discharge.
> Also keeps a record of battery cycles remaining till its next recycle. 
> It will keep a record of the car's Identification code. 
> When swapping, it will receive the swapping station Identification code through uart and stores it in memory. 
> Also when requested, it will send all battey datas. 
> Displays all these datas to I2C display 
    * things to master: ADC, UART, I2C, data Logging 

> Controller 2: (IN THE SWAPPING STATION)
> keeps track of all the batteries in the swapping station. All the controllers in the batteries talks to this controller and sends their datas via uart. 
> will send this data to a wifi module and the data can be viewed by user by connecting to network
> when not swapping, it charges every battery available to it to max. 
> during swapping, Send the Station Unique ID to battery microcontroller during uart. the controller 1 logs this data. It then checks the battery level and swaps the battery with any other battery with sufficient charge.
> it checks if the battery is to be recycled. 


> implemented so far: 
> I2C driving oled
> UART communication 
> ADC Reading. 

