# C_programmable_Library

Linux System programmable C/C++ libraries
Both static and dynamic libraries are created.

The libraries developed are
1) Generic
2) Programmable
3) Extensible
4) Modularized 

Here as an example Doubly linked list library is developed.
Advanced concepts like Makefile and Iterative Macros etc are included.

Any application which wants to organize its internal data structures using doubly linked 
list can use this libraries.

In this search and comparision operation is delegated to the library itself using callback
(function pointer) functions.

User needs to write appropriate callbak maethods in the application and register them with 
libraries using functions provided by libraries so libraries can use them to do application 
specific task while being application agnostics.

This library is programmable means user can programm it(using function pointer). This feature in other 
lanuages such as C++/Java is implemented using generics.

For more details look into individual folders of the project.




