#include<stdio.h>
#include"administer.h"
#include"consumer.h"
#include"menu.h"
#include"dofile.h"
void ShowWindowCon(struct Consumer consumer){
    if(!(consumer.is_available_)){
        printf("Your account is invalid\n");
        printf("****************************\n");
        printf("*\n");
        printf("*    1.save (invalid)\n*    2.pay(invalid)\n*    3.show\n*    4.change code(invalid)\n*    5.delete\n*    6.quit\n");//����
        printf("*\n");
        printf("****************************\n");
        printf("*    Please choose operator: ");}//ѡ�������
    else{
        printf("Your account is valid\n");
        printf("****************************\n");
        printf("*\n");
        printf("*    1.save\n*    2.pay\n*    3.show\n*    4.change code\n*    5.delete\n*    6.quit\n");//����
        printf("*\n");
        printf("****************************\n");
        printf("*    Please choose operator: ");//ѡ�������
    }
};
//����
float SaveMoney(struct Consumer consumer){
    float n;//���Ǯ
    printf("Please input your money: ");
    scanf("%f",&n);
    printf("You seccessfully save %.2f dollor !\n",n);
    return n;
    };
//�����
void Pay(struct Consumer consumer){};//����������������
//������
void Show(struct Consumer consumer){
    printf("name: %s\n",consumer.name_);//����
    printf("id: %s\n",consumer.id_);//���֤
    printf("balance: %.2f\n",consumer.balance_);//���
    printf("number: %d\n",consumer.number_);//����
    printf("score: %.2f\n",consumer.score_);//����
    if(consumer.is_available_){printf("Your card is valid !\n");}
    else printf("Your card is invalid !\n");//�Ƿ񼤻�
};
//ע������
void Delete(struct Consumer consumer){};
//�˳�����
int Quit(){return 1;};
int main(void){
    int n;//n��ʾ������
    Consumer consumer;//ʵ����ĳ�������߶���
    for(;;){
        ShowWindowCon(consumer);//������ʾ
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            if(consumer.is_available_){
            float money;
            money = SaveMoney(consumer);//money��ʾ���Ǯ
            consumer.balance_+=money;
            }
            else{printf("Pelase activate your code first !\n");};
            break;
        case 2:
            if(consumer.is_available_){Pay(consumer);}
            else{printf("Pelase activate your code first !\n");};
            break;
        case 3:
            Show(consumer);
            break;
        case 4://�޸�����
            printf("New password: ");
            for(int i =0;i<=6;i++){
                char ch;
                ch=getchar();
                consumer.password_[i] = ch;
            }//�޸�����
            // printf("%s\n",consumer.password_);
            break;
        case 5://ע��
            printf("You succeesfully delete yourself !");
            return 1;
            break;
        case 6://�˳�
            printf("You succeesfully quit !\n");
            return 0;
            break;
        }
        }
}