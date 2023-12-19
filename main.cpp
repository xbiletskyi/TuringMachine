#include "Parser.h"

using namespace std;

struct Rule{
private:
    string condition;
    State* nextState;
    string newSymbol;
    char move;
public:
    Rule(string  condition, State*  nextState, string  newSymbol, const char& move)
    : condition(std::move(condition)), nextState(nextState), newSymbol(std::move(newSymbol)), move(move) {}
};

struct State{
public:
    string name;
    unordered_map<string, Rule*> rules;

    explicit State(const string& name){
        this->name = name;
        this->rules = unordered_map<string, Rule*>();
    }
    void addRule(const string&  condition, State* nextState, const string&  newSymbol, char  move){
        Rule* newRule = new Rule(condition, nextState, newSymbol, move);
        rules[condition] = newRule;
    }
};

struct TapeElement{
public:
    string data;
    TapeElement* next;
    TapeElement* prev;

    explicit TapeElement(const string& data){
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
    TapeElement* moveNext(){
        if(next){
            return next;
        }
        else{
            auto* newElement = new TapeElement("");
            newElement->prev = this;
            next = newElement;
            return newElement;
        }
    }

    TapeElement* movePrev(){
        if(prev){
            return prev;
        }
        else{
            auto* newElement = new TapeElement("");
            newElement->next = this;
            prev = newElement;
            return newElement;
        }
    }
    TapeElement* changeNext(const string& newName){
        if (next){
            next->data = newName;
            return next;
        }
        else{
            auto* newElement = new TapeElement(newName);
            newElement->prev = this;
            next = newElement;
            return newElement;
        }
    }

    TapeElement* changePrev(const string& newName){
        if (prev){
            prev->data = newName;
            return prev;
        }
        else{
            auto* newElement = new TapeElement(newName);
            newElement->next = this;
            prev = newElement;
            return newElement;
        }
    }
};

struct TuringMachine{
private:
    TapeElement* currentSymbol;
    State* currentState;

public:
    void configureSimulator(const list<string>& commands){

        auto it = commands.begin();
        while(it != commands.end()){
            it++;
            string line = *it;
            
        }
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
