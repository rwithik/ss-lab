#include<bits/stdc++.h>

int main()
{
 FILE *f1,*f2,*f3,*f4,*f5;
 int i,len;
 char opcode[20],operand[20],label[20],name[20],opcode1[20],operand1[20],arg[20];
 f1=fopen("minp2.txt","r");
 f2=fopen("ntab2.txt","r");
 f3=fopen("dtab2.txt","r");
 f4=fopen("atab2.txt","w+");
 f5=fopen("op2.txt","w");
 fscanf(f1,"%s%s%s",label,opcode,operand);
 while(strcmp(opcode,"END")!=0)
 {
  if(strcmp(opcode,"MACRO")==0)
  {
   fscanf(f1,"%s%s%s",label,opcode,operand);
   while(strcmp(opcode,"MEND")!=0)
   fscanf(f1,"%s%s%s",label,opcode,operand);
  }
  else
  {
   fscanf(f2,"%s",name);
   if(strcmp(opcode,name)==0)
   {
    len=strlen(operand);
    for(i=0;i<len;i++)
    {
     if(operand[i]!=',')
     fprintf(f4,"%c",operand[i]);
     else
     fprintf(f4,"\n");
    }
    fseek(f2,SEEK_SET,0);
    fseek(f4,SEEK_SET,0);
    fscanf(f3,"%s%s",opcode1,operand1);
    fprintf(f5,".\t%s\t%s\n",opcode1,operand);
    fscanf(f3,"%s%s",opcode1,operand1);
    while(strcmp(opcode1,"MEND")!=0)
    {
     if((operand1[0]=='&'))
     {
      fscanf(f4,"%s",arg);
      fprintf(f5,"-\t%s\t%s\n",opcode1,arg);
     }
     else
     fprintf(f5,"-\t%s\t%s\n",opcode1,operand1);
     fscanf(f3,"%s%s",opcode1,operand1);
    }
   }
   else
   fprintf(f5,"%s\t%s\t%s\n",label,opcode,operand);
  }
  fscanf(f1,"%s%s%s",label,opcode,operand);
 }
 fprintf(f5,"%s\t%s\t%s\n",label,opcode,operand);
 fprintf(f4,"\n");
 fclose(f1);
 fclose(f2);
 fclose(f3);
 fclose(f4);
 fclose(f5);
 return 0;
}
