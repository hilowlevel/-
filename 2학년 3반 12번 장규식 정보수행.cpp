/**************************************************
*         �������� ������ �м� ���α׷���         *
*���� �ӵ� �׽�Ʈ�� ���� ������� �Ѱ� ��� ver.5 *
*	#�Ѱ� �ӵ�	#���                             *
*	2312 ��Խ�                                   *
**************************************************/

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int start_menu1(); //���� �޴����� 1�� ������ ����Ű�� �ִ� ȭ�� ��� 
int start_menu2(); //���� �޴����� 2�� ������ ����Ű�� �ִ� ȭ�� ��� 
int start_menu3(); //���� �޴����� 3�� ������ ����Ű�� �ִ� ȭ�� ��� 
int explain_program(); //���α׷� ���� �Լ� 
double integrate(int k); // ���� �� %������ ���� ��, �׷����� ���̸� ������ �Լ� 

int main(){
    int wait_time = 0, tmp = 0, average = 0; //�ʿ��� ������ ���� 
    
	/*�Է� ���� (�� ������ ����� �� line 40 ~ 85�� �ּ� ó�� ���ּ���.)
	//(����ó���� ������ ����� ���� �Ǳ� ������ ����ó���� �ش�Ǵ� ���� ���� �ʾҽ��ϴ�.) 
	int react_time[100] = {0, 246, 262, 253, 220, 226, 220, 216, 267, 225, 261, 230};
	// */
	
	SetConsoleTitle("���� �ӵ� �׽�Ʈ ���α׷�"); //�ܼ�â ���� ���� 
	start_menu1(); //���� �޴� ��� 
    
	for (int i = 3; i > 0; i --){
    	system("cls"); //�ܼ�â�� �۾� ����� 
    	printf("%d�� �Ŀ� �׽�Ʈ�� ���۵˴ϴ�.\n", i);
    	Sleep(1000); // 1000ms ���� ��ٸ��� 
	}
	
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //�۾� ������ ���� �۾����� �ʷϻ����� �ٲٱ� 
	printf("ȭ���� ������� �ٲ�� ���� �ִ��� ������ �����̽� �ٸ� ��������!\n");
	
	// /*
	//���� �ӵ��� ���ϴ� ���� (line 42 ~ 84)
	int react_time[5] = {100, 100, 100, 100, 100}; 
	
	for(int i = 0; i < 5; i ++){ 
		tmp = 0;
		
		do{
			//����ó�� �Ǵ� ���� 
			if(react_time[i] <= 75) { //������ ��� �迭�� ���� 100���� �ٲ��־��� ������ ó������ �� if���� �ɸ��� ���� 
				Sleep(1000);
				printf("���� �����̽� �ٸ� �� �� �����ּ���.(�� �����ʹ� �м��� ������ ������ õõ�� ������ �˴ϴ�.)\n"); 
				
				do{
					int start_time = clock(); //������ �ð��� start_time�� ���� 
					char space_bar = _getch(); //Ű���� �� �Է� �ޱ� 
					tmp = space_bar;
					
					if(space_bar == 32) if(clock() - start_time < 75) tmp = 0; //�� ������������ ���� ��� tmp�� 0���� �ٲپ do while���� �� ���������� �� 
				
				}while(tmp != 32);
			
			}
			
			system("color 02"); //������ �ٲ� �� 
			system("cls");
			printf("ȭ���� ������� �ٲ�� ���� �ִ��� ������ �����̽� �ٸ� ��������!\n");
			
			srand(time(NULL)); 
			wait_time = 1000;//(rand()*rand()%3000) + 2000; //�� �� �ڿ� ��Ÿ�� ������(���� ������ ���� ������ �ϱ� ���� ������ �����) 
			Sleep(wait_time);
			system("color 20"); 
			int start_time = clock(); //������ �ð��� start_time�� ���� 
			char space_bar = _getch(); //Ű���� �� �Է� �ޱ� 
			tmp = space_bar;
			
			if(space_bar == 32) react_time[i] = clock() - start_time; //������ �ð� - ������ �ð��� �̿��� ���� �ð��� ���� 
			
			if (react_time[i] <= 75) i --; //�� �� ���п� line49�� if���� ���� ���� ó���� ���� ��. ���� ó���� �����͸� �����ִ� ȿ���� ����. 

		}while(tmp != 32); //tmp�� 32(�����̽� ���� �ƽ�Ű �ڵ�)�� �ƴ϶�� ��� �Է� ���� �� �ֵ��� ��
		
		if (react_time[i+1] <= 75) printf("�����̽� �� �Է¿� �̻��� �����Ǿ����ϴ�. ��ø� ��ٷ��ּ���.\n"); //���� �ӵ��� 75ms �����̸� ����ó���� �Ѵٴ� ���� �˷��� 
	}
	// */

	system("color 07");
	system("cls");
	printf("�׽�Ʈ ���:\n");

	//���� Ƚ����ŭ ����� �����
	for(int i = 0; i < 5; i ++){
		printf("\t%2dȸ: +%3dms\n", i + 1, react_time[i]);
		average += react_time[i];
	}
	
	average /= 5; //average�� ���� ��� ������ 5�� ������ ��. 
	
	//�м� ��� ��� (line 100 ~ 119)
	printf("\n����� ��� ���� �ӵ��� %dms�Դϴ�.\n\n", average); 
	printf("�Ϲ����� ��� ���� �ӵ��� �� 270ms, ���ΰ��̸��� ��� ���� �ӵ��� �� 150ms�Դϴ�.\n\n");
	
	if(average > 270) printf("����� ���� �ӵ��� �Ϲ��ο� ���� %dms ���� ������, ���ΰ��̸ӿ� ���� %dms ���� �����ϴ�.\n\n", average - 270, average - 150);
	
	else if(average == 270) printf("����� ���� �ӵ��� ������� �Ϲ��ΰ� ������, ���ΰ��̸ӿ� ���� 120ms ���� �����ϴ�.\n\n");
	
	else if(average < 270 && average > 150)printf("����� ���� �ӵ��� �Ϲ��ο� ���� %dms ���� ������, ���ΰ��̸ӿ� ���� %dms ���� �����ϴ�.\n\n", 270 - average, average - 150);
	
	else if(average == 150) printf("����� ���� �ӵ��� �Ϲ��ο� ���� 120ms ���� ������, ������� ���ΰ��̸ӿ� �����ϴ�.\n\n");
	
	else printf("����� ���� �ӵ��� �Ϲ��ο� ���� %dms ���� ������, ���ΰ��̸ӿ� ���� %dms ���� �����ϴ�.\n\n", 270 - average, 150 - average);
	
	printf("���� �ӵ� �׽�Ʈ ����Ʈ�� ��� �ڷῡ ���ϸ�(https://humanbenchmark.com/tests/reactiontime),\n"); 
	printf("����� ���� %.2f%%�� ���� �ӵ��� ������ �ֽ��ϴ�.\n", integrate(average)); 
	printf("����, ��Ʈ�� ������� ���� �ӵ�(16ms)�� �����Ѵٸ� ����� ���� �ӵ��� ���� %.2f%%�Դϴ�.\n", integrate(average-16));
	printf("�׽�Ʈ�� ����Ǿ����ϴ�. �����ϼ̽��ϴ�.\n");
    
	return 0;
}

