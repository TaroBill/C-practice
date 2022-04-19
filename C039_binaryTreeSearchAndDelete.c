#include <stdio.h>

typedef struct tree_s{
    int data;
    struct tree_s *left;
    struct tree_s *right;
}tree_t;
typedef tree_t *treep_t;
treep_t addRoot(treep_t tree,int data){
    treep_t head=tree;
    treep_t newTree;
    newTree = (treep_t)malloc(sizeof(tree_t));
    newTree->data=data;
    newTree->left=NULL;
    newTree->right=NULL;
    if(tree==NULL){
        return newTree;
    }else{
        treep_t current=tree;
        while(current!=NULL){
            //printf("data %d current data %d\n",data,current->data);
            if(data>current->data){
                tree=current;
                current=current->right;
            }else if(data<current->data){
                tree=current;
                current=current->left;
            }
        }
        //printf("data %d tree data %d\n",data,tree->data);
        if(data>(tree->data))
            tree->right=newTree;
        else if(data<(tree->data))
            tree->left=newTree;
        return head;
    }
}
treep_t deleteRoot(treep_t tree,int data){
    treep_t head=tree;
    if(tree==NULL){
        return tree;
    }else{
        treep_t current=tree;
        while(current!=NULL){
            if(data>current->data){
                tree=current;
                current=current->right;
            }else if(data<current->data){
                tree=current;
                current=current->left;
            }else{
                if(current->left==NULL && current->right==NULL){
                    free(current);
                    if(data>tree->data){
                        tree->right=NULL;
                    }else if(data<tree->data){
                        tree->left=NULL;
                    }
                    return head;
                }else{
                    treep_t tmpleft=current->left;
                    treep_t tmpLeftUp=current;
                    treep_t tmpright=current->right;
                    treep_t tmpRightUp=current;
                    treep_t tmp=tmpleft;
                    if(tmpleft!=NULL){
                        while(tmp!=NULL){
                            tmpLeftUp=tmpleft;
                            tmpleft=tmp;
                            tmp=tmp->right;
                        }
                        if(tmpleft->left==NULL){
                            if(data>tree->data){
                                tmpleft->left=current->left;
                                tmpleft->right=current->right;
                                tmpLeftUp->right=NULL;
                                if(current!=tree){
                                    tree->right=tmpleft;
                                    free(current);
                                    return head;
                                }
                                free(current);
                                return tmpleft;
                            }else if(data<tree->data){
                                tmpleft->left=current->left;
                                tmpleft->right=current->right;
                                tmpLeftUp->right=NULL;
                                if(current!=tree){
                                    tree->left=tmpleft;
                                    free(current);
                                    return head;
                                }
                                free(current);
                                return tmpleft;
                            }else{
                                tmpleft->left=current->left;
                                tmpleft->right=current->right;
                                if(tmpLeftUp->data!=tmpleft->data)
                                    tmpLeftUp->right=NULL;
                                else
                                    tmpleft->left=NULL;
                                free(current);
                                return tmpleft;
                            }
                        }
                    }
                    tmp=tmpright;
                    while(tmp!=NULL){
                        tmpRightUp=tmpright;
                        tmpright=tmp;
                        tmp=tmp->left;
                    }
                    if(tmpright->right==NULL){
                        if(data>tree->data){
                            tmpright->left=current->left;
                            tmpright->right=current->right;
                            tmpRightUp->left=NULL;
                            if(current!=tree){
                                tree->right=tmpright;
                                free(current);
                                return head;
                            }
                            free(current);
                            return tmpright;
                        }else if(data<tree->data){
                            tmpright->left=current->left;
                            tmpright->right=current->right;
                            tmpRightUp->left=NULL;
                            if(current!=tree){
                                tree->left=tmpright;
                                free(current);
                                return head;
                            }
                            free(current);
                            return tmpright;
                        }else{
                           // printf("123");
                            tmpright->left=current->left;
                            tmpright->right=current->right;
                            if(tmpRightUp->data!=tmpright->data)
                                tmpRightUp->left=NULL;
                            else
                                tmpright->right=NULL;
                            free(current);
                            return tmpright;
                        }
                    }
                    if(tmpleft!=NULL){
                        tmp=tmpleft->left;
                        tmpLeftUp->right=tmp;
                        tmpleft->left=current->left;
                        tmpleft->right=current->right;
                        if(current!=tree){
                            if(data>tree->data)
                                tree->right=tmpleft;
                            else if(data<tree->data)
                                tree->left=tmpleft;
                            free(current);
                            return head;
                        }else{
                            free(current);
                            return tmpleft;
                        }
                    }else{
                        tmp=tmpright->right;
                        tmpRightUp->left=tmp;
                        tmpright->left=current->left;
                        tmpright->right=current->right;
                        if(current!=tree){
                            if(data>tree->data)
                                tree->right=tmpright;
                            else if(data<tree->data)
                                tree->left=tmpright;
                            free(current);
                            return head;
                        }else{
                            free(current);
                            return tmpright;
                        }
                    }
                }
                break;
            }
        }
    }
}
void pre(treep_t data,int *C){
    if(data==NULL)
        return;
    printf("%d",data->data);
    if((*C)>0){
        printf(",");
        (*C)--;
    }
    pre(data->left,C);
    pre(data->right,C);
}
void In(treep_t data,int *C){
    if(data==NULL)
        return;
    In(data->left,C);
    printf("%d",data->data);
    if((*C)>0){
        printf(",");
        (*C)--;
    }
    In(data->right,C);
}
void post(treep_t data,int *C){
    if(data==NULL)
        return;
    post(data->left,C);
    post(data->right,C);
    printf("%d",data->data);
    if((*C)>0){
        printf(",");
        (*C)--;
    }
}
void freeL(treep_t data){
    if(data==NULL)
        return;
    freeL(data->left);
    freeL(data->right);
    free(data);
}
int main(){
    char c;
    int ip;
    int count=0;
    treep_t data=NULL;
    do{
        count++;
        scanf("%d",&ip);
        scanf("%c",&c);
        data = addRoot(data,ip);
    }while(c!='\n');
    count-=2;
    int cc=count;
    scanf("%d",&ip);
    data = deleteRoot(data,ip);
    printf("preorder:");pre(data,&cc);
    printf("\n");
    cc=count;
    printf("inorder:");In(data,&cc);
    printf("\n");
    cc=count;
    printf("postorder:");post(data,&cc);
    printf("\n");
    freeL(data);
}
