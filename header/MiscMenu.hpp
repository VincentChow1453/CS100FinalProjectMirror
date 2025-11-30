#pragma once
class MiscMenu{
    protected:
        virtual void displayMenu() const=0;//helper class for startMenu
        virtual void chooseOption(const int option)=0;//helper class for startMenu
    public:
        virtual void startMenu()=0;
};