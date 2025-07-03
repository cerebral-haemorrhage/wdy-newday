#include <iostream>
#include <cstring>

using namespace std;

class String{
public:
    String();
    String(const char* s);
    String(const String& s);
    ~String();
    String& operator=(const String& s);
    char& operator[](size_t index);
    friend String operator+(const String& lhs,const String& rhs);
    friend ostream& operator<<(ostream& os, const String& str);
    friend istream& operator>>(istream& is, String& str);
    void tostring();
    size_t getlen();
private:
    char* m_str;
    size_t m_size;
    size_t m_cap;
};


void String::tostring(){
    if(m_str!=nullptr)
        cout << m_str<<"    m_size:"<<m_size<<"      address"<<&m_str <<endl;
    cout << "////////////////////////"<<endl;
}

String::String(){
    cout << "Called null parameter construction"<<endl;
    m_str = nullptr;
    m_size = 0;
    m_cap = 0;
    tostring();
}

String::String(const char* s):m_size(strlen(s)),m_cap(strlen(s)){
    cout << "Called parameterized construction"<<endl;
    m_str = new char[m_cap+1];
    strcpy(m_str,s);
    tostring();
}

String::String(const String& s):m_size(s.m_size),m_cap(s.m_cap){
    cout << "Called copy construction"<<endl;
    m_str = new char[m_size+1];
    strcpy(m_str,s.m_str);
    tostring();
}

String::~String(){
    delete[] m_str;
    m_size = 0;
    m_cap = 0;
    m_str = nullptr;
}
String& String::operator=(const String& s){
    cout << "assignment"<<endl;
    if(this==&s){
        delete[] m_str;
        String(s);
    }
    return *this;
}
String operator+(const String& lhs,const String& rhs){
    String result;
    result.m_size = lhs.m_size + rhs.m_size;
    result.m_cap =  lhs.m_cap + rhs.m_cap;
    result.m_str = new char[result.m_size];
    strcpy(result.m_str,rhs.m_str);
    strcat(result.m_str,rhs.m_str);
    return result;
}
ostream& operator<<(ostream& os, const String& str){
    os<<str.m_str;
    return os;
}

istream& operator>>(istream& is, String& str){
    char buffer[1024];
    is>>buffer;
    str = String(buffer);
    return is;
}

char& String::operator[](size_t index){
    if(index>=m_size||index<0){
        throw out_of_range("index out of rane");
    }
    return m_str[index];
}
size_t String::getlen(){
    return m_size;
}

int main(){

    String s1;//调用空参构造
    String s2("go go go");//有参构造
    String s3(s2);//拷贝构造
    String s4 = s3;//调用的还是拷贝构造

    s3 = "wddddddd";//赋值
    s4 = s3;//赋值
    
    for(int i = 0;i < s2.getlen();i++)cout << s2[i];//重载运算符[]
    cout << endl;
    cout << s2 << endl;//重载运算符<<


    cout << "please cin >> s1:";
    cin >> s1;//重载运算符>>
    cout << s1 <<endl;
    s1.tostring();
    return 0;
}