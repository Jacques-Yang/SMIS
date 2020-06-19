//创立学生信息单向链表类  
#include"Student.h"
#ifndef _StudList
#define _StudList

class StudentList
{
private:

//创立头结点
    Student *head;

public:

//无参构造函数
    StudentList();

//析构函数
    ~StudentList();

//添加学生结点函数
    void AddStud();

//显示学生链表信息函数
    void DisplayNum();

//计算链表长度函数
    int StuLength();

//显示单科成绩最高分学生信息函数
void SingleScoreSearch(int score_num);

//查找学生信息返回指针函数
    Student * SearchStu(char number[]);

//修改链表中学生结点信息函数
    void ModifyStu(Student * p);

//删除链表中学生结点函数
    void DeleteStu(Student * p);

//总分排序函数
    void ScoreSumSort();

//单科成绩排序函数
    void SingleScoreSort(int score_num);
    
//保存学生链表信息到文件函数
    void SavaStu(const char FileName[]);

//从文件读取学生链表信息函数
    void ReadStu(const char FileName[]);
};
#endif

