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
        printf("*    1.save (invalid)\n*    2.pay(invalid)\n*    3.show\n*    4.change code(invalid)\n*    5.delete\n*    6.quit\n");//操作
        printf("*\n");
        printf("****************************\n");
        printf("*    Please choose operator: ");}//选择操作数
    else{
        printf("Your account is valid\n");
        printf("****************************\n");
        printf("*\n");
        printf("*    1.save\n*    2.pay\n*    3.show\n*    4.change code\n*    5.delete\n*    6.quit\n");//操作
        printf("*\n");
        printf("****************************\n");
        printf("*    Please choose operator: ");//选择操作数
    }
};
//存款函数
float SaveMoney(struct Consumer consumer){
    float n;//存的钱
    printf("Please input your money: ");
    scanf("%f",&n);
    printf("You seccessfully save %.2f dollor !\n",n);
    return n;
    };
//付款函数
void Pay(struct Consumer consumer){};//函数体由李浩宇完成
//报表函数
void Show(struct Consumer consumer){
    printf("name: %s\n",consumer.name_);//姓名
    printf("id: %s\n",consumer.id_);//身份证
    printf("balance: %.2f\n",consumer.balance_);//余额
    printf("number: %d\n",consumer.number_);//卡号
    printf("score: %.2f\n",consumer.score_);//积分
    if(consumer.is_available_){printf("Your card is valid !\n");}
    else printf("Your card is invalid !\n");//是否激活
};
//注销函数
void Delete(struct Consumer consumer){};
//退出函数
int Quit(){return 1;};
int main(void){
    int n;//n表示操作数
    Consumer consumer;//实例化某个消费者对象
    for(;;){
        ShowWindowCon(consumer);//窗口显示
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            if(consumer.is_available_){
            float money;
            money = SaveMoney(consumer);//money表示存的钱
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
        case 4://修改密码
            printf("New password: ");
            for(int i =0;i<=6;i++){
                char ch;
                ch=getchar();
                consumer.password_[i] = ch;
            }//修改密码
            // printf("%s\n",consumer.password_);
            break;
        case 5://注销
            printf("You succeesfully delete yourself !");
            return 1;
            break;
        case 6://退出
            printf("You succeesfully quit !\n");
            return 0;
            break;
        }
        }
}