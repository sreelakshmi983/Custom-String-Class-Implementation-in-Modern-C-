#include<iostream>
#include<string.h>
using namespace std;

class STRING
{
	char *s;
public:
	STRING()
	{
	//	cout<<"default constructor"<<endl;
		s=new char[100];
	}
	STRING(const char *str)
	{
	//	cout<<"parameterized constructor"<<endl;
		s=new char[strlen(str)+1];
		strcpy(s,str);
	}
	STRING(const STRING &t){
	//	cout<<"copy constructor"<<endl;
		s=new char(strlen(t.s)+1);
		strcpy(s,t.s);
	}
	~STRING(){
	//	cout<<"destructor"<<endl;
		if(s!=nullptr)
		{
			delete []s;
			s=nullptr;
		}
	}
	void getdata()
	{
		cout<<s<<endl;
	}
	STRING operator =(STRING t)
	{
		for(int i=0;i<strlen(t.s);i++)
			s[i]=t.s[i];
		return t;
	}
	char& operator [](int i)
	{
	//	cout<<"operator []"<<endl;
		return s[i];
	}
	STRING operator +(STRING t2)
	{
	//	cout<<"operator +"<<endl;
		char *temp=new char[strlen(s)+strlen(t2.s)+1];
		strcpy(temp,s);
		strcat(temp,t2.s);
		STRING result(temp);
		delete []temp;
		return result;
	}
	int operator >(STRING t2)
	{
	//	cout<<"operator >"<<endl;
		int i;
		i=strcmp(s,t2.s);
		if(i>0)
			return 1;
		else 
			return 0;
	}
	int operator <(STRING t2)
	{
	//	cout<<"operator <"<<endl;
		int i;
		i=strcmp(s,t2.s);
		if(i<0)
			return 1;
		else
			return 0;
	}
	int operator ==(STRING t2)
	{
	//	cout<<"operator =="<<endl;
		int i;
		i=strcmp(s,t2.s);
		if(i==0)
			return 1;
		else
			return 0;

	}
	int operator !=(STRING t2)
	{
	//	cout<<"operator !="<<endl;
		int i;
		i=strcmp(s,t2.s);
		if(i!=0)
			return 1;
		else
			return 0;
	}
	int operator >=(STRING t2)
	{
	//	cout<<"operator >="<<endl;
		int i;
		i=strcmp(s,t2.s);
		if(i>=0)
			return 1;
		else 
			return 0;
	}
	int operator <=(STRING t2)
	{
	//	cout<<"operator <="<<endl;
		int i;
		i=strcmp(s,t2.s);
		if(i<=0)
			return 1;
		else 
			return 0;
	}

friend istream& operator >>(istream &,STRING &);
friend ostream& operator <<(ostream &,STRING &);
friend void Strcat(STRING &s1,const STRING &s2);
friend int Strlen(STRING p);
friend void Strcpy(STRING&,const STRING&);
friend const char * Strchr(const STRING &,char);
friend void Strupr(STRING &);
friend void Strlwr(STRING &);
friend int Strcmp(const STRING &,const STRING &);
friend char * Strstr(STRING &,const STRING &);
friend void Strrev(STRING &);
friend void Strncat(STRING &s1,const STRING &s2,int n);
friend void Strncpy(STRING &d,const STRING &sr,int n);
friend int Strncmp(const STRING &,const STRING &,int n);
friend const char * Strrchr(const STRING &p,char ch);
};
/////////////////////////////////////////////////
int Strlen(STRING );
void Strcat(STRING &s1,const STRING &s2);
void Strcpy(STRING&,const STRING&);
const char * Strchr(const STRING &,char);
void Strupr(STRING &);
void Strlwr(STRING &);
int Strcmp(const STRING &,const STRING &);
char * Strstr(STRING &,const STRING &);
void Strrev(STRING &);
void Strncat(STRING &s1,const STRING &s2,int n);
void Strncpy(STRING &d,const STRING &sr,int n);
int Strncmp(const STRING &,const STRING &,int n);
const char * Strrchr(const STRING &p,char ch);
////////////////////////////////////////////////
istream& operator >>(istream &in,STRING &d)
{
	//	cout<<"extraction operator >>"<<endl;
	in>>d.s;
	return in;
}
ostream& operator <<(ostream &out,STRING &d)
{
	//	cout<<"insertion operator <<"<<endl;
	out<<d.s;
	return out;
}
int main()
{
	STRING s1,s2("vector"),s3(s2),s4,s5;
	cout<<"enter a string:";
	cin>>s1;
	cout<<"s1="<<s1<<"<------default constructor"<<endl;
	cout<<"s2="<<s2<<"<------parameterized constructor"<<endl;
	cout<<"s3="<<s3<<"<------copy constructor"<<endl;
	s4=s1;
	cout<<"assignment operator s4=s1----->"<<s4<<endl;
	s4=s1+s2;
	cout<<"concatenation of two strings s4=s1+s2----->"<<s4<<endl;
	cout<<"index operator s1[2]----->"<<s1[2]<<endl;
	cout<<"checking s1>s2----->"<<(s1>s2)<<endl;
	cout<<"checking s1<s2----->"<<(s1<s2)<<endl;
	cout<<"checking s1>=s2----->"<<(s1>=s2)<<endl;
	cout<<"checking s1<=s2----->"<<(s1<=s2)<<endl;
	cout<<"checking s1!=s2----->"<<(s1!=s2)<<endl;
	cout<<"checking s1==s2----->"<<(s1==s2)<<endl;
	cout<<"Strlen(s1)----->"<<Strlen(s1)<<endl;
	Strcpy(s2,s1);
	cout<<"Strcpy(s2,s1)----->s2="<<s2<<endl;
	Strcat(s3,s1);
	cout<<"Strcat(s3,s1)----->s3="<<s3<<endl;
	const char *p2=Strchr(s3,'r');
	if(p2==nullptr)
		cout<<"Strchr(s3,'r')----->no char found"<<endl;
	else
		cout<<"Strchr(s3,'r')----->"<<p2<<endl;
	Strupr(s4);
	Strlwr(s1);
	cout<<"Strupr(s4)----->s4="<<s4<<endl;
	cout<<"Strlwr(s1)----->s1="<<s1<<endl;
	cout<<"Strcmp(s1,s3)----->"<<Strcmp(s1,s3)<<endl;
	cout<<"enter a string:";
	cin>>s5;
	cout<<"s5="<<s5<<endl;
	cout<<"Strstr(s3,s5)----->"<<Strstr(s3,s5)<<endl;
	Strrev(s2);
	cout<<"Strrev(s2)----->s2="<<s2<<endl;
	Strncat(s5,s1,2);
	cout<<"Strncat(s5,s1,2)----->s5="<<s5<<endl;
	STRING s6;
	Strncpy(s6,s5,3);
	cout<<"Strncpy(s6,s5,3)----->s6="<<s6<<endl;
	cout<<"Strncmp(s5,s6,3)----->"<<Strncmp(s5,s6,3)<<endl;
	const char *p=Strrchr(s5,'t');
	if(p==nullptr)
		cout<<"Strrchr(s5,'t')----->no char found"<<endl;
	else
		cout<<"Strrchr(s5,'t')----->"<<p<<endl;

}
int Strlen(STRING p)
{
	int i;
	for(i=0;p.s[i];i++);
	return i;
}
void Strcpy(STRING &d,const STRING &sr)
{
	int i;
	for(i=0;sr.s[i];i++)
		d.s[i]=sr.s[i];
	d.s[i]='\0';
}
void Strncpy(STRING &d,const STRING &sr,int n)
{
	int i;
	for(i=0;i<n;i++)
		d.s[i]=sr.s[i];
	d.s[i]='\0';
}
const char * Strchr(const STRING &p,char ch)
{
	int i;
	for(i=0;p.s[i];i++)
		if(p.s[i]==ch)
			return &p.s[i];
	return nullptr;
}
const char * Strrchr(const STRING &p,char ch)
{

	int i=strlen(p.s);
	for(i=i-1;i>=0;i--)
		if(p.s[i]==ch)
			return &p.s[i];
	return nullptr;
}
void Strupr(STRING &p)
{
	int i;
	for(i=0;p.s[i];i++)
		if(p.s[i]>='a' && p.s[i]<='z')
			p.s[i]=p.s[i]-32;
}
void Strlwr(STRING &p)
{
	int i;
	for(i=0;p.s[i];i++)
		if(p.s[i]>='A' && p.s[i]<='Z')
			p.s[i]=p.s[i]+32;
}
void Strrev(STRING &p)
{
	char t;
	int i,j,len;
	len=strlen(p.s);
	for(i=0,j=len-1;i<j;i++,j--)
	{
		t=p.s[i];
		p.s[i]=p.s[j];
		p.s[j]=t;
	}
}
int Strcmp(const STRING &s1,const STRING &s2)
{
        int i;
        for(i=0;s1.s[i];i++)
        {
                if(s1.s[i]!=s2.s[i])
                        return s1.s[i]-s2.s[i];
        }
        if(s1.s[i]==s2.s[i])
                return 0;
        else
                return -s2.s[i];
}
int Strncmp(const STRING &s1,const STRING &s2,int n)
{
        int i;
        for(i=0;i<n;i++)
        {
                if(s1.s[i]!=s2.s[i])
                        return s1.s[i]-s2.s[i];
        }
        if(s1.s[i]==s2.s[i])
                return 0;
        else
                return -s2.s[i];
}
char * Strstr(STRING &m,const STRING &s)
{
	int i,j=0;
	for(i=0;m.s[i];i++)
	{
		if(m.s[i]==s.s[j])
		{
			for(j=i;s.s[j];j++)
			{
				if(s.s[j]!=m.s[i+j])
					break;
			}
			if(s.s[j]==0)
				return (m.s)+i;
			j=0;
		}
	}
	return 0;

}

void Strcat(STRING &s1,const STRING &s2)
{
        int i,j;
        for(i=strlen(s1.s),j=0;s2.s[j];i++,j++)
                s1.s[i]=s2.s[j];
        s1.s[i]='\0';
}
void Strncat(STRING &s1,const STRING &s2,int n)
{
	int i,j;
	for(i=strlen(s1.s),j=0;j<n;i++,j++)
		s1.s[i]=s2.s[j];
	s1.s[i]='\0';
}











