


#include<vector>
#include<initializer_list>
#include"vector3d.h"


using namespace std;

namespace gpp
{
vector3d::vector3d(float x, float y, float z)
{
this->x=floatClean(x);
this->y=floatClean(y);
this->z=floatClean(z);
}

vector3d::vector3d(const vector3d& dv)
{
*this=dv;
}

vector3d& vector3d::operator=(const vector3d& dv)
{
this->x=dv.x;
this->y=dv.y;
this->z=dv.z;
return *this;
}

vector3d& vector3d::operator=(const initializer_list<float>& points)
{
vector<float> df(points);
switch(df.size())
{
case 1:
{
this->x=floatClean(df[0]);
break;
}
case 2:
{
this->x=floatClean(df[0]);
this->y=floatClean(df[1]);
break;
}
case 3:
{
this->x=floatClean(df[0]);
this->y=floatClean(df[1]);
this->z=floatClean(df[2]);
break;
}
}
return *this;
}

bool vector3d::operator==(const vector3d& dv)const
{
return this->x==dv.x&&this->y==dv.y&&this->z==dv.z;
}

bool vector3d::operator==(const initializer_list<float>& dv)const
{
vector<float> df(dv);
switch(df.size())
{
case 1:
{
return this->x==df[0];
}
case 2:
{
return this->x==df[0]&&this->y==df[1];
}
case 3:
{
return this->x==df[0]&&this->y==df[1]&&this->z==df[2];
}
}
return false;
}

vector3d vector3d::operator+(float escalar)const
{
return vector3d(this->x+escalar, this->y+escalar, this->z+escalar);
}

vector3d& vector3d::operator+=(float escalar)
{
this->x+=escalar;
this->y+=escalar;
this->z+=escalar;
return *this;
}

vector3d vector3d::operator-(float escalar)const
{
return vector3d(this->x-escalar, this->y-escalar, this->z-escalar);
}

vector3d& vector3d::operator-=(float escalar)
{
this->x-=escalar;
this->y-=escalar;
this->z-=escalar;
return *this;
}

vector3d vector3d::operator*(float escalar)const
{
return vector3d(this->x*escalar, this->y*escalar, this->z*escalar);
}

vector3d& vector3d::operator*=(float escalar)
{
this->x*=escalar;
this->y*=escalar;
this->z*=escalar;
return *this;
}

vector3d vector3d::operator/(float escalar)const
{
if(escalar==0)
{
return vector3d(this->x, this->y, this->z);
}
return vector3d((this->x/escalar), (this->y/escalar), (this->z/escalar));
}

vector3d& vector3d::operator/=(float escalar)
{
if(escalar==0)
{
return *this;
}
this->x/=escalar;
this->y/=escalar;
this->z/=escalar;
return *this;
}

vector3d vector3d::operator-(const vector3d& dv)const
{
return vector3d(this->x-dv.x, this->y-dv.y, this->z-dv.z);
}

vector3d& vector3d::operator-=(const vector3d& dv)
{
this->x-=dv.x;
this->y-=dv.y;
this->z-=dv.z;
return *this;
}

vector3d vector3d::operator+(const vector3d& dv)const
{
return vector3d(this->x+dv.x, this->y+dv.y, this->z+dv.z);
}

vector3d& vector3d::operator+=(const vector3d& dv)
{
this->x+=dv.x;
this->y+=dv.y;
this->z+=dv.z;
return *this;
}

vector3d vector3d::operator*(const vector3d& dv)const
{
return vector3d(this->x*dv.x, this->y*dv.y, this->z*dv.z);
}

vector3d& vector3d::operator*=(const vector3d& dv)
{
this->x*=dv.x;
this->y*=dv.y;
this->z*=dv.z;
return *this;
}

vector3d vector3d::operator/(const vector3d& v )const
{
return vector3d(((v.x!=0) ? this->x/v.x : this->x), ((v.y!=0) ? this->y/v.y : this->y), ((v.z!=0) ? this->z/v.z : this->z));
}

vector3d& vector3d::operator/=(const vector3d& v )
{
if(v.x!=0)
{
this->x/=v.x;
}
if(v.y!=0)
{
this->y/=v.y;
}
if(v.z!=0)
{
this->z/=v.z;
}
return *this;
}

bool vector3d::isNull()const
{
return x==0.0f&&y==0.0f&&z==0.0f;
}

float vector3d::length()const
{
//is the same formula as the distance
return sqrt((this->x*this->x)+(this->y*this->y)+(this->z*this->z));
}

void vector3d::normalize()
{
float len=this->length();
if(len>0)
{
this->x/=len;
this->y/=len;
this->z/=len;
}
}

float vector3d::get(int axis)const
{
switch(axis)
{
case 0:
return this->x;
case 1:
return this->y;
case 2:
return this-> z;
}
return -1;
}

float vector3d::get_x()const
{
return this->x;
}

float vector3d::get_y()const
{
return this->y;
}

float vector3d::get_z()const
{
return this->z;
}

void vector3d::get_xyz(float * x, float* y, float* z)
{
if(x!=NULL)
{
*x=this->x;
}
if(y!=NULL)
{
*y=this->y;
}
if(z!=NULL)
{
*z=this->z;
}
}

void vector3d::set_x(float x)
{
this->x=x;
}

void vector3d::set_y(float y)
{
this->y=y;
}

void vector3d::set_z(float z)
{
this->z=z;
}

void vector3d::set_xyz(float x, float y, float z)
{
this->x=x;
this->y=y;
this->z=z;
}

float vector3d::dotProduct(const vector3d& v1, const vector3d&  v2)
{
//just multiply everything and add.
return ((v1.x*v2.x)+(v1.y*v2.y)+(v1.z*v2.z));
}

vector3d vector3d::crozProduct(const vector3d& v1, const vector3d& v2)
{
vector3d v;
v.x=((v1.y*v2.z)-(v1.z*v2.y));
v.y=((v1.z*v2.x)-(v1.x*v2.z));
v.z=((v1.x*v2.y)-(v1.y*v2.x));
return v;
}

float vector3d::tripleProduct(const vector3d& v1, const vector3d& v2, const vector3d& v3)
{
vector3d v=crozProduct(v1, v2);
return dotProduct(v, v3);
}

float vector3d::angle_from(const vector3d&  v1, const vector3d&  v2)
{
float escalar=dotProduct(v1, v2);
float product=(v1.length()*v2.length());
float angle=acos((escalar/product));
angle=(angle*180)/GPP_PI;
return angle;
}

float vector3d::get_distance(const vector3d&  v1, const vector3d&  v2)
{
vector3d v(v1-v2);
v.x*=v.x;
v.y*=v.y;
v.z*=v.z;
float df=(v.x+v.y+v.z);
return sqrt(df);
}

float vector3d::get_squared_distance(const vector3d&  v1, const vector3d&  v2)
{
vector3d v(v1-v2);
v.x*=v.x;
v.y*=v.y;
v.z*=v.z;
float df=(v.x+v.y+v.z);
return df;
}

float vector3d::floatClean(float v)
{
if(isnan(v))
{
return 0.0f;
}
if(isinf(v))
{
return 0.0f;
}
if(v==-0)
{
return 0.0f;
}
return v;
}
//Functions

ostream& operator<<(ostream& os, const vector3d& dv)
{
os.precision(2);
os<<fixed;
os<<dv.x<<"\t"<<dv.y<<"\t"<<dv.z<<endl;
return os;
}
}