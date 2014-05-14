#include "p_pseudotracker.h"

PseudoTracker::PseudoTracker(){
    myAzimuth = 0.0;
    myZenith = 0.0;
    myDistance =0.0;
    myMotor = false;
    myInit = false;
    myCompIt = false;
    isConnected = false;
    side = 1;

    this->sensorActionInProgress = false;
}

PluginMetaData* PseudoTracker::getMetaData(){

    PluginMetaData* metaData = new PluginMetaData();

    metaData->name = "PseudoTracker";
    metaData->pluginName = "OpenIndy Default Plugin";
    metaData->author = "mlux";
    metaData->description = "Simuliert einen Laser Tracker";
    metaData->iid = "de.openIndy.Plugin.Sensor.LaserTracker.v001";
    //...

    return metaData;
}


QList<Configuration::ReadingTypes>* PseudoTracker::getSupportedReadingTypes(){

    QList<Configuration::ReadingTypes> *readingTypes = new QList<Configuration::ReadingTypes>;

    readingTypes->append(Configuration::ePolar);
    readingTypes->append(Configuration::eDirection);
    readingTypes->append(Configuration::eDistance);
    readingTypes->append(Configuration::eCartesian);
    readingTypes->append(Configuration::eTemperatur);
    readingTypes->append(Configuration::eLevel);

    return readingTypes;
}

QList<Configuration::SensorFunctionalities> PseudoTracker::getSupportedSensorActions()
{
    QList<Configuration::SensorFunctionalities> sensorActions;

    sensorActions.append(Configuration::eHome);
    sensorActions.append(Configuration::eInitialize);
    sensorActions.append(Configuration::eMoveAngle);
    sensorActions.append(Configuration::eMoveXYZ);
    sensorActions.append(Configuration::eToggleSight);
    sensorActions.append(Configuration::eCompensation);
    sensorActions.append(Configuration::eMotorState);

    return sensorActions;

}

QList<Configuration::ConnectionTypes>* PseudoTracker::getConnectionType(){
    QList<Configuration::ConnectionTypes> *connectionTypes = new QList<Configuration::ConnectionTypes>;
    connectionTypes->append(Configuration::eNetwork);
    connectionTypes->append(Configuration::eSerial);

    return connectionTypes;
}

QMap<QString,int>* PseudoTracker::getIntegerParameter(){
    return NULL;
}

QMap<QString,double>* PseudoTracker::getDoubleParameter(){

    return NULL;

}

QMap <QString, QStringList>* PseudoTracker::getStringParameter(){

    QMap <QString, QStringList>* stringParameter = new QMap<QString, QStringList>;

    QStringList SMRTypes;

    SMRTypes.append("1.5''");
    SMRTypes.append("1.0''");
    SMRTypes.append("0.5''");

    stringParameter->insert("active probe",SMRTypes);

    return stringParameter;

}

QStringList PseudoTracker::selfDefinedActions()
{
    QStringList ownActions;

    ownActions.append("echo");

    return ownActions;
}

bool PseudoTracker::doSelfDefinedAction(QString a)
{
    this->sensorActionInProgress = true;
    if(a == "echo"){
      writeToConsole(a);
    }
    this->sensorActionInProgress = false;
    return true;
}

QMap<QString, double>* PseudoTracker::getDefaultAccuracy()
{
    QMap<QString,double> *defaultAccuracy = new QMap<QString,double>;

    defaultAccuracy->insert("sigmaAzimuth",0.000001570);
    defaultAccuracy->insert("sigmaZenith",0.000001570);
    defaultAccuracy->insert("sigmaDistance",0.000025);
    defaultAccuracy->insert("sigmaX",0.000025);
    defaultAccuracy->insert("sigmaY",0.000025);
    defaultAccuracy->insert("sigmaZ",0.000025);
    defaultAccuracy->insert("sigmaTempDeg", 0.5);
    defaultAccuracy->insert("sigmaAngleXZ", 0.000001570);
    defaultAccuracy->insert("sigmaAngleYZ", 0.000001570);

    return defaultAccuracy;
}

