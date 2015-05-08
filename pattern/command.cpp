#include <iostream>


class Command {
    public:
        virtual ~Command();
        virtual void execute() = 0;
};


class Jump: public Command{
    public:
        virtual void execute() {std::cout << "jump" << std::endl;};
};

class Shoot: public Command{
    public:
        virtual void execute() {std::cout << "shoot" << std::endl;};
};

class Slash: public Command{
    public:
        virtual void execute() {std::cout << "slash" << std::endl;};
};

class Walk: public Command{
    public:
        virtual void execute() {std::cout << "walk" << std::endl;};
};

class InputHandler{
    public:
        Command* handleInput(char button);
        InputHandler();
    private:
        Command * Button_X;
        Command * Button_Y;
        Command * Button_A;
        Command * Button_B;
};

InputHandler::InputHandler(){
    Button_X = new Jump();
    Button_Y = new Shoot();
    Button_A = new Slash();
    Button_B = new Walk();
}

Command* InputHandler::handleInput(char button){
    switch (button){
        case 'Y' : return Button_Y;
        case 'X' : return Button_Y;
        case 'A' : return Button_A;
        case 'B' : return Button_B;
        default  : return NULL;
    }
}

int main(){
    InputHandler myInput{};
    char button;
    while (true){
        std::cout << "Enter input:";
        std::cin >> button;
        button = std::toupper(button);
        auto button_pressed = myInput.handleInput(button);
        if (button_pressed)
            button_pressed->execute();
        else{
            std::cout << "Wrong button pressed." << std::endl;
            break;
        }
    }
}
