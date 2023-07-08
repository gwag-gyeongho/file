#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS


typedef struct student{
    int id;
    int esruoc;
    struct student *left;
    struct student *right;
}student;

typedef struct class{
    student * std;
}class;

int inp=0;
int read=0;
int outp=0;
class priv[35];

void init()
{
    int i;
    for(i=0;i<35;i++)
        priv[i].std=NULL;
}



void sdelete(int cl,int info)
{
    FILE *in = fopen("result.txt", "a");
    if(cl<100 && cl>134 || info<2000 && info>2499)
    {
        fprintf(in,"%d     %d     A    **out of class ID**\n",info,cl);
        fclose(in);
        return;
    }
    else if(info<2000 || info>2499)
    {
        fprintf(in,"%d     %d     A    **out of student ID**\n",info,cl);
        fclose(in);
        return;
    }
    student * cur;
    if(priv[cl-100].std==NULL)
    {
        fprintf(in,"%d    %d      D    **NOT exist student**\n",info,cl);
        fclose(in);
        return;
    }
    int tf=0;
    for(cur=priv[cl-100].std;cur->right!=NULL;cur=cur->right)
    {
        if(cur->id==info)
            break;
    }
    if(cur->id==info)
    {
        if(cur==priv[cl-100].std)
        {
            priv[cl-100].std=cur->right;
        }
        else if(cur->right==NULL)
        {
            cur->left->right=NULL;
        }
        else
        {
            cur->left->right=cur->right;
            cur->right->left=cur->left;
        }
        outp++;
        free(cur);
    }
    else
    {
        fprintf(in,"%d      %d      D      **NOT exist student**\n",info,cl);
    }
    fclose(in);
}

void sinsert(int cl,int info)
{
    FILE *in = fopen("result.txt", "a");
    if(cl<100 || cl>134)
    {
        fprintf(in,"%d      %d      A      **out of class ID**\n",info,cl);
        fclose(in);
        return;
    }
    else if(info<2000 || info>2499)
    {
        fprintf(in,"%d      %d      A      **out of student ID**\n",info,cl);
        fclose(in);
        return;
    }

    int k = cl-100;
    
    student * i;
    if(priv[k].std!=NULL)
    {
        for(i=priv[k].std;i->id!=info;i=i->right)
        {
            if(i->right==NULL)
                break;
        }
        if(i->id==info)
        {
            fprintf(in,"%d      %d      A      **already class have student**\n",info,cl);
            fclose(in);
            return;
        }
        
        student * a;
        a=(student*)malloc(sizeof(student));
        inp++;
        a->id=info;
        a->esruoc=cl;
        a->right=priv[k].std;
        a->left=NULL;
        priv[k].std=a;
        a->right->left=a;
    }
    else
    {
        student * dm;
        dm=(student*)malloc(sizeof(student));
        inp++;
        dm->id=info;
        dm->esruoc=cl;
        dm->left=NULL;
        priv[k].std=dm;
        dm->right=NULL;
    }
    fclose(in);
}

int main()
{
    int number=1;
    int cl,info;
    char c;
    init();
    char buff[30];
    int a=0,b=0;
    FILE *in = fopen("input.txt","r");
    fgets(buff, sizeof(buff), in);
    int i;
    while(buff[0]!='E'&&buff[1]!='O'&&buff[2]!='F')
    {
        for(i=0;i<10;i++)
        {
            if(buff[i]>='0'&&buff[i]<='9')
            {
                a=a*10+(int)buff[i]-48;
            }
        }
        for(i=10;i<20;i++)
        {
            if(buff[i]>='0'&&buff[i]<='9')
            {
                b=b*10+(int)buff[i]-48;
            }
        }
        for(i=20;i<30;i++)
        {
            if(buff[i]=='\0')
                break;
            if(buff[i]>='A'&&buff[i]<='Z')
            {
                c=buff[i];
                break;
            }
        }
        if(c=='A')
        {
            sinsert(b,a);
        }
        else if(c=='D')
        {
            sdelete(b,a);
        }
        else
        {
            FILE *le = fopen("result.txt","a");
            fprintf(le,"NOT A or D\n");
            fclose(le);
        }
        fgets(buff, sizeof(buff), in);
        a=0;
        b=0;
    }


    FILE *le = fopen("result.txt","a");
    fprintf(le,"-------------------------------------\n");
    for(i=0;i<35;i++)
    {
        if(priv[i].std==NULL)
        {
            continue;
        }
        student * cur;
        cur=priv[i].std;
        fprintf(le,"%d:      ",i+100);
        while(cur->right!=NULL)
        {
            fprintf(le,"%d      ",cur->id);
            cur=cur->right;
        }
        fprintf(le,"%d\n",cur->id);
    }
    fprintf(le,"\n\n\n");
    fprintf(le,"read : %d    input : %d    canel : %d\n",read,inp,outp);
    fprintf(le,"-------------------------------------\n");
    fclose(le);
    return 0;
}