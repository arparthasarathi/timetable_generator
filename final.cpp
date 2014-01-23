#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <assert.h>


int index1,j,index2,index3,index4,test1,test2,test3,test4;



using namespace std;

void student_page();
void professor_page();
void admin_id_creation();
void admin_page();

class login

{
protected:
       
    int i,flag,k;	
    vector<string> l_in,p_in;
	string l,p;
    string u_name,p_word;

public:
     
    void lpage()
    {
        ifstream login_in("login.txt");  
       	ifstream password_in("password.txt");
       	vector<string> r_in;
        string r;
        int c=0;

      
        ifstream stu_details_roll_in("stu_roll.txt");
        
        
        while(getline(stu_details_roll_in, r))
        {
                               r_in.push_back(r);
        }

	    while(getline(login_in, l))
	    {
                                l_in.push_back(l);
                                c++;
         }

	
    	while(getline(password_in, p))
	    {
                                p_in.push_back(p);
        }
      
      
        
        if(c==0)
        {
                                    admin_id_creation();
                                    }     
        
      
        
	
        cout<<"Username:\t";
        cin>>u_name;
        
        cout<<"Password:\t";
        cin>>p_word;
  
        cin.get();
        
            
                            
        
    
        for(i=1;i<=l_in.size();i++)
        
        {//1                                                           
                          
                                    
                       if(u_name==l_in[0]) 
                       {//2
                                          test3=1;
                        if(p_word==p_in[0])
                       { //3
                                          test2=1;
                         admin_page();
                         break;
                         }//4
                       }//5
    
                       while(l_in[i].size()==6)
                       {//6
                         if(u_name==l_in[i]) 
                         { //7                 
                                            test3=1;
                                            if( p_word==p_in[i])
                       {//8
                        professor_page();
                         flag=1;
                         test2=1;
                         if(i%2==0)
                         {//9
                         index1=i;
                         }//10
                         else
                         index1=i+1;
                         break;
                         }    //11                   
                        }//12
                        }//13
                        
                        if(flag==1)
                        break;
    
                        if(u_name==l_in[i])
                        {    //14             
                                           test3=1;
                                           if(p_word==p_in[i])
                        {//15
                        index2=i;
                        test2=1;
                        for(k=0;k<=r_in.size();k++)
                        {//16
                         if(u_name==r_in[k])
                        {    //17               
                        index1=k;
                        break;
                        }//18
                        }//19
                       }//20
                        student_page();
                        break;
                      }//21
                      
                      
                      
                       if(l_in[1]=="\0")
                   {//22
                       cout<<"\nThe details are not added\nPlease contact Admin";
                       break;
                   }//23
                     
                             
                               
                   
                      
}                                          
                      if(test3!=1)
                      cout<<"\nInvalid Username";
                      
                      if(test2!=1)
                      cout<<"\nWrong password";
                                

                      
            
    

                      

    login_in.close();
    password_in.close();
    stu_details_roll_in.close();
    cin.get();
    
                        
	
  }
  
}l_page;

class student : public login

{

protected:  
        
      int k;
      vector<string> s_in;
      string s;	
      
      struct assignment
      {
             string a,b,c,d,e;
      }x[10];

public:
              
      void stu_id_creation()


      {
          ofstream login_on;
          login_on.open ("login.txt", fstream::in | fstream::out | fstream::ate); 
          ofstream password_on;
          password_on.open("password.txt", fstream::in | fstream::out | fstream::ate);
            
          ifstream stu_details_in("stu_details.txt"); 
          vector<string> s_in;
          string s;
           
           while(getline(stu_details_in,s))
           {
               s_in.push_back(s);
           }       

           for(i=1;i<=s_in.size()/5;i++)
           {                
                            
                            login_on<<2011239000+i<<"\n";             
                            password_on<<2011239000+i<<"\n";
                            index4=i;
           }
           
           login_on.close();
           password_on.close();
          
           
     }        
        