void PseudoTracker::abortAction()
{
    //abort action
}


//! connect app with laser tracker
bool PseudoTracker::connectSensor(ConnectionConfig *cConfig){

    this->sensorActionInProgress = true;
    if(cConfig != NULL){
        qDebug() << cConfig->ip;
        qDebug() << cConfig->port;
        isConnected = true;
        QThread::msleep(1000);
        this->sensorActionInProgress = false;
        return true;
    }else{
        qDebug() << "null pointer";
        this->sensorActionInProgress = false;
        return false;
    }


}

//! disconnect app with laser tracker
bool PseudoTracker::disconnectSensor(){
    this->sensorActionInProgress  = true;
    qDebug() << "pseudo tracker disconnect";
    isConnected = false;
    QThread::msleep(1000);
    this->sensorActionInProgress = false;
    return true;
}

//! starts initialization
bool PseudoTracker::initialize(){

    this->sensorActionInProgress = true;
    qDebug() << "pseudo tracker is initialized";
    myInit = true;
    QThread::msleep(1000);
    this->sensorActionInProgress = false;
    return true;
}

//! move laser tracker to specified position
bool PseudoTracker::move(double azimuth, double zenith, double distance,bool isrelativ){

    qDebug() << "pseudo tracker is moved to:" << azimuth << "," << zenith << "," << distance << "," << isrelativ ;
    this->sensorActionInProgress = true;
    myAzimuth = azimuth;
    myZenith = zenith;
    myDistance = distance;


    QThread::msleep(1000);
    this->sensorActionInProgress = false;
    return true;
}

bool PseudoTracker::move(double x, double y, double z){

    qDebug() << "pseudo tracker is moved to:" << x << "," << y << "," << z;
    this->sensorActionInProgress = true;
    myAzimuth = qAtan2(y,x);
    myDistance = qSqrt(x*x+y*y+z*z);
    myZenith = acos(z/myDistance);

    QThread::msleep(1000);
    this->sensorActionInProgress = false;
    return true;
}

//! sets laser tracke to home position
bool PseudoTracker::home(){

    qDebug() << "pseudo tracker is moved to home" ;
    this->sensorActionInProgress = true;
    QThread::msleep(1000);
    this->sensorActionInProgress = false;
    return true;

}

//! turns motors on or off
bool PseudoTracker::changeMotorState(){

    this->sensorActionInProgress = true;
    qDebug() << "pseudo tracker changed motor state" ;
    if(myMotor){
        this->sensorActionInProgress = false;
        myMotor = false;
    }else{
        this->sensorActionInProgress = false;
        myMotor = true;
    }
    QThread::msleep(1000);
    this->sensorActionInProgress = false;
    return true;

}

//! toggle between frontside and backside
bool PseudoTracker::toggleSightOrientation(){

    qDebug() << "pseudo tracker toggeld Sight orientation" ;
    this->sensorActionInProgress = true;
    if(side = 1){
       side = 2;
    }else{
        side = 1;
    }
    QThread::msleep(1000);
    this->sensorActionInProgress = false;
    return true;
}

bool PseudoTracker::compensation() {
    qDebug() << "compensation successful";
    this->sensorActionInProgress = true;
    QThread::msleep(5000);
    myCompIt = true;
    this->sensorActionInProgress = false;
    return true;
}


QList<Reading*> PseudoTracker::measure(MeasurementConfig *mc){

    switch (mc->typeOfReading) {
    case Configuration::ePolar:{
        return measurePolar(mc);
        break;
    }case Configuration::eDistance:{
        return measureDistance(mc);
        break;
    }case Configuration::eDirection:{
        return measureDirection(mc);
        break;
    }case Configuration::eCartesian:{
        return measureCartesian(mc);
        break;
    }
    default:
        break;
    }

    QList<Reading*> readings;
    return readings;
}

