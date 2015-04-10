#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QObject>
#include <QtXml>

#include "geometry.h"
#include "position.h"
#include "radius.h"
#include "direction.h"

/*!
 * \brief The Ellipse class
 */
class Ellipse : public Geometry
{
    Q_OBJECT

public:
    Ellipse(const bool &isNominal, QObject *parent = 0);
    Ellipse(const bool &isNominal, const Position &center, const Direction &normal, const double &a, const double &b, const Direction &semiMajorAxis, QObject *parent = 0);

    Ellipse(const Ellipse &copy, QObject *parent = 0);

    Ellipse &operator=(const Ellipse &copy);

    ~Ellipse();

    //########################################
    //order of unknown parameters (Qxx-matrix)
    //########################################

    enum EllipseUnknowns{
        unknownCenterX,
        unknownCenterY,
        unknownCenterZ,
        unknownNormalI,
        unknownNormalJ,
        unknownNormalK,
        unknownA,
        unknownB,
        unknownSemiMajorAxisI,
        unknownSemiMajorAxisJ,
        unknownSemiMajorAxisK
    };

    //###################################################################
    //check wether this geometry has a direction, a position and a radius
    //###################################################################

    bool hasDirection() const;
    bool hasPosition() const;

    //#############################
    //get or set ellipse parameters
    //#############################

    const Direction &getDirection() const;
    const Position &getPosition() const;

    const double &getA() const;
    const double &getB() const;
    const Direction &getSemiMajorAxisDirection() const;

    void setEllipse(const Position &center, const Direction &normal, const double &a, const double &b, const Direction &semiMajorAxis);

    //###########################
    //reexecute the function list
    //###########################

    void recalc();

    //#################
    //save and load XML
    //#################

    QDomElement toOpenIndyXML(QDomDocument &xmlDoc) const;
    bool fromOpenIndyXML(QDomElement &xmlElem);

private:

    //##################
    //ellipse attributes
    //##################

    Position center; //center
    Direction normal; //normal vector
    double a; //semi-major axis length
    double b; //semi-minor axis length
    Direction semiMajorAxis; //semi-major axis direction

};

#endif // ELLIPSE_H
