/**
 * Project Untitled
 */


#ifndef _SUBJECT_H
#define _SUBJECT_H

class Subject {
public: 
    
/**
 * @param Observer*
 */
virtual void attacha(void Observer*) = 0;
    
/**
 * @param Observer*
 */
virtual void detach(void Observer*) = 0;
    
virtual void notify() = 0;
    
virtual void ~Subject() = 0;
};

#endif //_SUBJECT_H