      void stu_sort()
      {
              
          	ifstream password_in("password.txt");
            ifstream login_in("login.txt");

             while(getline(login_in, l))
             
             {

                                     l_in.push_back(l);
             }

	
    	    while(getline(password_in, p))
	        {
                                       p_in.push_back(p);
            }
         
            ifstream stu_details_in("stu_details.txt");
           
   
            ofstream stu_details_roll_on;
            stu_details_roll_on.open("stu_roll.txt");
   
            while(getline(stu_details_in, s))
            {
                                       s_in.push_back(s);
            }
   
            for(i=0,j=0;i<s_in.size(),j<s_in.size()/5;j++,i+=5)
            {
        
                                x[j].a.assign(s_in[i]);
                                x[j].b.assign(s_in[i+1]);
                                x[j].c.assign(s_in[i+2]);
                                x[j].d.assign(s_in[i+3]);
                                x[j].e.assign(s_in[i+4]);
                                
           }
    
            for(j=0;j<s_in.size()/5;j++)
            {
                    for(i=j;i<s_in.size()/5;i++)
                     {
                                    if(x[i+1].a=="\0")
                                    break;
           
                                    if(x[j].a>x[i+1].a)
                           {                             
                                          string temp;
                                          temp=x[j].a;
                                          x[j].a=x[i+1].a;
                                          x[i+1].a=temp;  
                                          temp=x[j].b;
                                          x[j].b=x[i+1].b;
                                          x[i+1].b=temp;  
                                          temp=x[j].c;
                                          x[j].c=x[i+1].c;
                                          x[i+1].c=temp;  
                                          temp=x[j].d;
                                          x[j].d=x[i+1].d;
                                          x[i+1].d=temp;  
                                          temp=x[j].e;
                                          x[j].e=x[i+1].e;
                                          x[i+1].e=temp;                                                                                                                                    
                           }
                    }
          }
     
          for(j=0;j<s_in.size()/5;j++)
          {                          
                                 stu_details_roll_on<<l_in[j+1]<<"\n";
                                 stu_details_roll_on<<x[j].a<<"\n"<<x[j].b<<"\n"<<x[j].c<<"\n"<<x[j].d<<"\n"<<x[j].e<<"\n";
          }
          
         
          
                                     
     stu_details_roll_on.close();
     stu_details_in.close();
     login_in.close();
     password_in.close();
     cin.get();

}

     void stu_adddetails()
     
     {
            ifstream stu_details_in("stu_details.txt");
            while(getline(stu_details_in, s))
            {
                               s_in.push_back(s);
            }
          
            int n,o,m;
          
            string stuname,fathername,address,number;
         
            cout<<"\n\nNumber of new students\n\n";
            cin>>n;
            ifstream login_in("login.txt");  
          	ifstream password_in("password.txt");

	        while(getline(login_in, l))
            {
                                    l_in.push_back(l);
            }

	
    	    while(getline(password_in, p))
	        {
                                     p_in.push_back(p);
             }
          
             int tpr;
             string y;
             getline(cin,y);
          
             for(o=1,tpr=s_in.size()/5+o-1;o<=n;tpr++,o++)
          
             {
                    
                    cout<<"\nName of the student:\t";
                    getline(cin,stuname);
                    cout<<"\nFather's Name:\t";
                    getline(cin,fathername);
                    cout<<"\nAddress:\t";
                    getline(cin,address);
                    cout<<"\nContact Number:\t";
                    getline(cin,number);
                    x[tpr].a.assign(stuname);
                    x[tpr].b.assign(fathername);
                    x[tpr].c.assign(address);
                    x[tpr].d.assign(number);
                                          
          
          }
          
          char temp;
          
          for(o=1,tpr=s_in.size()/5+o-1;o<=n;tpr++,o++)
          {
                          for(m=tpr;m<=tpr;m++)
                          {
                                      
                                    if(x[m+1].a=="\0")
                                    break;
           
                                    if(x[tpr].a>x[m+1].a)
          
                           {                             
          
                                          string temp;
                                          temp=x[tpr].a;
                                          x[tpr].a=x[m+1].a;
                                          x[m+1].a=temp;  
                                          temp=x[tpr].b;
                                          x[tpr].b=x[m+1].b;
                                          x[m+1].b=temp;  
                                          temp=x[tpr].c;
                                          x[tpr].c=x[m+1].c;
                                          x[m+1].c=temp;  
                                          temp=x[tpr].d;
                                          x[tpr].d=x[m+1].d;
                                          x[m+1].d=temp;  
                                          
                           }
                           
                           }
          }

          long int num;
          
          for(o=1,tpr=s_in.size()/5+o-1;o<=n;tpr++,o++)
          {
          
          istringstream ( l_in[s_in.size()/5] ) >> num;
          
          ofstream login_on;
          login_on.open ("login.txt", fstream::in | fstream::out | fstream::ate); 
          
          ofstream password_on;
          password_on.open("password.txt", fstream::in | fstream::out | fstream::ate);
          
          ofstream stu_details_roll_on;
          stu_details_roll_on.open("stu_roll.txt",fstream::in | fstream::out | fstream::ate);
          
          login_on<<num+o<<"\n";
          password_on<<num+o<<"\n";
                              
          stu_details_roll_on<<num+o<<"\n";
          stu_details_roll_on<<x[tpr].a<<"\n"<<x[tpr].b<<"\n"<<x[tpr].c<<"\n"<<x[tpr].d<<"\n";
          
          login_on.close();
          password_on.close();
          
          }
          
          login_in.close();
          password_in.close();
                            
}   

