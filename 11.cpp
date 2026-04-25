
//编写主函数：
//用Person类创建2个指针，p1和
//p2；
//用new创建两个Person对象，分别将指针赋值给p1, p2；
//用showme成员函数显示p1, p2所指对象的值；
//再输入一组“姓名、年龄和性别”值，用成员函数Register为p1的成员赋值；
//将p1所指对象的值赋值给p2所指对象；
//用showme显示p1、p2所指对象的值；
//删除动态对象。
//
//输入格式 :
//为p1的成员赋值时使用的数据
//
//输出格式 :
//person1和person2的默认值
//
//person1和person2的赋值后的值
//
//析构函数输出的信息
//
//输入样例 :
//mike 21 m
//输出样例 :
//在这里给出相应的输出。例如：
//
//person1 : XXX 0 m
//person2 : XXX 0 m
//person1 : mike 21 m
//person2 : mike 21 m
//Now destroying the instance of Person
//Now destroying the instance of Person
#include<iostream>
using namespace std;
class Person {
private:
	string name;
	int age;
	char sex;
public:
	Person& operator=(const Person& other) {
		// 把other的值复制给this对象
		this->name = other.name;
		this->age = other.age;
		this->sex = other.sex;
		return *this;
	}
	Person() : name("XXX"), age(0), sex('m') {}
	void Register(string n, int a, char s) {
		name = n;
		age = a;
		sex = s;
	}
	~Person() {
		cout << "Now destroying the instance of Person" << endl;
	}
	void showme() {
		cout << name <<" "<< age <<" "<< sex << endl;
	}
};

int main() {
	string name;
	int age;
	char sex;
	cin >> name >> age >> sex;
	Person* p1 = new Person();
	Person* p2 = new Person();
	cout << "person1:";
	p1->showme();
	cout << "person2:";
	p2->showme();
	p1->Register(name, age, sex);
	*p2 = *p1;
	cout << "person1:";
	p1->showme();
	cout << "person2:";
	p2->showme();
	delete p1;
	delete p2;
	return 0;
}