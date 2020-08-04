#include<iostream>
using namespace std;

typedef struct BiTNode{
		char data;
		struct BiTNode *lchild,*rchild;
		
}BiTNode,*BiTree;

class Tree{
char data;
};

void CreateBiTree(BiTree &T)
{
    char ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else{
        T=new BiTNode;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}//���򴴽�������

void InOrderTraverse(BiTree T){
		if(T)
	{	
		InOrderTraverse(T->lchild);
		cout<<T->data;
		InOrderTraverse(T->rchild);
	}
};//���������

void PreOrderTraverse(BiTree T){
		if(T)
	{	
		cout<<T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
};//���������
void PostOrderTraverse(BiTree T){
		if(T)
	{	
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout<<T->data;
	}
};//���������





//�ڵ����
int NodeCount(BiTree T)
{
	if(T==NULL)return 0;
	else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
};





//Ҷ�ڵ����
int LeafNodeCount(BiTree T ){
       if(T==NULL)return 0;

	   if((T->lchild==NULL)&&(T->rchild==NULL))
		   return 1;

	   else return LeafNodeCount(T->lchild)+LeafNodeCount(T->rchild);
};


//�����������
int Depth(BiTree T){ 
	int m,n; 
	if(T==NULL)	return 0;
	 else{
		m=Depth(T->lchild);
		n=Depth(T->rchild);
		if(m>n)return (m+1);
		else return(n+1);		 
	 }

}; 
//����
void exchange(BiTree T){
		BiTree change;
	if(T!=NULL)
	{
	change=T->lchild;
	T->lchild=T->rchild;
	T->rchild=change;
	exchange(T->lchild);
	exchange(T->rchild);
	}
};
//˫�����������
void doublebianli(BiTree T)
{
	if(T)
	{
		cout<<T->data;
		doublebianli(T->lchild);
		cout<<T->data;
		doublebianli(T->rchild);
	}
}

void main(){
BiTree T;
cout<<"�����������:";
CreateBiTree(T);
cout<<endl<<"����������:";
PreOrderTraverse(T);
cout<<endl<<"����������:";
InOrderTraverse(T);
cout<<endl<<"����������:";
PostOrderTraverse(T);
cout<<endl<<"Ҷ�ӽڵ�����"<<LeafNodeCount(T);
cout<<endl<<"���ĸ���:"<<NodeCount(T);
cout<<endl<<"�������:"<<Depth(T);
cout<<endl<<"����������ÿ���������Ӻ��Һ��ӣ�";
exchange(T);
cout<<endl<<"����������:";
PreOrderTraverse(T);
cout<<endl<<"˫�������������"<<endl;
doublebianli(T);
cout<<endl<<"succeed."<<endl;
}














