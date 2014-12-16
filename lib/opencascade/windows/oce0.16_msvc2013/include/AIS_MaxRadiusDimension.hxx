// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _AIS_MaxRadiusDimension_HeaderFile
#define _AIS_MaxRadiusDimension_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_AIS_MaxRadiusDimension_HeaderFile
#include <Handle_AIS_MaxRadiusDimension.hxx>
#endif

#ifndef _gp_Pnt_HeaderFile
#include <gp_Pnt.hxx>
#endif
#ifndef _AIS_EllipseRadiusDimension_HeaderFile
#include <AIS_EllipseRadiusDimension.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _DsgPrs_ArrowSide_HeaderFile
#include <DsgPrs_ArrowSide.hxx>
#endif
#ifndef _Handle_PrsMgr_PresentationManager3d_HeaderFile
#include <Handle_PrsMgr_PresentationManager3d.hxx>
#endif
#ifndef _Handle_Prs3d_Presentation_HeaderFile
#include <Handle_Prs3d_Presentation.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_Prs3d_Projector_HeaderFile
#include <Handle_Prs3d_Projector.hxx>
#endif
#ifndef _Handle_Geom_Transformation_HeaderFile
#include <Handle_Geom_Transformation.hxx>
#endif
#ifndef _Handle_SelectMgr_Selection_HeaderFile
#include <Handle_SelectMgr_Selection.hxx>
#endif
class Standard_ConstructionError;
class TopoDS_Shape;
class TCollection_ExtendedString;
class gp_Pnt;
class PrsMgr_PresentationManager3d;
class Prs3d_Presentation;
class Prs3d_Projector;
class Geom_Transformation;
class SelectMgr_Selection;



//!  Ellipse  Max  radius  dimension  of  a  Shape  which  can  be  Edge <br>
//!  or  Face  (planar  or  cylindrical(surface  of  extrusion  or <br>
//!  surface  of  offset)) <br>
class AIS_MaxRadiusDimension : public AIS_EllipseRadiusDimension {

public:

  //! Max  Ellipse  radius dimension <br>
//!  Shape  can  be  edge  ,  planar  face  or  cylindrical  face <br>
//! <br>
  Standard_EXPORT   AIS_MaxRadiusDimension(const TopoDS_Shape& aShape,const Standard_Real aVal,const TCollection_ExtendedString& aText);
  //!  Max  Ellipse  radius dimension with  position <br>
//!  Shape  can  be  edge  ,  planar  face  or  cylindrical  face <br>
//! <br>
  Standard_EXPORT   AIS_MaxRadiusDimension(const TopoDS_Shape& aShape,const Standard_Real aVal,const TCollection_ExtendedString& aText,const gp_Pnt& aPosition,const DsgPrs_ArrowSide aSymbolPrs,const Standard_Real anArrowSize = 0.0);
  //! computes the presentation according to a point of view <br>
//!          given by <aProjector>. <br>
//!          To be Used when the associated degenerated Presentations <br>
//!          have been transformed by <aTrsf> which is not a Pure <br>
//!          Translation. The HLR Prs can't be deducted automatically <br>
//!          WARNING :<aTrsf> must be applied <br>
//!           to the object to display before computation  !!! <br>
  Standard_EXPORT   virtual  void Compute(const Handle(Prs3d_Projector)& aProjector,const Handle(Geom_Transformation)& aTrsf,const Handle(Prs3d_Presentation)& aPresentation) ;




  DEFINE_STANDARD_RTTI(AIS_MaxRadiusDimension)

protected:




private: 

  
  Standard_EXPORT   virtual  void Compute(const Handle(PrsMgr_PresentationManager3d)& aPresentationManager,const Handle(Prs3d_Presentation)& aPresentation,const Standard_Integer aMode = 0) ;
  
  Standard_EXPORT     void Compute(const Handle(Prs3d_Projector)& aProjector,const Handle(Prs3d_Presentation)& aPresentation) ;
  
  Standard_EXPORT   virtual  void ComputeSelection(const Handle(SelectMgr_Selection)& aSelection,const Standard_Integer aMode) ;
  
  Standard_EXPORT     void ComputeEllipse(const Handle(Prs3d_Presentation)& aPresentation) ;
  
  Standard_EXPORT     void ComputeArcOfEllipse(const Handle(Prs3d_Presentation)& aPresentation) ;

gp_Pnt myApexP;
gp_Pnt myApexN;
gp_Pnt myEndOfArrow;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif