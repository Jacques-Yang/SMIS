//����ѧ����Ϣ����������  
#include"Student.h"
#ifndef _StudList
#define _StudList

class StudentList
{
private:

//����ͷ���
    Student *head;

public:

//�޲ι��캯��
    StudentList();

//��������
    ~StudentList();

//���ѧ����㺯��
    void AddStud();

//��ʾѧ��������Ϣ����
    void DisplayNum();

//���������Ⱥ���
    int StuLength();

//��ʾ���Ƴɼ���߷�ѧ����Ϣ����
void SingleScoreSearch(int score_num);

//����ѧ����Ϣ����ָ�뺯��
    Student * SearchStu(char number[]);

//�޸�������ѧ�������Ϣ����
    void ModifyStu(Student * p);

//ɾ��������ѧ����㺯��
    void DeleteStu(Student * p);

//�ܷ�������
    void ScoreSumSort();

//���Ƴɼ�������
    void SingleScoreSort(int score_num);
    
//����ѧ��������Ϣ���ļ�����
    void SavaStu(const char FileName[]);

//���ļ���ȡѧ��������Ϣ����
    void ReadStu(const char FileName[]);
};
#endif

