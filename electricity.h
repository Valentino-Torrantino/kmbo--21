#pragma once
#include<string>
#include<iostream>


using namespace std;

class Object;


struct Pole {
    string name;
    Object* connectedObject;
    string connectedObjectPole;
    Pole(const string& name_) : name(name_), connectedObject(nullptr) {}
};

class Object {
    string name;

protected:
    Object(const string& name_) : name(name_) {}

        Pole* getPole(size_t idx) {
        if (idx > getPoleCount()) {
            string str = "O" + to_string(idx);
            return getPole(str);
        }
        else {
            return nullptr;
        }
    };

    virtual const Pole* getPole(size_t idx) const = 0;

public:
    virtual ~Object() {}

    const string& getName() const { return name; }
    void getName(const string& newName) { name = newName; }

    Pole* getPole(const string& name) { return const_cast<Pole*>(const_cast<const Object*>(this)->getPole(name)); }

    virtual const Pole* getPole(const string& name) const = 0;

        virtual size_t getPoleCount() const = 0;

    bool isConnectedTo(const Object& other) const;

    bool connect(const string& poleName, Object& other, const string& otherPoleName);

    bool disconnect(const string& poleName);
};

class Switch : public Object {
public:
    Pole A1, A2;

    Switch(const string& name = "");

    virtual size_t getPoleCount() const { return 2; }

    virtual const Pole* getPole(const string& name) const;

protected:
    virtual const Pole* getPole(size_t idx) const;
};


class Power : public Object {
public:
    Pole A1, A2, A3;

    Power(const string& name = "");

    virtual size_t getPoleCount() const { return 3; }

    virtual const Pole* getPole(const string& name) const;

protected:
    virtual const Pole* getPole(size_t idx) const;
};


class Light : public Object {
public:
    Pole A1, A2;

    bool st = false;

    Light(const string& name = "");

    virtual size_t getPoleCount() const { return 2; }

    virtual const Pole* getPole(const string& name) const;

protected:
    virtual const Pole* getPole(size_t idx) const;
};

