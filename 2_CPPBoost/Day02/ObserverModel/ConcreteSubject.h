/**
 * Project Untitled
 */


#ifndef _CONCRETESUBJECT_H
#define _CONCRETESUBJECT_H

#include "Subject.h"


class ConcreteSubject: public Subject {
public: 
    
/**
 * @param Observer*
 */
void attach(void Observer*);
    
/**
 * @param Observer*
 */
void detach(void Observer*);
    
void notify();
    
/**
 * @param int
 */
void setStatus(void int);
    
int getStatus();
private: 
    void _oblist:list<Observer*>;
    void _status:int;
};

#endif //_CONCRETESUBJECT_H