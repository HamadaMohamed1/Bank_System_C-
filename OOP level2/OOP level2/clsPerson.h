#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsPerson
{
private:
    string _first_name;
    string _last_name;
    string _phone;
    string _email;
public:
    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {
        _first_name = FirstName;
        _last_name = LastName;
        _email = Email;
        _phone = Phone;
    }
   
    void SetFirstName(string FirstName)
    {
        _first_name = FirstName;
    }
    string GetFirstName()
    {
        return _first_name;
    }
    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

    void SetLastName(string LastName)
    {
        _last_name = LastName;
    }
    string GetLasttName()
    {
        return _last_name;
    }
    __declspec(property(get = GetLasttName, put = SetLastName)) string LastName;

    void SetEmail(string Email)
    {
        _email = Email;
    }
    string GetEmail()
    {
        return _email;
    }
    __declspec(property(get = GetEmail, put = SetEmail)) string Email;

    void SetPhone(string Phone)
    {
        _phone = Phone;
    }
    string GetPhone()
    {
        return _phone;
    }
    __declspec(property(get = GetPhone, put = SetPhone)) string Phone;

    string GetFullName()
    {
        return (_first_name + " " + _last_name);
    }
   
   
    
};

