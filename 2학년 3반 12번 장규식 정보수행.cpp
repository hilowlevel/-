/**************************************************
*         정보과학 데이터 분석 프로그래밍         *
*반응 속도 테스트를 통한 사용자의 한계 출력 ver.5 *
*	#한계 속도	#평균                             *
*	2312 장규식                                   *
**************************************************/

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int start_menu1(); //시작 메뉴에서 1번 문항을 가르키고 있는 화면 출력 
int start_menu2(); //시작 메뉴에서 2번 문항을 가르키고 있는 화면 출력 
int start_menu3(); //시작 메뉴에서 3번 문항을 가르키고 있는 화면 출력 
int explain_program(); //프로그램 설명 함수 
double integrate(int k); // 상위 몇 %인지를 구할 때, 그래프의 넓이를 구해줄 함수 

int main(){
    int wait_time = 0, tmp = 0, average = 0; //필요한 변수들 선언 
    
	/*입력 샘플 (이 샘플을 사용할 시 line 40 ~ 85을 주석 처리 해주세요.)
	//(예외처리는 실제로 실행될 때만 되기 때문에 예외처리에 해당되는 값은 넣지 않았습니다.) 
	int react_time[100] = {0, 246, 262, 253, 220, 226, 220, 216, 267, 225, 261, 230};
	// */
	
	SetConsoleTitle("반응 속도 테스트 프로그램"); //콘솔창 제목 변경 
	start_menu1(); //시작 메뉴 출력 
    
	for (int i = 3; i > 0; i --){
    	system("cls"); //콘솔창에 글씨 지우기 
    	printf("%d초 후에 테스트가 시작됩니다.\n", i);
    	Sleep(1000); // 1000ms 동안 기다리기 
	}
	
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //글씨 강조를 위해 글씨색을 초록색으로 바꾸기 
	printf("화면이 녹색으로 바뀌는 순간 최대한 빠르게 스페이스 바를 누르세요!\n");
	
	// /*
	//반응 속도를 구하는 과정 (line 42 ~ 84)
	int react_time[5] = {100, 100, 100, 100, 100}; 
	
	for(int i = 0; i < 5; i ++){ 
		tmp = 0;
		
		do{
			//예외처리 되는 구간 
			if(react_time[i] <= 75) { //위에서 모든 배열의 값을 100으로 바꿔주었기 때문에 처음부터 이 if문에 걸리지 않음 
				Sleep(1000);
				printf("지금 스페이스 바를 한 번 눌러주세요.(이 데이터는 분석에 사용되지 않으니 천천히 눌러도 됩니다.)\n"); 
				
				do{
					int start_time = clock(); //현재의 시간을 start_time에 저장 
					char space_bar = _getch(); //키보드 값 입력 받기 
					tmp = space_bar;
					
					if(space_bar == 32) if(clock() - start_time < 75) tmp = 0; //또 비정상적으로 했을 경우 tmp를 0으로 바꾸어서 do while문을 못 빠져나오게 함 
				
				}while(tmp != 32);
			
			}
			
			system("color 02"); //배경색을 바꿔 줌 
			system("cls");
			printf("화면이 녹색으로 바뀌는 순간 최대한 빠르게 스페이스 바를 누르세요!\n");
			
			srand(time(NULL)); 
			wait_time = 1000;//(rand()*rand()%3000) + 2000; //몇 초 뒤에 나타날 것인지(더욱 랜덤한 수가 나오게 하기 위해 제곱을 사용함) 
			Sleep(wait_time);
			system("color 20"); 
			int start_time = clock(); //현재의 시간을 start_time에 저장 
			char space_bar = _getch(); //키보드 값 입력 받기 
			tmp = space_bar;
			
			if(space_bar == 32) react_time[i] = clock() - start_time; //현재의 시간 - 과거의 시간을 이용해 반응 시간을 구함 
			
			if (react_time[i] <= 75) i --; //이 줄 덕분에 line49의 if문에 의해 예외 처리가 감지 됨. 예외 처리한 데이터를 없애주는 효과도 있음. 

		}while(tmp != 32); //tmp가 32(스페이스 바의 아스키 코드)가 아니라면 계속 입력 받을 수 있도록 함
		
		if (react_time[i+1] <= 75) printf("스페이스 바 입력에 이상이 감지되었습니다. 잠시만 기다려주세요.\n"); //반응 속도가 75ms 이하이면 예외처리를 한다는 것을 알려줌 
	}
	// */

	system("color 07");
	system("cls");
	printf("테스트 결과:\n");

	//실행 횟수만큼 결과를 출력함
	for(int i = 0; i < 5; i ++){
		printf("\t%2d회: +%3dms\n", i + 1, react_time[i]);
		average += react_time[i];
	}
	
	average /= 5; //average에 합이 모두 들어갔으니 5로 나누어 줌. 
	
	//분석 결과 출력 (line 100 ~ 119)
	printf("\n당신의 평균 반응 속도는 %dms입니다.\n\n", average); 
	printf("일반인의 평균 반응 속도는 약 270ms, 프로게이머의 평균 반응 속도는 약 150ms입니다.\n\n");
	
	if(average > 270) printf("당신의 반응 속도는 일반인에 비해 %dms 정도 느리며, 프로게이머에 비해 %dms 정도 느립니다.\n\n", average - 270, average - 150);
	
	else if(average == 270) printf("당신의 반응 속도는 평균적인 일반인과 같으며, 프로게이머에 비해 120ms 정도 느립니다.\n\n");
	
	else if(average < 270 && average > 150)printf("당신의 반응 속도는 일반인에 비해 %dms 정도 빠르며, 프로게이머에 비해 %dms 정도 느립니다.\n\n", 270 - average, average - 150);
	
	else if(average == 150) printf("당신의 반응 속도는 일반인에 비해 120ms 정도 빠르며, 평균적인 프로게이머와 같습니다.\n\n");
	
	else printf("당신의 반응 속도는 일반인에 비해 %dms 정도 빠르며, 프로게이머에 비해 %dms 정도 빠릅니다.\n\n", 270 - average, 150 - average);
	
	printf("반응 속도 테스트 사이트의 통계 자료에 의하면(https://humanbenchmark.com/tests/reactiontime),\n"); 
	printf("당신은 상위 %.2f%%의 반응 속도를 가지고 있습니다.\n", integrate(average)); 
	printf("또한, 노트북 모니터의 반응 속도(16ms)를 감안한다면 당신의 반응 속도는 상위 %.2f%%입니다.\n", integrate(average-16));
	printf("테스트가 종료되었습니다. 수고하셨습니다.\n");
    
	return 0;
}

