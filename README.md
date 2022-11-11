# Model-View-Architecture-Custom-Delegates
Exploring the Model View Architecture Implementation in QT.

QT Implements the Model-View-Architecture (MVC) slightly differently than usual. Rather than having the Controller, it uses something called a Delegate to interact between the Model and the View. Essentially when we load our Data into the Model and then Assign it to the View, we can then interact with the View by double clicking any field. This spawns a delegate which allows us to enter in new choices for the data in that field (based on the role we want to amend in that data field).

So here I have re-implemented the delegate and model classes in order to provide my own functionality. Instead of the rating appearing as a regular numerical spinbox, I have implemented a scale of 5-point stars which you can drag or click in order to enter your value. Additionally the Favourite Colour field has been replaced with a Combo Box to allow you to choose from the range of colours the system recognises. As soon as one is selected the field is repainted with that colour.

We can create entirely custom tables and tree views, to display and interact with Data using the Model View Architecture.

https://user-images.githubusercontent.com/111576658/201354712-71911bbf-c781-4c55-b801-1ed685c62af5.mp4

