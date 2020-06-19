#include<iostream>
#include"Student.cpp"
#include"StudentList.cpp"
#include<cstring>
using namespace std;

//系统菜单函数的声明
void Menu();

//从文件读取数据的菜单函数的声明
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
        cout<<"请选择你想要进行的操作："; cin>>menu_flag;
        switch (menu_flag)
        {
        case '1':
            cout<<"请选择你的查看类型【<1> 总分升序排序  <2> 单科成绩升序排序】："; cin>>display_flag;
            while(display_flag != "1" && display_flag != "2")
            {
                cout<<"输入错误，请重新输入【<1> 总分升序排序  <2> 单科成绩升序排序】："; cin>>display_flag;
            }
            if(display_flag == "1")
            {
                stud.ScoreSumSort();
                stud.DisplayNum();
            }
            if(display_flag == "2")
            {
                cout<<"请选择一门课程进行成绩排序【<1> 数据结构  <2> Java  <3> C++  <4> 软件工程  <5> 体育】："; cin>>display_flag;
                while(display_flag != "1" && display_flag != "2" && display_flag != "3" && display_flag != "4" && display_flag != "5")
                {
                    cout<<"输入错误，请重新输入【<1> 数据结构  <2> Java  <3> C++  <4> 软件工程  <5> 体育】："; cin>>display_flag;
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
            cout<<"请输入你想删除的学生的学号："; cin>>menu_number;
            main_pointer = stud.SearchStu(menu_number);
            stud.DeleteStu(main_pointer);
            if(main_pointer == NULL) {cout<<" 未查找到学号为 "<<menu_number<<" 的学生信息|----------------------------------------"<<endl;}
            stud.DisplayNum();
            break;
        case '4':
            cout<<"请输入你想修改的学生的学号："; cin>>menu_number;
            main_pointer = stud.SearchStu(menu_number);
            stud.ModifyStu(main_pointer);
            if(main_pointer == NULL) {cout<<" 未查找到学号为 "<<menu_number<<" 的学生信息|----------------------------------------"<<endl;}
            break;
        case '5':
            cout<<"请选择你的查找条件【<1> 学号  <2> 单科成绩最高分】"; cin>>display_flag;
            while(display_flag != "1" && display_flag != "2")
            {
                cout<<"输入错误，请重新输入【<1> 学号  <2> 单科成绩最高分】："; cin>>display_flag;
            }
            if(display_flag == "1")
            {
                cout<<"请输入你想查找的学生的学号："; cin>>menu_number;
                main_pointer = stud.SearchStu(menu_number);
                if(main_pointer != NULL) {main_pointer->Display(1);}
                else {cout<<"--------------------------------------------|未查找到学号为 "<<menu_number<<" 的学生信息|-----------------------------------------"<<endl;}
            }
            if(display_flag == "2")
            {
                cout<<"请选择一门课程【<1> 数据结构  <2> Java  <3> C++  <4> 软件工程  <5> 体育】："; cin>>display_flag;
                while(display_flag != "1" && display_flag != "2" && display_flag != "3" && display_flag != "4" && display_flag != "5")
                {
                    cout<<"输入错误，请重新输入【<1> 数据结构  <2> Java  <3> C++  <4> 软件工程  <5> 体育】："; cin>>display_flag;
                }
                cout<<endl;
                if(display_flag == "1") {stud.SingleScoreSearch(0);}  if(display_flag == "2") {stud.SingleScoreSearch(1);}
                if(display_flag == "3") {stud.SingleScoreSearch(2);}  if(display_flag == "4") {stud.SingleScoreSearch(3);}
                if(display_flag == "5") {stud.SingleScoreSearch(1);}
            }
            break;
        case '0':
            cout<<"请问是否将改动保存至文件？(Y/N)："; cin>>display_flag;
            while(display_flag != "Y" && display_flag != "y" && display_flag != "N" && display_flag != "n")
            {
                cout<<"输入错误，请重新输入(Y/N)："; cin>>display_flag;
            }
            if(display_flag == "Y" || display_flag == "y")
            {
                stud.SavaStu(FileName);
            }
            if(display_flag == "N" || display_flag == "n")
            {
                cout<<"未对文件进行任何改动！"<<endl;
            }
            flag = false;
            break;
        default:
            cout<<"输入错误！！！ ";
            break;
            
        }
        cout<<"请按Enter键以继续...";
        getchar(); getchar();
        system("cls");
    }
    cout<<"-----------------------------------------------------------|已安全退出系统|----------------------------------------------------------"<<endl;
    system("pause");
    return 0;
}

void Menu()
{
    cout<<"\t\t\t---------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t|                                学 生 信 息 管 理 系 统                              |"<<endl;
    cout<<"\t\t\t---------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t|                                 < 1 >    查看学生信息                               | "<<endl;
    cout<<"\t\t\t---------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t|                                 < 2 >    添加学生信息                               | "<<endl;
    cout<<"\t\t\t---------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t|                                 < 3 >    删除学生信息                               | "<<endl;
    cout<<"\t\t\t---------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t|                                 < 4 >    修改学生信息                               | "<<endl;
    cout<<"\t\t\t---------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t|                                 < 5 >    查找学生信息                               | "<<endl;
    cout<<"\t\t\t---------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t|                                 < 0 >    安全退出系统                               | "<<endl;
    cout<<"\t\t\t---------------------------------------------------------------------------------------"<<endl;
}

void ReadMenu(StudentList student , const char FileName[])
{
    string readflag;
    cout<<"请问你需要从文件导入学生信息吗？(Y/N)："; cin>>readflag;
    while(readflag != "Y" && readflag != "y" && readflag != "N" && readflag != "n")
    {
        cout<<"输入有误，请重新输入(Y/N)："; cin>>readflag; 
    }
    if(readflag == "Y" || readflag == "y")
    {
        student.ReadStu(FileName);

    }
    if(readflag == "N" || readflag == "n")
    {
        cout<<"请手动录入学生信息！"<<endl;
    }   
}