int start_menu1(){
	int tmp = 0;
	system("cls");
	printf("==반응 속도 테스트를 통한 사용자의 한계 출력==\n\n");
	printf("이 프로그램은 사용자의 반응 속도를 분석해주는 프로그램입니다.\n\n");
	printf("방향키로 조절한 후 엔터 버튼을 누르세요.\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
    printf("-> 1. 반응 속도 테스트 시작\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\n   2. 프로그램 설명\n");
    printf("\n   3. 프로그램 종료\n");
    
    //원하는 키보드 값을 입력 받을 때까지 입력 받음 (line 134 ~ 140)
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
	printf("==반응 속도 테스트를 통한 사용자의 한계 출력==\n\n");
	printf("이 프로그램은 사용자의 반응 속도를 분석해주는 프로그램입니다.\n\n");
	printf("방향키로 조절한 후 엔터 버튼을 누르세요.\n\n");
    printf("   1. 반응 속도 테스트 시작\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
    printf("-> 2. 프로그램 설명\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\n   3. 프로그램 종료\n");
    
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
	printf("==반응 속도 테스트를 통한 사용자의 한계 출력==\n\n");
	printf("이 프로그램은 사용자의 반응 속도를 분석해주는 프로그램입니다.\n\n");
	printf("방향키로 조절한 후 엔터 버튼을 누르세요.\n\n");
    printf("   1. 반응 속도 테스트 시작\n\n");
    printf("   2. 프로그램 설명\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
    printf("-> 3. 프로그램 종료\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	
	while(tmp != 72 && tmp != 13){
    	char a = _getch();
    	tmp = a;
    	
		if(a == 72) start_menu2();
		
		else if(a == 13){
    		system("cls");
    		printf("프로그램이 종료되었습니다.\n");
    		exit(0); 
		}
		
	}
	
	return 0;
}

int explain_program(){
	int tmp = 0;
	system("cls");
	printf("이 프로그램은 사용자의 반응 속도를 측정, 분석해주는 프로그램입니다.\n\n");
	printf("화면이 녹색으로 변하면 최대한 빨리 스페이스 바를 한 번만 누르면 됩니다.\n\n");
	printf("녹색 화면은 총 5번 나타나며, 스페이스 바를 누른 시점을 기준으로 2 ~ 5초의 간격을 두고 나타납니다.\n\n"); 
	printf("녹색 화면이 나타나기 이전에 스페이스 바를 누르거나, 반응 속도가 75ms 이하로 나온 데이터는 예측하고 누른 것으로 간주하여 그 데이터는 분석에 사용되지 않습니다.\n\n");
	printf("결과 표시 단계에서의 평균은 반응 속도 테스트 사이트(https://humanbenchmark.com/tests/reactiontime)의 통계 자료를 이용하였습니다.\n");
	printf("일반인의 평균 반응 속도는 약 270ms가 맞으나, 이 통계 자료에서 사용한 데이터는 일반인들이 여러 번 연습 한 후 가장 잘 나온 데이터들을 모은 값입니다. 그러니 좌절하지 마시고 여러 번 도전해보세요.)\n\n"); 
	printf("반응 속도 테스트 사이트의 방문을 원하면 스페이스 바를, 시작 화면으로 돌아가려면 엔터 버튼을 눌러주세요.\n");
	
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
	//처음 배열부터 순서대로 반응 속도가 75ms, 87.5ms, 100ms, ... , 475ms인 사람들의 상대적인 비율임
	//위의 값들의 자료 출처: https://humanbenchmark.com/tests/reactiontime

	if(k > 475) return 100;
	
	if(k < 75) return 0; //노트북 반응 속도를 감안한 평균 반응 속도에 의해 생길 수 있는 예외를 처리해 줌 
	
	int x = k/25, y = k%25; //입력 받은 값을 25*x + y 꼴로 나누어 줌 
	double sum = 0;
	
	if(y < 13){
		if(x == 3) sum = (constant[0] + constant[1]*y/25)*y/25; //x = 3일 때는 밑의 for문에서 문제가 생기므로 다르게 처리해 줌 
		
		else{
			for(int i = 0; i <= 2*x - 8; i++) sum = sum + constant[i];//사다리꼴 공식을 활용한 정적분의 근사에서 아이디어를 얻음 
		
			sum = (sum + constant[2*x - 7]/2)/2 + (constant[2*x - 7] + constant[2*x - 6]*y/25)*y/25;
		}
		
	}
	
	else{
		if(x == 3) sum = constant[2*x - 6]/4 + (2*constant[2*x - 6] + constant[2*x - 5]*(2*y - 25)/25)*(2*y - 25)/100;
		
		else{
			for(int i = 0; i <= 2*x - 7; i++) sum = sum + constant[i];//사다리꼴 공식을 활용한 정적분의 근사에서 아이디어를 얻음 
			
			sum = (sum + constant[2*x - 6]/2)/2 + (2*constant[2*x - 6] + constant[2*x - 5]*(2*y - 25)/25)*(2*y - 25)/100;
		}
		
	}
	
	return sum*100/40.17; //배열의 값들로 그래프를 그렸을 때, 총 넓이가 40.17이기 때문에 백분율을 구하기 위해 *100/40.17을 함 
}
