//
//  BugUnit.cpp
//  HelloWorldDemo
//
//  Created by syh on 15-1-9.
//
//

#include "BugUnit.h"
BugUnit::~BugUnit()
{
    if (_listener != nullptr)
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(_listener);
        CC_SAFE_RELEASE_NULL(_listener);
    }
}

bool BugUnit::init()
{
    do
    {
        
        _listener = cocos2d::EventListenerCustom::create("remove_child", CC_CALLBACK_1(BugUnit::eventCallback, this));
        CC_BREAK_IF(_listener == nullptr);
        _listener->retain();
        
        cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(_listener, 1);
        
        return true;
    }while (0);
    
    return false;
}

void BugUnit::eventCallback(cocos2d::EventCustom *event)
{
    if (event->getEventName() == "remove_child")
    {
        if (_listener != nullptr)
        {
            cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(_listener);
            CC_SAFE_RELEASE_NULL(_listener);
        }
        
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("remove_child");
    }
}