    void stu_changepassword()

    {
         
        string new_pass;
        ifstream login_in("login.txt");
        ifstream password_in("password.txt");
        ofstream password_on;
        password_on.open("password1.txt");
        
          cout<<"Enter new password\t";
          cin>>new_pass;

           while(getline(login_in, l))

        {
           l_in.push_back(l);
        }

	
    	   while(getline(password_in, p))
	    {        
          
            int spot = p.find(l_in[index2]);
            
            if(spot >= 0)
            {
                  
                    string tmpstring = p.substr(0,spot);
                    tmpstring += new_pass;
                    tmpstring += p.substr(spot+l_in[index2].length(), p.length());
                    p = tmpstring;
            }
         
            password_on << p << endl;
          
         }
         
         
         login_in.close();
         password_in.close();
         password_on.close();
         test1=1;
         
         

   } 

    
                 
}stu_page;

class professor : public login

{

protected:  
        
      int k;
      vector<string> pro_in;
      string pro;	
      
      struct assignment
      {
             string a,b,c,d,e;
      }x[10];

public:
              
      void pro_id_creation()


      {
          ofstream login_on;
          login_on.open ("login.txt", fstream::in | fstream::out | fstream::ate); 
          ofstream password_on;
          password_on.open("password.txt", fstream::in | fstream::out | fstream::ate);
            
          ifstream pro_details_in("pro_details.txt"); 
          vector<string> pro_in;
          string pro;
           
           while(getline(pro_details_in,pro))
           {
               pro_in.push_back(pro);
           }       

           for(i=1;i<=pro_in.size()/5;i++)
           {                
                            
                            login_on<<201100+i<<"\n";             
                            password_on<<201100+i<<"\n";
                            index3=i;
           }
           
           login_on.close();
           password_on.close();
          
           
     }        
        


      void pro_sort()
      {
              
          	ifstream password_in("password.txt");
            ifstream login_in("login.txt");

             while(getline(login_in, l))
             
             {

                                     l_in.push_back(l);
             }

	
    	    while(getline(password_in, p))
	        {
                                       p_in.push_back(p);
            }
         
            ifstream pro_details_in("pro_details.txt");
            ofstream pro_details_roll_on;
            pro_details_roll_on.open("pro_roll.txt");
   
            while(getline(pro_details_in, pro))
            {
                                       pro_in.push_back(pro);
            }
   
            for(i=0,j=0;i<pro_in.size(),j<pro_in.size()/5;j++,i+=5)
            {
        
                                x[j].a.assign(pro_in[i]);
                                x[j].b.assign(pro_in[i+1]);
                                x[j].c.assign(pro_in[i+2]);
                                x[j].d.assign(pro_in[i+3]);
                                x[j].e.assign(pro_in[i+4]);
                                
           }
    
            for(j=0;j<pro_in.size()/5;j++)
            {
                    for(i=j;i<pro_in.size()/5;i++)
                     {
                                    if(x[i+1].a=="\0")
                                    break;
           
                                    if(x[j].a>x[i+1].a)
                           {                             
                                          string temp;
                                          temp=x[j].a;
                                          x[j].a=x[i+1].a;
                                          x[i+1].a=temp;  
                                          temp=x[j].b;
                                          x[j].b=x[i+1].b;
                                          x[i+1].b=temp;  
                                          temp=x[j].c;
                                          x[j].c=x[i+1].c;
                                          x[i+1].c=temp;  
                                          temp=x[j].d;
                                          x[j].d=x[i+1].d;
                                          x[i+1].d=temp;  
                                          temp=x[j].e;
                                          x[j].e=x[i+1].e;
                                          x[i+1].e=temp;                                                                                                                                    
                           }
                    }
          }
     
          for(j=0;j<pro_in.size()/5;j++)
          {                          
                                 pro_details_roll_on<<l_in[j+index4+1]<<"\n";
                                 pro_details_roll_on<<x[j].a<<"\n"<<x[j].b<<"\n"<<x[j].c<<"\n"<<x[j].d<<"\n"<<x[j].e<<"\n";
          }
          
         
          
                                     
     pro_details_roll_on.close();
     pro_details_in.close();
     login_in.close();
     password_in.close();
     cin.get();

}

