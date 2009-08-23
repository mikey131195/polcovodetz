﻿

#ifndef  __IGROUP_CONTROLLER
#define  __IGROUP_CONTROLLER

//-------------------------------------------------------

#include <IAbstractController.h>
#include <Messages.h>

//-------------------------------------------------------

class IGroupInputDriver;
class IGroupOutputDriver;

//-------------------------------------------------------
/**
  Интерфейс для "командующего группой объектов".
  Предполагаемые цели и задачи: принимать сообщения от 
  "главнокоммандующего" ( ICommandController ) и подчиненных ( IObjectController ).

  Предполагается, что он должен решать, как направлять подчиненные объекты. 

  Гарантируется: класс работает асинхронно с ядром и с объектами других комманд.
  Приоритет потока не выше приоритета ядра.

  ToDo: сделать многопоточным.
  ToDo: определить таймаут инициализации.
*/
class IGroupController : public IAbstractController
{
    Q_OBJECT;

public:
    
    /**Инициализация. Запускается ядром ДО начала игры.
       Из-за асинхронности класс может опаздать к началу игры, т. к. 
       долго конфигурировался.
    */
    virtual bool    init( IGroupInputDriver*, IGroupOutputDriver* ) = 0;

signals:
    void sendTopMessage( GroupCommandMessage* );
    void sendDownMessage( GroupObjectMessage* );
};

//-------------------------------------------------------

#endif //__IGROUP_CONTROLLER

//-------------------------------------------------------

