#include<stdlib.h>
#include<tmwp>
#include<iostream>
#include<ctime>
using namespace std;
using namespace tmwp;
void dispatchTime(Request &request,Response &response)
{
time_t t=time(0);
char *now=ctime(&t);
response.write("<!DOCTYPE HTML>");
response.write("<html lang='en'>");
response.write("<head>");
response.write("<meta charset='utf-8'>");
response.write("<title>The Clock</title>");
response.write("</head>");
response.write("<body>");
response.write("<h1>");
response.write(now);
response.write("</h1>");
response.write("<a href='now'>Refresh</a><br>");
response.write("<a href='index.html'>Home</a><br>");
response.write("</body>");
response.write("</html>");
response.close();
}
void getCityView(Request & request,Response & response)
{
cout<<"getCityView is being processed"<<endl;
string cityCodeString=request.get("cityCode");
cout<<"("<<cityCodeString<<")"<<endl;
int cityCode=atoi(cityCodeString.c_str());
if(cityCode==1)request.forward("Ujjain.html");
else if(cityCode==2)request.forward("Indore.html");
else if(cityCode==3)request.forward("Dewas.html");
else 
{
request.setKeyValue("error","invalid choice city not selected");
request.forward("errorPage");
}
}
void createErrorPage(Request & request,Response & response)
{
string errorMessage=request.getValue("error");
response.write("<!DOCTYPE HTML>");
response.write("<html lang='en'>");
response.write("<head>");
response.write("<meta charset='utf-8'>");
response.write("<title>The Clock</title>");
response.write("</head>");
response.write("<body>");
response.write("<h1>");
response.write(errorMessage);
response.write("</h1>");
response.write("<a href='index.html'>Home</a><br>");
response.write("</body>");
response.write("</html>");
response.close();
}
void saveEnquiry(Request &request,Response &response)
{
string n=request.get("nm");
string c=request.get("ct");
string a=request.get("ad");
string m=request.get("msg");
cout<<"Data received"<<endl;
cout<<"Name : "<<n<<endl;
cout<<"City : "<<c<<endl;
cout<<"Address : "<<a<<endl;
cout<<"Query : "<<m<<endl;
request.forward("SaveNotification.html");
}
void sam(Request &request,Response &response)
{
cout<<"Sam got called"<<endl;
request.forward("Indore.html");
}
void tom(Request &request,Response &response)
{
response.write("<!DOCTYPE HTML>");
response.write("<html lang='en'>");
response.write("<head>");
response.write("<meta charset='utf-8'>");
response.write("<title>The Clock</title>");
response.write("</head>");
response.write("<body>");
response.write("<h1>");
response.write("Response generated from Tom the great");
response.write("</h1>");
response.write("<a href='index.html'>Home</a><br>");
response.write("</body>");
response.write("</html>");
response.close();
}
int main()
{
TMWebProjector server(8080);
server.onRequest("/now",dispatchTime);
server.onRequest("/addEnquiry",saveEnquiry);
server.onRequest("/getCity",getCityView);
server.onRequest("/errorPage",createErrorPage);
server.onRequest("/ssss",sam);
server.onRequest("/YYYY",tom);
server.start();
return 0;
}