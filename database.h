﻿//
// Created by danil on 04.05.2022.
//

#ifndef KURSAH_DATABASE_H
#define KURSAH_DATABASE_H

#include <string>
#include <vector>
#include <iostream>
#include <forward_list>

using std::endl;
using std::cout;
using std::vector;
using std::string;
using std::forward_list;

class DataBase{
public:
    virtual void insert(string*) = 0;
    virtual void remove(string) = 0;
    virtual vector<string*> find(string, string) const = 0;
    virtual void update(string) = 0;
    virtual void drop() = 0;
    virtual ~DataBase() = default;
};

class DataBaseList: public DataBase{
private:
    forward_list<string*> list;
    int count_columns, id, count_str;
    string* name_columns;
public:
    DataBaseList(int count);

    int getCountColumns()const{
        return this->count_columns+1;
    }

    void setNameColumns(string* f){
        this->name_columns = new string[count_columns+1];
        this->name_columns[0] = "id";
        for (int i = 1; i < count_columns+1;i++)
            this->name_columns[i] = f[i-1];
    }

    void insert(string*)override;

    void remove(string)override;

    void show(){
        for (int i =0; i < this->count_columns + 1; i++)
            cout << this->name_columns[i] << " | ";

        cout << endl;

        for (auto str_ptr : this->list){
            for (int i =0; i < this->count_columns + 1; i++)
                cout << str_ptr[i] << " | ";

            cout << endl;
        }
    }

    vector<string*> find(string, string)const override;

    void update(string)override{
        return;
    }

    void drop()override;
};
#endif //KURSAH_DATABASE_H
