// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepFeat_MakeCylindricalHole_HeaderFile
#define _BRepFeat_MakeCylindricalHole_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _gp_Ax1_HeaderFile
#include <gp_Ax1.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _BRepFeat_Status_HeaderFile
#include <BRepFeat_Status.hxx>
#endif
#ifndef _TopoDS_Face_HeaderFile
#include <TopoDS_Face.hxx>
#endif
#ifndef _BRepFeat_Builder_HeaderFile
#include <BRepFeat_Builder.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
class StdFail_NotDone;
class Standard_ConstructionError;
class gp_Ax1;
class TopoDS_Shape;


//! Provides a tool to make cylindrical holes on a shape. <br>
class BRepFeat_MakeCylindricalHole  : public BRepFeat_Builder {
public:

  DEFINE_STANDARD_ALLOC

  //! Empty constructor. <br>
      BRepFeat_MakeCylindricalHole();
  //! Sets the axis of the hole(s). <br>
        void Init(const gp_Ax1& Axis) ;
  //! Sets the shape and  axis on which hole(s)  will be <br>
//!          performed. <br>
        void Init(const TopoDS_Shape& S,const gp_Ax1& Axis) ;
  //! Performs every  holes of   radius  <Radius>.  This <br>
//!          command  has the  same effect as   a cut operation <br>
//!          with an  infinite cylinder   defined by the  given <br>
//!          axis and <Radius>. <br>
  Standard_EXPORT     void Perform(const Standard_Real Radius) ;
  //! Performs evry   hole  of  radius  <Radius> located <br>
//!          between PFrom  and  PTo  on the  given  axis.   If <br>
//!          <WithControl> is set  to Standard_False no control <br>
//!          are  done  on   the  resulting  shape   after  the <br>
//!          operation is performed. <br>
  Standard_EXPORT     void Perform(const Standard_Real Radius,const Standard_Real PFrom,const Standard_Real PTo,const Standard_Boolean WithControl = Standard_True) ;
  //! Performs the first hole of radius <Radius>, in the <br>
//!          direction of  the defined axis. First hole signify <br>
//!          first encountered after the origin of the axis. If <br>
//!          <WithControl> is set  to Standard_False no control <br>
//!          are  done  on   the  resulting  shape   after  the <br>
//!          operation is performed. <br>
  Standard_EXPORT     void PerformThruNext(const Standard_Real Radius,const Standard_Boolean WithControl = Standard_True) ;
  //! Performs  evry  holes of  radius  <Radius> located <br>
//!          after  the   origin  of   the given    axis.    If <br>
//!          <WithControl> is  set to Standard_False no control <br>
//!          are done   on   the  resulting  shape   after  the <br>
//!          operation is performed. <br>
  Standard_EXPORT     void PerformUntilEnd(const Standard_Real Radius,const Standard_Boolean WithControl = Standard_True) ;
  //! Performs a  blind   hole of radius    <Radius> and <br>
//!          length <Length>.  The length is  measured from the <br>
//!          origin of the given  axis. If <WithControl> is set <br>
//!          to  Standard_False no  control  are done after the <br>
//!          operation is performed. <br>
  Standard_EXPORT     void PerformBlind(const Standard_Real Radius,const Standard_Real Length,const Standard_Boolean WithControl = Standard_True) ;
  //! Returns the status after a hole is performed. <br>
        BRepFeat_Status Status() const;
  //! Builds the    resulting shape  (redefined     from <br>
//!          MakeShape). Invalidates the  given parts  of tools <br>
//!          if  any,   and performs the  result   of the local <br>
//!          operation. <br>
  Standard_EXPORT     void Build() ;





protected:





private:

  
  Standard_EXPORT     BRepFeat_Status Validate() ;


gp_Ax1 myAxis;
Standard_Boolean myAxDef;
BRepFeat_Status myStatus;
Standard_Boolean myIsBlind;
Standard_Boolean myValidate;
TopoDS_Face myTopFace;
TopoDS_Face myBotFace;


};


#include <BRepFeat_MakeCylindricalHole.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif