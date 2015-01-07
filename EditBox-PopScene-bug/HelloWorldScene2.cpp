#include "HelloWorldScene2.h"

USING_NS_CC;

Scene* HelloWorld2::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld2::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld2::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld2::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World2", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    auto editBoxSize = Size(visibleSize.width - 100, 60);
    std::string pNormalSprite = "green_edit.png";
    _editName = ui::EditBox::create(editBoxSize, ui::Scale9Sprite::create(pNormalSprite));
    _editName->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height*3/4));
    _editName->setFontName("Paint Boy");
    _editName->setFontSize(25);
    _editName->setFontColor(Color3B::RED);
    _editName->setPlaceHolder("Name:");
    _editName->setPlaceholderFontColor(Color3B::WHITE);
    _editName->setMaxLength(8);
    _editName->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
    _editName->setDelegate(this);
    addChild(_editName);
    
    return true;
}

void HelloWorld2::editBoxEditingDidBegin(cocos2d::ui::EditBox* editBox)
{
    log("editBox %p DidBegin !", editBox);
}

void HelloWorld2::editBoxEditingDidEnd(cocos2d::ui::EditBox* editBox)
{
    log("editBox %p DidEnd !", editBox);
}

void HelloWorld2::editBoxTextChanged(cocos2d::ui::EditBox* editBox, const std::string& text)
{
    log("editBox %p TextChanged, text: %s ", editBox, text.c_str());
}

void HelloWorld2::editBoxReturn(ui::EditBox* editBox)
{
    log("editBox %p was returned !",editBox);
}


void HelloWorld2::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->popScene();
}
