#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//�ļ���

//�ı��ļ�
//д�ļ�,�Գ���Ϊ�����ж����������
void test01()
{
    //1.�����ļ���ͷ�ļ�
    //2.����������
    ofstream ofs;
    //3.���ļ�
    ofs.open("test.txt",ios::out);
    //4.д����
    ofs << "liyou" << endl;
    ofs << "��" << endl;
    ofs << 18 << endl;
    //5.�ر��ļ�
    ofs.close();
}
//���ļ�
void test02()
{
    //1.����ͷ�ļ�
    //2.����������
    ifstream ifs;
    //3.���ļ����ж��ļ��Ƿ�򿪳ɹ�
    ifs.open("test.txt",ios::in);
    if(!ifs.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    //4.������
    //��һ��
//    char buf[1024] = {0};
//    while(ifs>>buf)
//    {
//        cout << buf << endl;
//    }
    //�ڶ���
//
    //������
//    string buf;
//    while(getline(ifs,buf))
//    {
//        cout << buf << endl;
//    }
    //������ ������ʹ��
    char c;
    while((c = ifs.get())!=EOF) //EOF end of file
    {
        cout << c;
    }
    //5.�ر��ļ�
    ifs.close();
}

//�������ļ�
class Person
{
public:
    char m_Name[64];
    int m_Age;
};
//д
void test03()
{
    //1.����ͷ�ļ�
    //2.����������
    ofstream ofs("person.txt",ios::out | ios::binary);
    //3.���ļ�
//    ofs.open("person.txt",ios::out | ios::binary);
    //4.д�ļ�
    Person p = {"liyou",18};
//    p.m_Name = {"liyou";
//    p.m_Age = 18;
    ofs.write((const char*)&p,sizeof(Person));
    //�ر��ļ�
    ofs.close();
}
//��
void test04()
{
    //1.����ͷ�ļ�
    //2.����������
    ifstream ifs("person.txt",ios::in | ios::binary);
    //3.���ļ����ж��ļ��Ƿ�򿪳ɹ�
    if(!ifs.is_open())
    {
        cout << "���ļ�ʧ��" << endl;
        return;
    }
    //4.���ļ�
    Person p;
    ifs.read((char*)&p,sizeof(Person));
    //5.�ر��ļ�
    cout << p.m_Name << "\t" << p.m_Age << endl;
    ifs.close();
}

int main() {
//    test04();
//    test03();
//    test02();
//    test01();

    return 0;
}