int start_menu1(){
	int tmp = 0;
	system("cls");
	printf("==���� �ӵ� �׽�Ʈ�� ���� ������� �Ѱ� ���==\n\n");
	printf("�� ���α׷��� ������� ���� �ӵ��� �м����ִ� ���α׷��Դϴ�.\n\n");
	printf("����Ű�� ������ �� ���� ��ư�� ��������.\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
    printf("-> 1. ���� �ӵ� �׽�Ʈ ����\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\n   2. ���α׷� ����\n");
    printf("\n   3. ���α׷� ����\n");
    
    //���ϴ� Ű���� ���� �Է� ���� ������ �Է� ���� (line 134 ~ 140)
	while(tmp != 80 && tmp != 13){
    	char a = _getch();
    	tmp = a;
    	
		if(a == 80) start_menu2();
		
	}
	
	return 0;
}

int start_menu2(){
	int tmp = 0;
	system("cls");
	printf("==���� �ӵ� �׽�Ʈ�� ���� ������� �Ѱ� ���==\n\n");
	printf("�� ���α׷��� ������� ���� �ӵ��� �м����ִ� ���α׷��Դϴ�.\n\n");
	printf("����Ű�� ������ �� ���� ��ư�� ��������.\n\n");
    printf("   1. ���� �ӵ� �׽�Ʈ ����\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
    printf("-> 2. ���α׷� ����\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\n   3. ���α׷� ����\n");
    
	while(tmp != 72 && tmp != 80 && tmp != 13){
    	char a = _getch();
    	tmp = a;
    	
    	if(a == 72) start_menu1(); 
		
		else if(a == 80) start_menu3(); 
		
		else if(a == 13) explain_program();
		
	}
	
	return 0;
}

int start_menu3(){
	int tmp = 0;
	system("cls");
	printf("==���� �ӵ� �׽�Ʈ�� ���� ������� �Ѱ� ���==\n\n");
	printf("�� ���α׷��� ������� ���� �ӵ��� �м����ִ� ���α׷��Դϴ�.\n\n");
	printf("����Ű�� ������ �� ���� ��ư�� ��������.\n\n");
    printf("   1. ���� �ӵ� �׽�Ʈ ����\n\n");
    printf("   2. ���α׷� ����\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
    printf("-> 3. ���α׷� ����\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	
	while(tmp != 72 && tmp != 13){
    	char a = _getch();
    	tmp = a;
    	
		if(a == 72) start_menu2();
		
		else if(a == 13){
    		system("cls");
    		printf("���α׷��� ����Ǿ����ϴ�.\n");
    		exit(0); 
		}
		
	}
	
	return 0;
}

int explain_program(){
	int tmp = 0;
	system("cls");
	printf("�� ���α׷��� ������� ���� �ӵ��� ����, �м����ִ� ���α׷��Դϴ�.\n\n");
	printf("ȭ���� ������� ���ϸ� �ִ��� ���� �����̽� �ٸ� �� ���� ������ �˴ϴ�.\n\n");
	printf("��� ȭ���� �� 5�� ��Ÿ����, �����̽� �ٸ� ���� ������ �������� 2 ~ 5���� ������ �ΰ� ��Ÿ���ϴ�.\n\n"); 
	printf("��� ȭ���� ��Ÿ���� ������ �����̽� �ٸ� �����ų�, ���� �ӵ��� 75ms ���Ϸ� ���� �����ʹ� �����ϰ� ���� ������ �����Ͽ� �� �����ʹ� �м��� ������ �ʽ��ϴ�.\n\n");
	printf("��� ǥ�� �ܰ迡���� ����� ���� �ӵ� �׽�Ʈ ����Ʈ(https://humanbenchmark.com/tests/reactiontime)�� ��� �ڷḦ �̿��Ͽ����ϴ�.\n");
	printf("�Ϲ����� ��� ���� �ӵ��� �� 270ms�� ������, �� ��� �ڷῡ�� ����� �����ʹ� �Ϲ��ε��� ���� �� ���� �� �� ���� �� ���� �����͵��� ���� ���Դϴ�. �׷��� �������� ���ð� ���� �� �����غ�����.)\n\n"); 
	printf("���� �ӵ� �׽�Ʈ ����Ʈ�� �湮�� ���ϸ� �����̽� �ٸ�, ���� ȭ������ ���ư����� ���� ��ư�� �����ּ���.\n");
	
	while(tmp != 13 && tmp != 32){
		char a = _getch();
		tmp = a;
 	
		if(a == 13) start_menu1();
		
		else if(a == 32){
			system("start https://humanbenchmark.com/tests/reactiontime");
			explain_program();
		}
		
	}
	
	return 0;
}

double integrate(int k){
	double constant[32]= {0.01, 0.04, 0.09, 0.38, 1.2, 2.64, 4.95, 7.29, 8.44, 8.84, 8.7, 8.16, 7.03, 5.63, 4.36, 3.2, 2.3, 1.63, 1.2, 0.92, 0.69, 0.54, 0.43, 0.36, 0.3, 0.24, 0.19, 0.15, 0.14, 0.13, 0.11, 0.1};
	//ó�� �迭���� ������� ���� �ӵ��� 75ms, 87.5ms, 100ms, ... , 475ms�� ������� ������� ������
	//���� ������ �ڷ� ��ó: https://humanbenchmark.com/tests/reactiontime

	if(k > 475) return 100;
	
	if(k < 75) return 0; //��Ʈ�� ���� �ӵ��� ������ ��� ���� �ӵ��� ���� ���� �� �ִ� ���ܸ� ó���� �� 
	
	int x = k/25, y = k%25; //�Է� ���� ���� 25*x + y �÷� ������ �� 
	double sum = 0;
	
	if(y < 13){
		if(x == 3) sum = (constant[0] + constant[1]*y/25)*y/25; //x = 3�� ���� ���� for������ ������ ����Ƿ� �ٸ��� ó���� �� 
		
		else{
			for(int i = 0; i <= 2*x - 8; i++) sum = sum + constant[i];//��ٸ��� ������ Ȱ���� �������� �ٻ翡�� ���̵� ���� 
		
			sum = (sum + constant[2*x - 7]/2)/2 + (constant[2*x - 7] + constant[2*x - 6]*y/25)*y/25;
		}
		
	}
	
	else{
		if(x == 3) sum = constant[2*x - 6]/4 + (2*constant[2*x - 6] + constant[2*x - 5]*(2*y - 25)/25)*(2*y - 25)/100;
		
		else{
			for(int i = 0; i <= 2*x - 7; i++) sum = sum + constant[i];//��ٸ��� ������ Ȱ���� �������� �ٻ翡�� ���̵� ���� 
			
			sum = (sum + constant[2*x - 6]/2)/2 + (2*constant[2*x - 6] + constant[2*x - 5]*(2*y - 25)/25)*(2*y - 25)/100;
		}
		
	}
	
	return sum*100/40.17; //�迭�� ����� �׷����� �׷��� ��, �� ���̰� 40.17�̱� ������ ������� ���ϱ� ���� *100/40.17�� �� 
}
