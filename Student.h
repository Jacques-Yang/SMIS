/**����ѧ����Ϣ��
 * ���ԣ�ѧ�ţ��������Ա����䣬�绰���룬�ɼ�
 * ��������ӣ�ɾ�����޸ģ���ѯ
 */
#ifndef _Stud
#define _Stud
#include<cstring>
class Student
{

public:

    char number[20];    
    char name[20];
    int sex;           //trueΪ"��"��falseΪ"Ů"
    int age;
    char tel[20];
    int score[5];
    int score_sum = 0;
    float average_score = 0;

//ָ����һ������ָ��
Student * next ;


//���ι��캯��
    Student(char new_number[] , char new_name[] , int new_sex , int new_age , char new_tel[] , int new_score[5]);

//�޲ι��캯��
    Student();

//��������
    ~Student();

//��ʾѧ����Ϣ����
    void Display(int method);

//���ѧ����Ϣ����
    void AddStu();

//����ѧ��ѧ�ź���
    void setNumber(char m_number[]);
    
//����ѧ����������
    void setName(char m_name[]);

//����ѧ���Ա���
    void setSex(int m_sex);

//����ѧ�����亯��
    void setAge(int m_age);

//����ѧ���绰���뺯��
    void setTel(char m_tel[]);

//����ѧ���γ̳ɼ�����
    void setScore(int m_score[]);

};
#endif




