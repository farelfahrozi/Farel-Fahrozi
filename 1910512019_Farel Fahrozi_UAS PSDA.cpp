
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

typedef struct Node
{
    int data;
    Node *kiri;
    Node *kanan;
};

Node *Pohon = NULL;

using namespace std;

void insertnode (Node **root, int databaru)
{
    if ((*root)==NULL)
       {
        Node *baru;
        baru = new Node;
        baru->data=databaru;
        baru->kiri=NULL;
        baru->kanan=NULL;
        (*root) = baru;
        (*root) -> kiri = NULL;
        (*root) -> kanan = NULL;
        printf("Data Dimasukkan Ke Dalam Tree");
       }
    else if (databaru<(*root)->data)
              insertnode(&(*root)->kiri,databaru);
    else if (databaru>(*root)->data)
        insertnode(&(*root)->kanan,databaru);
    else if (databaru==(*root)->data)
        printf("Data Sudah Ada Dalam Tree");
}

void preOrder(Node *root)
{
    if(root!=NULL)
    {
        if(root->data!=NULL)
        {
            printf("%d ",root->data);
        }
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node *root)
{
       if(root!=NULL)
       {
           inOrder(root->kiri);
           if(root->data!=NULL)
           {
               printf("%d ",root->data);
           }
           inOrder(root->kanan);
        }
}

void postOrder(Node *root)
{
       if(root!=NULL)
       {
         postOrder(root->kiri);
         postOrder(root->kanan);
         if(root->data!=NULL)
         {
            printf("%d ",root->data);
         }
       }
}

int count(Node *root)
{
       if(root==NULL)
              return 0;
       else
              return count(root->kiri)+ count(root->kanan)+1;
}

int height(Node *root)
{
       if(root == NULL)
              return -1;
       else{
              int u = height(root->kiri);
        int v = height(root->kanan);
        if(u > v)
          return u + 1;
        else
          return v + 1;
       }
}

void search(Node **root, int cari)
{
    if((*root) == NULL)
    {
        printf("TIDAK DITEMUKAN");
    }

    else if(cari < (*root)->data)
        search(&(*root)->kiri,cari);
    
    else if(cari > (*root)->data)
        search(&(*root)->kanan,cari);

    else if(cari == (*root)->data)
        printf("DITEMUKAN");
}

int Max(struct Node* root) 
{ 
    if (root == NULL) 
      return INT_MIN; 
    int res = root->data; 
    int lres = Max(root->kiri); 
    int rres = Max(root->kanan); 
    if (lres > res) 
      res = lres; 
    if (rres > res) 
      res = rres; 
    return res; 
} 

int Min(struct Node* root) 
{ 
    if (root == NULL) 
      return INT_MAX; 
    int res = root->data; 
    int lres = Min(root->kiri); 
    int rres = Min(root->kanan); 
    if (lres < res) 
      res = lres; 
    if (rres < res) 
      res = rres; 
    return res; 
} 

void hapus(Node **root, int del)
{
       Node *curr;
       Node *parent;
       curr = (*root);

       bool flag = false;
  
       while(curr != NULL)
       {
              if(curr->data == del)
              {
                     flag = true;
  
                      break;
              }
              else
              {
                  parent = curr;
                  if(del>curr->data)
                     curr = curr->kanan;
                  else
                     curr = curr->kiri;
              }
       }

    if(!flag)
    {
        cout<<" Node Tidak Ada Dalam Tree"<<endl;
        return;
    }
    
       if(height(Pohon) == 0)
       {
              if( curr->kiri== NULL && curr->kanan == NULL)
              {
                     (*root) = NULL;
                    
                     return;
              }
       }

       else if(height(Pohon) > 0)
       {
              if( curr->kiri== NULL && curr->kanan == NULL)
              {
                     if(parent->kiri == curr)
                     {
                           parent->kiri = NULL;
                           delete curr;
                     }
                     else
                     {
                           parent->kanan = NULL;
                           delete curr;
                     }

                     return;
              }

              if((curr->kiri == NULL && curr->kanan != NULL)|| (curr->kiri != NULL && curr->kanan == NULL))
              {
                     if(curr->kiri == NULL && curr->kanan != NULL)
                     {
                           if(parent->kiri == curr)
                           {
                              parent->kiri = curr->kanan;
                              delete curr;
                         }
                         else 
                         {
                              parent->kanan = curr->kanan; 
                              delete curr;
                         }
                     }
                  else
                  {
                           if(parent->kiri == curr)
                           {
                                  parent->kiri = curr->kiri; 
                                  delete curr;
                           }
                           else 
                           {
                               parent->kanan = curr->kiri; 
                               delete curr;
                            }
                   }
                   return;
              }


              if (curr->kiri != NULL && curr->kanan != NULL)
              {
                     Node* bantu;
                     bantu = curr->kanan;

                     if((bantu->kiri == NULL) && (bantu->kanan == NULL))
                     {

                           curr = bantu;
                           delete bantu;
                           curr->kanan = NULL;
                     }
                     else 
                     {
                           if((curr->kanan)->kiri != NULL)
                           {
                                  Node* bantu2;
                                  Node* bantu3; 
                                  bantu3 = curr->kanan;         
                                  bantu2 = (curr->kanan)->kiri; 

                                  while(bantu2->kiri != NULL)
                                  {
                                         bantu3 = bantu2;
                                         bantu2 = bantu2->kiri;
                                  }
                                  curr->data = bantu2->data;
                                  delete bantu2;
                                  bantu3->kiri = NULL;
                        }
                        else 
                        {
                              Node* tmp;
                              tmp = curr->kanan;
                              curr->data = tmp->data;
                              curr->kanan = tmp->kanan;
                              delete tmp;
                        }

                     }
                     return;
              }
       }
}



int main()
{
    char pil;
    int del,cari;
    while (true)
    {
        system("cls"); 
        char data;
        printf("\n\t==========================\n");
        printf("\t Binary Search Tree (BST)");
        printf("\n\t==========================\n");
        printf("\nMAIN PROGAM");
        printf("\n---------------------\n");
        printf("(1) Masukkan Data/Node \n");
        
        printf("(2) Melihat Node Dalam Preorder, Inorder, Postorder\n");
        
        printf("(3) Mencari Bilangan pada Tree \n");
        
        printf("(4) Menghapus Node\n");
        
        printf("(5) Menampilkan Nilai Terbesar dan Terkecil dalam Tree\n");
        
        printf("(6) Reset Tree\n");
        
        printf("(7) Exit Progam\n");
        
        printf("Pilihan Anda : ");
        scanf("%c",&pil);
        fflush(stdin); 
        switch(pil)
        {
            case '1':
                     printf("\n-------");
                     printf("\nMasukkan Data : ");
                     scanf("%d", &data);
                     insertnode(&Pohon,data);
                     _getch();
                      break;

            case '2':
                     printf("\n Data Dalam Preorder, Inorder, Postorder");
                     printf("\n------");
                     if(Pohon!=NULL)
                     {
                           printf("\nPreorder  : ");
                           preOrder(Pohon);
                           printf("\nInorder   : ");
                           inOrder(Pohon); 
                           printf("\nPostorder : ");
                           postOrder(Pohon); 
                     }else
                           printf("\nTree Masih kosong!");

                     _getch();
                     break;
                     
			case '3':
				
                     if(Pohon!=NULL)
                     {
                           printf("\n\nPENCARIAN DATA");
                           printf("\n--------------");
                           printf("\nMasukkan node yang ingin dicari : ");
                           scanf("%d", &cari);
                           search(&Pohon, cari);
               
                     }else
                           printf("\n Tree Masih Kosong");

                     _getch();
                     break;
                     
        	case '4':
             if(Pohon!=NULL)
                     if(Pohon!=NULL)
                     {
                           printf("\nSebelum Node dihapus : ");
                           printf("\n---------------------- ");

                           printf("\nPreorder  : ");
                           preOrder(Pohon); 
                           printf("\nInorder   : ");
                           inOrder(Pohon); 
                           printf("\nPostorder : ");
                           postOrder(Pohon); 
                           printf("\n\nPenghapusan Node : ");
                           printf("\n------------------\n");
                           printf("Masukkan data yang ingin dihapus: ");
                           scanf("%d", &del);
                        
                         
                           hapus(&Pohon, del);
                           printf("\n\nSetelah Node dihapus : ");
                           printf("\n---------------------- ");
                           printf("\nPreorder  : ");
                           preOrder(Pohon); 
                           printf("\nInorder   : ");
                           inOrder(Pohon); 
                           printf("\nPostorder : ");
                           postOrder(Pohon); 
                     }
                     else
                           printf("\n Tree Masih Kosong");

                     _getch();
                     break;

				
			case '5':
					 printf("\n Menampilkan Nilai Terbesar dan Terkecil Dalam Tree ");
                     printf("\n---------------------------------------------\n");
                     if(Pohon!=NULL)
                     {
                           printf(" Nilai Terbesar Dari Tree  : %d \n", Max(Pohon));
                           printf(" Nilai Terkecil Dari Tree  : %d \n", Min(Pohon));
                       }
                     else
                           printf("Tree Masih Kosong");
                    
                     _getch();
                     break;	 
                     
            case '6':
					 Pohon=NULL;
                     printf("\n Mereset Tree");
                     printf("\n-----------------------");
                     printf("\n Tree Sudah Di Kosongkan");
                     _getch();
                     break;     
					 
			case'7':
        			 exit(0);
                     break;
                         
			  }
       }
}
