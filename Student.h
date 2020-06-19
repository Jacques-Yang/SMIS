/**创立学生信息类
 * 属性：学号，姓名，性别，年龄，电话号码，成绩
 * 方法：添加，删除，修改，查询
 */
#ifndef _Stud
#define _Stud
#include<cstring>
class Student
{

public:

    char number[20];    
    char name[20];
    int sex;           //true为"男"，false为"女"
    int age;
    char tel[20];
    int score[5];
    int score_sum = 0;
    float average_score = 0;

//指向下一个结点的指针
Student * next ;


//带参构造函数
    Student(char new_number[] , char new_name[] , int new_sex , int new_age , char new_tel[] , int new_score[5]);

//无参构造函数
    Student();

//析构函数
    ~Student();

//显示学生信息函数
    void Display(int method);

//添加学生信息函数
    void AddStu();

//设置学生学号函数
    void setNumber(char m_number[]);
    
//设置学生姓名函数
    void setName(char m_name[]);

//设置学生性别函数
    void setSex(int m_sex);

//设置学生年龄函数
    void setAge(int m_age);

//设置学生电话号码函数
    void setTel(char m_tel[]);

//设置学生课程成绩函数
    void setScore(int m_score[]);

};
#endif




