#include <iostream>
using namespace std;
typedef struct Hcode
{
    int code[100];   
    int start;           
};
typedef struct
{
	char ch;
    int weight;
    int parent;
    int leftchild;
    int rightchild;	
}Huffman;

Huffman huffman[100];
Hcode code[100];

void HuffmanTree(int n)
{
	int a,b,c,d;
    for(int i=0;i<n*2-1;i++)
	{
        huffman[i].weight=0;
        huffman[i].parent=-1;
        huffman[i].leftchild=-1;
        huffman[i].rightchild=-1;
    }
    printf("\n请输入哈夫曼字符（中间以空格相间） ");
    for(int i=0;i<n;i++){
		cin>>huffman[i].ch;
	} 
	printf("\n请输入哈夫曼权重（中间以空格相间） ");
	for(int i=0;i<n;i++){	
		scanf("%d",&huffman[i].weight);
	} 
    for(int i=0;i<n-1;i++)
	{
        a=b=-1;
        c=d=10000;
        for(int j=0;j<n+i;j++)
		{
            if(huffman[j].parent==-1 && huffman[j].weight<c)
			{
                d=c;
                b=a;
                a=j;
                c=huffman[j].weight;
            }
            else if (huffman[j].parent==-1 && huffman[j].weight<d)
			{
                b=j;
                d=huffman[j].weight;
            }
        }
        huffman[n+i].leftchild=a;
        huffman[n+i].rightchild=b;
        huffman[n+i].weight=c+d;
        huffman[a].parent=n+i;
        huffman[b].parent=n+i;
    }
}
void printHuffmanTree(int n)
{
    Hcode tcode;
    int cParent;
    int c;
    for(int i = 0;i<n;i++){
        tcode.start=n-1;
        c=i;
        cParent=huffman[i].parent;
        while(cParent !=-1)
		{
            if(huffman[cParent].leftchild ==c)
			{
                tcode.code[tcode.start] = 0;
            }
            else
			{
                tcode.code[tcode.start] = 1;
            }
            tcode.start--;
            c=cParent;
            cParent=huffman[c].parent;
        }
        for(int j=tcode.start+1;j<n;j++)
		{
            code[i].code[j] = tcode.code[j];
        }
        code[i].start = tcode.start;
    }
}
int main()
{
	int n;
    cout<<"输入哈夫曼字符个数:"<<endl;
    cin>>n;
    HuffmanTree(n);
    printHuffmanTree(n);
    for (int i=0;i<n;++i)
	{
        printf("%c的哈夫曼编码为:",huffman[i].ch);
        for(int j=code[i].start+1;j<n;++j)
		{
              cout<<code[i].code[j];
        }
        cout<<endl;
    }
    return 0;
}

