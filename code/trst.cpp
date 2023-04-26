#include<iostream>
#include<cstring>

void GetNext(char* p,int next[])  
{  
    int pLen = strlen(p);  
    next[0] = -1;  
    int k = -1;  
    int j = 0;  
    while (j < pLen - 1)  
    {  
      if (k == -1 || p[j] == p[k])   
      {  
        ++k;  
        ++j;  
        next[j] = k;  
      }  
      else   
      {  
        k = next[k];  
      }  
  }  
}  

int main(){
  char p[20] = {'1','2','1','2','A','1','2','1','2','B'};
  // char p[20] = {'A','B','A','C','D','A','B','A','B','C'};
  int n[20];
  GetNext(p,n);
  for (int i=0; i<10; i++){
    std::cout << n[i];
  }
  return 0;
}

