#include<administer.h>
#include<consumer.h>
#include<dofile.h>
#include<menu.h>
#include<stdio.h>
#include<stdlib.h>

//void ShowWindowAdm();
//void MakeCard(Apply_Node *card);
//void CheckApply(Apply_Node *Apply);
//void SendCard(Consume_Node *card);
//void Showinfo();
//void ChangePsw();

Consumer_Node *head;               //ͷ�ڵ�
Apply_Node *head_Apply;            //ͷ�ڵ�

int main(){
}

void ShowWindowAdm(){
    printf("�𾴵Ĺ���Ա,��ӭʹ�ù��￨����ϵͳ!n");
    printf("  *********************\n");
    printf("**  ���￨����ϵͳ  **\n");
    printf("**  �ƿ�---1  **\n");
    printf("**  ����---2  **\n");
    printf("**  ����---3  **\n");
    printf("**  �鿴��Ϣ---4  **\n");
    printf("**  �޸�����---5  **\n");
    printf("**  �˳�����ϵͳ---0  **\n");

    printf("�������Ӧ�Ĺ��ܼ�(����):  ");
}

void MakeCard(Apply_Node *card){                                      //�ƿ�
    Consumer_Node *s=(Consumer_Node *)malloc(sizeof(Consumer_Node));

    s->number_=card->number_;
    s->name_=card->name_;
    s->password_=card->password_;
    s->id_=card->id_;
    s->is_available_=false;
    
    s->next_=head->next_;
    head->next_=s;
    printf("�ƿ��ɹ�������\n");

}

void CheckApply(Apply_Node *apply){                                //����
    system("cls");
    Apply_Node *p=(Apply_Node *)malloc(sizeof(Apply_Node));
    int number;
    int flag;
    p=apply->next;
    if(apply->next!=NULL){
        while(p!=NULL){
            printf("��������Ĺ��￨��Ϣ:\n");
            printf("����:%d\n",p->number_);
            printf("����:%s\n",p->name_);
            printf("���֤:%s\n",p->id_);
            printf("\n");

            p=p->next;
        }

        while(1){
            printf("������׼����Ŀ���:");
            scanf("%d",&number);
 
            p=apply->next;
            while(1){
                if(p->number_==number){
                    break;
                }

                else{
                    p=p->next;
                }
            }

            MakeCard(p);
            printf("�Ƿ��������(��(1)/��(0):");
            scanf("%d",&flag);
            if(flag==0){
                break;
            }
        }
    }

    else if(apply->next=NULL){                 
            printf("����������Ĺ��￨\n");
    }
}

void SendCard(Consumer_Node *card){                          //����
    card->is_available_=true;
}

void ShowInfo(){
    Consumer_Node *s=(Consumer_Node *)malloc(sizeof(Consumer_Node));
    s=head->next_;
    while(s!=NULL){
        printf("����:%d\n",s->number_);
        printf("����:%s\n",s->name_);
        printf("����:%s\n",s->password_);
        printf("���֤:%s\n",s->id_);
        printf("���:%f\n",s->balance_);
        printf("����:%f\n",s->score_);
        printf("\n");
        s=s->next_;
    }
}

void ChangePsw(Administer Adm){
    char password[6];
    printf("������������:");
    scanf("%s",password);
     
    Adm.password_=password;
}

void AskCard(struct Apply_Node* apply){        //���빺�￨
    int number;
    char name[10];
    char password[6];
    char id[18];
    printf("�����뿨��:");
    scanf("%d",&number);

    printf("��������:");
    scanf("%s",name);

    printf("����������:");
    scanf("%s",password);

    printf("���������֤:");
    scanf("%s",id);

    Apply_Node *p=(Apply_Node *)malloc(sizeof(Apply_Node));
    p->number_=number;
    p->name_=name;
    p->password_=password;
    p->id_=id;

    p->next=apply->next;
    apply->next=p;

}	