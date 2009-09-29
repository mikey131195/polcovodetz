﻿

#ifndef  __IOBJECT_DRIVERS
#define  __IOBJECT_DRIVERS

//-------------------------------------------------------

#include <IAbstractDrivers.h>
#include <PObject.h>
#include <MovementDirection.h>

//-------------------------------------------------------

class IObjectController;

class ObjectGroupMessage;
class GroupObjectMessage;
class ObjectCoreMessage;
class CoreObjectMessage;

//-------------------------------------------------------

enum ObjectRotation
{ 
    ToTop, 
    ToBottom, 
    ToLeft, 
    ToRight 
};

//-------------------------------------------------------
/**
    Драйвер
*/
class IObjectDriver : public IAbstractInputDriver
{
    Q_OBJECT;

public:
    virtual MovementDirection nearesPointToFlag()const = 0;

    virtual PtrPObject& pObject() = 0;

    /**
        Устанавливает скорость как процент от максимальной.
        Значения - от 0 до 100
    */
    virtual void setSpeed( const int persent ) = 0;

    /**
        Устанавливает текущий поворот объекта
    */
    virtual void setRotation( const ObjectRotation& rotation ) = 0;
   
    /**
        Выпускает снаряд
    */
    virtual void makeAttack() = 0;

signals:
    /**
        Сигнал приема сообщений.
    */
    void message( GroupObjectMessage* mesage );
};

//-------------------------------------------------------

#endif //__IOBJECT_DRIVERS

//-------------------------------------------------------
