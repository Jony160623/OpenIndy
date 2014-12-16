// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _AppParCurves_ConstraintCouple_HeaderFile
#define _AppParCurves_ConstraintCouple_HeaderFile

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
#ifndef _AppParCurves_Constraint_HeaderFile
#include <AppParCurves_Constraint.hxx>
#endif


//! associates an index and a constraint for an object. <br>
//! This couple is used by AppDef_TheVariational when performing approximations. <br>
class AppParCurves_ConstraintCouple  {
public:

  DEFINE_STANDARD_ALLOC

  //! returns an indefinite ConstraintCouple. <br>
  Standard_EXPORT   AppParCurves_ConstraintCouple();
  //! Create a couple the object <Index> will have the <br>
//!          constraint <Cons>. <br>
  Standard_EXPORT   AppParCurves_ConstraintCouple(const Standard_Integer TheIndex,const AppParCurves_Constraint Cons);
  //! returns the index of the constraint object. <br>
  Standard_EXPORT     Standard_Integer Index() const;
  //! returns the constraint of the object. <br>
  Standard_EXPORT     AppParCurves_Constraint Constraint() const;
  //! Changes the index of the constraint object. <br>
  Standard_EXPORT     void SetIndex(const Standard_Integer TheIndex) ;
  //! Changes the constraint of the object. <br>
  Standard_EXPORT     void SetConstraint(const AppParCurves_Constraint Cons) ;





protected:





private:



Standard_Integer myIndex;
AppParCurves_Constraint myConstraint;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif