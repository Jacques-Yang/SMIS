#include<iostream>
#include<cstring>
#include"StudentList.h"
#include<fstream>
#include<stdio.h>
using namespace std;

//�޲ι��캯��
StudentList::StudentList()
{
    //����һ��ͷ���
    int head_score[5] = {0,0,0,0,0};
    char head_num[20] = "Head"; char head_name[20] = "Head"; char head_tel[20] = "Head";
    head = new Student(head_num,head_name,true,0,head_tel,head_score);
    head->next = NULL;
}

//��������
StudentList::~StudentList() {}

//���ѧ����㺯��
void StudentList::AddStud()
{
    Student * addstu = new Student , * find; bool add_flag = true; string add_again;
    if(head->next == NULL) 
    {
        addstu->next = head->next; head->next = addstu;
        cout<<"�ѳɹ����ѧ��Ϊ "<<addstu->number<<" ��ѧ����Ϣ��"<<endl;
    }
    else
    {
        while(head->next != NULL)
        {
            for(find = head->next ; find != NULL ; find = find->next)
            {
                if(strcmp(find->number , addstu->number)==0)
                {
                    add_flag = false;
                    cout<<"��ѧ����ѧ�� "<<addstu->number<<" ��Ψһ���Ƿ����������ѧ������Ϣ��(Y/N)��"; cin>>add_again;
                    while(add_again != "Y" && add_again != "y" && add_again != "N" && add_again != "n")
                    {cout<<"������������Ƿ����������ѧ������Ϣ��(Y/N)��"; cin>>add_again;}
                    if(add_again == "Y" || add_again == "y") 
                    {
                        delete addstu; addstu = NULL;
                        cout<<"�õģ������������ѧ������Ϣ"<<endl;
                        addstu = new Student; add_flag = true; find = head;    
                    }
                    if(add_again == "N" || add_again == "n") {delete addstu; addstu = NULL; break;}        
                }
            }
            for(find = head->next ; find != NULL ; find = find->next)
            {
                if(strcmp(find->tel , addstu->tel)==0)
                {
                    add_flag = false;
                    cout<<"��ѧ���ĵ绰���� "<<addstu->tel<<" ��Ψһ���Ƿ����������ѧ������Ϣ��(Y/N)��"; cin>>add_again;
                    while(add_again != "Y" && add_again != "y" && add_again != "N" && add_again != "n")
                    {cout<<"������������Ƿ����������ѧ������Ϣ��(Y/N)��"; cin>>add_again;}
                    if(add_again == "Y" || add_again == "y") 
                    {
                        delete addstu; addstu = NULL;
                        cout<<"�õģ������������ѧ������Ϣ"<<endl;
                        addstu = new Student; add_flag = true; find = head;
                    }
                    if(add_again == "N" || add_again == "n") {delete addstu; addstu = NULL; break;}        
                }
            }
            if(add_flag == true)
            {
                addstu->next = head->next;
                head->next = addstu;
                cout<<"�ѳɹ����ѧ��Ϊ "<<addstu->number<<" ��ѧ����Ϣ��"<<endl;
                cout<<"�����Ƿ�������ѧ����Ϣ��(Y/N)��"<<endl; cin>>add_again;
                while(add_again != "Y" && add_again != "y" && add_again != "N" && add_again != "n")
                {cout<<"�����������������(Y/N)��"; cin>>add_again;}
                if(add_again == "Y" || add_again == "y")
                {addstu = new Student;}
                if(add_again == "N" || add_again == "n") {cout<<"���˳�..."<<endl; break;}
            }
            else {cout<<"���ѷ������ѧ����Ϣ��"<<endl;break;} 
        }
    }
}

