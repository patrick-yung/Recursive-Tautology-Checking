#include <iostream>
#include <string>
#include <fstream>
using namespace std;




bool contain(string a, string b, int x){

  for(int n=0; n<x;n++){
    if(a[n]=='2'){  
      
    }else if(a[n]==b[n]){      
    }else{
      return false;
    }  
  }
  return true;
}

int quickSortA(int A[], int low, int high)
{
    int pivot = A[low];
    int count = 0;
    for (int i = low + 1; i <= high; i++) {
        if (A[i] <= pivot)
            count++;
    }
     int start = low + count;
    std::swap(A[start], A[low]);
     int i = low, j = high;
    while (i < start && j > start) {
        while (A[i] <= pivot) {
            i++;
        }
        while (A[j] > pivot) {
            j--;
        }
        if (i < start && j > start) {
            std::swap(A[i++], A[j--]);
        }
    }
    return start;
}
 
void quickSort(int A[], int low, int high)
{
    if (low >= high)
        return;
     int p = quickSortA(A, low, high);
     quickSort(A, low, p - 1);
     quickSort(A, p + 1, high);
}
 
/////////////////

std::string unate(std::string a, int x, int y){
  if(a.length()==x){
    return a;
  }
  std::string unqiue;
 std:: string final;
  for(int q=0;q<y;q++){
    std::string tmp=a.substr(q*x,x);

    //loop whole array//
    for(int w=0;w<y;w++){
      //Array same as tmp//
      
      if(w==q){
        w++;
      }
      int e=0;
      int dif=0;//check if different//
      int pos=-1;
      int f=0;
      int state=0;//check if contain//
      while(e<x){
        if(tmp[e]==a[w*x+e]){
          f++;
                      state++;

        }else{
    if((tmp[e]=='0'&&a[w*x+e]=='1')||(tmp[e]=='1'&&a[w*x+e]=='0')){
            //second chance//
            if(pos==-1){
            pos=e;
            }
            dif++;
          }else if(tmp[e]=='2'){
            //check if better
            dif++;
            f++;  
          }
        }
        //ROTATE//
        e++;
      }
      //if better add//

      
      if(f==x){
        if(final.find(tmp) != std::string::npos&&final.find(tmp)%x==0){
        }else{
            std::string bob=a.substr(w*x,x);
    
            if(unqiue.find(bob) != std::string::npos&&unqiue.find(bob)%x==0){
              }else{
                                     
              unqiue=unqiue+bob;
              }
          final=final+tmp;
        }
      }else if(dif==1&&state==x-1){
            std::string bob=a.substr(w*x,x);
    
            if(unqiue.find(bob) != std::string::npos&&unqiue.find(bob)%x==0){
              }else{
                           
              unqiue=unqiue+bob;
              }
        //is different by 1//
        tmp[pos]='2';
          if(final.find(tmp) != std::string::npos&&final.find(tmp)%x==0){
        }else{
            if(unqiue.find(bob) != std::string::npos&&unqiue.find(bob)%x==0){
              }else{
              
              unqiue=unqiue+bob;
              }
            final=final+tmp;
        }
      }
    }

    }


  
  //add all unqiue//
  for(int n=0;n<y;n++){
      
    std::string bob=a.substr(n*x,x);
     
    if(unqiue.find(bob) != std::string::npos&&unqiue.find(bob)%x==0){
        
      }else{
        if(final.find(bob) != std::string::npos&&final.find(bob)%x==0){
          }else{
              final=final+bob;   
          }
      }
  }
  if(final==a){
  return final;
   }else{ 
  return unate(final,x, final.length()/x); 
   }
  
}




int select(std::string a, const int x, const int y){
  int up[50], down[50], total[50], min[50];
  for(int q=0;q<x;q++){
    up[q]=0;
    down[q]=0;
    total[q]=0;
    min[q]=0;

  }
  for(int q=0;q<x*y;q++){
    if(a[q]=='1'){
      up[q%x]++;
      total[q%x]++;
    }else if(a[q]=='0'){
      down[q%x]++;
      total[q%x]++;
    }else if(a[q]=='2'){
      min[q%x]++;
    }
  }
  int max=0;
  int value=0;

  for(int n=0;n<x;n++){
    if(value<total[n]){
        value=total[n];
        max=n;
      }else if(value==total[n]&&min[n]<abs(up[n]-down[n])){
      value=total[n];
      max=n;
    } 
  }
  return max;
}

