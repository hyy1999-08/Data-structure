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
}//先序创建二叉树

void InOrderTraverse(BiTree T){
		if(T)
	{	
		InOrderTraverse(T->lchild);
		cout<<T->data;
		InOrderTraverse(T->rchild);
	}
};//中序遍历法

void PreOrderTraverse(BiTree T){
		if(T)
	{	
		cout<<T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
};//先序遍历法
void PostOrderTraverse(BiTree T){
		if(T)
	{	
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout<<T->data;
	}
};//后序遍历法





//节点个数
int NodeCount(BiTree T)
{
	if(T==NULL)return 0;
	else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
};





//叶节点个数
int LeafNodeCount(BiTree T ){
       if(T==NULL)return 0;

	   if((T->lchild==NULL)&&(T->rchild==NULL))
		   return 1;

	   else return LeafNodeCount(T->lchild)+LeafNodeCount(T->rchild);
};


//计算树的深度
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
//交换
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
//双序遍历二叉树
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
cout<<"先序遍历输入:";
CreateBiTree(T);
cout<<endl<<"先序遍历输出:";
PreOrderTraverse(T);
cout<<endl<<"中序遍历输出:";
InOrderTraverse(T);
cout<<endl<<"后序遍历输出:";
PostOrderTraverse(T);
cout<<endl<<"叶子节点数："<<LeafNodeCount(T);
cout<<endl<<"结点的个数:"<<NodeCount(T);
cout<<endl<<"树的深度:"<<Depth(T);
cout<<endl<<"交换二叉树每个结点的左孩子和右孩子：";
exchange(T);
cout<<endl<<"先序遍历输出:";
PreOrderTraverse(T);
cout<<endl<<"双序遍历二叉树："<<endl;
doublebianli(T);
cout<<endl<<"succeed."<<endl;
}