//�ܷ�������
void StudentList::ScoreSumSort()
{
    Student * sort_p = head->next; Student * r = head->next;
    cout<<"ѧ��"<<"\t\t"<<"����"<<"\t"<<"�Ա�"<<"\t"<<"����"<<"\t"<<"�绰����"<<"\t"<<"���ݽṹ"<<"\t"<<"Java"<<"\t"<<"C++"<<"\t"<<"�������"<<"\t"<<"����"<<"\t"<<"�ܷ�"<<"\t"<<"ƽ���ɼ�"<<endl;
    if(sort_p != NULL)
    {
        if(sort_p->next != NULL)
        {
            for(int i = 1 ; i < StuLength() ; i++)
            {   
                bool len_flag = true ;
                for(sort_p ; sort_p->next != NULL ; sort_p = sort_p->next)
                {
                    if(sort_p->score_sum > sort_p->next->score_sum)
                    {
                        strcpy(head->number , sort_p->number) ; strcpy(head->name , sort_p->name) ;
                        head->sex = sort_p->sex ; head->age = sort_p->age ; strcpy(head->tel , sort_p->tel) ;
                        for(int k = 0 ; k < 5 ; k++) {head->score[k] = sort_p->score[k];}
                        head->score_sum = sort_p->score_sum ; head->average_score = sort_p->average_score ;
                            
                        strcpy(sort_p->number , sort_p->next->number) ; strcpy(sort_p->name , sort_p->next->name) ;
                        sort_p->sex = sort_p->next->sex ; sort_p->age = sort_p->next->age ; strcpy(sort_p->tel , sort_p->next->tel) ;
                        for(int m = 0 ; m < 5 ; m++) {sort_p->score[m] = sort_p->next->score[m];}
                        sort_p->score_sum = sort_p->next->score_sum ; sort_p->average_score = sort_p->next->average_score ; 
                        
                        strcpy(sort_p->next->number , head->number) ; strcpy(sort_p->next->name , head->name) ;
                        sort_p->next->sex = head->sex ; sort_p->next->age = head->age ; strcpy(sort_p->next->tel , head->tel) ;
                        for(int n = 0 ; n < 5 ; n++) {sort_p->next->score[n] = head->score[n];}
                        sort_p->next->score_sum = head->score_sum ; sort_p->next->average_score = head->average_score ;
                        len_flag = false ;
                    }
                }
                sort_p = head->next;
                if(len_flag == true) {break;}
            }
            while(r != NULL) {r->Display(0); r = r->next;}
        }
        else {sort_p->Display(0);}
    }
    else {cout<<"��ǰϵͳ��û��ѧ����Ϣ..."<<endl;}    
}

//��ʾ���Ƴɼ���߷�ѧ����Ϣ����
void StudentList::SingleScoreSearch(int score_num)
{
    Student * sort_p = head->next; Student * r = head->next;
    if(sort_p != NULL)
    {
        if(sort_p->next != NULL)
        {
            for(int i = 1 ; i < StuLength() ; i++)
            {   
                bool len_flag = true ;
                for(sort_p ; sort_p->next != NULL ; sort_p = sort_p->next)
                {
                    if(sort_p->score[score_num] > sort_p->next->score[score_num])    
                    {
                        strcpy(head->number , sort_p->number) ; strcpy(head->name , sort_p->name) ;
                        head->sex = sort_p->sex ; head->age = sort_p->age ; strcpy(head->tel , sort_p->tel) ;
                        for(int k = 0 ; k < 5 ; k++) {head->score[k] = sort_p->score[k];}
                        head->score_sum = sort_p->score_sum ; head->average_score = sort_p->average_score ;
                
                        strcpy(sort_p->number , sort_p->next->number) ; strcpy(sort_p->name , sort_p->next->name) ;
                        sort_p->sex = sort_p->next->sex ; sort_p->age = sort_p->next->age ; strcpy(sort_p->tel , sort_p->next->tel) ;
                        for(int m = 0 ; m < 5 ; m++) {sort_p->score[m] = sort_p->next->score[m];}
                        sort_p->score_sum = sort_p->next->score_sum ; sort_p->average_score = sort_p->next->average_score ;
                        
                        strcpy(sort_p->next->number , head->number) ; strcpy(sort_p->next->name , head->name) ;
                        sort_p->next->sex = head->sex ; sort_p->next->age = head->age ; strcpy(sort_p->next->tel , head->tel) ;
                        for(int n = 0 ; n < 5 ; n++) {sort_p->next->score[n] = head->score[n];}
                        sort_p->next->score_sum = head->score_sum ; sort_p->next->average_score = head->average_score ;
                                
                        len_flag = false ;
                    }
                }
                sort_p = head->next; if(len_flag == true) {break;}
            }
            int num = 0;
            for(r ; r != NULL ; r = r->next)
            {
                if(r->next == NULL)
                {
                    for(Student * p = head->next ; p != NULL ; p = p->next)
                    {if(p->score[score_num] == r->score[score_num]) {p->Display(1); num ++;}}
                }
            }
            cout<<"---------------------------------------|Ϊ �� �� �� "<<num<<" �� �� �� �� �� �� ѧ ��|-----------------------------------------"<<endl;
        }
        else {sort_p->Display(0);}
    }
}

