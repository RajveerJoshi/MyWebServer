#include<tmwp>
#include<iostream>
using namespace tmwp;
using namespace std;
void doSomething(int dataCount,char *data[])
{
cout<<"great,this code got executed on server side"<<endl;
if(dataCount>0) cout<<"Data That Arrived"<<endl;
for(int r=0;r<dataCount;r++)
{
cout<<data[r]<<endl;
}
}
int main()
{
TMWebProjector server(8080);
server.onRequest("/register",doSomething);
server.start();
return 0;
}