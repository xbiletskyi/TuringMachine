#include <utility>

#include "Parser.h"

using namespace std;

struct Rule{
private:
    string condition;
    shared_ptr<State> nextState;
    string newSymbol;
    char move;
public:
    Rule(string  condition, shared_ptr<State> nextState, string  newSymbol, const char& move)
    : condition(std::move(condition)), nextState(std::move(nextState)), newSymbol(std::move(newSymbol)), move(move) {}
};

struct State{
public:
    unordered_map<string, Rule*> rules;

    explicit State(){
        this->rules = unordered_map<string, Rule*>();
    }
    void addRule(const string&  condition, shared_ptr<State> nextState, const string&  newSymbol, char  move){
        Rule* newRule = new Rule(condition, std::move(nextState), newSymbol, move);
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
    static void simStudioInterpreter(const string& text, const list<string>& tape){
        list<string> commands;
        unordered_map<string, vector<string>> arrays;
        int index = 0;

    }

    void configureSimulator(const list<string>& commands, const list<string>& tape){
        unordered_map<string, vector<string>> arrays;
        unordered_map<string, shared_ptr<State>> states;
        int index = 0, endLine;
        auto it = commands.begin();
        while(it != commands.end()){
            it++;
            string line = *it;
            if (line[0] == 'f'){ // format "f:stateName:condition:newStateName:newSymbol" where ':' is a Unit Separator symbol
                int nameIndex = 2;
                string stateName, condition, newStateName, newSymbol;
                stateName = parseName(line, nameIndex);
                condition = parseName(line, nameIndex);
                newStateName = parseName(line, nameIndex);
                newSymbol = parseName(line, nameIndex);
                if (states.find(stateName) == states.end()){
                    states[stateName] = make_shared<State>();
                }
                if (states.find(newStateName) == states.end()){
                    states[newStateName] = make_shared<State>();
                }
                shared_ptr<State> state = states[stateName];
                shared_ptr<State> newState = states[newStateName];
                if (arrays.find(condition) != arrays.end()){
                    vector<string> conditions = arrays[condition];
                    for (const auto& cond : conditions){

                    }
                }
            }
        }
    }
private:
    struct TuringCode{
        list<string> commands;
        list<string> arrays;
    };
    static list<string> formatText(string& text){
        unique_ptr<TuringCode> code = make_unique<TuringCode>();
        string currentLine;
        int index = 0;
        while (index + 1 < text.size()){
            if (text[index] != ' '){
                if (text[index] == 'f'){
                    currentLine += 'f';
                    
                }
            }
            index++;
        }
    }

    static void skipSpaces(string& text, int& index){
        while(text[index] == ' ' && index + 1 < text.size()){
            index++;
        }
    }
    static string parseName(const string& line, int& index){
        string name;
        char delimiter = UNIT_SEPARATOR;
        while(line[index] != delimiter || line.size() > index + 1){
            name.push_back(line[index]);
            index++;
        }
        return name;
    }

};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