//���Ƴɼ�������
void StudentList::SingleScoreSort(int score_num)
{
    Student * sort_p = head->next; Student * r = head->next;
    cout<<"ѧ��"<<"\t\t"<<"����"<<"\t"<<"�Ա�"<<"\t"<<"����"<<"\t"<<"�绰����"<<"\t"<<"���ݽṹ"<<"\t"<<"Java"<<"\t"<<"C++"<<"\t"<<"�������"<<"\t"<<"����"<<"\t"<<"�ܷ�"<<"\t"<<"ƽ���ɼ�"<<endl;
    if(sort_p != NULL)
    {
        if(sort_p->next != NULL)
        {
            for(int i = 1 ; i < StuLength() ; i++)
            {   
                bool len_flag = true ;
                for(sort_p ; sort_p->next != NULL ; sort_p = sort_p->next)
                {
                    if(sort_p->score[score_num] > sort_p->next->score[score_num])    
                    {
                        strcpy(head->number , sort_p->number) ; strcpy(head->name , sort_p->name) ;
                        head->sex = sort_p->sex ; head->age = sort_p->age ; strcpy(head->tel , sort_p->tel) ;
                        for(int k = 0 ; k < 5 ; k++) {head->score[k] = sort_p->score[k];}
                        head->score_sum = sort_p->score_sum ; head->average_score = sort_p->average_score ;
                
                        strcpy(sort_p->number , sort_p->next->number) ; strcpy(sort_p->name , sort_p->next->name) ;
                        sort_p->sex = sort_p->next->sex ; sort_p->age = sort_p->next->age ; strcpy(sort_p->tel , sort_p->next->tel) ;
                        for(int m = 0 ; m < 5 ; m++) {sort_p->score[m] = sort_p->next->score[m];}
                        sort_p->score_sum = sort_p->next->score_sum ; sort_p->average_score = sort_p->next->average_score ;
                        
                        strcpy(sort_p->next->number , head->number) ; strcpy(sort_p->next->name , head->name) ;
                        sort_p->next->sex = head->sex ; sort_p->next->age = head->age ; strcpy(sort_p->next->tel , head->tel) ;
                        for(int n = 0 ; n < 5 ; n++) {sort_p->next->score[n] = head->score[n];}
                        sort_p->next->score_sum = head->score_sum ; sort_p->next->average_score = head->average_score ;
                                
                        len_flag = false ;
                    }
                }
                sort_p = head->next;
                if(len_flag == true) {break;}
            }
            while(r != NULL) {r->Display(0); r = r->next;}
        }
    }
    else {cout<<"��ǰϵͳ��û��ѧ����Ϣ..."<<endl;} 
}

//��ʾѧ��������Ϣ����
void StudentList::DisplayNum()
{
    int stunum = 0; int boynum = 0; int girlnum = 0; int sexflag;
    Student * t = head->next;
    while(t != NULL)
    {
        sexflag = t->sex; stunum ++ ;
        if(sexflag > 0) {boynum ++ ; }
        if(sexflag <= 0){girlnum ++ ;}
        t = t->next;
    }
    cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<"||ѧ����������"<<stunum<<"��"<<" "<<"||"<<"������������"<<boynum<<"��"<<" "<<"||"<<"Ů����������"<<girlnum<<"��"<<endl;
}

//���������Ⱥ���
int StudentList::StuLength()
{
    int sum = 0;
    if(head->next == NULL) {return 0;}
    else
    {
        for(Student * len_p = head->next ; len_p != NULL ; len_p = len_p->next) {sum ++;}
        return sum;
    }  
}

//����ѧ����Ϣ����ָ�뺯��
Student * StudentList::SearchStu(char number[])
{
    bool flag = false;  
    Student * p = head->next;  
    while(p!=NULL)
    {
        if(strcmp(p->number , number)==0) {flag = true; break;}  
        p = p->next;
    }
    if(flag == false) {return NULL;}
    else {return p;}  
}

