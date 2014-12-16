// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _GeomFill_PolynomialConvertor_HeaderFile
#define _GeomFill_PolynomialConvertor_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _math_Matrix_HeaderFile
#include <math_Matrix.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
class StdFail_NotDone;
class gp_Pnt;
class gp_Vec;
class TColgp_Array1OfPnt;
class TColgp_Array1OfVec;


//!  To convert circular section in polynome <br>
class GeomFill_PolynomialConvertor  {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   GeomFill_PolynomialConvertor();
  //! say if <me> is Initialized <br>
  Standard_EXPORT     Standard_Boolean Initialized() const;
  
  Standard_EXPORT     void Init() ;
  
  Standard_EXPORT     void Section(const gp_Pnt& FirstPnt,const gp_Pnt& Center,const gp_Vec& Dir,const Standard_Real Angle,TColgp_Array1OfPnt& Poles) const;
  
  Standard_EXPORT     void Section(const gp_Pnt& FirstPnt,const gp_Vec& DFirstPnt,const gp_Pnt& Center,const gp_Vec& DCenter,const gp_Vec& Dir,const gp_Vec& DDir,const Standard_Real Angle,const Standard_Real DAngle,TColgp_Array1OfPnt& Poles,TColgp_Array1OfVec& DPoles) const;
  
  Standard_EXPORT     void Section(const gp_Pnt& FirstPnt,const gp_Vec& DFirstPnt,const gp_Vec& D2FirstPnt,const gp_Pnt& Center,const gp_Vec& DCenter,const gp_Vec& D2Center,const gp_Vec& Dir,const gp_Vec& DDir,const gp_Vec& D2Dir,const Standard_Real Angle,const Standard_Real DAngle,const Standard_Real D2Angle,TColgp_Array1OfPnt& Poles,TColgp_Array1OfVec& DPoles,TColgp_Array1OfVec& D2Poles) const;





protected:





private:



Standard_Integer Ordre;
Standard_Boolean myinit;
math_Matrix BH;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif