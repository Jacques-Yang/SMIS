#include"Student.h"
#include"StudentList.h"
#include<cstring>
#include<iostream>
using namespace std;

string coursename[5] = {"数据结构","Java","C++","软件工程","体育"};

//带参构造函数
Student::Student( char new_number[] , char new_name[] , int new_sex , int new_age , char new_tel[] , int new_score[5])
{
    strcpy(number , new_number);
    strcpy(name , new_name);
    sex = new_sex ;
    age = new_age;
    strcpy(tel , new_tel);
    for(int i = 0 ; i < 5 ; i++)
    {
        score[i] = new_score[i];
        score_sum += score[i]; 
    }
    average_score = score_sum / 5.0 ;
}

//无参构造函数
Student::Student()
{
    AddStu();
}

//析构函数
Student::~Student()
{
}

//显示学生信息函数
void Student::Display(int method)
{   
    switch (method)
    {
    case 0:
        cout<<number<<"\t"<<name<<"\t"<<(sex > 0 ? " 男" : " 女")<<"\t"<<" "<<age<<"\t"<<tel<<"\t";
        for(int i = 0 ; i < 5 ; i++)
        {
            cout<<score[i]<<"\t";
            if(i == 0 || i == 3) cout<<"\t";
        }
        cout<<score_sum<<"\t"<<average_score<<endl;
        break;
    case 1:
        cout<<"------------------------|已为你查到学号为 "<<number<<" 的学生的相关信息|-----------------------"<<endl<<endl;
        cout<<"---------|基本信息|--------"<<endl;
        cout<<"|"<<endl;
        cout<<"| 学    号 ："<<number<<endl;
        cout<<"| 姓    名 ："<<name<<endl;
        cout<<"| 性    别 ："<<(sex > 0 ? "男" : "女")<<endl;
        cout<<"| 年    龄 ："<<age<<endl;
        cout<<"| 电话号码 ："<<tel<<endl;
        cout<<"|"<<endl;
        cout<<"---------|课程成绩|--------"<<endl;
        cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl<<"|";
        for(int i = 0 ; i < 5 ; i++)
        {
            cout<<coursename[i]<<"："<<score[i]<<"  "<<"|";
        }
        cout<<"总分："<<score_sum<<"  "<<"|"<<"平均成绩："<<average_score<<endl;
        cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"<<endl;
        break;
    default:
        cout<<"Student::Display Error!"<<endl;
        break;
    }   
}

//添加学生信息函数
void Student::AddStu()
{
    cout<<"请输入学生信息"<<endl;
    cout<<"学号："; cin>>number;
    cout<<"姓名："; cin>>name;
    cout<<"性别(1为男，0为女)："; cin>>sex;
    cout<<"年龄："; cin>>age;
    cout<<"电话号码："; cin>>tel;
    for(int i = 0 ; i < 5 ; i++)
    {
        cout<<coursename[i]<<"：";
        cin>>score[i];
        score_sum += score[i];
    }
    average_score = score_sum / 5.0 ;
}


//设置学生学号函数
    void Student::setNumber(char m_number[])
    {
        strcpy(number , m_number);
    }

//设置学生姓名函数
    void Student::setName(char m_name[])
    {
        strcpy(name , m_name);
    }

//设置学生性别函数
    void Student::setSex(int m_sex)
    {
        sex = m_sex;
    }

//设置学生年龄函数
    void Student::setAge(int m_age)
    {
        age = m_age;
    }

//设置学生电话号码函数
    void Student::setTel(char m_tel[])
    {
        strcpy(tel , m_tel);
    }

//设置学生课程成绩函数
    void Student::setScore(int m_score[])
    {
        for(int i = 0 ; i < 5 ; i++)
        {
            score[i] = m_score[i];
        }
    }