std::string merge(string a, string b, int x, int sel){
  string total="";
for(int n=0;n<a.length()/x;n++){
    std::string add=a.substr(n*x,x);
    int test=0;

   if(b.find(add)%x==0){
   total=total+add;
    test++;
    }   
  
  if(test==0){
   for(int m=0;m<b.length()/x;m++){     
     std::string better=b.substr(m*x,x);
     if(contain(better,add,x)&&m==b.length()/x-1){
       test++;
      total=total+add;
      break;
       } 
    }
  }
  if(test==0){
      add[sel]='1';
      total=total+add;
     }
  }

 for(int n=0;n<b.length()/x;n++){
    std::string add=b.substr(n*x,x);
    int test=0;

   if(a.find(add)%x==0){
   total=total+add;
    test++;
    }   
  
  if(test==0){
   for(int m=0;m<a.length()/x;m++){     
     std::string better=a.substr(m*x,x);
     if(contain(better,add,x)&&m==a.length()/x-1){
       test++;
      total=total+add;
      break;
       } 
    }
  }
  if(test==0){
      add[sel]='0';
      total=total+add;
     }
  } 
  return total; 
}

std::string simple(std::string a, int x, int y){
  //IF EMPTY
  if(a==""){
    return "";
  }
  std::string test;
  for(int q=0;q<x;q++){
    //All don't care condition//
    test=test+'2';
  }
  std::string annie;
  annie=unate(a,x,a.length()/x);
    if(annie.find(test) != std::string::npos&&annie.find(test)%x==0){
    return test;
    }

  if(annie.length() == x){
    return annie;
    }
  //UNATE//
  if(a.find(test) != std::string::npos&&a.find(test)%x==0){
    return a;
    }
 
  int sel=select(a,x,a.length()/x);
  std::string up="";
  std::string down="";

  
  for(int n=0;n<a.length()/x;n++){
    std::string add=a.substr(n*x,x);    
    add.replace(sel,1,"2");
    if(a[n*x+sel]=='1'){
    up=up+add;
    }else if(a[n*x+sel]=='0'){
    down=down+add;
    }else if(a[n*x+sel]=='2'){
    down=down+add;
    up=up+add;
    }
  }

  up=simple(up, x, up.length()/x);
  down=simple(down, x, down.length()/x);
  
  std::string total=merge(up,down, x, sel)+annie;

  return total;
}


//x is the size//
//y the number//
//0 is negative//
//1 is positive//
//2 is don't care//

string fool(string a,int x){
  string final="";
  for(int n=0;n<a.length()/x;n++){
    std::string add=a.substr(n*x,x); 
    if(final.find(add) != std::string::npos&&final.find(add)%x==0){
    }else{
        final=final+add;
    }
  }
  final = unate(final,x,final.length()/x);
  return final;
}



int main() {


  
   ifstream  my_file; 
   my_file.open("test1.txt"); 

    string v="";
    string b="";
  getline(my_file,v);
  getline(my_file,b);
  int x=0;
  int y=0;
  if(v.length()==1){
    x=v[0]-'0';
  }else if(v.length()==2){
    x=10*(v[0]-'0')+(v[1]-'0');
  }else if(v.length()==2){
    x=100*(v[0]-'0')+10*(v[1]-'0')+(v[2]-'0');
  } 
  if(b.length()==1){
    y=b[0]-'0';
  }else if(b.length()==2){
    y=10*(b[0]-'0')+(b[1]-'0');
  }else if(b.length()==2){
    y=100*(b[0]-'0')+10*(b[1]-'0')+100*(b[2]-'0');
  }

  

    std::string test2="";
    for(int n=0;n<y;n++){
      string str;
      getline(my_file,str);
      test2=test2+str;
    }
      my_file.close();
    std::string a="";
  a=simple(test2,x,y);
a=fool(a,x);
      cout<<x<<endl;
  cout<<a.length()/x<<endl;

   int tmp[50]={};
  for(int n=0;n<a.length()/x;n++){
     std::string yo=a.substr(n*x,x);
   for(int m=0; m<x;m++){
       tmp[n]+=yo[m]-'0';
      if(m!=x-1){
         tmp[n]=tmp[n]*10;
       }
     }
   }
  //SORT IT//
   quickSort(tmp, 0, a.length()/x-1);

  int max=0;
  for(int n=0;n<x-1;n++){
    max=max*10;
    max+=2;
  }
  
  for(int n=0;n<a.length()/x;n++){
    while(max>tmp[n]){
      cout<<"0";
      max=max/10;
    }
    cout<<tmp[n]<<endl;
  }
    return 0;
}
