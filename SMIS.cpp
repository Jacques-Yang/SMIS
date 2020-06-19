#include<iostream>
#include"Student.cpp"
#include"StudentList.cpp"
#include<cstring>
using namespace std;

//ϵͳ�˵�����������
void Menu();

//���ļ���ȡ���ݵĲ˵�����������
void ReadMenu(StudentList student , const char FileName[]);

int main()
{
    StudentList stud; Student * main_pointer; 
    const char FileName[30] = "data.txt"; char menu_flag , menu_number[20];
    ReadMenu(stud , FileName);
    string display_flag;  bool flag = true; 
    while(flag)
    {
        Menu();
        cout<<"��ѡ������Ҫ���еĲ�����"; cin>>menu_flag;
        switch (menu_flag)
        {
        case '1':
            cout<<"��ѡ����Ĳ鿴���͡�<1> �ܷ���������  <2> ���Ƴɼ��������򡿣�"; cin>>display_flag;
            while(display_flag != "1" && display_flag != "2")
            {
                cout<<"����������������롾<1> �ܷ���������  <2> ���Ƴɼ��������򡿣�"; cin>>display_flag;
            }
            if(display_flag == "1")
            {
                stud.ScoreSumSort();
                stud.DisplayNum();
            }
            if(display_flag == "2")
            {
                cout<<"��ѡ��һ�ſγ̽��гɼ�����<1> ���ݽṹ  <2> Java  <3> C++  <4> �������  <5> ��������"; cin>>display_flag;
                while(display_flag != "1" && display_flag != "2" && display_flag != "3" && display_flag != "4" && display_flag != "5")
                {
                    cout<<"����������������롾<1> ���ݽṹ  <2> Java  <3> C++  <4> �������  <5> ��������"; cin>>display_flag;
                }
                if(display_flag == "1") {stud.SingleScoreSort(0);}  if(display_flag == "2") {stud.SingleScoreSort(1);}
                if(display_flag == "3") {stud.SingleScoreSort(2);}  if(display_flag == "4") {stud.SingleScoreSort(3);}
                if(display_flag == "5") {stud.SingleScoreSort(4);}
                stud.DisplayNum();
            } 
            break; 
        case '2':
            stud.AddStud();
            stud.DisplayNum();
            break;
        case '3':
            cout<<"����������ɾ����ѧ����ѧ�ţ�"; cin>>menu_number;
            main_pointer = stud.SearchStu(menu_number);
            stud.DeleteStu(main_pointer);
            if(main_pointer == NULL) {cout<<" δ���ҵ�ѧ��Ϊ "<<menu_number<<" ��ѧ����Ϣ|----------------------------------------"<<endl;}
            stud.DisplayNum();
            break;
        case '4':
            cout<<"�����������޸ĵ�ѧ����ѧ�ţ�"; cin>>menu_number;
            main_pointer = stud.SearchStu(menu_number);
            stud.ModifyStu(main_pointer);
            if(main_pointer == NULL) {cout<<" δ���ҵ�ѧ��Ϊ "<<menu_number<<" ��ѧ����Ϣ|----------------------------------------"<<endl;}
            break;
        case '5':
            cout<<"��ѡ����Ĳ���������<1> ѧ��  <2> ���Ƴɼ���߷֡�"; cin>>display_flag;
            while(display_flag != "1" && display_flag != "2")
            {
                cout<<"����������������롾<1> ѧ��  <2> ���Ƴɼ���߷֡���"; cin>>display_flag;
            }
            if(display_flag == "1")
            {
                cout<<"������������ҵ�ѧ����ѧ�ţ�"; cin>>menu_number;
                main_pointer = stud.SearchStu(menu_number);
                if(main_pointer != NULL) {main_pointer->Display(1);}
                else {cout<<"--------------------------------------------|δ���ҵ�ѧ��Ϊ "<<menu_number<<" ��ѧ����Ϣ|-----------------------------------------"<<endl;}
            }
            if(display_flag == "2")
            {
                cout<<"��ѡ��һ�ſγ̡�<1> ���ݽṹ  <2> Java  <3> C++  <4> �������  <5> ��������"; cin>>display_flag;
                while(display_flag != "1" && display_flag != "2" && display_flag != "3" && display_flag != "4" && display_flag != "5")
                {
                    cout<<"����������������롾<1> ���ݽṹ  <2> Java  <3> C++  <4> �������  <5> ��������"; cin>>display_flag;
                }
                cout<<endl;
                if(display_flag == "1") {stud.SingleScoreSearch(0);}  if(display_flag == "2") {stud.SingleScoreSearch(1);}
                if(display_flag == "3") {stud.SingleScoreSearch(2);}  if(display_flag == "4") {stud.SingleScoreSearch(3);}
                if(display_flag == "5") {stud.SingleScoreSearch(1);}
            }
            break;
        case '0':
            cout<<"�����Ƿ񽫸Ķ��������ļ���(Y/N)��"; cin>>display_flag;
            while(display_flag != "Y" && display_flag != "y" && display_flag != "N" && display_flag != "n")
            {
                cout<<"�����������������(Y/N)��"; cin>>display_flag;
            }
            if(display_flag == "Y" || display_flag == "y")
            {
                stud.SavaStu(FileName);
            }
            if(display_flag == "N" || display_flag == "n")
            {
                cout<<"δ���ļ������κθĶ���"<<endl;
            }
            flag = false;
            break;
        default:
            cout<<"������󣡣��� ";
            break;
            
        }
        cout<<"�밴Enter���Լ���...";
        getchar(); getchar();
        system("cls");
    }
    cout<<"-----------------------------------------------------------|�Ѱ�ȫ�˳�ϵͳ|----------------------------------------------------------"<<endl;
    system("pause");
    return 0;
}

void Menu()
{
    cout<<"\t\t\t---------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t|                                ѧ �� �� Ϣ �� �� ϵ ͳ                              |"<<endl;
    cout<<"\t\t\t---------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t|                                 < 1 >    �鿴ѧ����Ϣ                               | "<<endl;
    cout<<"\t\t\t---------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t|                                 < 2 >    ���ѧ����Ϣ                               | "<<endl;
    cout<<"\t\t\t---------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t|                                 < 3 >    ɾ��ѧ����Ϣ                               | "<<endl;
    cout<<"\t\t\t---------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t|                                 < 4 >    �޸�ѧ����Ϣ                               | "<<endl;
    cout<<"\t\t\t---------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t|                                 < 5 >    ����ѧ����Ϣ                               | "<<endl;
    cout<<"\t\t\t---------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t|                                 < 0 >    ��ȫ�˳�ϵͳ                               | "<<endl;
    cout<<"\t\t\t---------------------------------------------------------------------------------------"<<endl;
}

void ReadMenu(StudentList student , const char FileName[])
{
    string readflag;
    cout<<"��������Ҫ���ļ�����ѧ����Ϣ��(Y/N)��"; cin>>readflag;
    while(readflag != "Y" && readflag != "y" && readflag != "N" && readflag != "n")
    {
        cout<<"������������������(Y/N)��"; cin>>readflag; 
    }
    if(readflag == "Y" || readflag == "y")
    {
        student.ReadStu(FileName);

    }
    if(readflag == "N" || readflag == "n")
    {
        cout<<"���ֶ�¼��ѧ����Ϣ��"<<endl;
    }   
}