QVariantMap PseudoTracker::readingStream(Configuration::ReadingTypes streamFormat)
{
    this->sensorActionInProgress = true;

    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    QVariantMap m;


        x =((double) std::rand()/RAND_MAX)*(10.0-1.0)+1.0;
        y =((double) std::rand()/RAND_MAX)*(10.0-1.0)+1.0;
        z =((double) std::rand()/RAND_MAX)*(10.0-1.0)+1.0;

        m.insert("x",x);
        m.insert("y",y);
        m.insert("z",z);

    QThread::msleep(100);

    this->sensorActionInProgress = false;

    return m;

}

bool PseudoTracker::getConnectionState()
{
    return isConnected;
}

bool PseudoTracker::isReadyForMeasurement()
{
    return true;
}

QMap<QString, QString> PseudoTracker::getSensorStats()
{
    this->sensorActionInProgress = true;
    QMap<QString, QString> stats;

    stats.insert("connected",QString::number(isConnected));
    stats.insert("side", QString::number(side));
    stats.insert("myAzimuth", QString::number(myAzimuth));
    stats.insert("myZenith", QString::number(myZenith));
    stats.insert("myDistance", QString::number(myDistance));
    stats.insert("myMotor", QString::number(myMotor));
    stats.insert("myInit", QString::number(myInit));
    stats.insert("myCompIt", QString::number(myCompIt));

    this->sensorActionInProgress = false;
    return stats;

}

bool PseudoTracker::isBusy()
{
    return this->sensorActionInProgress;
}


QList<Reading*> PseudoTracker::measurePolar(MeasurementConfig *m){

    this->sensorActionInProgress = true;
    QList<Reading*> readings;

    Reading *p = new Reading();

    /*p->rPolar.azimuth = ((double) std::rand()/RAND_MAX)*(6.283185-0.0001)+1.0;
    p->rPolar.zenith = ((double) std::rand()/RAND_MAX)*(1.57079-0.0001)+1.0;
    p->rPolar.distance = ((double) std::rand()/RAND_MAX)*(10.0-1.0)+1.0;
    p->rPolar.fsBs = m->face;*/

    p->rPolar.azimuth = myAzimuth;
    p->rPolar.zenith = myZenith;
    p->rPolar.distance = myDistance;
    p->rPolar.fsBs = m->face;

    p->instrument = this;
    p->measuredAt = QDateTime::currentDateTime();

    QThread::msleep(1000);

    readings.append(p);
    this->sensorActionInProgress = false;
    return readings;

}

QList<Reading*> PseudoTracker::measureDistance(MeasurementConfig *m){

    this->sensorActionInProgress = true;
    QList<Reading*> readings;

    Reading *p = new Reading();

    p->rDistance.distance = myDistance;
    p->instrument = this;
    p->measuredAt = QDateTime::currentDateTime();

    QThread::msleep(1000);

    readings.append(p);
    this->sensorActionInProgress = false;
    return readings;
}

QList<Reading*> PseudoTracker::measureDirection(MeasurementConfig *m){

    this->sensorActionInProgress = true;
    QList<Reading*> readings;

    Reading *p = new Reading();

    p->rDirection.azimuth = myAzimuth;
    p->rDirection.zenith = myZenith;
    p->rDirection.fsBs = m->face;

    p->instrument = this;
    p->measuredAt = QDateTime::currentDateTime();

    QThread::msleep(1000);

    readings.append(p);
    this->sensorActionInProgress = false;
    return readings;
}

QList<Reading*> PseudoTracker::measureCartesian(MeasurementConfig *m){

    this->sensorActionInProgress = true;
    QList<Reading*> readings;

    Reading *p = new Reading();

    p->rCartesian.xyz.setAt(0, (myDistance * qSin(myZenith) * qCos(myAzimuth)));
    p->rCartesian.xyz.setAt(1, (myDistance * qSin(myZenith) * qSin(myAzimuth)));
    p->rCartesian.xyz.setAt(2, (myDistance * qCos(myZenith)));
    p->rCartesian.xyz.setAt(3, 1);

    p->instrument = this;
    p->measuredAt = QDateTime::currentDateTime();

    QThread::msleep(1000);

    readings.append(p);
    this->sensorActionInProgress = false;
    return readings;
}
