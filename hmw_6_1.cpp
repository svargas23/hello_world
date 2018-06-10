//
//  hmw_6_1.cpp
//  Homework 6
//
//  Created by Sal vargas on 6/5/18.
//  Copyright © 2018 Sal Vargas. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person{
public:
    Person(string pname);
    void set_best_friend(Person* jp);//this is going to update the best_friend pointer and the popularity integer
    string get_name() const{
        return name;
    };
    
    string get_b_f() const{
        return best_friend->get_name();
    };
    
    void set_popularity() {
        
        popularity++;
    };

    
    void print();


private:
    string name;
    Person* best_friend;
    int popularity;
};

Person::Person(string pname){
    name = pname;
    best_friend = NULL;
    popularity = 0;
};


void Person::set_best_friend(Person* jp){
  
    best_friend = jp;
    best_friend->set_popularity();
};

void Person::print(){

    cout << get_name()<<" | "<<get_b_f()<< " | " <<popularity<<endl;
};


int main(){
    
    vector <Person*> list;
    
    bool program = true;
    while (program){
        cout << "Name: ";
        string name;
        cin >> name;
    
        //Person p(name);
        
        //Person* ip = &p;
        
        //These two lines of code are essentially equal to the line below containing 'new'
        //The line below skips over the need to actually create an object for the data
 
        Person* ip= new Person(name);

        list.push_back(ip);
        
        cout << "\nContinue (y/n)?";
        string response;
        cin>> response;
        if (response != "y") program = false;
        
        if (program == false) delete ip;
        
        cout <<endl;
    }
    
    
    //for (int i = 0; i < list.size(); i++){
    //    cout << list[i]->get_name()<< " ";
    //}
    //used this to make sure my while loop above was working properly
 
    
    cout << "Enter the names of best Friends: \n";
    for (int i = 0; i<list.size(); i++){
        cout <<"Best friend of "<<list[i]->get_name()<<": ";
        string best_friend;
        cin >> best_friend;
        
        bool condition= true;
        for (int k=0; k<list.size(); ++k) {
            
            if (best_friend== list[k]->get_name()) {
                list[i]->set_best_friend(list[k]);
                condition = false;
            }
            
        }
        if (condition == true){
            Person* jp = new Person("NONE");
            list[i]->set_best_friend(jp);
           
        if (i == list.size()-1) delete jp;
        }
    }
    
    cout << "Information: \n";
    for(int i = 0; i<list.size(); i++){
       
        list[i]->print();
        
    };
    return 0;
}

