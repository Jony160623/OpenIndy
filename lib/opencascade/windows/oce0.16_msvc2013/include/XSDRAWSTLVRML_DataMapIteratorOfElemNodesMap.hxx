// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _XSDRAWSTLVRML_DataMapIteratorOfElemNodesMap_HeaderFile
#define _XSDRAWSTLVRML_DataMapIteratorOfElemNodesMap_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TCollection_BasicMapIterator_HeaderFile
#include <TCollection_BasicMapIterator.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_XSDRAWSTLVRML_DataMapNodeOfElemNodesMap_HeaderFile
#include <Handle_XSDRAWSTLVRML_DataMapNodeOfElemNodesMap.hxx>
#endif
class Standard_NoSuchObject;
class TColStd_DataMapOfIntegerInteger;
class TColStd_MapIntegerHasher;
class XSDRAWSTLVRML_ElemNodesMap;
class XSDRAWSTLVRML_DataMapNodeOfElemNodesMap;



class XSDRAWSTLVRML_DataMapIteratorOfElemNodesMap  : public TCollection_BasicMapIterator {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   XSDRAWSTLVRML_DataMapIteratorOfElemNodesMap();
  
  Standard_EXPORT   XSDRAWSTLVRML_DataMapIteratorOfElemNodesMap(const XSDRAWSTLVRML_ElemNodesMap& aMap);
  
  Standard_EXPORT     void Initialize(const XSDRAWSTLVRML_ElemNodesMap& aMap) ;
  
  Standard_EXPORT    const Standard_Integer& Key() const;
  
  Standard_EXPORT    const TColStd_DataMapOfIntegerInteger& Value() const;





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif