//
//  BugUnit.h
//  HelloWorldDemo
//
//  Created by syh on 15-1-9.
//
//

#ifndef __HelloWorldDemo__BugUnit__
#define __HelloWorldDemo__BugUnit__

#include "cocos2d.h"

class BugUnit : public cocos2d::Ref
{
public:
    virtual ~BugUnit();
    
    CREATE_FUNC(BugUnit);
    virtual bool init();
    
protected:
    cocos2d::EventListenerCustom* _listener;
    
    void eventCallback(cocos2d::EventCustom *event);
};

#endif /* defined(__HelloWorldDemo__BugUnit__) */