//�޸�������ѧ�������Ϣ����
void StudentList::ModifyStu(Student * m_p)
{
    if(m_p != NULL)
    {
        char m_number[20];  char m_name[20];  int m_sex;                  
        int m_age;  char m_tel[20];  string flag;
        
        cout<<"������ѧ����Ϣ"<<endl;
        cout<<"ѧ�ţ�"; cin>>m_number;
        cout<<"������"; cin>>m_name;
        cout<<"�Ա�(1Ϊ�У�0ΪŮ)��"; cin>>m_sex; 
        cout<<"���䣺"; cin>>m_age;
        cout<<"�绰���룺"; cin>>m_tel;

        while(1)
        {
            for(Student * s = head->next ; s != NULL ; s = s->next)
            {
                if(strcmp(s->number , m_number)==0)
                {
                    if(s != m_p)
                    {
                        cout<<"��ѧ���޸ĺ��ѧ�Ų�Ψһ���������޸ĸ�ѧ����ѧ��"<<endl;
                        cout<<"ѧ�ţ�"; cin>>m_number; s = head;    
                    }   
                }
            }
            for(Student * s = head->next ; s != NULL ; s = s->next)
            {
                if(strcmp(s->tel , m_tel)==0)
                {
                    if(s != m_p)
                    {
                        cout<<"��ѧ���޸ĺ�ĵ绰���벻Ψһ���������޸ĸ�ѧ���ĵ绰����"<<endl;
                        cout<<"�绰���룺"; cin>>m_tel;
                        s = head;
                    }    
                }
            }
            break;
        }
        cout<<"ȷ��Ҫ�����޸���(Y/N)��";cin>>flag;
        while(flag != "Y" && flag != "y" && flag != "N" && flag != "n")
        {
            cout<<"���벻��ȷ������������(Y/N)��";
            cin>>flag;
        }
        if(flag=="Y" || flag=="y")
        {
            char temp[20];
            strcpy(temp , m_p->number);
            m_p->setNumber(m_number);
            m_p->setName(m_name);
            m_p->setSex(m_sex);
            m_p->setAge(m_age);
            m_p->setTel(m_tel);
            cout<<"�Ѿ��ɹ��޸�ѧ��Ϊ "<<temp<<" ��ѧ���Ļ�����Ϣ������"<<endl;
        }
        if(flag=="N" || flag=="n")
        {
            cout<<"δ�����κ��޸�..."<<endl;
        }
    }
    else {cout<<"----------------------------------------------|�޸�ʧ�ܣ�����";}
}

//ɾ��������ѧ����㺯��
void StudentList::DeleteStu(Student * del_p)
{
    if(del_p == NULL) {cout<<"----------------------------------------------|ɾ��ʧ�ܣ�����";}
    if(del_p != NULL)
    {
        bool flag = false;
        for(Student * del_s = head ; del_s != NULL ; del_s = del_s->next)
        {
            if(del_s->next == del_p)
            {
                del_s->next = del_p->next;
                cout<<"�Ѿ��ɹ�ɾ��ѧ��Ϊ "<<del_p->number<<" ��ѧ������Ϣ������"<<endl;
                delete del_p; del_p == NULL;
                flag = true;
                break;
            }
        }
    }   
}

//��������ѧ��������Ϣ���ļ�����
void StudentList::SavaStu(const char FileName[])
{
    FILE * w ;
    w = fopen(FileName , "w");

    char number[20];
    char name[20];
    int sex;           //trueΪ"��"��falseΪ"Ů"
    int age;
    char tel[20];
    int score[5];

    Student * p = head->next;
    if(p == NULL) {cout<<"����ʧ�ܣ���ϵͳ��û��ѧ����Ϣ..."<<endl;}
    while(p != NULL)
    {
        int score_sum = 0; float average_score = 0;
        strcpy(number , p->number);
        strcpy(name , p->name);
        sex = p->sex;
        age = p->age;
        strcpy(tel , p->tel);
        for(int i = 0 ; i < 5 ; i++)
        {
            score[i] = p->score[i];
            score_sum += score[i];
        }
        average_score = score_sum / 5.0 ;
        fprintf(w , "%s %s %d %d %s %d %d %d %d %d %d %f\n" , number,name,sex,age,tel,score[0],score[1],score[2],score[3],score[4],score_sum,average_score);
        p = p->next;
        if(p == NULL) {cout<<"�ѳɹ���ѧ����Ϣ���浽�ļ�"<<FileName<<"�У�"<<endl;}
    }
    fclose(w);
}

//�������ļ���ȡѧ��������Ϣ����
void StudentList::ReadStu(const char FileName[])
{
    char number[20];
    char name[20];
    int sex;           //trueΪ"��"��falseΪ"Ů"
    int age;
    char tel[20];
    int score[5];
    int score_num; float average_score;
    Student * p = head->next ,* q;

    while(p != NULL)
    {
        q = p->next;
        delete p; 
        p = q;
    }
    delete q; q = NULL;

    FILE * r ;
    r = fopen(FileName , "r");
    if(r==NULL)
    {
        cout<<"�ļ���ʧ�ܣ�����"<<endl;
    }
    else {cout<<"�ѳɹ����ļ���Ϊ"<<FileName<<"���ļ��ж�ȡ��ѧ����Ϣ��"<<endl;}
    while(fscanf(r,"%s %s %d %d %s %d %d %d %d %d %d %f",&number,&name,&sex,&age,&tel,&score[0],&score[1],&score[2],&score[3],&score[4],&score_num,&average_score)!=EOF)
    {
        Student * s = new Student(number , name , sex , age , tel , score);
        s->next = head->next;
        head->next = s;  
    }
    fclose(r);
}