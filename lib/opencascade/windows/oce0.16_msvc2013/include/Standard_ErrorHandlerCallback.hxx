// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Standard_ErrorHandlerCallback_HeaderFile
#define _Standard_ErrorHandlerCallback_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
class Standard_ErrorHandler;


//! Defines a base class for callback objects that can be registered <br>
//!          in the OCC error handler (the class simulating C++ exceptions) <br>
//!          so as to be correctly destroyed when error handler is activated. <br>
//! <br>
//!          Note that this is needed only when Open CASCADE is compiled with <br>
//!          NO_CXX_EXCEPTION or OCC_CONVERT_SIGNALS options (i.e. on UNIX/Linux). <br>
//!          In that case, raising OCC exception and/or signal will not cause <br>
//!          C++ stack unwinding and destruction of objects created in the stack. <br>
//! <br>
//!          This class is intended to protect critical objects and operations in <br>
//!          the try {} catch {} block from being bypassed by OCC signal or exception. <br>
//! <br>
//!          Inherit your object from that class, implement DestroyCallback() function, <br>
//!          and call Register/Unregister in critical points. <br>
//! <br>
//!          Note that you must ensure that your object has life span longer than <br>
//!          that of the try {} block in which it calls Register(). <br>
class Standard_ErrorHandlerCallback  {
public:

  DEFINE_STANDARD_ALLOC

  //! Registers this callback object in the current error handler <br>
//!          (if found). <br>
        void RegisterCallback() ;
  //! Unregisters this callback object from the error handler. <br>
        void UnregisterCallback() ;
virtual Standard_EXPORT ~Standard_ErrorHandlerCallback ();
  //! The callback function to perform necessary callback action. <br>
//!          Called by the exception handler when it is being destroyed but <br>
//!          still has this callback registered. <br>
  Standard_EXPORT   virtual  void DestroyCallback()  = 0;


friend class Standard_ErrorHandler;



protected:

  //! Empty constructor <br>
      Standard_ErrorHandlerCallback();




private:



Standard_Address myHandler;
Standard_Address myPrev;
Standard_Address myNext;


};


#include <Standard_ErrorHandlerCallback.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif