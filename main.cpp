#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//文件流

//文本文件
//写文件,以程序为中心判断输入输出流
void test01()
{
    //1.包含文件流头文件
    //2.创建流对象
    ofstream ofs;
    //3.打开文件
    ofs.open("test.txt",ios::out);
    //4.写数据
    ofs << "liyou" << endl;
    ofs << "男" << endl;
    ofs << 18 << endl;
    //5.关闭文件
    ofs.close();
}
//读文件
void test02()
{
    //1.包含头文件
    //2.创建流对象
    ifstream ifs;
    //3.打开文件并判断文件是否打开成功
    ifs.open("test.txt",ios::in);
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    //4.读数据
    //第一种
//    char buf[1024] = {0};
//    while(ifs>>buf)
//    {
//        cout << buf << endl;
//    }
    //第二种
//
    //第三种
//    string buf;
//    while(getline(ifs,buf))
//    {
//        cout << buf << endl;
//    }
    //第四种 不建议使用
    char c;
    while((c = ifs.get())!=EOF) //EOF end of file
    {
        cout << c;
    }
    //5.关闭文件
    ifs.close();
}

//二进制文件
class Person
{
public:
    char m_Name[64];
    int m_Age;
};
//写
void test03()
{
    //1.包含头文件
    //2.创建流对象
    ofstream ofs("person.txt",ios::out | ios::binary);
    //3.打开文件
//    ofs.open("person.txt",ios::out | ios::binary);
    //4.写文件
    Person p = {"liyou",18};
//    p.m_Name = {"liyou";
//    p.m_Age = 18;
    ofs.write((const char*)&p,sizeof(Person));
    //关闭文件
    ofs.close();
}
//读
void test04()
{
    //1.包含头文件
    //2.创建流对象
    ifstream ifs("person.txt",ios::in | ios::binary);
    //3.打开文件与判断文件是否打开成功
    if(!ifs.is_open())
    {
        cout << "打开文件失败" << endl;
        return;
    }
    //4.读文件
    Person p;
    ifs.read((char*)&p,sizeof(Person));
    //5.关闭文件
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