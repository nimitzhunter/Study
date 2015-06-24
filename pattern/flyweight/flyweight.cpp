#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>

unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 rand_gen (seed1);

class TreeCharacterisics{
    public:
        TreeCharacterisics(){
            texture = "very course";
        }
        void showchar() const {
            std::cout << texture << std::endl;
        }
    private:
        std::string texture;
        char array[10000];
};

class Generator{
    public:
        const static TreeCharacterisics * flyweight_obj;
};

const TreeCharacterisics* Generator::flyweight_obj = new TreeCharacterisics();

class Tree{
    public :
        Tree(){
            tree_char_ = Generator::flyweight_obj;
            heigh = rand_gen() % 100;
            age = rand_gen() % 20;
        }
        void printchars(){
            std::cout << "height " << heigh << " age " << age << " other chars ";
            tree_char_->showchar();
        }

    private:
        const TreeCharacterisics * tree_char_;
        int heigh;
        int age;
};

class Tree2{
    public :
        Tree2(){
            tree_char_ = TreeCharacterisics();
            heigh = rand_gen() % 100;
            age = rand_gen() % 20;
        }
        void printchars(){
            std::cout << "height " << heigh << " age " << age << " other chars ";
            tree_char_.showchar();
        }

    private:
        TreeCharacterisics  tree_char_;
        int heigh;
        int age;
};

int main(){
    std::vector<Tree> myTrees;
    std::vector<Tree2> myTrees2;

    int i;
    for (i=0; i < 1000 ; ++i){
        myTrees.push_back(Tree());
        myTrees2.push_back(Tree2());
    }

    std::cout << " The size of myTrees:" << sizeof(myTrees) << std::endl;
    std::cout << " The size of myTrees2:" << sizeof(myTrees2) << std::endl;

    //i = 0;
    //for(auto tree : myTrees){
        //++i;
        //std::cout << " tree #" << i;
        //tree.printchars();
    //}
}
