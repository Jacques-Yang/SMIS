#include"Student.h"
#include"StudentList.h"
#include<cstring>
#include<iostream>
using namespace std;

string coursename[5] = {"���ݽṹ","Java","C++","�������","����"};

//���ι��캯��
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

//�޲ι��캯��
Student::Student()
{
    AddStu();
}

//��������
Student::~Student()
{
}

//��ʾѧ����Ϣ����
void Student::Display(int method)
{   
    switch (method)
    {
    case 0:
        cout<<number<<"\t"<<name<<"\t"<<(sex > 0 ? " ��" : " Ů")<<"\t"<<" "<<age<<"\t"<<tel<<"\t";
        for(int i = 0 ; i < 5 ; i++)
        {
            cout<<score[i]<<"\t";
            if(i == 0 || i == 3) cout<<"\t";
        }
        cout<<score_sum<<"\t"<<average_score<<endl;
        break;
    case 1:
        cout<<"------------------------|��Ϊ��鵽ѧ��Ϊ "<<number<<" ��ѧ���������Ϣ|-----------------------"<<endl<<endl;
        cout<<"---------|������Ϣ|--------"<<endl;
        cout<<"|"<<endl;
        cout<<"| ѧ    �� ��"<<number<<endl;
        cout<<"| ��    �� ��"<<name<<endl;
        cout<<"| ��    �� ��"<<(sex > 0 ? "��" : "Ů")<<endl;
        cout<<"| ��    �� ��"<<age<<endl;
        cout<<"| �绰���� ��"<<tel<<endl;
        cout<<"|"<<endl;
        cout<<"---------|�γ̳ɼ�|--------"<<endl;
        cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl<<"|";
        for(int i = 0 ; i < 5 ; i++)
        {
            cout<<coursename[i]<<"��"<<score[i]<<"  "<<"|";
        }
        cout<<"�ܷ֣�"<<score_sum<<"  "<<"|"<<"ƽ���ɼ���"<<average_score<<endl;
        cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"<<endl;
        break;
    default:
        cout<<"Student::Display Error!"<<endl;
        break;
    }   
}

//���ѧ����Ϣ����
void Student::AddStu()
{
    cout<<"������ѧ����Ϣ"<<endl;
    cout<<"ѧ�ţ�"; cin>>number;
    cout<<"������"; cin>>name;
    cout<<"�Ա�(1Ϊ�У�0ΪŮ)��"; cin>>sex;
    cout<<"���䣺"; cin>>age;
    cout<<"�绰���룺"; cin>>tel;
    for(int i = 0 ; i < 5 ; i++)
    {
        cout<<coursename[i]<<"��";
        cin>>score[i];
        score_sum += score[i];
    }
    average_score = score_sum / 5.0 ;
}


//����ѧ��ѧ�ź���
    void Student::setNumber(char m_number[])
    {
        strcpy(number , m_number);
    }

//����ѧ����������
    void Student::setName(char m_name[])
    {
        strcpy(name , m_name);
    }

//����ѧ���Ա���
    void Student::setSex(int m_sex)
    {
        sex = m_sex;
    }

//����ѧ�����亯��
    void Student::setAge(int m_age)
    {
        age = m_age;
    }

//����ѧ���绰���뺯��
    void Student::setTel(char m_tel[])
    {
        strcpy(tel , m_tel);
    }

//����ѧ���γ̳ɼ�����
    void Student::setScore(int m_score[])
    {
        for(int i = 0 ; i < 5 ; i++)
        {
            score[i] = m_score[i];
        }
    }