     void pro_adddetails()
     
     {
            ifstream pro_details_in("pro_details.txt");
            while(getline(pro_details_in, pro))
            {
                               pro_in.push_back(pro);
            }
          
            int n,o,m;
          
            string proname,fathername,address,number;
         
            cout<<"\n\nNumber of new professors\n\n";
            cin>>n;
            ifstream login_in("login.txt");  
          	ifstream password_in("password.txt");

	        while(getline(login_in, l))
            {
                                    l_in.push_back(l);
            }

	
    	    while(getline(password_in, p))
	        {
                                     p_in.push_back(p);
             }
          
             int tpr;
             string y;
             getline(cin,y);
          
             for(o=1,tpr=pro_in.size()/5+o-1;o<=n;tpr++,o++)
          
             {
                    
                    cout<<"\nName of the professor:\t";
                    getline(cin,proname);
                    cout<<"\nFather's Name:\t";
                    getline(cin,fathername);
                    cout<<"\nAddress:\t";
                    getline(cin,address);
                    cout<<"\nContact Number:\t";
                    getline(cin,number);
                    x[tpr].a.assign(proname);
                    x[tpr].b.assign(fathername);
                    x[tpr].c.assign(address);
                    x[tpr].d.assign(number);
                                          
          
          }
          
          char temp;
          
          for(o=1,tpr=pro_in.size()/5+o-1;o<=n;tpr++,o++)
          {
                          for(m=tpr;m<=tpr;m++)
                          {
                                      
                                    if(x[m+1].a=="\0")
                                    break;
           
                                    if(x[tpr].a>x[m+1].a)
          
                           {                             
          
                                          string temp;
                                          temp=x[tpr].a;
                                          x[tpr].a=x[m+1].a;
                                          x[m+1].a=temp;  
                                          temp=x[tpr].b;
                                          x[tpr].b=x[m+1].b;
                                          x[m+1].b=temp;  
                                          temp=x[tpr].c;
                                          x[tpr].c=x[m+1].c;
                                          x[m+1].c=temp;  
                                          temp=x[tpr].d;
                                          x[tpr].d=x[m+1].d;
                                          x[m+1].d=temp;  
                                          
                           }
                           
                           }
          }

          long int num;
          
          for(o=1,tpr=pro_in.size()/5+o-1;o<=n;tpr++,o++)
          {
          
          istringstream ( l_in[pro_in.size()/5] ) >> num;
          
          ofstream login_on;
          login_on.open ("login.txt", fstream::in | fstream::out | fstream::ate); 
          
          ofstream password_on;
          password_on.open("password.txt", fstream::in | fstream::out | fstream::ate);
          
          ofstream pro_details_roll_on;
          pro_details_roll_on.open("pro_roll.txt",fstream::in | fstream::out | fstream::ate);
          
          login_on<<num+o<<"\n";
          password_on<<num+o<<"\n";
          
          }
}
    
    void pro_changepassword()

