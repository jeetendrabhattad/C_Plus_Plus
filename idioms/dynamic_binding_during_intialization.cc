/*
Description : Simulate calling of virtual functions during object initialization.
Sometimes it is desirable to invoke virtual functions of derived classes while a derived object is being initialized. 
Language rules explicitly prohibit this from happening because calling member functions of derived object before derived part of the object is initialized 
is dangerous. It is not a problem if the virtual function does not access data members of the object being constructed.
But there is no general way of ensuring it.

Solution:
There are multiple ways of achieving the desired effect. Each has its own pros and cons. In general the approaches can be divided into two categories. One using two phase initialization and other one using only single phase initialization.

Two phase initialization technique separates object construction from initializing its state. Such a separation may not be always possible. Initialization of object's state is clubbed together in a separate function, which could be a member function or a free standing function.
*/
