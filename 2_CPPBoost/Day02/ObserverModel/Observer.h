/**
 * Project Untitled
 */


#ifndef _OBSERVER_H
#define _OBSERVER_H

class Observer {
public: 
    
/**
 * @param status int
 */
virtual void update(void status int) = 0;
    
virtual void ~Observer() = 0;
};

#endif //_OBSERVER_H