    {
         
        string new_pass;
        ifstream login_in("login.txt");
        ifstream password_in("password.txt");
        ofstream password_on;
        password_on.open("password1.txt");
        
          cout<<"Enter new password\t";
          cin>>new_pass;

           while(getline(login_in, l))

        {
           l_in.push_back(l);
        }

	
    	   while(getline(password_in, p))
	    {        
          
            int spot = p.find(l_in[index2]);
            
            if(spot >= 0)
            {
                  
                    string tmpstring = p.substr(0,spot);
                    tmpstring += new_pass;
                    tmpstring += p.substr(spot+l_in[index2].length(), p.length());
                    p = tmpstring;
            }
         
            password_on << p << endl;
          
         }
         
         
         login_in.close();
         password_in.close();
         password_on.close();
         test1=1;
         
         

   } 


                 
}pro_page;


          void student_page()
          {
      
       
               char fname1[]="password.txt",fname2[]="password1.txt";
               vector<string> r_in;
               string r;
               system("CLS");
               int spage;
               cout<<"\n1.Details\n\n2.Change password";
               cout<<"\n\nEnter the choice:\t";
               cin>>spage;
      
               ifstream stu_details_roll_in("stu_roll.txt");
      
               while(getline(stu_details_roll_in, r))
               {
                               r_in.push_back(r);
               }
      
               switch(spage)
               {
                   case 1:  cout<<"\n\nRoll No:\t"<<r_in[index1];
                            cout<<"\nName:\t"<<r_in[index1+1];
                            break;
                            
                   case 2: stu_page.stu_changepassword();
                           break;
              } 
                
      stu_details_roll_in.close();
      cin.get();
      
      }
      void professor_page()
          {
      
       
               char fname1[]="password.txt",fname2[]="password1.txt";
               vector<string> r_in;
               string r;
               system("CLS");
               int ppage;
               cout<<"\n1.Details\n\n2.Change password";
               cout<<"\n\nEnter the choice:\t";
               cin>>ppage;
      
               ifstream pro_details_roll_in("pro_roll.txt");
      
               while(getline(pro_details_roll_in, r))
               {
                               r_in.push_back(r);
               }
      
               switch(ppage)
               {
                   case 1:  cout<<"\n\nRoll No:\t"<<r_in[index1];
                            cout<<"\nName:\t"<<r_in[index1+1];
                            break;
                            
                   case 2: pro_page.pro_changepassword();
                           break;
              } 
                
      pro_details_roll_in.close();
      cin.get();
      
      }

      void admin_id_creation()

      {
           ofstream password_on;
           password_on.open("password.txt");
           ofstream login_on;
           login_on.open("login.txt");
          
           login_on<<"administrator"<<"\n";
           password_on<<"abc123"<<"\n";
          
           login_on.close();
           password_on.close();
          
      }         



      void admin_page()

      {
     
           int apage;
           system("CLS");
           cout<<"\n\t\t\tSelect the operation to be performed\n\n";
           cout<<"\n\t\t\t1.Student's Database Creation\n\t\t\t2.Professor's Database Creation\n\t\t\t3.Addition of New Student\n\t\t\t4.Addition of Professor\n\t\t\t5.Batches\n\t\t\t6.Courses\n\t\t\t7.Back to Homepage\n\n";
           
           while(apage!=7)
           {
         
                           cout<<"\n\nEnter the action to be performed:\t";
                             cin>>apage;
                             switch(apage)
           {    
                   case 1:       {
                                 vector<string> l_in;
                                 string l;
                                 ifstream login_in("login.txt");
	                             while(getline(login_in, l))
                                 {

                                                         l_in.push_back(l);
                                 }
                                
                                 {                        
                                 stu_page.stu_id_creation();
                                 stu_page.stu_sort();
                                 cout<<"Details Added";
                                 }
                                 
                                 login_in.close();
                                 }
                                 cin.get();
                                 break;
                            
                   case 2:        {
                                 vector<string> l_in,s_in;
                                 string l,s;
                                 ifstream login_in("login.txt");
                                 
	                             while(getline(login_in, l))
                                 {

                                                         l_in.push_back(l);
                                 }
                                 
                                  
                                  
                                 {                        
                                 pro_page.pro_id_creation();
                                 pro_page.pro_sort();
                                 cout<<"Details Added";
                                 }
                         
                                
                                 login_in.close();
                                 }
                                 cin.get();
                                 break;       
                                 
                   case 3:       stu_page.stu_adddetails();
                                 cout<<"Details Added"; 
                                 break;
                   
                   case 4:        pro_page.pro_adddetails();
                                 cout<<"Details Added"; 
                                 break;
                   
                   case 7:       l_page.lpage();
                                 break;
                                 
                   default:      cout<<"Please select the appropiate option\n\n";       
      }
      }
    
}

int main()
{
      
      l_page.lpage();
      if(test1==1) 
      {
      remove("password.txt");
      rename("password1.txt","password.txt");
      }
      
}
