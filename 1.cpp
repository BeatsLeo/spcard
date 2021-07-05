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

Consumer_Node *head;               //头节点
Apply_Node *head_Apply;            //头节点

int main(){
}

void ShowWindowAdm(){
    printf("尊敬的管理员,欢迎使用购物卡管理系统!n");
    printf("  *********************\n");
    printf("**  购物卡管理系统  **\n");
    printf("**  制卡---1  **\n");
    printf("**  审批---2  **\n");
    printf("**  发卡---3  **\n");
    printf("**  查看信息---4  **\n");
    printf("**  修改密码---5  **\n");
    printf("**  退出管理系统---0  **\n");

    printf("请输入对应的功能键(数字):  ");
}

void MakeCard(Apply_Node *card){                                      //制卡
    Consumer_Node *s=(Consumer_Node *)malloc(sizeof(Consumer_Node));

    s->number_=card->number_;
    s->name_=card->name_;
    s->password_=card->password_;
    s->id_=card->id_;
    s->is_available_=false;
    
    s->next_=head->next_;
    head->next_=s;
    printf("制卡成功！！！\n");

}

void CheckApply(Apply_Node *apply){                                //审批
    system("cls");
    Apply_Node *p=(Apply_Node *)malloc(sizeof(Apply_Node));
    int number;
    int flag;
    p=apply->next;
    if(apply->next!=NULL){
        while(p!=NULL){
            printf("正在申请的购物卡信息:\n");
            printf("卡号:%d\n",p->number_);
            printf("姓名:%s\n",p->name_);
            printf("身份证:%s\n",p->id_);
            printf("\n");

            p=p->next;
        }

        while(1){
            printf("输入批准申请的卡号:");
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
            printf("是否继续操作(是(1)/否(0):");
            scanf("%d",&flag);
            if(flag==0){
                break;
            }
        }
    }

    else if(apply->next=NULL){                 
            printf("无正在申请的购物卡\n");
    }
}

void SendCard(Consumer_Node *card){                          //发卡
    card->is_available_=true;
}

void ShowInfo(){
    Consumer_Node *s=(Consumer_Node *)malloc(sizeof(Consumer_Node));
    s=head->next_;
    while(s!=NULL){
        printf("卡号:%d\n",s->number_);
        printf("姓名:%s\n",s->name_);
        printf("密码:%s\n",s->password_);
        printf("身份证:%s\n",s->id_);
        printf("余额:%f\n",s->balance_);
        printf("积分:%f\n",s->score_);
        printf("\n");
        s=s->next_;
    }
}

void ChangePsw(Administer Adm){
    char password[6];
    printf("请输入新密码:");
    scanf("%s",password);
     
    Adm.password_=password;
}

void AskCard(struct Apply_Node* apply){        //申请购物卡
    int number;
    char name[10];
    char password[6];
    char id[18];
    printf("请输入卡号:");
    scanf("%d",&number);

    printf("输入姓名:");
    scanf("%s",name);

    printf("请输入密码:");
    scanf("%s",password);

    printf("请输入身份证:");
    scanf("%s",id);

    Apply_Node *p=(Apply_Node *)malloc(sizeof(Apply_Node));
    p->number_=number;
    p->name_=name;
    p->password_=password;
    p->id_=id;

    p->next=apply->next;
    apply->next=p;

}	