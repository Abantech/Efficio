#Efficio C++
The Efficio C++ project is the base on which all other language projects are built.

Getting the Project to Build in Visual Studio
=============================================

1. Download [SWIG](http://swig.org/download) for Windows v3.0.10.
1. Add SWIG to the Path environment variable.
1. Download [Doxygen](http://doxygen.org).
1. Add Doxygen to the Path environment variable.
1. Download the Leap Motion SDK.
1. Create an environment variable called LEAP_SDK pointing to the Leap Motion SDK.


1. When the project is compiled .cxx files will be generated or overwritten for each given target language. Make sure these are writable and if generated for the first time, are included in the vcxproj