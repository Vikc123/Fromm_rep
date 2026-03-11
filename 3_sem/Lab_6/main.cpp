#include <iostream>
#include <list>
#include <string>

class Admin;
class Trainer;
class Client;
class Session;
class Person;
class Schedule;

class Schedule {
private:
    std::list<Session*> sessions;
public:
    Schedule();
    void addSession(Session* session) {
        sessions.push_back(session);
    };
    void removeSession(Session* session) {
        sessions.remove(session);
    }
    void showSessions() {
        for (auto it = sessions.begin(); it != sessions.end(); it++) {
            std::cout << *it << std::endl;
        }
    }
};

class GYM {
private:
    Schedule* schedule;
public:
    GYM() {
        this->schedule = Schedule();
    }
};

class Person {
private:
    std::string name;
    std::string id;
    int rep = 0;
public:
    void setName(std::string name) { this->name = name; }
    void setId(std::string id) { this->id = id; }
    std::string getName() { return this->name; }
    std::string getId() { return this->id; }
    int getRep() { return this->rep; }
    void display() {
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Id: " << this->id << std::endl;
        std::cout << "Rep: " << this->rep << std::endl;
    }
    virtual void set_mark() = 0;
    virtual void speak() = 0;
    virtual ~Person() {}
};

class Admin : public Person {
    public:
    void speak() override {
        std::cout << "Admin speak" << std::endl;
    };
    void set_mark() override {
        this->set_mark();
    }
};
class Trainer : public Person {
    public:
    void speak() override {
        std::cout << "Trainer speak" << std::endl;
    }
    void set_mark() override {
        this->set_mark();
    }
};
class Client : public Person {
    public:
    void speak() override {
        std::cout << "Client speak" << std::endl;
    }
    void set_mark() override {
        this->set_mark();
    }
};


class Session {
private:
    std::string data = "";
    Admin admin;
    Trainer trainer;
    std::list<Client> clients;
    int rep = 0;
public:

};

Schedule::Schedule() {
    Schedule schedule;
    Session* session = new Session;
    schedule.addSession(session);
    std::cout << "вызван конструктор расписания" << std::endl;
}


int main() {
    GYM gym();
    return 0;
}
