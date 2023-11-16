```
┌─────────────────────────────────────────────────────────────┐
 ____                        __      __                     
/\  _`\                     /\ \  __/\ \                    
\ \,\L\_\      __     ___   \ \ \/\ \ \ \    ___     ___    
 \/_\__ \    /'__`\  / __`\  \ \ \ \ \ \ \  / __`\ /' _ `\  
   /\ \L\ \ /\  __/ /\ \L\ \  \ \ \_/ \_\ \/\ \L\ \/\ \/\ \ 
   \ `\____\\ \____\\ \____/   \ `\___x___/\ \____/\ \_\ \_\
    \/_____/ \/____/ \/___/     '\/__//__/  \/___/  \/_/\/_/
                                                            
 ____                                            __      
/\  _`\                  __                     /\ \__   
\ \ \L\ \ _ __    ___   /\_\       __     ___   \ \ ,_\  
 \ \ ,__//\`'__\ / __`\ \/\ \    /'__`\  /'___\  \ \ \/  
  \ \ \/ \ \ \/ /\ \L\ \ \ \ \  /\  __/ /\ \__/   \ \ \_ 
   \ \_\  \ \_\ \ \____/ _\ \ \ \ \____\\ \____\   \ \__\
    \/_/   \/_/  \/___/ /\ \_\ \ \/____/ \/____/    \/__/
                        \ \____/                         
                         \/___/                          
                                                                          
└─────────────────────────────────────────────────────────────┘
```

# 🌐 서원대학교 5조 팀 프로젝트
서원대학교 1학년 2학기 5조 팀 프로젝트 통합 저장소입니다.    
     
* 구성
	* **개발 환경**: `GoormIDE (Ubuntu 18.04.6), Visual Studio Code (Windows 10)`
	* **Programming Language:** ![C](https://img.shields.io/badge/-C-00599C?style=flat&logo=C&logoColor=white)
	* **팀 구성**
		 * **팀장(1):** `연승현(202311420)`
  		 * **부팀장(2):** `정희태(202011474), 이호현(202311437)`
		 * **팀원(6):** `김예은(202010319), 김지성(202110343), 양혜성(202311419), 이정호(203311431), 장서진(202311825), 홍정일(202311447)`
         
* 발표
    * **장서진 (202311825): 학습계획서 (11.7)**
    * **홍정일 (202311447): 1~5단원 (11.8)**
    * **김예은 (202010319): 팀 프로젝트 제안 발표 (11.14)**
    * **김지성 (202110343): 5~6단원 (11.15)**
    * **이정호 (203311431): 7단원 (11.22)**
    * **홍정일 (202311447), 양혜성 (202311419): 8~10단원 (12.5)**
    * **김예은 (202010319), 장서진 (202311825): 팀 프로젝트 최종 발표 (12.6)**

* 파일 경로
    * **팀 프로젝트 파일:** `cd ./project/`
    * **N주차 프로그래밍 과제:** `cd ./assignment/`
    * **N주차 창작 과제:** `cd ./assignment/creation/`
    * **N주차 프로그램 팀별과제:** `cd ./assignment/creation/`
    * **파일 실행 코드 (FILE.c):** `gcc ./FILE.c -o /tmp/a.out -lm && clear && /tmp/a.out`
    
## 📝 가계부 프로그램 개발 프로젝트

* **사용 라이브러리**

    * **표준 라이브러리(Standard Library)**
        * `stdio.h`
        * `string.h`
        * `stdbool.h`
        * `json-c/json.h`
        
    * **사용자 정의 라이브러리(User-defined Library)**
    	* `fs.h`
        * `data_manager.h`
        * `prompt.h`
        
* **라이브러리 세부 소개 및 기능**

    * 라이브러리 소개
    
        | 	라이브러리    	|	 	 						소개 								   |
        | :---------------: | :----------------------------------------------------------------:|
        | stdio.h   		| 입출력 관련 함수들을 정의하고 선언하는 라이브러리    					 | 
        | string.h  		| 문자열 관련 함수들을 정의하고 선언하는 라이브러리      	   				 | 
        | stdbool.h 		| 불리언(Boolean) 타입과 관련된 상수들을 정의하는 라이브러리 (true, false) | 
        | json-c/json.h 	| JSON(JavaScript Object Notation) 데이터를 처리하기 위한 라이브러리     |
        | fs.h   			| 파일 입출력 관련 라이브러리      										| 
        | data_manager.h  	| 데이터 수정 및 검색 라이브러리   									   | 
        | prompt.h        	| UI 관련 라이브러리     		   									   |
    
## 🔧 IDE WorkSpace Tip & Guide

* Command feature
	* You can simply run your script using the shortcut icons on the top right.
	* Check out `PROJECT > Common/Build/Run/Test/Find Command` in the top menu.
	

* Useful shortcut
	
| Shortcuts name     | Command (Mac) | Command (Window) |
| ------------------ | :-----------: | :--------------: |
| Copy in Terminal   | ⌘ + C         | Ctrl + Shift + C |
| Paste in Terminal  | ⌘ + V         | Ctrl + Shift + V |
| Search File        | ⌥ + ⇧ + F     | Alt + Shift + F  |
| Terminal Toggle    | ⌥ + ⇧ + B     | Alt + Shift + B  |
| New Terminal       | ⌥ + ⇧ + T     | Alt + Shift + T  |
| Code Formatting    | ⌥ + ⇧ + P     | Alt + Shift + P  |
| Show All Shortcuts | ⌘ + H         | Ctrl + H         |
